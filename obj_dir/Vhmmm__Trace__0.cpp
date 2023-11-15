// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vhmmm__Syms.h"


void Vhmmm___024root__trace_chg_sub_0(Vhmmm___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vhmmm___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhmmm___024root__trace_chg_top_0\n"); );
    // Init
    Vhmmm___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vhmmm___024root*>(voidSelf);
    Vhmmm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vhmmm___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vhmmm___024root__trace_chg_sub_0(Vhmmm___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vhmmm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhmmm___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgSData(oldp+0,(vlSelf->hmmm__DOT__Instr),16);
        bufp->chgCData(oldp+1,(vlSelf->hmmm__DOT__RegSrc),2);
        bufp->chgCData(oldp+2,(vlSelf->hmmm__DOT__PcSrc),2);
        bufp->chgBit(oldp+3,(vlSelf->hmmm__DOT__MemWrite));
        bufp->chgBit(oldp+4,(vlSelf->hmmm__DOT__RegWrite));
        bufp->chgBit(oldp+5,(vlSelf->hmmm__DOT__MemAdrSrc));
        bufp->chgBit(oldp+6,(vlSelf->hmmm__DOT__MemDataSrc));
        bufp->chgIData(oldp+7,(vlSelf->hmmm__DOT__aluop),32);
        bufp->chgIData(oldp+8,(vlSelf->hmmm__DOT__instruction_type),32);
        bufp->chgCData(oldp+9,(vlSelf->hmmm__DOT__datapath__DOT__Pc),8);
        bufp->chgCData(oldp+10,((0xffU & ((IData)(2U) 
                                          + (IData)(vlSelf->hmmm__DOT__datapath__DOT__Pc)))),8);
        bufp->chgCData(oldp+11,((0xffU & ((1U & (IData)(vlSelf->hmmm__DOT__PcSrc))
                                           ? (((0U 
                                                == 
                                                (0xfU 
                                                 & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                                    >> 8U)))
                                                ? 0U
                                                : (0xffU 
                                                   & (IData)(vlSelf->__VdfgTmp_h79043d9e__0))) 
                                              << 1U)
                                           : (0x1feU 
                                              & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                                 << 1U))))),8);
        bufp->chgCData(oldp+12,((0xffU & (IData)(vlSelf->hmmm__DOT__Instr))),8);
        bufp->chgCData(oldp+13,(vlSelf->hmmm__DOT__datapath__DOT__MemDataAddress),8);
        bufp->chgSData(oldp+14,(((0U == (IData)(vlSelf->hmmm__DOT__RegSrc))
                                  ? (0xffU & (IData)(vlSelf->hmmm__DOT__Instr))
                                  : ((1U == (IData)(vlSelf->hmmm__DOT__RegSrc))
                                      ? vlSelf->hmmm__DOT__datapath__DOT__mem__DOT__RAM
                                     [vlSelf->hmmm__DOT__datapath__DOT__MemDataAddress]
                                      : ((2U == (IData)(vlSelf->hmmm__DOT__RegSrc))
                                          ? (0xffU 
                                             & ((IData)(2U) 
                                                + (IData)(vlSelf->hmmm__DOT__datapath__DOT__Pc)))
                                          : 0U)))),16);
        bufp->chgSData(oldp+15,(vlSelf->hmmm__DOT__datapath__DOT__rf_read_data_1),16);
        bufp->chgSData(oldp+16,(((0U == (0xfU & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                                 >> 4U)))
                                  ? 0U : vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers
                                 [(0xfU & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                           >> 4U))])),16);
        bufp->chgSData(oldp+17,(((0U == (0xfU & (IData)(vlSelf->hmmm__DOT__Instr)))
                                  ? 0U : vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers
                                 [(0xfU & (IData)(vlSelf->hmmm__DOT__Instr))])),16);
        bufp->chgSData(oldp+18,(vlSelf->hmmm__DOT__datapath__DOT__mem__DOT__RAM
                                [vlSelf->hmmm__DOT__datapath__DOT__MemDataAddress]),16);
        bufp->chgSData(oldp+19,(((IData)(vlSelf->hmmm__DOT__MemDataSrc)
                                  ? (IData)(vlSelf->hmmm__DOT__datapath__DOT__rf_read_data_1)
                                  : 0U)),16);
        bufp->chgCData(oldp+20,((0xfU & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                         >> 8U))),4);
        bufp->chgCData(oldp+21,((0xfU & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                         >> 4U))),4);
        bufp->chgCData(oldp+22,((0xfU & (IData)(vlSelf->hmmm__DOT__Instr))),4);
        bufp->chgSData(oldp+23,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[0]),16);
        bufp->chgSData(oldp+24,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[1]),16);
        bufp->chgSData(oldp+25,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[2]),16);
        bufp->chgSData(oldp+26,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[3]),16);
        bufp->chgSData(oldp+27,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[4]),16);
        bufp->chgSData(oldp+28,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[5]),16);
        bufp->chgSData(oldp+29,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[6]),16);
        bufp->chgSData(oldp+30,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[7]),16);
        bufp->chgSData(oldp+31,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[8]),16);
        bufp->chgSData(oldp+32,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[9]),16);
        bufp->chgSData(oldp+33,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[10]),16);
        bufp->chgSData(oldp+34,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[11]),16);
        bufp->chgSData(oldp+35,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[12]),16);
        bufp->chgSData(oldp+36,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[13]),16);
        bufp->chgSData(oldp+37,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[14]),16);
        bufp->chgSData(oldp+38,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[15]),16);
        bufp->chgIData(oldp+39,(vlSelf->hmmm__DOT__datapath__DOT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+40,(vlSelf->hmmm__DOT__datapath__DOT__unnamedblk2__DOT__i),32);
    }
    bufp->chgBit(oldp+41,(vlSelf->clk));
    bufp->chgBit(oldp+42,(vlSelf->reset));
    bufp->chgCData(oldp+43,(((IData)(vlSelf->reset)
                              ? 0U : (0xffU & ((2U 
                                                & (IData)(vlSelf->hmmm__DOT__PcSrc))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSelf->hmmm__DOT__PcSrc))
                                                    ? 
                                                   (((0U 
                                                      == 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                                          >> 8U)))
                                                      ? 0U
                                                      : 
                                                     (0xffU 
                                                      & (IData)(vlSelf->__VdfgTmp_h79043d9e__0))) 
                                                    << 1U)
                                                    : 
                                                   (0x1feU 
                                                    & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                                       << 1U)))
                                                : ((IData)(2U) 
                                                   + (IData)(vlSelf->hmmm__DOT__datapath__DOT__Pc)))))),8);
}

void Vhmmm___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhmmm___024root__trace_cleanup\n"); );
    // Init
    Vhmmm___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vhmmm___024root*>(voidSelf);
    Vhmmm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
