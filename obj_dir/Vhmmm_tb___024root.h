// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vhmmm_tb.h for the primary calling header

#ifndef VERILATED_VHMMM_TB___024ROOT_H_
#define VERILATED_VHMMM_TB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vhmmm_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vhmmm_tb___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ hmmm_tb__DOT__clk;
    CData/*0:0*/ hmmm_tb__DOT__reset;
    CData/*0:0*/ __Vdlyvval__hmmm_tb__DOT__clk__v0;
    CData/*0:0*/ __Vdlyvset__hmmm_tb__DOT__clk__v0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__hmmm_tb__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__hmmm_tb__DOT__reset__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlDelayScheduler __VdlySched;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vhmmm_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vhmmm_tb___024root(Vhmmm_tb__Syms* symsp, const char* v__name);
    ~Vhmmm_tb___024root();
    VL_UNCOPYABLE(Vhmmm_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
