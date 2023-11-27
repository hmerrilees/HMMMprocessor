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
  logic [1:0] rf_src_x, pc_src, mem_adr_src, alu_src_b;
  logic mem_write, rf_write_x, rf_write_y, mem_data_src, alu_src_a;

  alu_op_t alu_op;
  instr_t  instruction_type;

  Controller controller (
      .instruction(instruction),
      .alu_op(alu_op),
      .alu_src_a(alu_src_a),
      .alu_src_b(alu_src_b),
      .mem_write(mem_write),
      .rf_write_x(rf_write_x),
      .rf_src_x(rf_src_x),
      .rf_write_y(rf_write_y),
      .mem_adr_src(mem_adr_src),
      .mem_data_src(mem_data_src),
      .pc_src(pc_src),
      .instruction_type(instruction_type)
  );

  Datapath datapath (
      .clk(clk),
      .reset(reset),
      .mem_write(mem_write),
      .rf_write_x(rf_write_x),
      .rf_src_x(rf_src_x),
      .rf_write_y(rf_write_y),
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
    mem_write_en,
    input logic [7:0] pc,
    mem_data_address,
    input logic [15:0] mem_write_data,
    output logic [15:0] instruction,
    mem_read_data
);
  initial $readmemb("program.txt", RAM);

  logic [15:0] RAM[255:0];

  always_ff @(posedge clk) if (mem_write_en) RAM[mem_data_address] <= mem_write_data;

  assign instruction   = RAM[{1'b0, pc[7:1]}];  // needs to be word-aligned to 2 bytes TODO check
  assign mem_read_data = RAM[mem_data_address];
endmodule

module RegisterFile (
    input logic clk,
    input logic [3:0] rf_read_adr_1,
    rf_read_adr_2,
    rf_read_adr_3,
    input logic rf_write_en_1,
    rf_write_en_2,
    input logic [15:0] rf_write_data_1,
    rf_write_data_2,
    output logic [15:0] rf_read_data_1,
    rf_read_data_2,
    rf_read_data_3
);

  // TODO pretty sure we are allocating flops for r0 needlessly
  logic [15:0] registers[15:0];

  assign rf_read_data_1 = (rf_read_adr_1 != 0) ? registers[rf_read_adr_1] : 16'd0;
  assign rf_read_data_2 = (rf_read_adr_2 != 0) ? registers[rf_read_adr_2] : 16'd0;
  assign rf_read_data_3 = (rf_read_adr_3 != 0) ? registers[rf_read_adr_3] : 16'd0;

  always_ff @(posedge clk) begin
    if (rf_write_en_1 & rf_write_en_2 & (rf_read_adr_1 == rf_read_adr_2))
      $display(
          "WARNING: write to same register in same cycle. Second write channel takes priority."
      );
    if (rf_write_en_1) registers[rf_read_adr_1] = rf_write_data_1;
    if (rf_write_en_2) registers[rf_read_adr_2] = rf_write_data_2;
  end
endmodule

module Controller (
    input logic [15:0] instruction,
    output alu_op_t alu_op,
    output logic mem_write,
    rf_write_x,
    rf_write_y,
    mem_data_src,
    alu_src_a,
    output logic [1:0] rf_src_x,
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

      16'b0100_????_????_0010: instruction_type = POPR;
      16'b0100_????_????_0011: instruction_type = PUSHR;

      // ADDN
      16'b0101_????_????_????: instruction_type = ADDN;

      // ADD
      16'b0110_????_????_????: instruction_type = ADD;
      // 16'b0110_0000_0000_0000: instruction_type = NOP; // add duplicate, covered as the default case
      16'b0110_????_????_0000: instruction_type = COPY;

      // SUB
      16'b0111_????_????_????: instruction_type = SUB;
      16'b0111_????_0000_????: instruction_type = NEG;  // sub duplicate

      // Mul
      16'b1000_????_????_????: instruction_type = MUL;

      // Div
      16'b1001_????_????_????: instruction_type = DIV;

      // Mod
      16'b1010_????_????_????: instruction_type = MOD;

      // JUMPN_CALLN
      16'b1011_0000_????_????: instruction_type = JUMPN;
      16'b1011_????_????_????: instruction_type = CALLN;


      // Conditional jumps

      16'b1100_????_????_????: instruction_type = JEQZN;

      16'b1101_????_????_????: instruction_type = JNEZN;

      16'b1110_????_????_????: instruction_type = JGTZN;

      16'b1111_????_????_????: instruction_type = JLTZN;
      default: begin
        $display("unknown instruction, defaulting to NOP");
        instruction_type = NOP;
      end
    endcase

  // rf_src_x:
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
  //  alu_src_b: 
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
    rf_src_x = 2'b00;  // register file gets write data from immediate
    rf_write_x = 0;  // disable write to register file
    alu_op = ALU_ADD;  // default ALU operation is ADD
    alu_src_a = 0;  // default ALU source A is the contents of register rX
    alu_src_b = 2'b00;  // default ALU source B is the contents of register rY

    $display("\n");
    case (instruction_type)
      LOADR: begin
        $display("LOADR");
        // Load register rX with data from the address location held in reg. rY
        mem_adr_src = 2'b1;  // get the memory from address valued rY
        rf_src_x = 2'b01;  // direct data from memory to rX
        rf_write_x = 1;  // enable write to rx
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
        rf_src_x   = 2'b00;  // direct the immediate to rX
        rf_write_x = 1;  // enable write to rx
      end
      LOADN: begin
        $display("LOADN");
        // Load register rX with the contents of memory address N
        mem_adr_src = 2'b0;  // get the memory at the address corresponding to the immediate
        rf_src_x = 2'b01;  // direct data from memory to rX
        rf_write_x = 1;  // enable write to rx
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
        pc_src = 2'b10;  // next program counter is sourced from the immediate (provided rX satisfies the condition)

      end
      JNEZN: begin
        $display("JNEZN");
        pc_src = 2'b10;  // next program counter is sourced from the immediate (provided rX satisfies the condition)
      end
      JGTZN: begin
        $display("JGTZN");
        pc_src = 2'b10;  // next program counter is sourced from the immediate (provided rX satisfies the condition)
      end
      JLTZN: begin
        $display("JLTZN");
        pc_src = 2'b10;  // next program counter is sourced from the immediate (provided rX satisfies the condition)
      end
      CALLN: begin
        $display("CALLN");
        // Copy addr. of next instr. into rX and then jump to mem. addr. N
        pc_src = 2'b10;  // next program counter is sourced from the immediate
        rf_src_x = 2'b10; // save the instruction address immediately following the CALLN instruction into rX
        rf_write_x = 1;  // enable write to rX
      end
      STOREN: begin
        $display("STOREN");
        // Store contents of register rX into memory address N
        mem_adr_src = 2'b00;  // direct the immediate to the memory address
        mem_data_src = 1;  // direct rX to the memory data input
        mem_write = 1;  // enable write to memory
      end
      STORER: begin
        $display("STORER");
        // Store contents of register rX into memory address held in reg. rY
        mem_data_src = 1;  // get data from rX
        mem_adr_src = 2'b01;  // direct to address at rY
        mem_write = 1;  // enable write to memory
      end
      POPR: begin
        $display("POPR");
        // Load contents of register rX from stack pointed to by register rY: rY -= 1; rX = memory[rY]

        // alu_result = rY - 1
        alu_src_a = 0;  // rY
        alu_src_b = 2'b11;  // 1
        alu_op = ALU_SUB;  // sub

        // rY = alu_result
        rf_write_y = 1;  // enable write to rY (default source from alu_result)

        // rX = memory[rY]
        mem_adr_src = 2'b10;  // get the data at the address corresponding to old rY + 1 (alu_result)
        rf_src_x = 2'b01;  // direct the memory data to rX
        rf_write_x = 1;  // enable write to rX

      end
      PUSHR: begin
        $display("PUSHR");
        // Store contents of register rX onto stack pointed to by register rY: memory[rY] = rX; rY += 1
        // 
        mem_data_src = 1;  // direct the contents of rX to the memory
        mem_adr_src = 2'b01;  // write to memory address rY
        mem_write = 1;  // enable write to memory

        // alu_result = rY + 1
        alu_src_a = 0;  // rY
        alu_src_b = 2'b11;  // 1
        alu_op = ALU_ADD;  // add

        // rY = alu_result
        rf_write_y = 1;  // enable write to rY (default source from alu_result)
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
        // alu_result = rY + rZ
        alu_src_a = 0;  // rY
        alu_src_b = 2'b00;  // rZ
        alu_op = ALU_ADD;

        // rX = alu_result
        rf_src_x = 2'b11;  // register file gets write data from the ALU result
        rf_write_x = 1;  // enable write to rx
      end
      ADDN: begin  // Copy is a duplicate of ADD which always gets 
        $display("ADDN");  // todo check
        // alu_result = rX + N
        alu_src_a = 1;  // rX
        alu_src_b = 2'b01;  // immediate
        alu_op = ALU_ADD;

        // rX = alu_result
        rf_src_x = 2'b11;  // register file gets write data from the ALU result
        rf_write_x = 1;  // enable write to rx
      end
      SUB, NEG: begin
        case (instruction_type)
          SUB: $display("SUB");
          NEG:
          $display(
              "NEG"
          );  // NEG is the case of SUB where source a is taken from r0, which is hard-wired to 0
        endcase
        // alu_result = rY - rZ
        alu_src_a = 0;  // rY
        alu_src_b = 2'b00;  // rZ
        alu_op = ALU_SUB;

        // rX = alu_result
        rf_src_x = 2'b11;  // register file gets write data from the ALU result
        rf_write_x = 1;  // enable write to rx
      end
      MUL: begin
        $display("MUL");
        // alu_result = rY * rZ
        alu_src_a = 0;  // rY
        alu_src_b = 2'b00;  // rZ
        alu_op = ALU_MUL;

        // rX = alu_result
        rf_src_x = 2'b11;  // register file gets write data from the ALU result
        rf_write_x = 1;  // enable write to rx
      end
      DIV: begin
        $display("DIV");
        // alu_result = rY / rZ
        alu_src_a = 0;  // rY
        alu_src_b = 2'b00;  // rZ
        alu_op = ALU_DIV;

        // rX = alu_result
        rf_src_x = 2'b11;  // register file gets write data from the ALU result
        rf_write_x = 1;  // enable write to rx
      end
      MOD: begin
        $display("MOD");
        // alu_result = rY % rZ
        alu_src_a = 0;  // rY
        alu_src_b = 2'b00;  // rZ
        alu_op = ALU_MOD;

        // rX = alu_result
        rf_src_x = 2'b11;  // register file gets write data from the ALU result
        rf_write_x = 1;  // enable write to rx
      end
    endcase
  end



endmodule

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
      .alu_input_a(alu_input_a),
      .alu_input_b(alu_input_b),
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
    input logic [15:0] alu_input_a,
    alu_input_b,
    output logic [15:0] alu_result
);

  always_comb
    case (alu_op)
      ALU_ADD: alu_result = alu_input_a + alu_input_b;
      ALU_SUB: alu_result = alu_input_a - alu_input_b;
      ALU_MUL: alu_result = alu_input_a * alu_input_b;
      ALU_DIV: alu_result = alu_input_a / alu_input_b;  // todo check div by 0
      ALU_MOD: alu_result = alu_input_a % alu_input_b;
    endcase


endmodule

