/* verilator lint_off CASEOVERLAP */
/* verilator lint_off DECLFILENAME */
/* verilator lint_off UNUSEDSIGNAL */

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
  logic [15:0] Instr;
  logic [1:0] RegSrc, PcSrc;
  logic MemWrite, RegWrite, MemAdrSrc, MemDataSrc, ALUSrcA, ALUSrcB;

  alu_op_t alu_op;
  instr_t  instruction_type;


  Controller controller (
      .instr(Instr),
      .alu_op(alu_op),
      .ALUSrcA(ALUSrcA),
      .ALUSrcB(ALUSrcB),
      .MemWrite(MemWrite),
      .RegWrite(RegWrite),
      .MemAdrSrc(MemAdrSrc),
      .MemDataSrc(MemDataSrc),
      .RegSrc(RegSrc),
      .PcSrc(PcSrc),
      .instruction_type(instruction_type)
  );

  Datapath datapath (
      .clk(clk),
      .reset(reset),
      .MemWrite(MemWrite),
      .RegWrite(RegWrite),
      .RegSrc(RegSrc),
      .MemAdrSrc(MemAdrSrc),
      .MemDataSrc(MemDataSrc),
      .PcSrc(PcSrc),
      .alu_op(alu_op),
      .ALUSrcA(ALUSrcA),
      .ALUSrcB(ALUSrcB),
      .instruction_type(instruction_type),
      .Instr(Instr)
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
    input logic [15:0] write_data_1,
    output logic [15:0] read_data_1,
    read_data_2,
    read_data_3
);

  logic [15:0] registers[15:0];

  assign read_data_1 = (address_1 != 0) ? registers[address_1] : 16'd0; // be careful on this one, written value doesn't update until next cycle
  assign read_data_2 = (address_2 != 0) ? registers[address_2] : 16'd0;
  assign read_data_3 = (address_3 != 0) ? registers[address_3] : 16'd0;

  always_ff @(posedge clk) if (write_en_1) registers[address_1] <= write_data_1;

endmodule

