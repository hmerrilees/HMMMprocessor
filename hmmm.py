
# globals
controller = Controller()
datapath = Datapath()


def bitstring(n):
    binary = bin(n)
    without_prefix = binary[2:]
    extended_with_zeros = without_prefix.zfill(16)
    return extended_with_zeros

def readmemb(self):
    # read from program.txt
    with open('program.txt', 'r') as f:
        i = 0
        for line in f:
            line = line.split('#', 1)[0] # eliminate comments
            line = ''.join(filter(str.isdigit, line)) # preserve only digits
            if line == '':
                continue
            line = int(line, 2) # convert binary to decimal
            self.memory[i] = line
            i += 1

class RegisterFile:
    def __init__(self):
        self.reset()

    def reset(self):
        self.registers = [0] * 16

    def cycle(self):
        global controller, datapath

        # === sequential section ===
        # in hardware, this runs once per clock cycle

        if (controller.rf_write_en_1 and controller.rf_write_en_2 and (datapath.rf_read_adr_1 == datapath.rf_read_adr_2)):
            print("WARNING: write to same register in same cycle. Second write channel takes priority.")
        if controller.rf_write_en_1:
            self.registers[datapath.rf_read_adr_1] = datapath.rf_write_data_1
        if controller.rf_write_en_2:
            self.registers[datapath.rf_read_adr_2] = datapath.rf_write_data_2

    # === combinational section ===
    # In hardware, the remainder of the assignments would be evaluated continuously, here they are computed on the fly.

    @property
    def read_data_1(self):
        global datapath
        if rf_read_adr_1 == 0:
            return 0
        else:
            return self.registers[datapath.rf_read_adr_1]

    @property
    def read_data_2(self):
        global datapath
        if rf_read_adr_2 == 0:
            return 0
        else:
            return self.registers[datapath.rf_read_adr_2]

    @property
    def read_data_3(self):
        global datapath
        if rf_read_adr_3 == 0:
            return 0
        else:
            return self.registers[datapath.rf_read_adr_3]




class Memory:
    def __init__(self):
        self.reset()

    def reset(self):
        global memory
        memory = [0] * 256
        self.readmemb()

    def cycle(self):
        global controller, datapath

        # === sequential section ===
        # in hardware, this runs once per clock cycle

        if controller.mem_write_en:
            self.memory[datapath.mem_data_address] = datapath.mem_write_data

    # === combinational section ===
    # In hardware, the remainder of the assignments would be defined *combiniationally*, 
    # i.e. constantly and continuously updated without waiting for a clock cycle.
    # Because python does not have a straightforward analogue to combinational logic such that we could 
    # update elsewhere the values which depend on `instruction`, we will assign them all here.

    # Because we are running "single-threaded", we can act under the assumption that there is no other code
    # running at the same time, i.e. no other code to grab an incorrect value before we get the chance to update it below.

    @property
    def instruction(self): 
        global datapath
        return self.memory[datapath.pc >> 1] # align to 2 bytes, right shift by 1 bit is just an efficient way to divide by 2

    @property
    def mem_data_data(self):
        global datapath
        return self.memory[datapath.mem_data_address]

class ALU:
    @property
    def alu_result(self):
        global controller, datapath
        a = datapath.alu_input_a
        b = datapath.alu_input_b


        # === combinational section === 
        # it's actually all combinational, we don't need to wait for a clock cycle because we aren't reading/writing any state local to this particular module

        # on a real hardware, this block would be done in parallel
        add_result = a + b
        sub_result = a - b
        mul_result = a * b
        div_result = a / b
        mod_result = a % b

        # and this branching would be performed by a multiplexer, like the one we made!
        match controller.alu_op:
            case ALU_ADD:
                result = add_result
            case ALU_SUB:
                result = sub_result
            case ALU_MUL:
                result = mul_result
            case ALU_DIV:
                result = div_result
            case ALU_MOD: 
                result = mod_result

        return result


