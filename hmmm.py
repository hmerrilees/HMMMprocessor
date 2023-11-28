def bitstring(n):
    binary = bin(n)
    without_prefix = binary[2:]
    extended_with_zeros = without_prefix.zfill(16)
    return extended_with_zeros


def i16_to_int(n):
    if n >> 15:
        return n - 0x10000
    else:
        return n


class RegisterFile:
    def __init__(self, controller, datapath):
        self.controller = controller
        self.datapath = datapath

    def reset(self):
        self.registers = [0] * 16

    def cycle(self):
        adr_x = self.datapath.rf_adr_x
        write_data_x = self.datapath.rf_write_data_x
        write_en_x = self.controller.rf_write_en_x

        adr_y = self.datapath.rf_adr_y
        write_data_y = self.datapath.rf_write_data_y
        write_en_y = self.controller.rf_write_en_y

        if write_en_x and write_en_y and (adr_x == adr_y):
            print(
                "WARNING: write to same register in same cycle. Second write channel takes priority."
            )
        if write_en_x:
            self.registers[adr_x] = write_data_x
        if write_en_y:
            self.registers[adr_y] = write_data_y

    @property
    def read_data_x(self):
        adr_x = self.datapath.rf_adr_x

        if adr_x == 0:
            return 0
        else:
            return self.registers[adr_x]

    @property
    def read_data_y(self):
        adr_y = self.datapath.rf_adr_y

        if adr_y == 0:
            return 0
        else:
            return self.registers[adr_y]

    @property
    def read_data_z(self):
        adr_z = self.datapath.rf_adr_z

        if adr_z == 0:
            return 0
        else:
            return self.registers[adr_z]


class Memory:
    def __init__(self, controller, datapath):
        self.controller = controller
        self.datapath = datapath
        self.reset()

    def readmemb(self):
        # read from program.txt
        with open("program.txt", "r") as f:
            i = 0
            for line in f:
                line = line.split("#", 1)[0]  # eliminate comments
                line = "".join(filter(str.isdigit, line))  # preserve only digits
                if line == "":
                    continue
                line = int(line, 2)  # convert binary to decimal
                self.RAM[i] = line
                i += 1

    def reset(self):
        self.RAM = [0] * 256
        self.readmemb()

    def cycle(self):
        mem_write_en = self.controller.mem_write_en
        mem_data_address = self.datapath.mem_data_address
        mem_write_data = self.datapath.mem_write_data

        if mem_write_en:
            self.RAM[mem_data_address] = mem_write_data

    @property
    def instruction(self):
        pc = self.datapath.pc

        return self.RAM[
            pc >> 1
        ]  # align to 2 bytes, right shift by 1 bit is just an efficient way to divide by 2

    @property
    def mem_data_data(self):
        data_address = self.datapath.mem_data_address

        return self.RAM[data_address]


class ALU:
    def __init__(self, controller, datapath):
        self.controller = controller
        self.datapath = datapath

    @property
    def result(self):
        a = self.datapath.alu_input_a
        b = self.datapath.alu_input_b
        alu_op = self.controller.alu_op

        # on a real hardware, this block would be done in parallel
        add_result = a + b
        sub_result = a - b
        mul_result = a * b
        if b != 0:
            div_result = a / b
            mod_result = a % b
        else:
            div_result = 0
            mod_result = 0

        # and this branching would be performed by a multiplexer, like the one we made!
        match alu_op:
            case "ALU_ADD":
                alu_result = add_result
            case "ALU_SUB":
                alu_result = sub_result
            case "ALU_MUL":
                alu_result = mul_result
            case "ALU_DIV":
                alu_result = div_result
            case "ALU_MOD":
                alu_result = mod_result

        return alu_result


