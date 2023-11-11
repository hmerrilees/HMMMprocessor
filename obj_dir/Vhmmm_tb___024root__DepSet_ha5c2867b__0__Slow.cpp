// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vhmmm_tb.h for the primary calling header

#include "verilated.h"

#include "Vhmmm_tb__Syms.h"
#include "Vhmmm_tb___024root.h"

VL_ATTR_COLD void Vhmmm_tb___024root___eval_static(Vhmmm_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhmmm_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhmmm_tb___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vhmmm_tb___024root___eval_initial__TOP(Vhmmm_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhmmm_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhmmm_tb___024root___eval_initial__TOP\n"); );
    // Init
    VlUnpacked<SData/*15:0*/, 256> hmmm_tb__DOT__hmmm__DOT__datapath__DOT__mem__DOT__RAM;
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        hmmm_tb__DOT__hmmm__DOT__datapath__DOT__mem__DOT__RAM[__Vi0] = 0;
    }
    VlWide<3>/*95:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e747874U;
    __Vtemp_1[1U] = 0x6772616dU;
    __Vtemp_1[2U] = 0x70726fU;
    VL_READMEM_N(true, 16, 256, 0, VL_CVT_PACK_STR_NW(3, __Vtemp_1)
                 ,  &(hmmm_tb__DOT__hmmm__DOT__datapath__DOT__mem__DOT__RAM)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vhmmm_tb___024root___eval_final(Vhmmm_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhmmm_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhmmm_tb___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vhmmm_tb___024root___eval_settle(Vhmmm_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhmmm_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhmmm_tb___024root___eval_settle\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vhmmm_tb___024root___dump_triggers__act(Vhmmm_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhmmm_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhmmm_tb___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge hmmm_tb.clk or posedge hmmm_tb.reset)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vhmmm_tb___024root___dump_triggers__nba(Vhmmm_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhmmm_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhmmm_tb___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge hmmm_tb.clk or posedge hmmm_tb.reset)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vhmmm_tb___024root___ctor_var_reset(Vhmmm_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhmmm_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhmmm_tb___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->hmmm_tb__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->hmmm_tb__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->__Vdlyvval__hmmm_tb__DOT__clk__v0 = VL_RAND_RESET_I(1);
    vlSelf->__Vdlyvset__hmmm_tb__DOT__clk__v0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__hmmm_tb__DOT__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__hmmm_tb__DOT__reset__0 = VL_RAND_RESET_I(1);
}
