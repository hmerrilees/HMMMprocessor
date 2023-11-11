// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vhmmm.h for the primary calling header

#ifndef VERILATED_VHMMM___024UNIT_H_
#define VERILATED_VHMMM___024UNIT_H_  // guard

#include "verilated.h"


class Vhmmm__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vhmmm___024unit final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vhmmm__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vhmmm___024unit(Vhmmm__Syms* symsp, const char* v__name);
    ~Vhmmm___024unit();
    VL_UNCOPYABLE(Vhmmm___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
