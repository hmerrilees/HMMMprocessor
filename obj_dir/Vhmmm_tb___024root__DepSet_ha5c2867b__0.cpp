// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vhmmm_tb.h for the primary calling header

#include "verilated.h"

#include "Vhmmm_tb__Syms.h"
#include "Vhmmm_tb___024root.h"

VL_ATTR_COLD void Vhmmm_tb___024root___eval_initial__TOP(Vhmmm_tb___024root* vlSelf);
VlCoroutine Vhmmm_tb___024root___eval_initial__TOP__0(Vhmmm_tb___024root* vlSelf);
VlCoroutine Vhmmm_tb___024root___eval_initial__TOP__1(Vhmmm_tb___024root* vlSelf);

void Vhmmm_tb___024root___eval_initial(Vhmmm_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhmmm_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhmmm_tb___024root___eval_initial\n"); );
    // Body
    Vhmmm_tb___024root___eval_initial__TOP(vlSelf);
    Vhmmm_tb___024root___eval_initial__TOP__0(vlSelf);
    Vhmmm_tb___024root___eval_initial__TOP__1(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__hmmm_tb__DOT__clk__0 
        = vlSelf->hmmm_tb__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__hmmm_tb__DOT__reset__0 
        = vlSelf->hmmm_tb__DOT__reset;
}

VL_INLINE_OPT VlCoroutine Vhmmm_tb___024root___eval_initial__TOP__0(Vhmmm_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhmmm_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhmmm_tb___024root___eval_initial__TOP__0\n"); );
    // Body
    vlSelf->hmmm_tb__DOT__clk = 0U;
    vlSelf->hmmm_tb__DOT__reset = 1U;
    co_await vlSelf->__VdlySched.delay(0xaULL, nullptr, 
                                       "hmmm.sv", 45);
    vlSelf->hmmm_tb__DOT__reset = 0U;
}

VL_INLINE_OPT VlCoroutine Vhmmm_tb___024root___eval_initial__TOP__1(Vhmmm_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhmmm_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhmmm_tb___024root___eval_initial__TOP__1\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VdlySched.delay(5ULL, nullptr, 
                                           "hmmm.sv", 
                                           47);
        vlSelf->__Vdlyvval__hmmm_tb__DOT__clk__v0 = 
            (1U & (~ (IData)(vlSelf->hmmm_tb__DOT__clk)));
        vlSelf->__Vdlyvset__hmmm_tb__DOT__clk__v0 = 1U;
    }
}

void Vhmmm_tb___024root___eval_act(Vhmmm_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhmmm_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhmmm_tb___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vhmmm_tb___024root___nba_sequent__TOP__0(Vhmmm_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhmmm_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhmmm_tb___024root___nba_sequent__TOP__0\n"); );
    // Body
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->hmmm_tb__DOT__reset))))) {
        VL_FINISH_MT("hmmm.sv", 218, "");
    }
}

VL_INLINE_OPT void Vhmmm_tb___024root___nba_sequent__TOP__1(Vhmmm_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhmmm_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhmmm_tb___024root___nba_sequent__TOP__1\n"); );
    // Body
    if (vlSelf->__Vdlyvset__hmmm_tb__DOT__clk__v0) {
        vlSelf->hmmm_tb__DOT__clk = vlSelf->__Vdlyvval__hmmm_tb__DOT__clk__v0;
        vlSelf->__Vdlyvset__hmmm_tb__DOT__clk__v0 = 0U;
    }
}

void Vhmmm_tb___024root___eval_nba(Vhmmm_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhmmm_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhmmm_tb___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vhmmm_tb___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vhmmm_tb___024root___nba_sequent__TOP__1(vlSelf);
    }
}

void Vhmmm_tb___024root___eval_triggers__act(Vhmmm_tb___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vhmmm_tb___024root___dump_triggers__act(Vhmmm_tb___024root* vlSelf);
#endif  // VL_DEBUG
void Vhmmm_tb___024root___timing_resume(Vhmmm_tb___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vhmmm_tb___024root___dump_triggers__nba(Vhmmm_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vhmmm_tb___024root___eval(Vhmmm_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhmmm_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhmmm_tb___024root___eval\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vhmmm_tb___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vhmmm_tb___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("hmmm.sv", 39, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
                Vhmmm_tb___024root___timing_resume(vlSelf);
                Vhmmm_tb___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vhmmm_tb___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("hmmm.sv", 39, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vhmmm_tb___024root___eval_nba(vlSelf);
        }
    }
}

void Vhmmm_tb___024root___timing_resume(Vhmmm_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhmmm_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhmmm_tb___024root___timing_resume\n"); );
    // Body
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

#ifdef VL_DEBUG
void Vhmmm_tb___024root___eval_debug_assertions(Vhmmm_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhmmm_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhmmm_tb___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