class Controller:
    def decode(instruction):
        instruction_bits = bitstring(instruction)

        # control flow & I/O
        if instruction_bits[0:4] == '0000' and instruction_bits[-4:] == '0000':
            instruction_type = "HALT"
        elif instruction_bits[0:4] == '0000' and instruction_bits[-4:] == '0001':
            instruction_type = "READ"
        elif instruction_bits[0:4] == '0000' and instruction_bits[-4:] == '0010':
            instruction_type = "WRITE"
        elif instruction_bits[0:4] == '0000' and instruction_bits[-4:] == '0011':
            instruction_type = "JUMPR"

        # non-arithmetic register/memory manipulation with address sourced from immediate
        elif instruction_bits[0:4] == '0001':
            instruction_type = "SETN"
        elif instruction_bits[0:4] == '0010':
            instruction_type = "LOADN"
        elif instruction_bits[0:4] == '0011':
            instruction_type = "STOREN"

        # register/memory manipulation with addresses sourced from register
        elif instruction_bits[0:4] == '0100' and instruction_bits[-4:] == '0000':
            instruction_type = "LOADR"
        elif instruction_bits[0:4] == '0100' and instruction_bits[-4:] == '0001':
            instruction_type = "STORER"
        elif instruction_bits[0:4] == '0100' and instruction_bits[-4:] == '0010':
            instruction_type = "POPR"
        elif instruction_bits[0:4] == '0100' and instruction_bits[-4:] == '0011':
            instruction_type = "PUSHR"

        # arithmetic operatoins
        elif instruction_bits[0:4] == '0101':
            instruction_type = "ADDN"
        elif instruction_bits[0:4] == '0110' and instruction_bits[-4:] == '0000':
            instruction_type = "COPY"
        elif instruction_bits[0:4] == '0110':
            instruction_type = "ADD"
        elif instruction_bits[0:4] == '0111' and instruction_bits[-9:-5] == '0000':
            instruction_type = "NEG"
        elif instruction_bits[0:4] == '0111':
            instruction_type = "SUB"
        elif instruction_bits[0:4] == '1000':
            instruction_type = "MUL"
        elif instruction_bits[0:4] == '1001':
            instruction_type = "DIV"
        elif instruction_bits[0:4] == '1010':
            instruction_type = "MOD"

        # control flow (cont.)
        elif instruction_bits[0:4] == '1011' and instruction_bits[5:9] == '0000':
            instruction_type = "JUMPN"
        elif instruction_bits[0:4] == '1011':
            instruction_type = "CALLN"

        # conditional control flow
        elif instruction_bits[0:4] == '1100':
            instruction_type = "JEQZN"
        elif instruction_bits[0:4] == '1101':
            instruction_type = "JNEZN"
        elif instruction_bits[0:4] == '1110':
            instruction_type = "JGTZN"
        elif instruction_bits[0:4] == '1111':
            instruction_type = "JLTZN"

        # default case
        else:
            instruction_type =  "NOP"

        return instruction_type


    def compute_controls(self):
        global datapath
        instruction_type = decode(datapath.memory.instruction)

        #defaults
        self._mem_adr_src = 0b0  # memory sources from immediate
        self._mem_data_src = 0b0  # memory gets write data from ALU result
        self._mem_write = 0b0  # disable write to memory
        self._pc_src = 0b00  # pc gets pc + 2
        self._reg_src_x = 0b00  # register file gets write data from immediate
        self._reg_write_x = 0b0  # disable write to register file
        self._reg_write_y = 0b0  # disable write to register file
        self._alu_op = "ALU_ADD"  # ALU operation is ADD
        self._alu_src_a = 0b0  # ALU source A is the contents of register rX
        self._alu_src_b = 0b00  # ALU source B is the contents of register rY

        match instruction_type:
          case "LOADR":
            # Load register rX with data from the address location held in reg. rY
            self._mem_adr_src = 0b1  # get the memory from address valued rY
            self._reg_src_x   = 0b01  # direct data from memory to rX
            self._reg_write_x = 0b1  # enable write to rx
          case "READ":
            # emulator, read from stdin, processor, read from 16 bit input (presumed to be hooked up to serial transfer peripheral)
            # Ideally, should stall the processor until the input is ready.
            # TODO 
          case "WRITE":
            # Print contents of register rX
            # rX is already hard-wired into the first address port of the register file
            # so we will simply print from the corresponding read_data_1 output
          case "SETN":
            # Set register rX equal to the integer N (-128 to +127)
            self._reg_src_x   = 0b00  # direct the immediate to rX
            self._reg_write_x = 0b1  # enable write to rx
          case "LOADN":
            # Load register rX with the contents of memory address N
            self._mem_adr_src = 0b0  # get the memory at the address corresponding to the immediate
            self._reg_src_x   = 0b01  # direct data from memory to rX
            self._reg_write_x = 0b1  # enable write to rx
          case "JUMPR":
            #Set program counter to address in rX
            self._pc_src = 0b11  # get the next program counter from the contents of rX
          case "JUMPN" | "JEQZN" | "JNEZN" | "JGTZN" | "JLTZN":
            # Set program counter to address N
            self._pc_src = 0b10  # get the next program counter from the immediate
          case "CALLN":
            # Copy addr. of next instr. into rX and then jump to mem. addr. N
            self._pc_src = 0b10  # next program counter is sourced from the immediate
            self._reg_src_x = 0b10 # save the instruction address immediately following the CALLN instruction into rX
            self._reg_write_x = 0b1  # enable write to rX
          case "STOREN":
            # Store contents of register rX into memory address N
            self._mem_adr_src = 0b00  # direct the immediate to the memory address
            self._mem_data_src = 0b1  # direct rX to the memory data input
            self._mem_write = 0b1  # enable write to memory
          case "STORER":
            # Store contents of register rX into memory address held in reg. rY
            self._mem_data_src = 0b1  # get data from rX
            self._mem_adr_src = 0b01  # direct to address at rY
            self._mem_write = 0b1  # enable write to memory
          case "POPR":
            # Load contents of register rX from stack pointed to by register rY: rY -= 0b1 rX = memory[rY]

            # alu_result = rY - 1
            self._alu_src_a = 0b0  # rY
            self._alu_src_b = 0b11  # 1
            self._alu_op = "ALU_SUB"  # sub

            # rY = alu_result
            self._reg_write_y = 0b1  # enable write to rY (default source from alu_result)

            # rX = memory[rY]
            self._mem_adr_src = 0b10  # get the data at the address corresponding to old rY + 0b1 (alu_result)
            self._reg_src_x = 0b01  # direct the memory data to rX
            self._reg_write_x = 0b1  # enable write to rX

          case "PUSHR":
            # Store contents of register rX onto stack pointed to by register rY: memory[rY] = rX rY += 1
            # 
            self._mem_data_src = 0b1  # direct the contents of rX to the memory
            self._mem_adr_src = 0b01  # write to memory address rY
            self._mem_write = 0b1  # enable write to memory

            # alu_result = rY + 1
            self._alu_src_a = 0b0  # rY
            self._alu_src_b = 0b11  # 1
            self._alu_op = "ALU_ADD"  # add

            # rY = alu_result
            self._reg_write_y = 0b1  # enable write to rY (default source from alu_result)
          case "ADD" | "COPY" | "NOP":
            # alu_result = rY + rZ
            self._alu_src_a = 0b0  # rY
            self._alu_src_b = 0b00  # rZ
            self._alu_op = "ALU_ADD"

            # rX = alu_result
            self._reg_src_x = 0b11  # register file gets write data from the ALU result
            self._reg_write_x = 0b1  # enable write to rx
          case "ADDN":
            # alu_result = rX + N
            self._alu_src_a = 0b1  # rX
            self._alu_src_b = 0b01  # immediate
            self._alu_op = "ALU_ADD"

            # rX = alu_result
            self._reg_src_x = 0b11  # register file gets write data from the ALU result
            self._reg_write_x = 0b1  # enable write to rx
          case "SUB" | "NEG":
            # alu_result = rY - rZ
            self._alu_src_a = 0b0  # rY
            self._alu_src_b = 0b00  # rZ
            self._alu_op = "ALU_SUB"

            # rX = alu_result
            self._reg_src_x = 0b11  # register file gets write data from the ALU result
            self._reg_write_x = 0b1  # enable write to rx
          case "MUL":
            # alu_result = rY * rZ
            self._alu_src_a = 0b0  # rY
            self._alu_src_b = 0b00  # rZ
            self._alu_op = "ALU_MUL"

            # rX = alu_result
            self._reg_src_x = 0b11  # register file gets write data from the ALU result
            self._reg_write_x = 0b1  # enable write to rx
          case "DIV":
            # alu_result = rY / rZ
            self._alu_src_a = 0b0  # rY
            self._alu_src_b = 0b00  # rZ
            self._alu_op = "ALU_DIV"

            # rX = alu_result
            self._reg_src_x = 0b11  # register file gets write data from the ALU result
            self._reg_write_x = 0b1  # enable write to rx
          case "MOD":
            # alu_result = rY % rZ
            self._alu_src_a = 0b0  # rY
            self._alu_src_b = 0b00  # rZ
            self._alu_op = "ALU_MOD"

            # rX = alu_result
            self._reg_src_x = 0b11  # register file gets write data from the ALU result
            self._reg_write_x = 0b1  # enable write to rx


        @property
        def mem_adr_src(self):
            self.compute_controls()
            return self._mem_adr_src

        @property
        def mem_data_src(self):
            self.compute_controls()
            return self._mem_data_src

        @property
        def mem_write(self):
            self.compute_controls()
            return self._mem_write

        @property
        def pc_src(self):
            self.compute_controls()
            return self._pc_src

        @property
        def reg_src_x(self):
            self.compute_controls()
            return self._reg_src_x

        @property
        def reg_write_x(self):
            self.compute_controls()
            return self._reg_write_x

        @property
        def reg_write_y(self):
            self.compute_controls()
            return self._reg_write_y

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





