/* verilator lint_off CASEOVERLAP */
/* verilator lint_off DECLFILENAME */
/* verilator lint_off UNUSEDSIGNAL */
/* verilator lint_off CASEINCOMPLETE */

typedef enum {
  HALT,
  NOP,
  READ,
  WRITE,
  SETN,
  LOADR,
  STORER,
  POPR,
  PUSHR,
  LOADN,
  STOREN,
  ADDN,
  ADD,
  COPY,
  SUB,
  NEG,
  MUL,
  DIV,
  MOD,
  JUMPR,
  JUMPN,
  JEQZN,
  JNEZN,
  JGTZN,
  JLTZN,
  CALLN
} instr_t;

typedef enum {
  ALU_ADD,
  ALU_SUB,
  ALU_MUL,
  ALU_DIV,
  ALU_MOD
} alu_op_t;


module hmmm (
    input logic clk,
    reset
);
  logic [15:0] instruction;
  logic [1:0] reg_src_x, pc_src, mem_adr_src, alu_src_b;
  logic mem_write, reg_write_x, reg_write_y, mem_data_src, alu_src_a;

  alu_op_t alu_op;
  instr_t  instruction_type;

  Controller controller (
      .instruction(instruction),
      .alu_op(alu_op),
      .alu_src_a(alu_src_a),
      .alu_src_b(alu_src_b),
      .mem_write(mem_write),
      .reg_write_x(reg_write_x),
      .reg_src_x(reg_src_x),
      .reg_write_y(reg_write_y),
      .mem_adr_src(mem_adr_src),
      .mem_data_src(mem_data_src),
      .pc_src(pc_src),
      .instruction_type(instruction_type)
  );

  Datapath datapath (
      .clk(clk),
      .reset(reset),
      .mem_write(mem_write),
      .reg_write_x(reg_write_x),
      .reg_src_x(reg_src_x),
      .reg_write_y(reg_write_y),
      .mem_adr_src(mem_adr_src),
      .mem_data_src(mem_data_src),
      .pc_src(pc_src),
      .alu_op(alu_op),
      .alu_src_a(alu_src_a),
      .alu_src_b(alu_src_b),
      .instruction_type(instruction_type),
      .instruction(instruction)
  );
endmodule

module Memory (
    input logic clk,
    write_en,
    input logic [7:0] instruction_address,
    data_address,
    input logic [15:0] write_data,
    output logic [15:0] instruction_data,
    read_data
);
  initial $readmemb("program.txt", RAM);

  logic [15:0] RAM[255:0];

  always_ff @(posedge clk) if (write_en) RAM[data_address] <= write_data;

  assign instruction_data = RAM[{
    1'b0, instruction_address[7:1]
  }];  // needs to be word-aligned to 2 bytes TODO check
  assign read_data = RAM[data_address];
endmodule

module RegisterFile (
    input logic clk,
    input logic [3:0] address_1,
    address_2,
    address_3,
    input logic write_en_1,
    write_en_2,
    input logic [15:0] write_data_1,
    write_data_2,
    output logic [15:0] read_data_1,
    read_data_2,
    read_data_3
);

  // TODO pretty sure we are allocating flops for r0 needlessly
  logic [15:0] registers[15:0];

  assign read_data_1 = (address_1 != 0) ? registers[address_1] : 16'd0; // be careful on this one, written value doesn't update until next cycle
  assign read_data_2 = (address_2 != 0) ? registers[address_2] : 16'd0;
  assign read_data_3 = (address_3 != 0) ? registers[address_3] : 16'd0;

  always_ff @(posedge clk) begin
    if (write_en_1 & write_en_2 & (address_1 == address_2))
      $display(
          "WARNING: write to same register in same cycle. Second write channel takes priority."
      );
    if (write_en_1) registers[address_1] = write_data_1;
    if (write_en_2) registers[address_2] = write_data_2;
  end
endmodule