module Controller (
    input logic [15:0] instr,
    output alu_op_t alu_op,
    output logic MemWrite,
    RegWrite,
    MemAdrSrc,
    MemDataSrc,
    ALUSrcA,
    ALUSrcB,
    output logic [1:0] RegSrc,
    PcSrc,
    output instr_t instruction_type
);


  always_comb
    casez (instr)

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

  // RegSrc:
  //	 00: from immediate
  //	 01: from data memory (data read)
  //	 10: from Pc + 2 (next instruction w/o jump)
  //	 11: from ALU result
  //
  // MemAdrSrc:
  //    0: from immediate
  //    1: from register file (data read 2, rY) 
  // PcSrc:
  //    00: from PC + 2
  //    10: from PCTarget (immediate)
  //    11: from PCTarget (rX)
  //
  //  MemDataSrc: // TODO this should be flipped... too late
  //    0: from ALU result
  //    1: from register file (data read 1, rX) 
  //
  //  AluSrcA:
  //    0: from register file (data read 2, rY)
  //    1: from register file (data read 1, rX)
  //


  always_comb begin
    // defaults
    MemAdrSrc = 0;  // memory sources from immediate
    MemDataSrc = 0;  // memory gets write data from ALU result
    MemWrite = 0;  // disable write to memory
    PcSrc = 2'b00;  // PC gets PC + 2
    RegSrc = 2'b00;  // register file gets write data from immediate
    RegWrite = 0;  // disable write to register file
    alu_op = ALU_ADD;  // default ALU operation is ADD
    ALUSrcA = 0;  // default ALU source A is the contents of register rX
    ALUSrcB = 0;  // default ALU source B is the contents of register rY

    $display("\n");
    case (instruction_type)
      LOADR: begin
        $display("LOADR");
        // Load register rX with data from the address location held in reg. rY
        MemAdrSrc = 1;  // write to the memory address that is the contents of register rY
        RegSrc = 2'b01;  // pass the data read from memory to the register file
        RegWrite = 1;  // enable write to rx
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
        RegSrc   = 2'b00;  // register file gets write data from immediate
        RegWrite = 1;  // enable write to rx
      end
      LOADN: begin
        $display("LOADN");
        // Load register rX with the contents of memory address N
        MemAdrSrc = 0;  // source memory address from the immediate
        RegSrc    = 2'b01;  // register file gets write data from memory
        RegWrite  = 1;  // enable write to rx
      end
      JUMPN: begin
        // Set program counter to address N
        $display("JUMPN");
        PcSrc = 2'b10;  // next program counter is sourced from the immediate
      end
      JUMPR: begin
        $display("JUMPR");
        //Set program counter to address in rX
        PcSrc = 2'b11;  // next program counter is sourced from the contents of register rX
      end
      CALLN: begin
        $display("CALLN");
        // Copy addr. of next instr. into rX and then jump to mem. addr. N
        PcSrc = 2'b10;  // next program counter is sourced from the immediate
        RegSrc = 2'b10; // register file gets write data from what would have been the next program counter
        RegWrite = 1;  // enable write to rX
      end
      STOREN: begin
        $display("STOREN");
        // Store contents of register rX into memory address N
        MemDataSrc = 1;  // memory gets write data from the contents of register rX
        MemWrite   = 1;  // enable write to memory
      end
      STORER: begin
        $display("STORER");
        // Store contents of register rX into memory address held in reg. rY
        MemAdrSrc  = 1;  // memory gets write data from the contents of register rY
        MemDataSrc = 1;  // memory gets write data from the contents of register rX
        MemWrite   = 1;  // enable write to memory
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
        alu_op  = ALU_ADD;
        ALUSrcA = 0;  // default ALU source A is the contents of register rY
        ALUSrcB = 0;  // default ALU source B is the contents of register rZ
        RegSrc  = 2'b11;  // register file gets write data from the ALU result
        RegWrite = 1;  // enable write to rx
      end
      ADDN: begin  // Copy is a duplicate of ADD which always gets 
        $display("ADDN");
        alu_op  = ALU_ADD;
        ALUSrcA = 1;  // default ALU source A is the contents of register rX
        ALUSrcB = 1;  // ALU source B is the immediate
        RegSrc  = 2'b11;  // register file gets write data from the ALU result
        RegWrite = 1;  // enable write to rx
      end
      SUB, NEG: begin
        case (instruction_type)
          SUB: $display("SUB");
          NEG:
          $display(
              "NEG"
          );  // NEG is the case of SUB where source a is taken from r0, which is hard-wired to 0
        endcase
        alu_op  = ALU_SUB;
        ALUSrcA = 0;  // default ALU source A is the contents of register rY
        ALUSrcB = 0;  // default ALU source B is the contents of register rZ
        RegSrc  = 2'b11;  // register file gets write data from the ALU result
        RegWrite = 1;  // enable write to rx
      end
      MUL: begin
        $display("MUL");
        alu_op  = ALU_MUL;
        ALUSrcA = 0;  // default ALU source A is the contents of register rY
        ALUSrcB = 0;  // default ALU source B is the contents of register rZ
        RegSrc  = 2'b11;  // register file gets write data from the ALU result
        RegWrite = 1;  // enable write to rx
      end
      DIV: begin
        $display("DIV");
        alu_op  = ALU_DIV;
        ALUSrcA = 0;  // default ALU source A is the contents of register rY
        ALUSrcB = 0;  // default ALU source B is the contents of register rZ
        RegSrc  = 2'b11;  // register file gets write data from the ALU result
        RegWrite = 1;  // enable write to rx
      end
      MOD: begin
        $display("MOD");
        alu_op  = ALU_MOD;
        ALUSrcA = 0;  // default ALU source A is the contents of register rY
        ALUSrcB = 0;  // default ALU source B is the contents of register rZ
        RegSrc  = 2'b11;  // register file gets write data from the ALU result
        RegWrite = 1;  // enable write to rx
      end
    endcase
  end