"""
module Datapath (
    input logic clk,
    reset,
    input logic mem_write,
    rf_write_x,
    rf_write_y,
    mem_data_src,
    alu_src_a,
    input logic [1:0] pc_src,
    alu_src_b,
    rf_src_x,
    mem_adr_src,
    input instr_t instruction_type,
    input alu_op_t alu_op,
    output logic [15:0] instruction
);

  // ==============  Internal Signals ============== 


  logic [7:0] pc, pc_plus_2, pc_next, pc_target, immediate, mem_data_address;

  logic [15:0]
      result,
      alu_result,
      alu_input_a,
      alu_input_b,
      rf_read_data_1,
      rf_read_data_2,
      rf_read_data_3,
      rf_write_data_1,
      rf_write_data_2,
      mem_read_data,
      mem_write_data;

  logic [3:0] rX, rY, rZ;

  assign rX = instruction[11:8];
  assign rY = instruction[7:4];
  assign rZ = instruction[3:0];
  assign immediate = instruction[7:0];

  logic zero, sign;


  // ============== pc logic ============== 
  always_ff @(posedge clk) pc <= pc_next;

  assign zero = (rf_read_data_1 == 0);
  assign sign = rf_read_data_1[15];

  logic take_jump;

  always_comb
    case (instruction_type)
      JEQZN:   take_jump = zero;
      JNEZN:   take_jump = ~zero;
      JGTZN:   take_jump = ~sign & ~zero;
      JLTZN:   take_jump = sign;
      JUMPR:   take_jump = 1;
      JUMPN:   take_jump = 1;
      default: take_jump = 1;
    endcase

  always_comb
    if (reset) pc_next = 0;
    else if (pc_src[1] & take_jump) pc_next = pc_target;
    else pc_next = pc_plus_2;  // word alignment is 2 bytes

  assign pc_target = pc_src[0] ? rf_read_data_1[7:0] : immediate << 1;  // todo check
  assign pc_plus_2 = pc + 2;


  // cheat to handle status prints, write and halt

  always_ff @(posedge clk) begin
    $display("Instruction number: %d", pc / 2);
    $display("instruction: %h", instruction);
    $display("zero: %b, sign: %b, take_jump: %b", zero, sign, take_jump);

    if (instruction_type == WRITE) $display("write: %b", rf_read_data_1);
    else if (instruction_type == HALT) begin
      $display("halt");

      // dump registers
      for (int i = 0; i < 15; i++) begin
        $display("reg[%d]: %h", i, rf.registers[i]);
      end
      $display("\n");
      // dump memory
      for (int i = 0; i < 255; i++) begin
        $display("mem[%d]: %h", i, mem.RAM[i]);
      end
      // done
      $finish;
    end
  end


  // ============== Memory logic ============== 
  Memory mem (
      .clk(clk),
      .mem_write_en(mem_write),
      .pc(pc),
      .mem_data_address(mem_data_address),
      .mem_write_data(mem_write_data),
      .instruction(instruction),
      .mem_read_data(mem_read_data)
  );

  always_comb
    case (mem_adr_src)
      2'b00: mem_data_address = immediate;
      2'b01: mem_data_address = rf_read_data_2[7:0];
      2'b10: mem_data_address = alu_result[7:0];
    endcase

  assign mem_write_data = mem_data_src ? rf_read_data_1 : alu_result;

  logic [15:0] imm_ext;
  assign imm_ext = immediate[7] ? {8'b11111111, immediate} : {8'b0, immediate};

  always_comb
    case (rf_src_x)
      2'b00: rf_write_data_1 = imm_ext;
      2'b01: rf_write_data_1 = mem_read_data;
      2'b10: rf_write_data_1 = {8'b0, pc_plus_2};
      2'b11: rf_write_data_1 = alu_result;
    endcase

  assign rf_write_data_2 = alu_result;

  // ============== REGISTER FILE logic ============== 
  RegisterFile rf (
      .clk(clk),
      .rf_read_adr_1(rX),
      .rf_read_adr_2(rY),
      .rf_read_adr_3(rZ),
      .rf_write_en_1(rf_write_x),
      .rf_write_en_2(rf_write_y),
      .rf_write_data_1(rf_write_data_1),
      .rf_write_data_2(rf_write_data_2),
      .rf_read_data_1(rf_read_data_1),
      .rf_read_data_2(rf_read_data_2),
      .rf_read_data_3(rf_read_data_3)
  );

  // ============= ALU logic ============== 

  ALU alu (
      .alu_op(alu_op),
      .src_a(alu_input_a),
      .src_b(alu_input_b),
      .alu_result(alu_result)
  );

  assign alu_input_a = alu_src_a ? rf_read_data_1 : rf_read_data_2;

  always_comb
    case (alu_src_b)
      2'b0:  alu_input_b = rf_read_data_3;
      2'b1:  alu_input_b = imm_ext;
      2'b10: alu_input_b = 0;
      2'b11: alu_input_b = 1;
    endcase
endmodule
"""
class Datapath:
    def __init__(self):
        self.memory = Memory()
        self.register_file = RegisterFile()
        self.alu = ALU()

    def cycle():
        global controller

        #local mem_write, rf_write_x, rf_write_y, mem_data_src, alu_src_a, pc_src, alu_src_b, rf_src_x, mem_adr_src, instruction_type, alu_op, instruction



        # === internal signals === 
        # TODO ...



    @property
    def instruction(self):
        return self.memory.instruction
                                        
    @property
    def rX(self):
        return (self.instruction & 0x0F00) >> 12 # instruction[11:8]

    @property
    def rY(self):
        return (self.instruction & 0x00F0) >> 8 # instruction[7:4]

    @property
    def rZ(self):
        return (self.instruction & 0x000F) # instruction[3:0]

    @property
    def immediate(self):
        # the immediate/constant is already the second half of the instruction, no need to shift
        return self.instruction & 0x00FF # instruction[7:0]


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