class Controller:
    def __init__(self, top):
        self.top = top

    @property
    def instruction_type(self):
        instruction = self.top.datapath.mem.instruction

        instruction_bits = bitstring(instruction)

        # control flow & I/O
        if instruction_bits[0:4] == "0000" and instruction_bits[-4:] == "0000":
            instruction_type = "HALT"
        elif instruction_bits[0:4] == "0000" and instruction_bits[-4:] == "0001":
            instruction_type = "READ"
        elif instruction_bits[0:4] == "0000" and instruction_bits[-4:] == "0010":
            instruction_type = "WRITE"
        elif instruction_bits[0:4] == "0000" and instruction_bits[-4:] == "0011":
            instruction_type = "JUMPR"

        # non-arithmetic register/memory manipulation with address sourced from immediate
        elif instruction_bits[0:4] == "0001":
            instruction_type = "SETN"
        elif instruction_bits[0:4] == "0010":
            instruction_type = "LOADN"
        elif instruction_bits[0:4] == "0011":
            instruction_type = "STOREN"

        # register/memory manipulation with addresses sourced from register
        elif instruction_bits[0:4] == "0100" and instruction_bits[-4:] == "0000":
            instruction_type = "LOADR"
        elif instruction_bits[0:4] == "0100" and instruction_bits[-4:] == "0001":
            instruction_type = "STORER"
        elif instruction_bits[0:4] == "0100" and instruction_bits[-4:] == "0010":
            instruction_type = "POPR"
        elif instruction_bits[0:4] == "0100" and instruction_bits[-4:] == "0011":
            instruction_type = "PUSHR"

        # arithmetic operatoins
        elif instruction_bits[0:4] == "0101":
            instruction_type = "ADDN"
        elif instruction_bits[0:4] == "0110" and instruction_bits[-4:] == "0000":
            instruction_type = "COPY"
        elif instruction_bits[0:4] == "0110":
            instruction_type = "ADD"
        elif instruction_bits[0:4] == "0111" and instruction_bits[-9:-5] == "0000":
            instruction_type = "NEG"
        elif instruction_bits[0:4] == "0111":
            instruction_type = "SUB"
        elif instruction_bits[0:4] == "1000":
            instruction_type = "MUL"
        elif instruction_bits[0:4] == "1001":
            instruction_type = "DIV"
        elif instruction_bits[0:4] == "1010":
            instruction_type = "MOD"

        # control flow (cont.)
        elif instruction_bits[0:4] == "1011" and instruction_bits[5:9] == "0000":
            instruction_type = "JUMPN"
        elif instruction_bits[0:4] == "1011":
            instruction_type = "CALLN"

        # conditional control flow
        elif instruction_bits[0:4] == "1100":
            instruction_type = "JEQZN"
        elif instruction_bits[0:4] == "1101":
            instruction_type = "JNEZN"
        elif instruction_bits[0:4] == "1110":
            instruction_type = "JGTZN"
        elif instruction_bits[0:4] == "1111":
            instruction_type = "JLTZN"

        # default case
        else:
            instruction_type = "NOP"

        return instruction_type

    def compute_controls(self):
        # defaults
        self._mem_adr_src = 0b0  # memory sources from immediate
        self._mem_data_src = 0b0  # memory gets write data from ALU result
        self._mem_write_en = 0b0  # disable write to memory
        self._pc_src = 0b00  # pc gets pc + 2
        self._rf_src_x = 0b00  # register file gets write data from immediate
        self._rf_write_en_x = 0b0  # disable write to register file
        self._rf_write_en_y = 0b0  # disable write to register file
        self._alu_op = "ALU_ADD"  # ALU operation is ADD
        self._alu_src_a = 0b0  # ALU source A is the contents of register rX
        self._alu_src_b = 0b00  # ALU source B is the contents of register rY

        match self.instruction_type:
            case "LOADR":
                # Load register rX with data from the address location held in reg. rY
                self._mem_adr_src = 0b1  # get the memory from address valued rY
                self._rf_src_x = 0b01  # direct data from memory to rX
                self._rf_write_en_x = 0b1  # enable write to rx
            case "READ":
                # emulator, read from stdin, processor, read from 16 bit input (presumed to be hooked up to serial transfer peripheral)
                # Ideally, should stall the processor until the input is ready.
                # TODO
                pass
            case "WRITE":
                # Print contents of register rX
                # rX is already hard-wired into the first address port of the register file
                # so we will simply print from the corresponding read_data_1 output
                pass
            case "SETN":
                # Set register rX equal to the integer N (-128 to +127)
                self._rf_src_x = 0b00  # direct the immediate to rX
                self._rf_write_en_x = 0b1  # enable write to rx
            case "LOADN":
                # Load register rX with the contents of memory address N
                self._mem_adr_src = (
                    0b0  # get the memory at the address corresponding to the immediate
                )
                self._rf_src_x = 0b01  # direct data from memory to rX
                self._rf_write_en_x = 0b1  # enable write to rx
            case "JUMPR":
                # Set program counter to address in rX
                self._pc_src = (
                    0b11  # get the next program counter from the contents of rX
                )
            case "JUMPN" | "JEQZN" | "JNEZN" | "JGTZN" | "JLTZN":
                # Set program counter to address N
                self._pc_src = 0b10  # get the next program counter from the immediate
            case "CALLN":
                # Copy addr. of next instr. into rX and then jump to mem. addr. N
                self._pc_src = (
                    0b10  # next program counter is sourced from the immediate
                )
                self._rf_src_x = 0b10  # save the instruction address immediately following the CALLN instruction into rX
                self._rf_write_en_x = 0b1  # enable write to rX
            case "STOREN":
                # Store contents of register rX into memory address N
                self._mem_adr_src = 0b00  # direct the immediate to the memory address
                self._mem_data_src = 0b1  # direct rX to the memory data input
                self._mem_write_en = 0b1  # enable write to memory
            case "STORER":
                # Store contents of register rX into memory address held in reg. rY
                self._mem_data_src = 0b1  # get data from rX
                self._mem_adr_src = 0b01  # direct to address at rY
                self._mem_write_en = 0b1  # enable write to memory
            case "POPR":
                # Load contents of register rX from stack pointed to by register rY: rY -= 0b1 rX = memory[rY]

                # alu_result = rY - 1
                self._alu_src_a = 0b0  # rY
                self._alu_src_b = 0b11  # 1
                self._alu_op = "ALU_SUB"  # sub

                # rY = alu_result
                self._rf_write_en_y = (
                    0b1  # enable write to rY (default source from alu_result)
                )

                # rX = memory[rY]
                self._mem_adr_src = 0b10  # get the data at the address corresponding to old rY + 0b1 (alu_result)
                self._rf_src_x = 0b01  # direct the memory data to rX
                self._rf_write_en_x = 0b1  # enable write to rX

            case "PUSHR":
                # Store contents of register rX onto stack pointed to by register rY: memory[rY] = rX rY += 1
                #
                self._mem_data_src = 0b1  # direct the contents of rX to the memory
                self._mem_adr_src = 0b01  # write to memory address rY
                self._mem_write_en = 0b1  # enable write to memory

                # alu_result = rY + 1
                self._alu_src_a = 0b0  # rY
                self._alu_src_b = 0b11  # 1
                self._alu_op = "ALU_ADD"  # add

                # rY = alu_result
                self._rf_write_en_y = (
                    0b1  # enable write to rY (default source from alu_result)
                )
            case "ADD" | "COPY" | "NOP":
                # alu_result = rY + rZ
                self._alu_src_a = 0b0  # rY
                self._alu_src_b = 0b00  # rZ
                self._alu_op = "ALU_ADD"

                # rX = alu_result
                self._rf_src_x = (
                    0b11  # register file gets write data from the ALU result
                )
                self._rf_write_en_x = 0b1  # enable write to rx
            case "ADDN":
                # alu_result = rX + N
                self._alu_src_a = 0b1  # rX
                self._alu_src_b = 0b01  # immediate
                self._alu_op = "ALU_ADD"

                # rX = alu_result
                self._rf_src_x = (
                    0b11  # register file gets write data from the ALU result
                )
                self._rf_write_en_x = 0b1  # enable write to rx
            case "SUB" | "NEG":
                # alu_result = rY - rZ
                self._alu_src_a = 0b0  # rY
                self._alu_src_b = 0b00  # rZ
                self._alu_op = "ALU_SUB"

                # rX = alu_result
                self._rf_src_x = (
                    0b11  # register file gets write data from the ALU result
                )
                self._rf_write_en_x = 0b1  # enable write to rx
            case "MUL":
                # alu_result = rY * rZ
                self._alu_src_a = 0b0  # rY
                self._alu_src_b = 0b00  # rZ
                self._alu_op = "ALU_MUL"

                # rX = alu_result
                self._rf_src_x = (
                    0b11  # register file gets write data from the ALU result
                )
                self._rf_write_en_x = 0b1  # enable write to rx
            case "DIV":
                # alu_result = rY / rZ
                self._alu_src_a = 0b0  # rY
                self._alu_src_b = 0b00  # rZ
                self._alu_op = "ALU_DIV"

                # rX = alu_result
                self._rf_src_x = (
                    0b11  # register file gets write data from the ALU result
                )
                self._rf_write_en_x = 0b1  # enable write to rx
            case "MOD":
                # alu_result = rY % rZ
                self._alu_src_a = 0b0  # rY
                self._alu_src_b = 0b00  # rZ
                self._alu_op = "ALU_MOD"

                # rX = alu_result
                self._rf_src_x = (
                    0b11  # register file gets write data from the ALU result
                )
                self._rf_write_en_x = 0b1  # enable write to rx

    @property
    def mem_adr_src(self):
        self.compute_controls()
        return self._mem_adr_src

    @property
    def mem_data_src(self):
        self.compute_controls()
        return self._mem_data_src

    @property
    def mem_write_en(self):
        self.compute_controls()
        return self._mem_write_en

    @property
    def pc_src(self):
        self.compute_controls()
        return self._pc_src

    @property
    def rf_src_x(self):
        self.compute_controls()
        return self._rf_src_x

    @property
    def rf_write_en_x(self):
        self.compute_controls()
        return self._rf_write_en_x

    @property
    def rf_write_en_y(self):
        self.compute_controls()
        return self._rf_write_en_y

    @property
    def alu_op(self):
        self.compute_controls()
        return self._alu_op

    @property
    def alu_src_a(self):
        self.compute_controls()
        return self._alu_src_a

    @property
    def alu_src_b(self):
        self.compute_controls()
        return self._alu_src_b


