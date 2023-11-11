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
    CData/*0:0*/ hmmm__DOT__RegWrite;
    CData/*0:0*/ hmmm__DOT__RegSrc;
    CData/*0:0*/ hmmm__DOT__MemAdrSrc;
    CData/*0:0*/ hmmm__DOT__PcSrc;
    CData/*7:0*/ hmmm__DOT__datapath__DOT__Pc;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__reset__0;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ hmmm__DOT__Instr;
    SData/*15:0*/ hmmm__DOT__datapath__DOT__SrcA;
    SData/*15:0*/ __VdfgTmp_h79120594__0;
    IData/*31:0*/ hmmm__DOT__aluop;
    IData/*31:0*/ hmmm__DOT__instruction_type;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<SData/*15:0*/, 256> hmmm__DOT__datapath__DOT__mem__DOT__RAM;
    VlUnpacked<SData/*15:0*/, 16> hmmm__DOT__datapath__DOT__rf__DOT__registers;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

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
