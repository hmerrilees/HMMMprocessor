// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vhmmm.h for the primary calling header

#include "verilated.h"

#include "Vhmmm__Syms.h"
#include "Vhmmm__Syms.h"
#include "Vhmmm___024unit.h"

void Vhmmm___024unit___ctor_var_reset(Vhmmm___024unit* vlSelf);

Vhmmm___024unit::Vhmmm___024unit(Vhmmm__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vhmmm___024unit___ctor_var_reset(this);
}

void Vhmmm___024unit::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vhmmm___024unit::~Vhmmm___024unit() {
}
