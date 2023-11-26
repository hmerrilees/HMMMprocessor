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
    tracep->declBit(c+52,"clk", false,-1);
    tracep->declBit(c+53,"reset", false,-1);
    tracep->pushNamePrefix("hmmm ");
    tracep->declBit(c+52,"clk", false,-1);
    tracep->declBit(c+53,"reset", false,-1);
    tracep->declBus(c+1,"Instr", false,-1, 15,0);
    tracep->declBus(c+2,"RegSrcX", false,-1, 1,0);
    tracep->declBus(c+3,"PcSrc", false,-1, 1,0);
    tracep->declBus(c+4,"MemAdrSrc", false,-1, 1,0);
    tracep->declBus(c+5,"ALUSrcB", false,-1, 1,0);
    tracep->declBit(c+6,"MemWrite", false,-1);
    tracep->declBit(c+7,"RegWriteX", false,-1);
    tracep->declBit(c+8,"RegWriteY", false,-1);
    tracep->declBit(c+9,"MemDataSrc", false,-1);
    tracep->declBit(c+10,"ALUSrcA", false,-1);
    tracep->declBus(c+11,"alu_op", false,-1, 31,0);
    tracep->declBus(c+12,"instruction_type", false,-1, 31,0);
    tracep->pushNamePrefix("controller ");
    tracep->declBus(c+1,"instr", false,-1, 15,0);
    tracep->declBus(c+11,"alu_op", false,-1, 31,0);
    tracep->declBit(c+6,"MemWrite", false,-1);
    tracep->declBit(c+7,"RegWriteX", false,-1);
    tracep->declBit(c+8,"RegWriteY", false,-1);
    tracep->declBit(c+9,"MemDataSrc", false,-1);
    tracep->declBit(c+10,"ALUSrcA", false,-1);
    tracep->declBus(c+2,"RegSrcX", false,-1, 1,0);
    tracep->declBus(c+5,"ALUSrcB", false,-1, 1,0);
    tracep->declBus(c+4,"MemAdrSrc", false,-1, 1,0);
    tracep->declBus(c+3,"PcSrc", false,-1, 1,0);
    tracep->declBus(c+12,"instruction_type", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("datapath ");
    tracep->declBit(c+52,"clk", false,-1);
    tracep->declBit(c+53,"reset", false,-1);
    tracep->declBit(c+6,"MemWrite", false,-1);
    tracep->declBit(c+7,"RegWriteX", false,-1);
    tracep->declBit(c+8,"RegWriteY", false,-1);
    tracep->declBit(c+9,"MemDataSrc", false,-1);
    tracep->declBit(c+10,"ALUSrcA", false,-1);
    tracep->declBus(c+3,"PcSrc", false,-1, 1,0);
    tracep->declBus(c+5,"ALUSrcB", false,-1, 1,0);
    tracep->declBus(c+2,"RegSrcX", false,-1, 1,0);
    tracep->declBus(c+4,"MemAdrSrc", false,-1, 1,0);
    tracep->declBus(c+12,"instruction_type", false,-1, 31,0);
    tracep->declBus(c+11,"alu_op", false,-1, 31,0);
    tracep->declBus(c+1,"Instr", false,-1, 15,0);
    tracep->declBus(c+13,"Pc", false,-1, 7,0);
    tracep->declBus(c+14,"PcPlus2", false,-1, 7,0);
    tracep->declBus(c+54,"PcNext", false,-1, 7,0);
    tracep->declBus(c+15,"PcTarget", false,-1, 7,0);
    tracep->declBus(c+16,"Imm", false,-1, 7,0);
    tracep->declBus(c+17,"mem_data_address", false,-1, 7,0);
    tracep->declBus(c+55,"result", false,-1, 15,0);
    tracep->declBus(c+18,"alu_result", false,-1, 15,0);
    tracep->declBus(c+19,"alu_src_a", false,-1, 15,0);
    tracep->declBus(c+20,"alu_src_b", false,-1, 15,0);
    tracep->declBus(c+21,"rf_read_data_1", false,-1, 15,0);
    tracep->declBus(c+22,"rf_read_data_2", false,-1, 15,0);
    tracep->declBus(c+23,"rf_read_data_3", false,-1, 15,0);
    tracep->declBus(c+24,"rf_write_data_1", false,-1, 15,0);
    tracep->declBus(c+18,"rf_write_data_2", false,-1, 15,0);
    tracep->declBus(c+25,"mem_read_data", false,-1, 15,0);
    tracep->declBus(c+26,"mem_write_data", false,-1, 15,0);
    tracep->declBus(c+27,"rX", false,-1, 3,0);
    tracep->declBus(c+28,"rY", false,-1, 3,0);
    tracep->declBus(c+29,"rZ", false,-1, 3,0);
    tracep->declBit(c+30,"zero", false,-1);
    tracep->declBit(c+31,"sign", false,-1);
    tracep->declBit(c+32,"take_jump", false,-1);
    tracep->declBus(c+33,"imm_ext", false,-1, 15,0);
    tracep->pushNamePrefix("alu ");
    tracep->declBus(c+11,"alu_op", false,-1, 31,0);
    tracep->declBus(c+19,"src_a", false,-1, 15,0);
    tracep->declBus(c+20,"src_b", false,-1, 15,0);
    tracep->declBus(c+18,"alu_result", false,-1, 15,0);
    tracep->declBit(c+30,"zero", false,-1);
    tracep->declBit(c+31,"sign", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("mem ");
    tracep->declBit(c+52,"clk", false,-1);
    tracep->declBit(c+6,"write_en", false,-1);
    tracep->declBus(c+13,"instruction_address", false,-1, 7,0);
    tracep->declBus(c+17,"data_address", false,-1, 7,0);
    tracep->declBus(c+26,"write_data", false,-1, 15,0);
    tracep->declBus(c+1,"instruction_data", false,-1, 15,0);
    tracep->declBus(c+25,"read_data", false,-1, 15,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("rf ");
    tracep->declBit(c+52,"clk", false,-1);
    tracep->declBus(c+27,"address_1", false,-1, 3,0);
    tracep->declBus(c+28,"address_2", false,-1, 3,0);
    tracep->declBus(c+29,"address_3", false,-1, 3,0);
    tracep->declBit(c+7,"write_en_1", false,-1);
    tracep->declBit(c+8,"write_en_2", false,-1);
    tracep->declBus(c+24,"write_data_1", false,-1, 15,0);
    tracep->declBus(c+18,"write_data_2", false,-1, 15,0);
    tracep->declBus(c+21,"read_data_1", false,-1, 15,0);
    tracep->declBus(c+22,"read_data_2", false,-1, 15,0);
    tracep->declBus(c+23,"read_data_3", false,-1, 15,0);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+34+i*1,"registers", true,(i+0), 15,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBus(c+50,"i", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->declBus(c+51,"i", false,-1, 31,0);
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
    bufp->fullCData(oldp+2,(vlSelf->hmmm__DOT__RegSrcX),2);
    bufp->fullCData(oldp+3,(vlSelf->hmmm__DOT__PcSrc),2);
    bufp->fullCData(oldp+4,(vlSelf->hmmm__DOT__MemAdrSrc),2);
    bufp->fullCData(oldp+5,(vlSelf->hmmm__DOT__ALUSrcB),2);
    bufp->fullBit(oldp+6,(vlSelf->hmmm__DOT__MemWrite));
    bufp->fullBit(oldp+7,(vlSelf->hmmm__DOT__RegWriteX));
    bufp->fullBit(oldp+8,(vlSelf->hmmm__DOT__RegWriteY));
    bufp->fullBit(oldp+9,(vlSelf->hmmm__DOT__MemDataSrc));
    bufp->fullBit(oldp+10,(vlSelf->hmmm__DOT__ALUSrcA));
    bufp->fullIData(oldp+11,(vlSelf->hmmm__DOT__alu_op),32);
    bufp->fullIData(oldp+12,(vlSelf->hmmm__DOT__instruction_type),32);
    bufp->fullCData(oldp+13,(vlSelf->hmmm__DOT__datapath__DOT__Pc),8);
    bufp->fullCData(oldp+14,((0xffU & ((IData)(2U) 
                                       + (IData)(vlSelf->hmmm__DOT__datapath__DOT__Pc)))),8);
    bufp->fullCData(oldp+15,((0xffU & ((1U & (IData)(vlSelf->hmmm__DOT__PcSrc))
                                        ? ((0U == (0xfU 
                                                   & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                                      >> 8U)))
                                            ? 0U : (IData)(vlSelf->__VdfgTmp_h79043d9e__0))
                                        : ((IData)(vlSelf->hmmm__DOT__Instr) 
                                           << 1U)))),8);
    bufp->fullCData(oldp+16,((0xffU & (IData)(vlSelf->hmmm__DOT__Instr))),8);
    bufp->fullCData(oldp+17,(vlSelf->hmmm__DOT__datapath__DOT__mem_data_address),8);
    bufp->fullSData(oldp+18,(vlSelf->hmmm__DOT__datapath__DOT__alu_result),16);
    bufp->fullSData(oldp+19,(vlSelf->hmmm__DOT__datapath__DOT__alu_src_a),16);
    bufp->fullSData(oldp+20,(vlSelf->hmmm__DOT__datapath__DOT__alu_src_b),16);
    bufp->fullSData(oldp+21,(vlSelf->hmmm__DOT__datapath__DOT__rf_read_data_1),16);
    bufp->fullSData(oldp+22,(vlSelf->hmmm__DOT__datapath__DOT__rf_read_data_2),16);
    bufp->fullSData(oldp+23,(((0U == (0xfU & (IData)(vlSelf->hmmm__DOT__Instr)))
                               ? 0U : vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers
                              [(0xfU & (IData)(vlSelf->hmmm__DOT__Instr))])),16);
    bufp->fullSData(oldp+24,(((2U & (IData)(vlSelf->hmmm__DOT__RegSrcX))
                               ? ((1U & (IData)(vlSelf->hmmm__DOT__RegSrcX))
                                   ? (IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_result)
                                   : (0xffU & ((IData)(2U) 
                                               + (IData)(vlSelf->hmmm__DOT__datapath__DOT__Pc))))
                               : ((1U & (IData)(vlSelf->hmmm__DOT__RegSrcX))
                                   ? vlSelf->hmmm__DOT__datapath__DOT__mem__DOT__RAM
                                  [vlSelf->hmmm__DOT__datapath__DOT__mem_data_address]
                                   : (IData)(vlSelf->hmmm__DOT__datapath__DOT__imm_ext)))),16);
    bufp->fullSData(oldp+25,(vlSelf->hmmm__DOT__datapath__DOT__mem__DOT__RAM
                             [vlSelf->hmmm__DOT__datapath__DOT__mem_data_address]),16);
    bufp->fullSData(oldp+26,(((IData)(vlSelf->hmmm__DOT__MemDataSrc)
                               ? (IData)(vlSelf->hmmm__DOT__datapath__DOT__rf_read_data_1)
                               : (IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_result))),16);
    bufp->fullCData(oldp+27,((0xfU & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                      >> 8U))),4);
    bufp->fullCData(oldp+28,((0xfU & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                      >> 4U))),4);
    bufp->fullCData(oldp+29,((0xfU & (IData)(vlSelf->hmmm__DOT__Instr))),4);
    bufp->fullBit(oldp+30,((0U == (IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_result))));
    bufp->fullBit(oldp+31,((1U & ((IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_result) 
                                  >> 0xfU))));
    bufp->fullBit(oldp+32,((1U & ((0x15U == vlSelf->hmmm__DOT__instruction_type)
                                   ? (0U == (IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_result))
                                   : ((0x16U == vlSelf->hmmm__DOT__instruction_type)
                                       ? (0U != (IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_result))
                                       : ((0x17U == vlSelf->hmmm__DOT__instruction_type)
                                           ? ((~ ((IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_result) 
                                                  >> 0xfU)) 
                                              & (0U 
                                                 != (IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_result)))
                                           : ((0x18U 
                                               != vlSelf->hmmm__DOT__instruction_type) 
                                              | ((IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_result) 
                                                 >> 0xfU))))))));
    bufp->fullSData(oldp+33,(vlSelf->hmmm__DOT__datapath__DOT__imm_ext),16);
    bufp->fullSData(oldp+34,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[0]),16);
    bufp->fullSData(oldp+35,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[1]),16);
    bufp->fullSData(oldp+36,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[2]),16);
    bufp->fullSData(oldp+37,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[3]),16);
    bufp->fullSData(oldp+38,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[4]),16);
    bufp->fullSData(oldp+39,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[5]),16);
    bufp->fullSData(oldp+40,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[6]),16);
    bufp->fullSData(oldp+41,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[7]),16);
    bufp->fullSData(oldp+42,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[8]),16);
    bufp->fullSData(oldp+43,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[9]),16);
    bufp->fullSData(oldp+44,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[10]),16);
    bufp->fullSData(oldp+45,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[11]),16);
    bufp->fullSData(oldp+46,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[12]),16);
    bufp->fullSData(oldp+47,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[13]),16);
    bufp->fullSData(oldp+48,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[14]),16);
    bufp->fullSData(oldp+49,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[15]),16);
    bufp->fullIData(oldp+50,(vlSelf->hmmm__DOT__datapath__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+51,(vlSelf->hmmm__DOT__datapath__DOT__unnamedblk2__DOT__i),32);
    bufp->fullBit(oldp+52,(vlSelf->clk));
    bufp->fullBit(oldp+53,(vlSelf->reset));
    bufp->fullCData(oldp+54,(((IData)(vlSelf->reset)
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
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlSelf->hmmm__DOT__PcSrc))
                                                  ? 
                                                 ((0U 
                                                   == 
                                                   (0xfU 
                                                    & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                                       >> 8U)))
                                                   ? 0U
                                                   : (IData)(vlSelf->__VdfgTmp_h79043d9e__0))
                                                  : 
                                                 ((IData)(vlSelf->hmmm__DOT__Instr) 
                                                  << 1U))
                                                 : 
                                                ((IData)(2U) 
                                                 + (IData)(vlSelf->hmmm__DOT__datapath__DOT__Pc)))))),8);
    bufp->fullSData(oldp+55,(vlSelf->hmmm__DOT__datapath__DOT__result),16);
}