endmodule

module Datapath (
    input logic clk,
    reset,
    input logic MemWrite,
    RegWrite,
    MemAdrSrc,
    MemDataSrc,
    ALUSrcA,
    ALUSrcB,
    input logic [1:0] PcSrc,
    RegSrc,
    input instr_t instruction_type,
    input alu_op_t alu_op,
    output logic [15:0] Instr
);


  logic [7:0] Pc, PcPlus2, PcNext, PcTarget, Imm, mem_data_address;

  logic [15:0]
      result,
      alu_result,
      alu_src_a,
      alu_src_b,
      rf_read_data_1,
      rf_read_data_2,
      rf_read_data_3,
      mem_read_data,
      mem_write_data;

  logic [3:0] rX, rY, rZ;


  //assign opcode = Instr[15:12];
  assign rX = Instr[11:8];
  assign rY = Instr[7:4];
  assign rZ = Instr[3:0];

  assign Imm = Instr[7:0];


  // PC logic
  assign PcTarget = PcSrc[0] ? rf_read_data_1[7:0] * 2 : Imm * 2;  // todo check

  assign PcPlus2 = Pc + 2;


  always_comb
    if (reset) PcNext = 0;
    else if (PcSrc[1]) PcNext = PcTarget;
    else PcNext = PcPlus2;  // word alignment is 2 bytes

  always_ff @(posedge clk) Pc <= PcNext;

  always_ff @(posedge clk) begin
    $display("PC: %h", Pc);
    $display("instruction: %h", Instr);

    // cheat to handle write
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

      $finish;
    end
  end




  // Memory logic
  Memory mem (
      .clk(clk),
      .write_en(MemWrite),
      .instruction_address(Pc),
      .data_address(mem_data_address),
      .write_data(mem_write_data),
      .instruction_data(Instr),
      .read_data(mem_read_data)
  );

  assign mem_data_address = MemAdrSrc ? rf_read_data_2[7:0] : Imm;
  assign mem_write_data   = MemDataSrc ? rf_read_data_1 : alu_result;  // TODO check

  always_comb
    case (RegSrc)
      2'b00: result = {8'b0, Imm};
      2'b01: result = mem_read_data;
      2'b10: result = {8'b0, PcPlus2};
      2'b11: result = alu_result;
    endcase


  // REGISTER FILE logic
  RegisterFile rf (
      .clk(clk),
      .address_1(rX),
      .address_2(rY),
      .address_3(rZ),
      .write_en_1(RegWrite),
      .write_data_1(result),
      .read_data_1(rf_read_data_1),
      .read_data_2(rf_read_data_2),
      .read_data_3(rf_read_data_3)
  );

  assign alu_src_a = ALUSrcA ? rf_read_data_2 : rf_read_data_1;
  assign alu_src_b = ALUSrcB ? {8'b0, Imm} : rf_read_data_3;


  // ALU logic
  logic zero, sign;

  ALU alu (
      .alu_op(alu_op),
      .zero(zero),
      .sign(sign),
      .src_a(alu_src_a),
      .src_b(alu_src_b),
      .alu_result(alu_result)
  );


endmodule

module ALU (
    input alu_op_t alu_op,
    input logic [15:0] src_a, src_b,
    output logic [15:0] alu_result,
    output logic zero, sign
);



  always_comb
    case (alu_op)
      ALU_ADD: alu_result = src_a + src_b;
      ALU_SUB: alu_result = src_a + ~src_b + 1;
      ALU_MUL: alu_result = src_a * src_b;
      ALU_DIV: alu_result = src_a / src_b; // check div by 0
      ALU_MOD: alu_result = src_a % src_b;
      //default: alu_result = 16'dx;
    endcase

  assign zero = (alu_result == 0);
  assign sign = alu_result[15];

endmodule
