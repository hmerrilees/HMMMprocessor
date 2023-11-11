// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vhmmm.h"
#include "Vhmmm__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vhmmm::Vhmmm(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vhmmm__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vhmmm::Vhmmm(const char* _vcname__)
    : Vhmmm(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vhmmm::~Vhmmm() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vhmmm___024root___eval_debug_assertions(Vhmmm___024root* vlSelf);
#endif  // VL_DEBUG
void Vhmmm___024root___eval_static(Vhmmm___024root* vlSelf);
void Vhmmm___024root___eval_initial(Vhmmm___024root* vlSelf);
void Vhmmm___024root___eval_settle(Vhmmm___024root* vlSelf);
void Vhmmm___024root___eval(Vhmmm___024root* vlSelf);

void Vhmmm::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vhmmm::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vhmmm___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vhmmm___024root___eval_static(&(vlSymsp->TOP));
        Vhmmm___024root___eval_initial(&(vlSymsp->TOP));
        Vhmmm___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vhmmm___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vhmmm::eventsPending() { return false; }

uint64_t Vhmmm::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vhmmm::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vhmmm___024root___eval_final(Vhmmm___024root* vlSelf);

VL_ATTR_COLD void Vhmmm::final() {
    Vhmmm___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vhmmm::hierName() const { return vlSymsp->name(); }
const char* Vhmmm::modelName() const { return "Vhmmm"; }
unsigned Vhmmm::threads() const { return 1; }
void Vhmmm::prepareClone() const { contextp()->prepareClone(); }
void Vhmmm::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vhmmm::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vhmmm___024root__trace_init_top(Vhmmm___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vhmmm___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vhmmm___024root*>(voidSelf);
    Vhmmm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vhmmm___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vhmmm___024root__trace_register(Vhmmm___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vhmmm::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vhmmm::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vhmmm___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
