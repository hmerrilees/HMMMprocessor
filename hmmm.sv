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
  SUB,
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
  ALU_MUL,
  ALU_DIV,
  ALU_MOD
} aluop_t;


module hmmm (
    input logic clk,
    reset
);
  logic [15:0] Instr;
  logic [1:0] RegSrc, PcSrc;
  logic MemWrite, RegWrite, MemAdrSrc, MemDataSrc;

  aluop_t aluop;
  instr_t instruction_type;


  Controller controller (
      .instr(Instr),
      .aluop(aluop),
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
    output logic [15:0] read_data_1, read_data_2,
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
    output aluop_t aluop,
    output logic MemWrite,
    RegWrite, MemAdrSrc, MemDataSrc,
    output logic [1:0] RegSrc, PcSrc,
    output instr_t instruction_type
);


  always_comb
    casez (instr)

      // CONTROL_FLOW
      16'b0000_0000_0000_0000: instruction_type = HALT;
      // TODO not really any good way to do read
      16'b0000_????_0000_0001: instruction_type = READ;
      16'b0000_????_0000_0010: instruction_type = WRITE;  // This was hacked, TODO make better
      16'b0000_????_0000_0011: instruction_type = JUMPR;  

      // SETN
      16'b0001_????_????_????: instruction_type = SETN; 

      // LOADN
      16'b0010_????_????_????: instruction_type = LOADN;

      // STOREN
      16'b0011_????_????_????: instruction_type = STOREN;  // TODO check


      // MEMORY_R
      16'b0100_????_????_0000: instruction_type = LOADR;  
      16'b0100_????_????_0001: instruction_type = STORER;  // TODO check
      16'b0100_????_????_0010: instruction_type = POPR;  // TODO
      16'b0100_????_????_0011: instruction_type = PUSHR;  // TODO

      // ADDN
      16'b0101_????_????_????: instruction_type = ADDN;  // TODO

      // ADD
      16'b0110_????_????_????: instruction_type = ADD;  // TODO
      // 16'b0110_0000_0000_0000: instruction_type = NOP; // add duplicate
      // 16'b0110_????_????_0000: instruction_type = COPY; // add duplicate

      // SUB
      16'b0111_????_????_????:
      instruction_type = SUB;  // just an add with inverted second source // TODO
      // 16'b0111_????_0000_????: instruction_type = NEG; // sub duplicate

      // Mul
      16'b1000_????_????_????: instruction_type = MUL;  // TODO

      // Div
      16'b1001_????_????_????: instruction_type = DIV;  // TODO

      // Mod
      16'b1010_????_????_????: instruction_type = MOD;  // TODO

      // JUMPN_CALLN
      16'b1011_0000_????_????: instruction_type = JUMPN;  // instr[11:8] 
      16'b1011_????_0000_0000: instruction_type = CALLN;  


      // Conditional jumps

      16'b1100_????_????_????: instruction_type = JEQZN;  // TODO

      16'b1101_????_????_????: instruction_type = JNEZN;  // TODO

      16'b1110_????_????_????: instruction_type = JGTZN;  // TODO

      16'b1111_????_????_????: instruction_type = JLTZN;  // TODO
      default: instruction_type = NOP;
    endcase


    // RegSrc:
    //	 00: from immediate
    //	 01: from data memory (data read)
    //	 10: from Pc + 2 (next instruction) // TODO check
    //
    // MemAdrSrc:
    //    0: from immediate
    //    1: from register file (data read 2) // TODO check
    // PcSrc:
    //    00: from PC + 2
    //    10: from PCTarget (immediate)
    //    11: from PCTarget (rX)
    //
    //  MemDataSrc:
    //    0: from ALU result
    //    1: from register file (data read 1) // TODO check
    //


  always_comb begin
    $display("\n");
    MemAdrSrc = 0; // imm
    MemDataSrc = 0;
    MemWrite = 0;
    PcSrc = 0;  // PC gets PC + 2
    RegSrc = 0;
    RegWrite = 0;
    aluop = ALU_ADD;
    case (instruction_type)
      LOADR: begin
	$display("LOADR");
	MemAdrSrc = 1;
	RegSrc = 1;
        RegWrite = 1;
      end
      WRITE: begin
	$display("WRITE");
	MemAdrSrc = 1;
      end
      SETN: begin
	$display("SETN");
	MemAdrSrc = 1;
	RegWrite = 1;
      end
      LOADN: begin
	$display("LOADN");
	MemAdrSrc = 0;
	RegSrc = 1;
	RegWrite = 1;
      end
      JUMPN: begin
	$display("JUMPN");
	PcSrc = 2'b10;
      end
      JUMPR: begin
      	$display("JUMPR");
	// PcNext from rX
	PcSrc = 2'b11;
      end
      CALLN: begin
	$display("CALLN");
	// Rx gets Pc+2
	// PcNext from current rX
	PcSrc = 2'b11;
	RegSrc = 2'b10;
      end
      STOREN: begin
      	$display("STOREN");
	MemDataSrc = 1;
	MemWrite = 1;
      end
      STORER: begin
	$display("$STORER");
	MemAdrSrc = 1;
	MemDataSrc = 1;
	MemWrite = 1;
      	
      end

      ADD: aluop = ALU_ADD;
    endcase
  end



