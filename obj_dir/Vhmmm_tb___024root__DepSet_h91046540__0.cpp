// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vhmmm_tb.h for the primary calling header

#include "verilated.h"

#include "Vhmmm_tb__Syms.h"
#include "Vhmmm_tb__Syms.h"
#include "Vhmmm_tb___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vhmmm_tb___024root___dump_triggers__act(Vhmmm_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vhmmm_tb___024root___eval_triggers__act(Vhmmm_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhmmm_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhmmm_tb___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, (((IData)(vlSelf->hmmm_tb__DOT__clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__hmmm_tb__DOT__clk__0))) 
                                     | ((IData)(vlSelf->hmmm_tb__DOT__reset) 
                                        & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__hmmm_tb__DOT__reset__0)))));
    vlSelf->__VactTriggered.set(1U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__Vtrigprevexpr___TOP__hmmm_tb__DOT__clk__0 
        = vlSelf->hmmm_tb__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__hmmm_tb__DOT__reset__0 
        = vlSelf->hmmm_tb__DOT__reset;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vhmmm_tb___024root___dump_triggers__act(vlSelf);
    }
#endif
}