module Controller (
    input logic [15:0] instruction,
    output alu_op_t alu_op,
    output logic mem_write,
    reg_write_x,
    reg_write_y,
    mem_data_src,
    alu_src_a,
    output logic [1:0] reg_src_x,
    alu_src_b,
    mem_adr_src,
    pc_src,
    output instr_t instruction_type
);


  always_comb
    casez (instruction)

      // CONTROL_FLOW
      16'b0000_0000_0000_0000: instruction_type = HALT;

      16'b0000_????_0000_0001: instruction_type = READ;  // todo no great way to do in hardware

      16'b0000_????_0000_0010: instruction_type = WRITE;
      16'b0000_????_0000_0011: instruction_type = JUMPR;

      // SETN
      16'b0001_????_????_????: instruction_type = SETN;

      // LOADN
      16'b0010_????_????_????: instruction_type = LOADN;

      // STOREN
      16'b0011_????_????_????: instruction_type = STOREN;


      // MEMORY_R
      16'b0100_????_????_0000: instruction_type = LOADR;
      16'b0100_????_????_0001: instruction_type = STORER;

      16'b0100_????_????_0010: instruction_type = POPR;  // TODO
      16'b0100_????_????_0011: instruction_type = PUSHR;  // TODO

      // ADDN
      16'b0101_????_????_????: instruction_type = ADDN;  // TODO

      // ADD
      16'b0110_????_????_????: instruction_type = ADD;  // TODO
      // 16'b0110_0000_0000_0000: instruction_type = NOP; // add duplicate, handled as default
      16'b0110_????_????_0000: instruction_type = COPY;  // add duplicate

      // SUB
      16'b0111_????_????_????: instruction_type = SUB;  // TODO
      16'b0111_????_0000_????: instruction_type = NEG;  // sub duplicate

      // Mul
      16'b1000_????_????_????: instruction_type = MUL;  // TODO

      // Div
      16'b1001_????_????_????: instruction_type = DIV;  // TODO

      // Mod
      16'b1010_????_????_????: instruction_type = MOD;  // TODO

      // JUMPN_CALLN
      16'b1011_0000_????_????: instruction_type = JUMPN;
      16'b1011_????_????_????: instruction_type = CALLN;


      // Conditional jumps

      16'b1100_????_????_????: instruction_type = JEQZN;  // TODO

      16'b1101_????_????_????: instruction_type = JNEZN;  // TODO

      16'b1110_????_????_????: instruction_type = JGTZN;  // TODO

      16'b1111_????_????_????: instruction_type = JLTZN;  // TODO
      default: begin
        $display("unknown instruction, defaulting to NOP");
        instruction_type = NOP;
      end
    endcase

  // reg_src_x:
  //	 00: from immediate
  //	 01: from data memory (data read)
  //	 10: from pc + 2 (next instruction w/o jump)
  //	 11: from ALU result
  //
  //
  // mem_adr_src:
  //   00: from immediate
  //   01: from register file (data read 2, rY) 
  //   10: from alu_result
  //
  // pc_src:
  //    00: from pc + 2
  //    10: from pc_target (immediate)
  //    11: from pc_target (rX)
  //
  //  mem_data_src: 
  //    0: from ALU result
  //    1: from register file (data read 1, rX) 
  //
  //  alu_src_a:
  //    0: from register file (data read 2, rY)
  //    1: from register file (data read 1, rX)
  //
  //  AluSrcB: 
  //    00: from register file (data read 3, rZ)
  //    01: from immediate
  //    10: from 0
  //    11: from 1


  always_comb begin
    // defaults
    mem_adr_src = 2'b0;  // memory sources from immediate
    mem_data_src = 0;  // memory gets write data from ALU result
    mem_write = 0;  // disable write to memory
    pc_src = 2'b00;  // pc gets pc + 2
    reg_src_x = 2'b00;  // register file gets write data from immediate
    reg_write_x = 0;  // disable write to register file
    alu_op = ALU_ADD;  // default ALU operation is ADD
    alu_src_a = 0;  // default ALU source A is the contents of register rX
    alu_src_b = 2'b00;  // default ALU source B is the contents of register rY

    $display("\n");
    case (instruction_type)
      LOADR: begin
        $display("LOADR");
        // Load register rX with data from the address location held in reg. rY
        mem_adr_src = 2'b1;  // get the memory from address valued rY
        reg_src_x   = 2'b01;  // direct data from memory to rX
        reg_write_x = 1;  // enable write to rx
      end
      READ: begin
        $display("READ");
        // emulator, read from stdin, processor, read from 16 bit input (presumed to be hooked up to serial transfer peripheral)
        // Ideally, should stall the processor until the input is ready.
        // TODO 
        $display("WARNING: READ unimplemented.");
      end
      WRITE: begin
        $display("WRITE");
        // Print contents of register rX
        // rX is already hard-wired into the first address port of the register file
        // so we will simply print from the corresponding read_data_1 output
      end
      SETN: begin
        $display("SETN");
        // Set register rX equal to the integer N (-128 to +127)
        reg_src_x   = 2'b00;  // direct the immediate to rX
        reg_write_x = 1;  // enable write to rx
      end
      LOADN: begin
        $display("LOADN");
        // Load register rX with the contents of memory address N
        mem_adr_src = 2'b0;  // get the memory at the address corresponding to the immediate
        reg_src_x   = 2'b01;  // direct data from memory to rX
        reg_write_x = 1;  // enable write to rx
      end
      JUMPN: begin
        // Set program counter to address N
        $display("JUMPN");
        pc_src = 2'b10;  // get the next program counter from the immediate
      end
      JUMPR: begin
        $display("JUMPR");
        //Set program counter to address in rX
        pc_src = 2'b11;  // get the next program counter from the contents of rX
      end
      JEQZN: begin
        $display("JEQZN");
        // If the contents of register rX is zero, set program counter to address N
        // We will add rx + 0 so we can use the comparison logic in the ALU on rX
        alu_op = ALU_ADD;  // ALU operation is ADD

        // get inputs a and b to the ALU from the contents of rX and 1 respectively
        alu_src_a = 1;
        alu_src_b = 2'b10;


        pc_src = 2'b10;  // next program counter is sourced from the immediate // CHECK

      end
      JNEZN: begin
        $display("JNEZN");
        // If the contents of register rX is not zero, set program counter to address N
        pc_src = 2'b10;  // next program counter is sourced from the immediate // CHECK
        // We will mul rx * 1 so we can use the comparison logic in the ALU on rX
        alu_op = ALU_ADD;  // ALU operation is ADD
        alu_src_a = 1;  // default ALU source A is the contents of register rX
        alu_src_b = 2'b10;  // default ALU source B is 0 (to enable comparison with 0)
      end
      JGTZN: begin
        $display("JGTZN");
        // If the contents of register rX is greater than zero, set program counter to address N
        pc_src = 2'b10;  // next program counter is sourced from the immediate // CHECK
        // We will mul rx * 1 so we can use the comparison logic in the ALU on rX
        alu_op = ALU_ADD;  // ALU operation is ADD
        alu_src_a = 1;  // default ALU source A is the contents of register rX
        alu_src_b = 2'b10;  // default ALU source B is 0 (to enable comparison with 0)
      end
      JLTZN: begin
        $display("JLTZN");
        // If the contents of register rX is less than zero, set program counter to address N
        pc_src = 2'b10;  // next program counter is sourced from the immediate // CHECK
        // We will mul rx * 1 so we can use the comparison logic in the ALU on rX
        alu_op = ALU_ADD;  // ALU operation is ADD
        alu_src_a = 1;  // default ALU source A is the contents of register rX
        alu_src_b = 2'b10;  // default ALU source B is 0 (to enable comparison with 0)
      end
      CALLN: begin
        $display("CALLN");
        // Copy addr. of next instr. into rX and then jump to mem. addr. N
        pc_src = 2'b10;  // next program counter is sourced from the immediate
        reg_src_x = 2'b10; // register file gets write data from what would have been the next program counter
        reg_write_x = 1;  // enable write to rX
      end
      STOREN: begin
        $display("STOREN");
        // Store contents of register rX into memory address N
        mem_data_src = 1;  // memory gets write data from the contents of register rX
        mem_write = 1;  // enable write to memory
      end
      STORER: begin
        $display("STORER");
        // Store contents of register rX into memory address held in reg. rY
        mem_adr_src = 2'b1;  // memory gets write data from the contents of register rY
        mem_data_src = 1;  // memory gets write data from the contents of register rX
        mem_write = 1;  // enable write to memory
      end
      POPR: begin
        $display("POPR");
        // Load contents of register rX from stack pointed to by register rY: rY -= 1; rX = memory[rY]
        alu_src_a = 0;  // rY
        alu_src_b = 2'b11;  // 1
        alu_op = ALU_SUB;  // sub
        mem_adr_src = 2'b10;  // get the value from the memory address corresponding to the alu_result
        reg_write_x = 1;  // enable write to rX
        reg_src_x = 2'b01;  // rx gets write data from memory
        reg_write_y = 1;  // enable write to rY (default from alu_result)
      end
      PUSHR: begin
        $display("PUSHR");
        // Store contents of register rX onto stack pointed to by register rY: memory[rY] = rX; rY += 1
        alu_src_a = 0;  // rY
        alu_src_b = 2'b11;  // 1
        alu_op = ALU_ADD;  // add
        mem_write = 1;  // enable write to memory
        mem_data_src = 1;  // memory gets write data from the contents of register rX
        mem_adr_src = 2'b01;  // read from memory address that is the value of rY
        reg_write_y = 1;  // enable write to rY (default from alu_result)
      end
      ADD, COPY, NOP: begin
        case (instruction_type)
          ADD: $display("ADD");
          COPY:
          $display(
              "COPY"
          );  // COPY is the case of ADD where sources b from r0, which is hard-wired to 0
          NOP:
          $display(
              "NOP"
          );  // NOP is the case of ADD where a, b, and result are all from/to r0, which is hard-wired to 0
        endcase
        alu_op = ALU_ADD;
        alu_src_a = 0;  // default ALU source A is the contents of register rY
        alu_src_b = 2'b00;  // default ALU source B is the contents of register rZ
        reg_src_x = 2'b11;  // register file gets write data from the ALU result
        reg_write_x = 1;  // enable write to rx
      end
      ADDN: begin  // Copy is a duplicate of ADD which always gets 
        $display("ADDN");
        alu_op = ALU_ADD;
        alu_src_a = 1;  // default ALU source A is the contents of register rX
        alu_src_b = 2'b01;  // ALU source B is the immediate
        reg_src_x = 2'b11;  // register file gets write data from the ALU result
        reg_write_x = 1;  // enable write to rx
      end
      SUB, NEG: begin
        case (instruction_type)
          SUB: $display("SUB");
          NEG:
          $display(
              "NEG"
          );  // NEG is the case of SUB where source a is taken from r0, which is hard-wired to 0
        endcase
        alu_op = ALU_SUB;
        alu_src_a = 0;  // default ALU source A is the contents of register rY
        alu_src_b = 2'b00;  // default ALU source B is the contents of register rZ
        reg_src_x = 2'b11;  // register file gets write data from the ALU result
        reg_write_x = 1;  // enable write to rx
      end
      MUL: begin
        $display("MUL");
        alu_op = ALU_MUL;
        alu_src_a = 0;  // default ALU source A is the contents of register rY
        alu_src_b = 2'b00;  // default ALU source B is the contents of register rZ
        reg_src_x = 2'b11;  // register file gets write data from the ALU result
        reg_write_x = 1;  // enable write to rx
      end
      DIV: begin
        $display("DIV");
        alu_op = ALU_DIV;
        alu_src_a = 0;  // default ALU source A is the contents of register rY
        alu_src_b = 2'b00;  // default ALU source B is the contents of register rZ
        reg_src_x = 2'b11;  // register file gets write data from the ALU result
        reg_write_x = 1;  // enable write to rx
      end
      MOD: begin
        $display("MOD");
        alu_op = ALU_MOD;
        alu_src_a = 0;  // default ALU source A is the contents of register rY
        alu_src_b = 2'b00;  // default ALU source B is the contents of register rZ
        reg_src_x = 2'b11;  // register file gets write data from the ALU result
        reg_write_x = 1;  // enable write to rx
      end
    endcase
  end