endmodule

module Datapath (
    input logic clk,
    reset,
    input logic MemWrite,
    RegWrite, MemAdrSrc, MemDataSrc,
    input logic [1:0] PcSrc, RegSrc,
    input instr_t instruction_type,
    output logic [15:0] Instr
);

  logic [7:0] Pc, PcNext, PcTarget, Imm, MemDataAddress;

  logic [15:0] Result, ALUResult, SrcA, rf_read_data_1, rf_read_data_2, rf_read_data_3, mem_read_data, mem_write_data;

  logic [3:0] rX, rY, rZ;


  //assign opcode = Instr[15:12];
  assign rX = Instr[11:8];
  assign rY = Instr[7:4];
  assign rZ = Instr[3:0];

  assign Imm = Instr[7:0];


  // PC logic
  assign PcTarget = PcSrc[0] ? Imm * 2 : rf_read_data_1[7:0] * 2; // todo check


  always_comb
    if (reset) PcNext = 0;
    else if (PcSrc[1]) PcNext = PcTarget;
    else PcNext = Pc + 2;  // word alignment is 2 bytes

  always_ff @(posedge clk, posedge reset) Pc <= PcNext;

  always_ff @(posedge clk)
  begin
    $display("instruction_address: %h", Pc);
    $display("instruction: %h", Instr);

    // cheat to handle write
    if (instruction_type == WRITE) $display("write: %b", rf_read_data_1);
    else if (instruction_type == HALT) begin
      $display("halt");
      $finish;
    end
  end



  assign MemDataAddress = MemAdrSrc ? rf_read_data_2[7:0] : Imm;


  
  assign ALUResult = 16'dx;
  assign mem_write_data = MemDataSrc ? rf_read_data_1 : ALUResult; // TODO check


  // Memory logic
  Memory mem (
      .clk(clk),
      .write_en(0),
      .instruction_address(Pc),
      .data_address(MemDataAddress),
      .write_data(16'dx),
      .instruction_data(Instr),
      .read_data(mem_read_data)
  );

  always_comb
    case (RegSrc)
      2'b00: Result = mem_read_data;
      2'b01: Result = {8'b0, Imm};
      2'b11: Result = {8'b0, PcNext}; 
      default: Result = 16'bx; 
    endcase


  // REGISTER FILE logic
  RegisterFile rf (
      .clk(clk),
      .address_1(rX),
      .address_2(rY),
      .address_3(rZ),
      .write_en_1(RegWrite),
      .write_data_1(Result),
      .read_data_1(rf_read_data_1),
      .read_data_2(rf_read_data_2),
      .read_data_3(rf_read_data_3)
  );
  // TODO EXTEND

  // ALU logic
  //ALU alu(.ALUOp(ALUOp), .Zero(Zero), .SrcA(SrcA), .SrcB(SrcB), .ALUResult(ALUResult));





endmodule

module ALU (
    input logic Zero,
    input aluop_t ALUOp,
    input logic [15:0] SrcA,
    SrcB,
    output logic [15:0] ALUResult
);

endmodule