class Datapath:
    def __init__(self, top):
        self.controller = top.controller
        self.mem = Memory(self.controller, self)
        self.rf = RegisterFile(self.controller, self)
        self.alu = ALU(self.controller, self)

    def reset(self):
        self.pc = 0
        self.mem.reset()
        self.rf.reset()

    def cycle(self):
        instruction_type = self.controller.instruction_type

        print(f"Instruction number: {self.pc // 2}")
        print(f"Instruction type: {instruction_type}")
        print(f"Instruction: {self.instruction:0>16x}")

        print()
        if instruction_type == "WRITE":
            print(f"write: {self.rf.read_data_x}")
        elif instruction_type == "HALT":
            print("halt")
            print("registers:")
            for i in range(16):
                print(f"reg[{i:0>1x}]: {i16_to_int(self.rf.registers[i]):>2d}")
            print("\nmemory:")
            for i in range(256):
                print(f"mem[{i:0>2x}]: {self.mem.RAM[i]:0>4x}")
            print("done")
            exit(0)

        self.mem.cycle()
        self.rf.cycle()

        self.pc = self.pc_next

    @property
    def rf_write_data_x(self):
        match self.controller.rf_src_x:
            case 0b00:
                return self.imm_ext
            case 0b01:
                return self.mem.read_data
            case 0b10:
                return self.pc_plus_2
            case 0b11:
                return self.alu.result

    @property
    def rf_write_data_y(self):
        return self.alu.result

    @property
    def mem_write_data(self):
        match self.controller.mem_data_src:
            case 0b0:
                return self.alu.result
            case 0b1:
                return self.rf.read_data_x

    @property
    def mem_data_address(self):
        match self.controller.mem_adr_src:
            case 0b00:
                return self.immediate
            case 0b01:
                return self.rf.read_data_y[-8:]
            case 0b10:
                return self.alu.result[-8:]

    @property
    def pc_target(self):
        pc_src_lsb = self.controller.pc_src & 1
        if pc_src_lsb:
            return self.rf.read_data_x
        else:
            return self.immediate << 1

    @property
    def pc_plus_2(self):
        return self.pc + 2

    @property
    def pc_next(self):
        pc_src = self.controller.pc_src
        pc_src_msb = pc_src >> 1
        if pc_src_msb & self.take_jump:
            return self.pc_target
        else:
            return self.pc_plus_2

    @property
    def zero(self):
        return int(self.rf.read_data_x == 0)

    @property
    def sign(self):
        msb = (self.rf.read_data_x >> 15) & 1
        return msb

    @property
    def take_jump(self):
        match self.controller.instruction_type:
            case "JEQZN":
                result = self.zero
            case "JNEZN":
                result = not self.zero
            case "JGTZN":
                result = not self.sign and not self.zero
            case "JLTZN":
                result = self.sign
            case "JUMPR":
                result = True
            case "JUMPN":
                result = True
            case _:
                result = True  # default case

        return int(result)

    @property
    def alu_input_a(self):
        if self.controller.alu_src_a:
            return self.rf.read_data_x
        else:
            return self.rf.read_data_y

    @property
    def alu_input_b(self):
        match self.controller.alu_src_b:
            case 0b00:
                return self.rf.read_data_z
            case 0b01:
                return self.imm_ext
            case 0b10:
                return 0
            case 0b11:
                return 1

    @property
    def imm_ext(self):
        old_msb = self.immediate >> 7
        if old_msb:
            return self.immediate | 0xFF00
        else:
            return self.immediate

    @property
    def instruction(self):
        return self.mem.instruction

    """
    bitmasking:
    0x is a prefix for hexadecimal numbers just as 0b is for binary numbers
    0x00F0 = 0b0000000011110000
    by ANDing with 1's for what we want to keep and 0's for what we want to discard, we can extract the desired bits
    e.g. (hex)    0x00F0 & 0x1234 = 0x0030
    e.g. (binary) 0b0000000011110000 & 0b0001001000110100 = 0b0000000000110000
    but we don't want 0x0030, we want 0x0003, so we right shift by 4 bits
    0x0030 >> 4 = 0x0003
    """

    @property
    def rf_adr_x(self):
        return (self.instruction & 0x0F00) >> 8  # instruction[11:8]

    @property
    def rf_adr_y(self):
        return (self.instruction & 0x00F0) >> 4  # instruction[7:4]

    @property
    def rf_adr_z(self):
        return self.instruction & 0x000F  # instruction[3:0]

    @property
    def immediate(self):
        # the immediate/constant is already the second half of the instruction, no need to shift
        return self.instruction & 0x00FF  # instruction[7:0]


class Top:
    def __init__(self):
        self.controller = Controller(self)
        self.datapath = Datapath(self)

        self.reset()

    def reset(self):
        self.datapath.reset()

    def cycle(self):
        self.datapath.cycle()


if __name__ == "__main__":
    top = Top()
    while True:
        top.cycle()
