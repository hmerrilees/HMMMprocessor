// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vhmmm_tb.h for the primary calling header

#include "verilated.h"

#include "Vhmmm_tb__Syms.h"
#include "Vhmmm_tb__Syms.h"
#include "Vhmmm_tb___024root.h"

void Vhmmm_tb___024root___ctor_var_reset(Vhmmm_tb___024root* vlSelf);

Vhmmm_tb___024root::Vhmmm_tb___024root(Vhmmm_tb__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vhmmm_tb___024root___ctor_var_reset(this);
}

void Vhmmm_tb___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vhmmm_tb___024root::~Vhmmm_tb___024root() {
}
