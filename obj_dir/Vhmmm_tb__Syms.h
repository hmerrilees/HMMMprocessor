// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VHMMM_TB__SYMS_H_
#define VERILATED_VHMMM_TB__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vhmmm_tb.h"

// INCLUDE MODULE CLASSES
#include "Vhmmm_tb___024root.h"
#include "Vhmmm_tb___024unit.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vhmmm_tb__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vhmmm_tb* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vhmmm_tb___024root             TOP;

    // CONSTRUCTORS
    Vhmmm_tb__Syms(VerilatedContext* contextp, const char* namep, Vhmmm_tb* modelp);
    ~Vhmmm_tb__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
