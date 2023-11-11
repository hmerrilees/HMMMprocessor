// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vhmmm_tb.h"
#include "Vhmmm_tb__Syms.h"

//============================================================
// Constructors

Vhmmm_tb::Vhmmm_tb(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vhmmm_tb__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vhmmm_tb::Vhmmm_tb(const char* _vcname__)
    : Vhmmm_tb(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vhmmm_tb::~Vhmmm_tb() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vhmmm_tb___024root___eval_debug_assertions(Vhmmm_tb___024root* vlSelf);
#endif  // VL_DEBUG
void Vhmmm_tb___024root___eval_static(Vhmmm_tb___024root* vlSelf);
void Vhmmm_tb___024root___eval_initial(Vhmmm_tb___024root* vlSelf);
void Vhmmm_tb___024root___eval_settle(Vhmmm_tb___024root* vlSelf);
void Vhmmm_tb___024root___eval(Vhmmm_tb___024root* vlSelf);

void Vhmmm_tb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vhmmm_tb::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vhmmm_tb___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vhmmm_tb___024root___eval_static(&(vlSymsp->TOP));
        Vhmmm_tb___024root___eval_initial(&(vlSymsp->TOP));
        Vhmmm_tb___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vhmmm_tb___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vhmmm_tb::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vhmmm_tb::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vhmmm_tb::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vhmmm_tb___024root___eval_final(Vhmmm_tb___024root* vlSelf);

VL_ATTR_COLD void Vhmmm_tb::final() {
    Vhmmm_tb___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vhmmm_tb::hierName() const { return vlSymsp->name(); }
const char* Vhmmm_tb::modelName() const { return "Vhmmm_tb"; }
unsigned Vhmmm_tb::threads() const { return 1; }
void Vhmmm_tb::prepareClone() const { contextp()->prepareClone(); }
void Vhmmm_tb::atClone() const {
    contextp()->threadPoolpOnClone();
}
