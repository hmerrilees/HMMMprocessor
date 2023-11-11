// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vhmmm_tb.h for the primary calling header

#include "verilated.h"

#include "Vhmmm_tb__Syms.h"
#include "Vhmmm_tb__Syms.h"
#include "Vhmmm_tb___024unit.h"

void Vhmmm_tb___024unit___ctor_var_reset(Vhmmm_tb___024unit* vlSelf);

Vhmmm_tb___024unit::Vhmmm_tb___024unit(Vhmmm_tb__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vhmmm_tb___024unit___ctor_var_reset(this);
}

void Vhmmm_tb___024unit::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vhmmm_tb___024unit::~Vhmmm_tb___024unit() {
}
