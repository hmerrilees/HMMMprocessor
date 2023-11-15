// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vhmmm__Syms.h"


VL_ATTR_COLD void Vhmmm___024root__trace_init_sub__TOP__0(Vhmmm___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vhmmm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhmmm___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+49,"clk", false,-1);
    tracep->declBit(c+50,"reset", false,-1);
    tracep->pushNamePrefix("hmmm ");
    tracep->declBit(c+49,"clk", false,-1);
    tracep->declBit(c+50,"reset", false,-1);
    tracep->declBus(c+1,"Instr", false,-1, 15,0);
    tracep->declBus(c+2,"RegSrc", false,-1, 1,0);
    tracep->declBus(c+3,"PcSrc", false,-1, 1,0);
    tracep->declBit(c+4,"MemWrite", false,-1);
    tracep->declBit(c+5,"RegWrite", false,-1);
    tracep->declBit(c+6,"MemAdrSrc", false,-1);
    tracep->declBit(c+7,"MemDataSrc", false,-1);
    tracep->declBit(c+8,"ALUSrcA", false,-1);
    tracep->declBit(c+9,"ALUSrcB", false,-1);
    tracep->declBus(c+10,"alu_op", false,-1, 31,0);
    tracep->declBus(c+11,"instruction_type", false,-1, 31,0);
    tracep->pushNamePrefix("controller ");
    tracep->declBus(c+1,"instr", false,-1, 15,0);
    tracep->declBus(c+10,"alu_op", false,-1, 31,0);
    tracep->declBit(c+4,"MemWrite", false,-1);
    tracep->declBit(c+5,"RegWrite", false,-1);
    tracep->declBit(c+6,"MemAdrSrc", false,-1);
    tracep->declBit(c+7,"MemDataSrc", false,-1);
    tracep->declBit(c+8,"ALUSrcA", false,-1);
    tracep->declBit(c+9,"ALUSrcB", false,-1);
    tracep->declBus(c+2,"RegSrc", false,-1, 1,0);
    tracep->declBus(c+3,"PcSrc", false,-1, 1,0);
    tracep->declBus(c+11,"instruction_type", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("datapath ");
    tracep->declBit(c+49,"clk", false,-1);
    tracep->declBit(c+50,"reset", false,-1);
    tracep->declBit(c+4,"MemWrite", false,-1);
    tracep->declBit(c+5,"RegWrite", false,-1);
    tracep->declBit(c+6,"MemAdrSrc", false,-1);
    tracep->declBit(c+7,"MemDataSrc", false,-1);
    tracep->declBit(c+8,"ALUSrcA", false,-1);
    tracep->declBit(c+9,"ALUSrcB", false,-1);
    tracep->declBus(c+3,"PcSrc", false,-1, 1,0);
    tracep->declBus(c+2,"RegSrc", false,-1, 1,0);
    tracep->declBus(c+11,"instruction_type", false,-1, 31,0);
    tracep->declBus(c+10,"alu_op", false,-1, 31,0);
    tracep->declBus(c+1,"Instr", false,-1, 15,0);
    tracep->declBus(c+12,"Pc", false,-1, 7,0);
    tracep->declBus(c+13,"PcPlus2", false,-1, 7,0);
    tracep->declBus(c+51,"PcNext", false,-1, 7,0);
    tracep->declBus(c+14,"PcTarget", false,-1, 7,0);
    tracep->declBus(c+15,"Imm", false,-1, 7,0);
    tracep->declBus(c+16,"mem_data_address", false,-1, 7,0);
    tracep->declBus(c+17,"result", false,-1, 15,0);
    tracep->declBus(c+18,"alu_result", false,-1, 15,0);
    tracep->declBus(c+19,"alu_src_a", false,-1, 15,0);
    tracep->declBus(c+20,"alu_src_b", false,-1, 15,0);
    tracep->declBus(c+21,"rf_read_data_1", false,-1, 15,0);
    tracep->declBus(c+22,"rf_read_data_2", false,-1, 15,0);
    tracep->declBus(c+23,"rf_read_data_3", false,-1, 15,0);
    tracep->declBus(c+24,"mem_read_data", false,-1, 15,0);
    tracep->declBus(c+25,"mem_write_data", false,-1, 15,0);
    tracep->declBus(c+26,"rX", false,-1, 3,0);
    tracep->declBus(c+27,"rY", false,-1, 3,0);
    tracep->declBus(c+28,"rZ", false,-1, 3,0);
    tracep->declBit(c+29,"zero", false,-1);
    tracep->declBit(c+30,"sign", false,-1);
    tracep->pushNamePrefix("alu ");
    tracep->declBus(c+10,"alu_op", false,-1, 31,0);
    tracep->declBus(c+19,"src_a", false,-1, 15,0);
    tracep->declBus(c+20,"src_b", false,-1, 15,0);
    tracep->declBus(c+18,"alu_result", false,-1, 15,0);
    tracep->declBit(c+29,"zero", false,-1);
    tracep->declBit(c+30,"sign", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("mem ");
    tracep->declBit(c+49,"clk", false,-1);
    tracep->declBit(c+4,"write_en", false,-1);
    tracep->declBus(c+12,"instruction_address", false,-1, 7,0);
    tracep->declBus(c+16,"data_address", false,-1, 7,0);
    tracep->declBus(c+25,"write_data", false,-1, 15,0);
    tracep->declBus(c+1,"instruction_data", false,-1, 15,0);
    tracep->declBus(c+24,"read_data", false,-1, 15,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("rf ");
    tracep->declBit(c+49,"clk", false,-1);
    tracep->declBus(c+26,"address_1", false,-1, 3,0);
    tracep->declBus(c+27,"address_2", false,-1, 3,0);
    tracep->declBus(c+28,"address_3", false,-1, 3,0);
    tracep->declBit(c+5,"write_en_1", false,-1);
    tracep->declBus(c+17,"write_data_1", false,-1, 15,0);
    tracep->declBus(c+21,"read_data_1", false,-1, 15,0);
    tracep->declBus(c+22,"read_data_2", false,-1, 15,0);
    tracep->declBus(c+23,"read_data_3", false,-1, 15,0);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+31+i*1,"registers", true,(i+0), 15,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBus(c+47,"i", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->declBus(c+48,"i", false,-1, 31,0);
    tracep->popNamePrefix(3);
}

VL_ATTR_COLD void Vhmmm___024root__trace_init_top(Vhmmm___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vhmmm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhmmm___024root__trace_init_top\n"); );
    // Body
    Vhmmm___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vhmmm___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vhmmm___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vhmmm___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vhmmm___024root__trace_register(Vhmmm___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vhmmm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhmmm___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vhmmm___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vhmmm___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vhmmm___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vhmmm___024root__trace_full_sub_0(Vhmmm___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vhmmm___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhmmm___024root__trace_full_top_0\n"); );
    // Init
    Vhmmm___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vhmmm___024root*>(voidSelf);
    Vhmmm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vhmmm___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vhmmm___024root__trace_full_sub_0(Vhmmm___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vhmmm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhmmm___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullSData(oldp+1,(vlSelf->hmmm__DOT__Instr),16);
    bufp->fullCData(oldp+2,(vlSelf->hmmm__DOT__RegSrc),2);
    bufp->fullCData(oldp+3,(vlSelf->hmmm__DOT__PcSrc),2);
    bufp->fullBit(oldp+4,(vlSelf->hmmm__DOT__MemWrite));
    bufp->fullBit(oldp+5,(vlSelf->hmmm__DOT__RegWrite));
    bufp->fullBit(oldp+6,(vlSelf->hmmm__DOT__MemAdrSrc));
    bufp->fullBit(oldp+7,(vlSelf->hmmm__DOT__MemDataSrc));
    bufp->fullBit(oldp+8,(vlSelf->hmmm__DOT__ALUSrcA));
    bufp->fullBit(oldp+9,(vlSelf->hmmm__DOT__ALUSrcB));
    bufp->fullIData(oldp+10,(vlSelf->hmmm__DOT__alu_op),32);
    bufp->fullIData(oldp+11,(vlSelf->hmmm__DOT__instruction_type),32);
    bufp->fullCData(oldp+12,(vlSelf->hmmm__DOT__datapath__DOT__Pc),8);
    bufp->fullCData(oldp+13,((0xffU & ((IData)(2U) 
                                       + (IData)(vlSelf->hmmm__DOT__datapath__DOT__Pc)))),8);
    bufp->fullCData(oldp+14,((0xffU & ((1U & (IData)(vlSelf->hmmm__DOT__PcSrc))
                                        ? (((0U == 
                                             (0xfU 
                                              & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                                 >> 8U)))
                                             ? 0U : 
                                            (0xffU 
                                             & (IData)(vlSelf->__VdfgTmp_h79043d9e__0))) 
                                           << 1U) : 
                                       (0x1feU & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                                  << 1U))))),8);
    bufp->fullCData(oldp+15,((0xffU & (IData)(vlSelf->hmmm__DOT__Instr))),8);
    bufp->fullCData(oldp+16,(vlSelf->hmmm__DOT__datapath__DOT__mem_data_address),8);
    bufp->fullSData(oldp+17,(((2U & (IData)(vlSelf->hmmm__DOT__RegSrc))
                               ? ((1U & (IData)(vlSelf->hmmm__DOT__RegSrc))
                                   ? (IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_result)
                                   : (0xffU & ((IData)(2U) 
                                               + (IData)(vlSelf->hmmm__DOT__datapath__DOT__Pc))))
                               : ((1U & (IData)(vlSelf->hmmm__DOT__RegSrc))
                                   ? vlSelf->hmmm__DOT__datapath__DOT__mem__DOT__RAM
                                  [vlSelf->hmmm__DOT__datapath__DOT__mem_data_address]
                                   : (0xffU & (IData)(vlSelf->hmmm__DOT__Instr))))),16);
    bufp->fullSData(oldp+18,(vlSelf->hmmm__DOT__datapath__DOT__alu_result),16);
    bufp->fullSData(oldp+19,(vlSelf->hmmm__DOT__datapath__DOT__alu_src_a),16);
    bufp->fullSData(oldp+20,(vlSelf->hmmm__DOT__datapath__DOT__alu_src_b),16);
    bufp->fullSData(oldp+21,(vlSelf->hmmm__DOT__datapath__DOT__rf_read_data_1),16);
    bufp->fullSData(oldp+22,(((0U == (0xfU & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                              >> 4U)))
                               ? 0U : (IData)(vlSelf->__VdfgTmp_h79120594__0))),16);
    bufp->fullSData(oldp+23,(((0U == (0xfU & (IData)(vlSelf->hmmm__DOT__Instr)))
                               ? 0U : vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers
                              [(0xfU & (IData)(vlSelf->hmmm__DOT__Instr))])),16);
    bufp->fullSData(oldp+24,(vlSelf->hmmm__DOT__datapath__DOT__mem__DOT__RAM
                             [vlSelf->hmmm__DOT__datapath__DOT__mem_data_address]),16);
    bufp->fullSData(oldp+25,(((IData)(vlSelf->hmmm__DOT__MemDataSrc)
                               ? (IData)(vlSelf->hmmm__DOT__datapath__DOT__rf_read_data_1)
                               : (IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_result))),16);
    bufp->fullCData(oldp+26,((0xfU & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                      >> 8U))),4);
    bufp->fullCData(oldp+27,((0xfU & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                      >> 4U))),4);
    bufp->fullCData(oldp+28,((0xfU & (IData)(vlSelf->hmmm__DOT__Instr))),4);
    bufp->fullBit(oldp+29,((0U == (IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_result))));
    bufp->fullBit(oldp+30,((1U & ((IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_result) 
                                  >> 0xfU))));
    bufp->fullSData(oldp+31,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[0]),16);
    bufp->fullSData(oldp+32,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[1]),16);
    bufp->fullSData(oldp+33,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[2]),16);
    bufp->fullSData(oldp+34,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[3]),16);
    bufp->fullSData(oldp+35,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[4]),16);
    bufp->fullSData(oldp+36,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[5]),16);
    bufp->fullSData(oldp+37,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[6]),16);
    bufp->fullSData(oldp+38,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[7]),16);
    bufp->fullSData(oldp+39,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[8]),16);
    bufp->fullSData(oldp+40,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[9]),16);
    bufp->fullSData(oldp+41,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[10]),16);
    bufp->fullSData(oldp+42,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[11]),16);
    bufp->fullSData(oldp+43,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[12]),16);
    bufp->fullSData(oldp+44,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[13]),16);
    bufp->fullSData(oldp+45,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[14]),16);
    bufp->fullSData(oldp+46,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[15]),16);
    bufp->fullIData(oldp+47,(vlSelf->hmmm__DOT__datapath__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+48,(vlSelf->hmmm__DOT__datapath__DOT__unnamedblk2__DOT__i),32);
    bufp->fullBit(oldp+49,(vlSelf->clk));
    bufp->fullBit(oldp+50,(vlSelf->reset));
    bufp->fullCData(oldp+51,(((IData)(vlSelf->reset)
                               ? 0U : (0xffU & ((2U 
                                                 & (IData)(vlSelf->hmmm__DOT__PcSrc))
                                                 ? 
                                                ((1U 
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
                                                 : 
                                                ((IData)(2U) 
                                                 + (IData)(vlSelf->hmmm__DOT__datapath__DOT__Pc)))))),8);
}
