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
        bufp->chgCData(oldp+3,(vlSelf->hmmm__DOT__MemAdrSrc),2);
        bufp->chgCData(oldp+4,(vlSelf->hmmm__DOT__ALUSrcB),2);
        bufp->chgBit(oldp+5,(vlSelf->hmmm__DOT__MemWrite));
        bufp->chgBit(oldp+6,(vlSelf->hmmm__DOT__RegWrite));
        bufp->chgBit(oldp+7,(vlSelf->hmmm__DOT__RegWriteDest));
        bufp->chgBit(oldp+8,(vlSelf->hmmm__DOT__MemDataSrc));
        bufp->chgBit(oldp+9,(vlSelf->hmmm__DOT__ALUSrcA));
        bufp->chgIData(oldp+10,(vlSelf->hmmm__DOT__alu_op),32);
        bufp->chgIData(oldp+11,(vlSelf->hmmm__DOT__instruction_type),32);
        bufp->chgCData(oldp+12,(vlSelf->hmmm__DOT__datapath__DOT__Pc),8);
        bufp->chgCData(oldp+13,((0xffU & ((IData)(2U) 
                                          + (IData)(vlSelf->hmmm__DOT__datapath__DOT__Pc)))),8);
        bufp->chgCData(oldp+14,((0xffU & ((1U & (IData)(vlSelf->hmmm__DOT__PcSrc))
                                           ? ((0U == 
                                               (0xfU 
                                                & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                                   >> 8U)))
                                               ? 0U
                                               : (0xffU 
                                                  & (IData)(vlSelf->__VdfgTmp_h79043d9e__0)))
                                           : (0x1feU 
                                              & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                                 << 1U))))),8);
        bufp->chgCData(oldp+15,((0xffU & (IData)(vlSelf->hmmm__DOT__Instr))),8);
        bufp->chgCData(oldp+16,(vlSelf->hmmm__DOT__datapath__DOT__mem_data_address),8);
        bufp->chgSData(oldp+17,(vlSelf->hmmm__DOT__datapath__DOT__result),16);
        bufp->chgSData(oldp+18,(vlSelf->hmmm__DOT__datapath__DOT__alu_result),16);
        bufp->chgSData(oldp+19,(vlSelf->hmmm__DOT__datapath__DOT__alu_src_a),16);
        bufp->chgSData(oldp+20,(vlSelf->hmmm__DOT__datapath__DOT__alu_src_b),16);
        bufp->chgSData(oldp+21,(vlSelf->hmmm__DOT__datapath__DOT__rf_read_data_1),16);
        bufp->chgSData(oldp+22,(vlSelf->hmmm__DOT__datapath__DOT__rf_read_data_2),16);
        bufp->chgSData(oldp+23,(((0U == (0xfU & (IData)(vlSelf->hmmm__DOT__Instr)))
                                  ? 0U : vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers
                                 [(0xfU & (IData)(vlSelf->hmmm__DOT__Instr))])),16);
        bufp->chgSData(oldp+24,(vlSelf->hmmm__DOT__datapath__DOT__mem__DOT__RAM
                                [vlSelf->hmmm__DOT__datapath__DOT__mem_data_address]),16);
        bufp->chgSData(oldp+25,(((IData)(vlSelf->hmmm__DOT__MemDataSrc)
                                  ? (IData)(vlSelf->hmmm__DOT__datapath__DOT__rf_read_data_1)
                                  : (IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_result))),16);
        bufp->chgCData(oldp+26,((0xfU & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                         >> 8U))),4);
        bufp->chgCData(oldp+27,((0xfU & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                         >> 4U))),4);
        bufp->chgCData(oldp+28,((0xfU & (IData)(vlSelf->hmmm__DOT__Instr))),4);
        bufp->chgBit(oldp+29,((0U == (IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_result))));
        bufp->chgBit(oldp+30,((1U & ((IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_result) 
                                     >> 0xfU))));
        bufp->chgBit(oldp+31,((1U & ((0x15U == vlSelf->hmmm__DOT__instruction_type)
                                      ? (0U == (IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_result))
                                      : ((0x16U == vlSelf->hmmm__DOT__instruction_type)
                                          ? (0U != (IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_result))
                                          : ((0x17U 
                                              == vlSelf->hmmm__DOT__instruction_type)
                                              ? ((~ 
                                                  ((IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_result) 
                                                   >> 0xfU)) 
                                                 & (0U 
                                                    != (IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_result)))
                                              : ((0x18U 
                                                  != vlSelf->hmmm__DOT__instruction_type) 
                                                 | ((IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_result) 
                                                    >> 0xfU))))))));
        bufp->chgSData(oldp+32,(vlSelf->hmmm__DOT__datapath__DOT__ImmExt),16);
        bufp->chgSData(oldp+33,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[0]),16);
        bufp->chgSData(oldp+34,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[1]),16);
        bufp->chgSData(oldp+35,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[2]),16);
        bufp->chgSData(oldp+36,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[3]),16);
        bufp->chgSData(oldp+37,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[4]),16);
        bufp->chgSData(oldp+38,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[5]),16);
        bufp->chgSData(oldp+39,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[6]),16);
        bufp->chgSData(oldp+40,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[7]),16);
        bufp->chgSData(oldp+41,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[8]),16);
        bufp->chgSData(oldp+42,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[9]),16);
        bufp->chgSData(oldp+43,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[10]),16);
        bufp->chgSData(oldp+44,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[11]),16);
        bufp->chgSData(oldp+45,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[12]),16);
        bufp->chgSData(oldp+46,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[13]),16);
        bufp->chgSData(oldp+47,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[14]),16);
        bufp->chgSData(oldp+48,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[15]),16);
        bufp->chgIData(oldp+49,(vlSelf->hmmm__DOT__datapath__DOT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+50,(vlSelf->hmmm__DOT__datapath__DOT__unnamedblk2__DOT__i),32);
    }
    bufp->chgBit(oldp+51,(vlSelf->clk));
    bufp->chgBit(oldp+52,(vlSelf->reset));
    bufp->chgCData(oldp+53,(((IData)(vlSelf->reset)
                              ? 0U : (0xffU & ((IData)(
                                                       (((IData)(vlSelf->hmmm__DOT__PcSrc) 
                                                         >> 1U) 
                                                        & ((0x15U 
                                                            == vlSelf->hmmm__DOT__instruction_type)
                                                            ? 
                                                           (0U 
                                                            == (IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_result))
                                                            : 
                                                           ((0x16U 
                                                             == vlSelf->hmmm__DOT__instruction_type)
                                                             ? 
                                                            (0U 
                                                             != (IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_result))
                                                             : 
                                                            ((0x17U 
                                                              == vlSelf->hmmm__DOT__instruction_type)
                                                              ? 
                                                             ((~ 
                                                               ((IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_result) 
                                                                >> 0xfU)) 
                                                              & (0U 
                                                                 != (IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_result)))
                                                              : 
                                                             ((0x18U 
                                                               != vlSelf->hmmm__DOT__instruction_type) 
                                                              | ((IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_result) 
                                                                 >> 0xfU)))))))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSelf->hmmm__DOT__PcSrc))
                                                    ? 
                                                   ((0U 
                                                     == 
                                                     (0xfU 
                                                      & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                                         >> 8U)))
                                                     ? 0U
                                                     : 
                                                    (0xffU 
                                                     & (IData)(vlSelf->__VdfgTmp_h79043d9e__0)))
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
