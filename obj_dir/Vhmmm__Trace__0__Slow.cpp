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
    tracep->declBit(c+31,"clk", false,-1);
    tracep->declBit(c+32,"reset", false,-1);
    tracep->pushNamePrefix("hmmm ");
    tracep->declBit(c+31,"clk", false,-1);
    tracep->declBit(c+32,"reset", false,-1);
    tracep->declBus(c+17,"Instr", false,-1, 15,0);
    tracep->declBus(c+18,"RegSrc", false,-1, 1,0);
    tracep->declBus(c+19,"PcSrc", false,-1, 1,0);
    tracep->declBit(c+20,"MemWrite", false,-1);
    tracep->declBit(c+21,"RegWrite", false,-1);
    tracep->declBit(c+22,"MemAdrSrc", false,-1);
    tracep->declBit(c+23,"MemDataSrc", false,-1);
    tracep->declBus(c+24,"aluop", false,-1, 31,0);
    tracep->declBus(c+25,"instruction_type", false,-1, 31,0);
    tracep->pushNamePrefix("controller ");
    tracep->declBus(c+17,"instr", false,-1, 15,0);
    tracep->declBus(c+24,"aluop", false,-1, 31,0);
    tracep->declBit(c+20,"MemWrite", false,-1);
    tracep->declBit(c+21,"RegWrite", false,-1);
    tracep->declBit(c+22,"MemAdrSrc", false,-1);
    tracep->declBit(c+23,"MemDataSrc", false,-1);
    tracep->declBus(c+18,"RegSrc", false,-1, 1,0);
    tracep->declBus(c+19,"PcSrc", false,-1, 1,0);
    tracep->declBus(c+25,"instruction_type", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("datapath ");
    tracep->declBit(c+31,"clk", false,-1);
    tracep->declBit(c+32,"reset", false,-1);
    tracep->declBit(c+20,"MemWrite", false,-1);
    tracep->declBit(c+21,"RegWrite", false,-1);
    tracep->declBit(c+22,"MemAdrSrc", false,-1);
    tracep->declBit(c+23,"MemDataSrc", false,-1);
    tracep->declBus(c+19,"PcSrc", false,-1, 1,0);
    tracep->declBus(c+18,"RegSrc", false,-1, 1,0);
    tracep->declBus(c+25,"instruction_type", false,-1, 31,0);
    tracep->declBus(c+17,"Instr", false,-1, 15,0);
    tracep->declBus(c+26,"Pc", false,-1, 7,0);
    tracep->declBus(c+33,"PcNext", false,-1, 7,0);
    tracep->declBus(c+34,"PcTarget", false,-1, 7,0);
    tracep->declBus(c+27,"Imm", false,-1, 7,0);
    tracep->declBus(c+35,"MemDataAddress", false,-1, 7,0);
    tracep->declBus(c+36,"Result", false,-1, 15,0);
    tracep->declBus(c+42,"ALUResult", false,-1, 15,0);
    tracep->declBus(c+43,"SrcA", false,-1, 15,0);
    tracep->declBus(c+37,"rf_read_data_1", false,-1, 15,0);
    tracep->declBus(c+38,"rf_read_data_2", false,-1, 15,0);
    tracep->declBus(c+39,"rf_read_data_3", false,-1, 15,0);
    tracep->declBus(c+40,"mem_read_data", false,-1, 15,0);
    tracep->declBus(c+41,"mem_write_data", false,-1, 15,0);
    tracep->declBus(c+28,"rX", false,-1, 3,0);
    tracep->declBus(c+29,"rY", false,-1, 3,0);
    tracep->declBus(c+30,"rZ", false,-1, 3,0);
    tracep->pushNamePrefix("mem ");
    tracep->declBit(c+31,"clk", false,-1);
    tracep->declBit(c+44,"write_en", false,-1);
    tracep->declBus(c+26,"instruction_address", false,-1, 7,0);
    tracep->declBus(c+35,"data_address", false,-1, 7,0);
    tracep->declBus(c+42,"write_data", false,-1, 15,0);
    tracep->declBus(c+17,"instruction_data", false,-1, 15,0);
    tracep->declBus(c+40,"read_data", false,-1, 15,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("rf ");
    tracep->declBit(c+31,"clk", false,-1);
    tracep->declBus(c+28,"address_1", false,-1, 3,0);
    tracep->declBus(c+29,"address_2", false,-1, 3,0);
    tracep->declBus(c+30,"address_3", false,-1, 3,0);
    tracep->declBit(c+21,"write_en_1", false,-1);
    tracep->declBus(c+36,"write_data_1", false,-1, 15,0);
    tracep->declBus(c+37,"read_data_1", false,-1, 15,0);
    tracep->declBus(c+38,"read_data_2", false,-1, 15,0);
    tracep->declBus(c+39,"read_data_3", false,-1, 15,0);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+1+i*1,"registers", true,(i+0), 15,0);
    }
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
    bufp->fullSData(oldp+1,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[0]),16);
    bufp->fullSData(oldp+2,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[1]),16);
    bufp->fullSData(oldp+3,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[2]),16);
    bufp->fullSData(oldp+4,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[3]),16);
    bufp->fullSData(oldp+5,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[4]),16);
    bufp->fullSData(oldp+6,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[5]),16);
    bufp->fullSData(oldp+7,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[6]),16);
    bufp->fullSData(oldp+8,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[7]),16);
    bufp->fullSData(oldp+9,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[8]),16);
    bufp->fullSData(oldp+10,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[9]),16);
    bufp->fullSData(oldp+11,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[10]),16);
    bufp->fullSData(oldp+12,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[11]),16);
    bufp->fullSData(oldp+13,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[12]),16);
    bufp->fullSData(oldp+14,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[13]),16);
    bufp->fullSData(oldp+15,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[14]),16);
    bufp->fullSData(oldp+16,(vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[15]),16);
    bufp->fullSData(oldp+17,(vlSelf->hmmm__DOT__Instr),16);
    bufp->fullCData(oldp+18,(vlSelf->hmmm__DOT__RegSrc),2);
    bufp->fullCData(oldp+19,(vlSelf->hmmm__DOT__PcSrc),2);
    bufp->fullBit(oldp+20,(vlSelf->hmmm__DOT__MemWrite));
    bufp->fullBit(oldp+21,(vlSelf->hmmm__DOT__RegWrite));
    bufp->fullBit(oldp+22,(vlSelf->hmmm__DOT__MemAdrSrc));
    bufp->fullBit(oldp+23,(vlSelf->hmmm__DOT__MemDataSrc));
    bufp->fullIData(oldp+24,(vlSelf->hmmm__DOT__aluop),32);
    bufp->fullIData(oldp+25,(vlSelf->hmmm__DOT__instruction_type),32);
    bufp->fullCData(oldp+26,(vlSelf->hmmm__DOT__datapath__DOT__Pc),8);
    bufp->fullCData(oldp+27,((0xffU & (IData)(vlSelf->hmmm__DOT__Instr))),8);
    bufp->fullCData(oldp+28,((0xfU & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                      >> 8U))),4);
    bufp->fullCData(oldp+29,((0xfU & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                      >> 4U))),4);
    bufp->fullCData(oldp+30,((0xfU & (IData)(vlSelf->hmmm__DOT__Instr))),4);
    bufp->fullBit(oldp+31,(vlSelf->clk));
    bufp->fullBit(oldp+32,(vlSelf->reset));
    bufp->fullCData(oldp+33,(vlSelf->hmmm__DOT__datapath__DOT__PcNext),8);
    bufp->fullCData(oldp+34,((0xffU & ((1U & (IData)(vlSelf->hmmm__DOT__PcSrc))
                                        ? (0x1feU & 
                                           ((IData)(vlSelf->hmmm__DOT__Instr) 
                                            << 1U))
                                        : (((0U == 
                                             (0xfU 
                                              & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                                 >> 8U)))
                                             ? 0U : 
                                            (0xffU 
                                             & (IData)(vlSelf->__VdfgTmp_h79043d9e__0))) 
                                           << 1U)))),8);
    bufp->fullCData(oldp+35,((0xffU & ((IData)(vlSelf->hmmm__DOT__MemAdrSrc)
                                        ? ((0U == (0xfU 
                                                   & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                                      >> 4U)))
                                            ? 0U : 
                                           vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers
                                           [(0xfU & 
                                             ((IData)(vlSelf->hmmm__DOT__Instr) 
                                              >> 4U))])
                                        : (IData)(vlSelf->hmmm__DOT__Instr)))),8);
    bufp->fullSData(oldp+36,(((0U == (IData)(vlSelf->hmmm__DOT__RegSrc))
                               ? vlSelf->hmmm__DOT__datapath__DOT__mem__DOT__RAM
                              [(0xffU & ((IData)(vlSelf->hmmm__DOT__MemAdrSrc)
                                          ? ((0U == 
                                              (0xfU 
                                               & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                                  >> 4U)))
                                              ? 0U : 
                                             vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers
                                             [(0xfU 
                                               & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                                  >> 4U))])
                                          : (IData)(vlSelf->hmmm__DOT__Instr)))]
                               : ((1U == (IData)(vlSelf->hmmm__DOT__RegSrc))
                                   ? (0xffU & (IData)(vlSelf->hmmm__DOT__Instr))
                                   : ((3U == (IData)(vlSelf->hmmm__DOT__RegSrc))
                                       ? (IData)(vlSelf->hmmm__DOT__datapath__DOT__PcNext)
                                       : 0U)))),16);
    bufp->fullSData(oldp+37,(((0U == (0xfU & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                              >> 8U)))
                               ? 0U : (IData)(vlSelf->__VdfgTmp_h79043d9e__0))),16);
    bufp->fullSData(oldp+38,(((0U == (0xfU & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                              >> 4U)))
                               ? 0U : vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers
                              [(0xfU & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                        >> 4U))])),16);
    bufp->fullSData(oldp+39,(((0U == (0xfU & (IData)(vlSelf->hmmm__DOT__Instr)))
                               ? 0U : vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers
                              [(0xfU & (IData)(vlSelf->hmmm__DOT__Instr))])),16);
    bufp->fullSData(oldp+40,(vlSelf->hmmm__DOT__datapath__DOT__mem__DOT__RAM
                             [(0xffU & ((IData)(vlSelf->hmmm__DOT__MemAdrSrc)
                                         ? ((0U == 
                                             (0xfU 
                                              & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                                 >> 4U)))
                                             ? 0U : 
                                            vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers
                                            [(0xfU 
                                              & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                                 >> 4U))])
                                         : (IData)(vlSelf->hmmm__DOT__Instr)))]),16);
    bufp->fullSData(oldp+41,(((IData)(vlSelf->hmmm__DOT__MemDataSrc)
                               ? ((0U == (0xfU & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                                  >> 8U)))
                                   ? 0U : (IData)(vlSelf->__VdfgTmp_h79043d9e__0))
                               : 0U)),16);
    bufp->fullSData(oldp+42,(0U),16);
    bufp->fullSData(oldp+43,(vlSelf->hmmm__DOT__datapath__DOT__SrcA),16);
    bufp->fullBit(oldp+44,(0U));
}
