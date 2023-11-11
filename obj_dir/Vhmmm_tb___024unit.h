// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vhmmm_tb.h for the primary calling header

#ifndef VERILATED_VHMMM_TB___024UNIT_H_
#define VERILATED_VHMMM_TB___024UNIT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vhmmm_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vhmmm_tb___024unit final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vhmmm_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vhmmm_tb___024unit(Vhmmm_tb__Syms* symsp, const char* v__name);
    ~Vhmmm_tb___024unit();
    VL_UNCOPYABLE(Vhmmm_tb___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
