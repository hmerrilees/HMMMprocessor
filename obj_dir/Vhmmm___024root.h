// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vhmmm.h for the primary calling header

#ifndef VERILATED_VHMMM___024ROOT_H_
#define VERILATED_VHMMM___024ROOT_H_  // guard

#include "verilated.h"


class Vhmmm__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vhmmm___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    CData/*1:0*/ hmmm__DOT__reg_src_x;
    CData/*1:0*/ hmmm__DOT__pc_src;
    CData/*1:0*/ hmmm__DOT__mem_adr_src;
    CData/*1:0*/ hmmm__DOT__alu_src_b;
    CData/*0:0*/ hmmm__DOT__mem_write;
    CData/*0:0*/ hmmm__DOT__reg_write_x;
    CData/*0:0*/ hmmm__DOT__reg_write_y;
    CData/*0:0*/ hmmm__DOT__mem_data_src;
    CData/*0:0*/ hmmm__DOT__alu_src_a;
    CData/*7:0*/ hmmm__DOT__datapath__DOT__pc;
    CData/*7:0*/ hmmm__DOT__datapath__DOT__pc_next;
    CData/*7:0*/ hmmm__DOT__datapath__DOT__mem_data_address;
    CData/*0:0*/ hmmm__DOT__datapath__DOT__take_jump;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ hmmm__DOT__instruction;
    SData/*15:0*/ hmmm__DOT__datapath__DOT__result;
    SData/*15:0*/ hmmm__DOT__datapath__DOT__alu_result;
    SData/*15:0*/ hmmm__DOT__datapath__DOT__alu_input_a;
    SData/*15:0*/ hmmm__DOT__datapath__DOT__alu_input_b;
    SData/*15:0*/ hmmm__DOT__datapath__DOT__rf_read_data_1;
    SData/*15:0*/ hmmm__DOT__datapath__DOT__rf_read_data_2;
    SData/*15:0*/ hmmm__DOT__datapath__DOT__imm_ext;
    SData/*15:0*/ __VdfgTmp_h1fe3baef__0;
    IData/*31:0*/ hmmm__DOT__alu_op;
    IData/*31:0*/ hmmm__DOT__instruction_type;
    IData/*31:0*/ hmmm__DOT__datapath__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ hmmm__DOT__datapath__DOT__unnamedblk2__DOT__i;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<SData/*15:0*/, 256> hmmm__DOT__datapath__DOT__mem__DOT__RAM;
    VlUnpacked<SData/*15:0*/, 16> hmmm__DOT__datapath__DOT__rf__DOT__registers;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vhmmm__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vhmmm___024root(Vhmmm__Syms* symsp, const char* v__name);
    ~Vhmmm___024root();
    VL_UNCOPYABLE(Vhmmm___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