endmodule

module Datapath (
    input logic clk,
    reset,
    input logic mem_write,
    reg_write_x,
    reg_write_y,
    mem_data_src,
    alu_src_a,
    input logic [1:0] pc_src,
    alu_src_b,
    reg_src_x,
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
      .write_en(mem_write),
      .instruction_address(pc),
      .data_address(mem_data_address),
      .write_data(mem_write_data),
      .instruction_data(instruction),
      .read_data(mem_read_data)
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
    case (reg_src_x)
      2'b00: rf_write_data_1 = imm_ext;
      2'b01: rf_write_data_1 = mem_read_data;
      2'b10: rf_write_data_1 = {8'b0, pc_plus_2};
      2'b11: rf_write_data_1 = alu_result;
    endcase

  assign rf_write_data_2 = alu_result;

  // ============== REGISTER FILE logic ============== 
  RegisterFile rf (
      .clk(clk),
      .address_1(rX),
      .address_2(rY),
      .address_3(rZ),
      .write_en_1(reg_write_x),
      .write_en_2(reg_write_y),
      .write_data_1(rf_write_data_1),
      .write_data_2(rf_write_data_2),
      .read_data_1(rf_read_data_1),
      .read_data_2(rf_read_data_2),
      .read_data_3(rf_read_data_3)
  );

  // ============= ALU logic ============== 

  ALU alu (
      .alu_op(alu_op),
      .zero(zero),
      .sign(sign),
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

module ALU (
    input alu_op_t alu_op,
    input logic [15:0] src_a,
    src_b,
    output logic [15:0] alu_result,
    output logic zero,
    sign
);

  always_comb
    case (alu_op)
      ALU_ADD: alu_result = src_a + src_b;
      ALU_SUB: alu_result = src_a - src_b;
      ALU_MUL: alu_result = src_a * src_b;
      ALU_DIV: alu_result = src_a / src_b;  // todo check div by 0
      ALU_MOD: alu_result = src_a % src_b;
    endcase

  assign zero = (alu_result == 0);
  assign sign = alu_result[15];

endmodule

