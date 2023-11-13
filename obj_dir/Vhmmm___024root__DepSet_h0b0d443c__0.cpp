// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vhmmm.h for the primary calling header

#include "verilated.h"

#include "Vhmmm__Syms.h"
#include "Vhmmm___024root.h"

VL_INLINE_OPT void Vhmmm___024root___ico_sequent__TOP__0(Vhmmm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhmmm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhmmm___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->hmmm__DOT__datapath__DOT__PcNext = ((IData)(vlSelf->reset)
                                                 ? 0U
                                                 : 
                                                (0xffU 
                                                 & ((2U 
                                                     & (IData)(vlSelf->hmmm__DOT__PcSrc))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlSelf->hmmm__DOT__PcSrc))
                                                      ? 
                                                     (0x1feU 
                                                      & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                                         << 1U))
                                                      : 
                                                     (((0U 
                                                        == 
                                                        (0xfU 
                                                         & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                                            >> 8U)))
                                                        ? 0U
                                                        : 
                                                       (0xffU 
                                                        & (IData)(vlSelf->__VdfgTmp_h79043d9e__0))) 
                                                      << 1U))
                                                     : 
                                                    ((IData)(2U) 
                                                     + (IData)(vlSelf->hmmm__DOT__datapath__DOT__Pc)))));
}

void Vhmmm___024root___eval_ico(Vhmmm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhmmm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhmmm___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vhmmm___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vhmmm___024root___eval_act(Vhmmm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhmmm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhmmm___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vhmmm___024root___nba_sequent__TOP__0(Vhmmm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhmmm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhmmm___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*3:0*/ __Vdlyvdim0__hmmm__DOT__datapath__DOT__rf__DOT__registers__v0;
    __Vdlyvdim0__hmmm__DOT__datapath__DOT__rf__DOT__registers__v0 = 0;
    SData/*15:0*/ __Vdlyvval__hmmm__DOT__datapath__DOT__rf__DOT__registers__v0;
    __Vdlyvval__hmmm__DOT__datapath__DOT__rf__DOT__registers__v0 = 0;
    CData/*0:0*/ __Vdlyvset__hmmm__DOT__datapath__DOT__rf__DOT__registers__v0;
    __Vdlyvset__hmmm__DOT__datapath__DOT__rf__DOT__registers__v0 = 0;
    // Body
    __Vdlyvset__hmmm__DOT__datapath__DOT__rf__DOT__registers__v0 = 0U;
    VL_WRITEF("instruction_address: %x\ninstruction: %x\n",
              8,vlSelf->hmmm__DOT__datapath__DOT__Pc,
              16,(IData)(vlSelf->hmmm__DOT__Instr));
    if (VL_UNLIKELY((3U == vlSelf->hmmm__DOT__instruction_type))) {
        VL_WRITEF("write: %b\n",16,((0U == (0xfU & 
                                            ((IData)(vlSelf->hmmm__DOT__Instr) 
                                             >> 8U)))
                                     ? 0U : (IData)(vlSelf->__VdfgTmp_h79043d9e__0)));
    } else if (VL_UNLIKELY((0U == vlSelf->hmmm__DOT__instruction_type))) {
        VL_WRITEF("halt\n");
        VL_FINISH_MT("hmmm.sv", 327, "");
    }
    if (vlSelf->hmmm__DOT__RegWrite) {
        __Vdlyvval__hmmm__DOT__datapath__DOT__rf__DOT__registers__v0 
            = ((0U == (IData)(vlSelf->hmmm__DOT__RegSrc))
                ? vlSelf->hmmm__DOT__datapath__DOT__mem__DOT__RAM
               [(0xffU & ((IData)(vlSelf->hmmm__DOT__MemAdrSrc)
                           ? ((0U == (0xfU & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                              >> 4U)))
                               ? 0U : (IData)(vlSelf->__VdfgTmp_h79120594__0))
                           : (IData)(vlSelf->hmmm__DOT__Instr)))]
                : ((1U == (IData)(vlSelf->hmmm__DOT__RegSrc))
                    ? (0xffU & (IData)(vlSelf->hmmm__DOT__Instr))
                    : ((3U == (IData)(vlSelf->hmmm__DOT__RegSrc))
                        ? (IData)(vlSelf->hmmm__DOT__datapath__DOT__PcNext)
                        : 0U)));
        __Vdlyvset__hmmm__DOT__datapath__DOT__rf__DOT__registers__v0 = 1U;
        __Vdlyvdim0__hmmm__DOT__datapath__DOT__rf__DOT__registers__v0 
            = (0xfU & ((IData)(vlSelf->hmmm__DOT__Instr) 
                       >> 8U));
    }
    if (__Vdlyvset__hmmm__DOT__datapath__DOT__rf__DOT__registers__v0) {
        vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[__Vdlyvdim0__hmmm__DOT__datapath__DOT__rf__DOT__registers__v0] 
            = __Vdlyvval__hmmm__DOT__datapath__DOT__rf__DOT__registers__v0;
    }
}

VL_INLINE_OPT void Vhmmm___024root___nba_sequent__TOP__1(Vhmmm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhmmm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhmmm___024root___nba_sequent__TOP__1\n"); );
    // Body
    vlSelf->hmmm__DOT__datapath__DOT__Pc = vlSelf->hmmm__DOT__datapath__DOT__PcNext;
    vlSelf->hmmm__DOT__Instr = vlSelf->hmmm__DOT__datapath__DOT__mem__DOT__RAM
        [(0xffU & ((IData)(vlSelf->hmmm__DOT__datapath__DOT__Pc) 
                   >> 1U))];
    vlSelf->hmmm__DOT__instruction_type = ((0x8000U 
                                            & (IData)(vlSelf->hmmm__DOT__Instr))
                                            ? ((0x4000U 
                                                & (IData)(vlSelf->hmmm__DOT__Instr))
                                                ? (
                                                   (0x2000U 
                                                    & (IData)(vlSelf->hmmm__DOT__Instr))
                                                    ? 
                                                   ((0x1000U 
                                                     & (IData)(vlSelf->hmmm__DOT__Instr))
                                                     ? 0x16U
                                                     : 0x15U)
                                                    : 
                                                   ((0x1000U 
                                                     & (IData)(vlSelf->hmmm__DOT__Instr))
                                                     ? 0x14U
                                                     : 0x13U))
                                                : (
                                                   (0x2000U 
                                                    & (IData)(vlSelf->hmmm__DOT__Instr))
                                                    ? 
                                                   ((0x1000U 
                                                     & (IData)(vlSelf->hmmm__DOT__Instr))
                                                     ? 
                                                    ((0x800U 
                                                      & (IData)(vlSelf->hmmm__DOT__Instr))
                                                      ? 
                                                     ((0x80U 
                                                       & (IData)(vlSelf->hmmm__DOT__Instr))
                                                       ? 1U
                                                       : 
                                                      ((0x40U 
                                                        & (IData)(vlSelf->hmmm__DOT__Instr))
                                                        ? 1U
                                                        : 
                                                       ((0x20U 
                                                         & (IData)(vlSelf->hmmm__DOT__Instr))
                                                         ? 1U
                                                         : 
                                                        ((0x10U 
                                                          & (IData)(vlSelf->hmmm__DOT__Instr))
                                                          ? 1U
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlSelf->hmmm__DOT__Instr))
                                                           ? 1U
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlSelf->hmmm__DOT__Instr))
                                                            ? 1U
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlSelf->hmmm__DOT__Instr))
                                                             ? 1U
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlSelf->hmmm__DOT__Instr))
                                                              ? 1U
                                                              : 0x17U))))))))
                                                      : 
                                                     ((0x400U 
                                                       & (IData)(vlSelf->hmmm__DOT__Instr))
                                                       ? 
                                                      ((0x80U 
                                                        & (IData)(vlSelf->hmmm__DOT__Instr))
                                                        ? 1U
                                                        : 
                                                       ((0x40U 
                                                         & (IData)(vlSelf->hmmm__DOT__Instr))
                                                         ? 1U
                                                         : 
                                                        ((0x20U 
                                                          & (IData)(vlSelf->hmmm__DOT__Instr))
                                                          ? 1U
                                                          : 
                                                         ((0x10U 
                                                           & (IData)(vlSelf->hmmm__DOT__Instr))
                                                           ? 1U
                                                           : 
                                                          ((8U 
                                                            & (IData)(vlSelf->hmmm__DOT__Instr))
                                                            ? 1U
                                                            : 
                                                           ((4U 
                                                             & (IData)(vlSelf->hmmm__DOT__Instr))
                                                             ? 1U
                                                             : 
                                                            ((2U 
                                                              & (IData)(vlSelf->hmmm__DOT__Instr))
                                                              ? 1U
                                                              : 
                                                             ((1U 
                                                               & (IData)(vlSelf->hmmm__DOT__Instr))
                                                               ? 1U
                                                               : 0x17U))))))))
                                                       : 
                                                      ((0x200U 
                                                        & (IData)(vlSelf->hmmm__DOT__Instr))
                                                        ? 
                                                       ((0x80U 
                                                         & (IData)(vlSelf->hmmm__DOT__Instr))
                                                         ? 1U
                                                         : 
                                                        ((0x40U 
                                                          & (IData)(vlSelf->hmmm__DOT__Instr))
                                                          ? 1U
                                                          : 
                                                         ((0x20U 
                                                           & (IData)(vlSelf->hmmm__DOT__Instr))
                                                           ? 1U
                                                           : 
                                                          ((0x10U 
                                                            & (IData)(vlSelf->hmmm__DOT__Instr))
                                                            ? 1U
                                                            : 
                                                           ((8U 
                                                             & (IData)(vlSelf->hmmm__DOT__Instr))
                                                             ? 1U
                                                             : 
                                                            ((4U 
                                                              & (IData)(vlSelf->hmmm__DOT__Instr))
                                                              ? 1U
                                                              : 
                                                             ((2U 
                                                               & (IData)(vlSelf->hmmm__DOT__Instr))
                                                               ? 1U
                                                               : 
                                                              ((1U 
                                                                & (IData)(vlSelf->hmmm__DOT__Instr))
                                                                ? 1U
                                                                : 0x17U))))))))
                                                        : 
                                                       ((0x100U 
                                                         & (IData)(vlSelf->hmmm__DOT__Instr))
                                                         ? 
                                                        ((0x80U 
                                                          & (IData)(vlSelf->hmmm__DOT__Instr))
                                                          ? 1U
                                                          : 
                                                         ((0x40U 
                                                           & (IData)(vlSelf->hmmm__DOT__Instr))
                                                           ? 1U
                                                           : 
                                                          ((0x20U 
                                                            & (IData)(vlSelf->hmmm__DOT__Instr))
                                                            ? 1U
                                                            : 
                                                           ((0x10U 
                                                             & (IData)(vlSelf->hmmm__DOT__Instr))
                                                             ? 1U
                                                             : 
                                                            ((8U 
                                                              & (IData)(vlSelf->hmmm__DOT__Instr))
                                                              ? 1U
                                                              : 
                                                             ((4U 
                                                               & (IData)(vlSelf->hmmm__DOT__Instr))
                                                               ? 1U
                                                               : 
                                                              ((2U 
                                                                & (IData)(vlSelf->hmmm__DOT__Instr))
                                                                ? 1U
                                                                : 
                                                               ((1U 
                                                                 & (IData)(vlSelf->hmmm__DOT__Instr))
                                                                 ? 1U
                                                                 : 0x17U))))))))
                                                         : 0x12U))))
                                                     : 0x10U)
                                                    : 
                                                   ((0x1000U 
                                                     & (IData)(vlSelf->hmmm__DOT__Instr))
                                                     ? 0xfU
                                                     : 0xeU)))
                                            : ((0x4000U 
                                                & (IData)(vlSelf->hmmm__DOT__Instr))
                                                ? (
                                                   (0x2000U 
                                                    & (IData)(vlSelf->hmmm__DOT__Instr))
                                                    ? 
                                                   ((0x1000U 
                                                     & (IData)(vlSelf->hmmm__DOT__Instr))
                                                     ? 0xdU
                                                     : 0xcU)
                                                    : 
                                                   ((0x1000U 
                                                     & (IData)(vlSelf->hmmm__DOT__Instr))
                                                     ? 0xbU
                                                     : 
                                                    ((8U 
                                                      & (IData)(vlSelf->hmmm__DOT__Instr))
                                                      ? 1U
                                                      : 
                                                     ((4U 
                                                       & (IData)(vlSelf->hmmm__DOT__Instr))
                                                       ? 1U
                                                       : 
                                                      ((2U 
                                                        & (IData)(vlSelf->hmmm__DOT__Instr))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlSelf->hmmm__DOT__Instr))
                                                         ? 8U
                                                         : 7U)
                                                        : 
                                                       ((1U 
                                                         & (IData)(vlSelf->hmmm__DOT__Instr))
                                                         ? 6U
                                                         : 5U))))))
                                                : (
                                                   (0x2000U 
                                                    & (IData)(vlSelf->hmmm__DOT__Instr))
                                                    ? 
                                                   ((0x1000U 
                                                     & (IData)(vlSelf->hmmm__DOT__Instr))
                                                     ? 0xaU
                                                     : 9U)
                                                    : 
                                                   ((0x1000U 
                                                     & (IData)(vlSelf->hmmm__DOT__Instr))
                                                     ? 4U
                                                     : 
                                                    ((0x800U 
                                                      & (IData)(vlSelf->hmmm__DOT__Instr))
                                                      ? 
                                                     ((0x80U 
                                                       & (IData)(vlSelf->hmmm__DOT__Instr))
                                                       ? 1U
                                                       : 
                                                      ((0x40U 
                                                        & (IData)(vlSelf->hmmm__DOT__Instr))
                                                        ? 1U
                                                        : 
                                                       ((0x20U 
                                                         & (IData)(vlSelf->hmmm__DOT__Instr))
                                                         ? 1U
                                                         : 
                                                        ((0x10U 
                                                          & (IData)(vlSelf->hmmm__DOT__Instr))
                                                          ? 1U
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlSelf->hmmm__DOT__Instr))
                                                           ? 1U
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlSelf->hmmm__DOT__Instr))
                                                            ? 1U
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlSelf->hmmm__DOT__Instr))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlSelf->hmmm__DOT__Instr))
                                                              ? 0x11U
                                                              : 3U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlSelf->hmmm__DOT__Instr))
                                                              ? 2U
                                                              : 1U))))))))
                                                      : 
                                                     ((0x400U 
                                                       & (IData)(vlSelf->hmmm__DOT__Instr))
                                                       ? 
                                                      ((0x80U 
                                                        & (IData)(vlSelf->hmmm__DOT__Instr))
                                                        ? 1U
                                                        : 
                                                       ((0x40U 
                                                         & (IData)(vlSelf->hmmm__DOT__Instr))
                                                         ? 1U
                                                         : 
                                                        ((0x20U 
                                                          & (IData)(vlSelf->hmmm__DOT__Instr))
                                                          ? 1U
                                                          : 
                                                         ((0x10U 
                                                           & (IData)(vlSelf->hmmm__DOT__Instr))
                                                           ? 1U
                                                           : 
                                                          ((8U 
                                                            & (IData)(vlSelf->hmmm__DOT__Instr))
                                                            ? 1U
                                                            : 
                                                           ((4U 
                                                             & (IData)(vlSelf->hmmm__DOT__Instr))
                                                             ? 1U
                                                             : 
                                                            ((2U 
                                                              & (IData)(vlSelf->hmmm__DOT__Instr))
                                                              ? 
                                                             ((1U 
                                                               & (IData)(vlSelf->hmmm__DOT__Instr))
                                                               ? 0x11U
                                                               : 3U)
                                                              : 
                                                             ((1U 
                                                               & (IData)(vlSelf->hmmm__DOT__Instr))
                                                               ? 2U
                                                               : 1U))))))))
                                                       : 
                                                      ((0x200U 
                                                        & (IData)(vlSelf->hmmm__DOT__Instr))
                                                        ? 
                                                       ((0x80U 
                                                         & (IData)(vlSelf->hmmm__DOT__Instr))
                                                         ? 1U
                                                         : 
                                                        ((0x40U 
                                                          & (IData)(vlSelf->hmmm__DOT__Instr))
                                                          ? 1U
                                                          : 
                                                         ((0x20U 
                                                           & (IData)(vlSelf->hmmm__DOT__Instr))
                                                           ? 1U
                                                           : 
                                                          ((0x10U 
                                                            & (IData)(vlSelf->hmmm__DOT__Instr))
                                                            ? 1U
                                                            : 
                                                           ((8U 
                                                             & (IData)(vlSelf->hmmm__DOT__Instr))
                                                             ? 1U
                                                             : 
                                                            ((4U 
                                                              & (IData)(vlSelf->hmmm__DOT__Instr))
                                                              ? 1U
                                                              : 
                                                             ((2U 
                                                               & (IData)(vlSelf->hmmm__DOT__Instr))
                                                               ? 
                                                              ((1U 
                                                                & (IData)(vlSelf->hmmm__DOT__Instr))
                                                                ? 0x11U
                                                                : 3U)
                                                               : 
                                                              ((1U 
                                                                & (IData)(vlSelf->hmmm__DOT__Instr))
                                                                ? 2U
                                                                : 1U))))))))
                                                        : 
                                                       ((0x100U 
                                                         & (IData)(vlSelf->hmmm__DOT__Instr))
                                                         ? 
                                                        ((0x80U 
                                                          & (IData)(vlSelf->hmmm__DOT__Instr))
                                                          ? 1U
                                                          : 
                                                         ((0x40U 
                                                           & (IData)(vlSelf->hmmm__DOT__Instr))
                                                           ? 1U
                                                           : 
                                                          ((0x20U 
                                                            & (IData)(vlSelf->hmmm__DOT__Instr))
                                                            ? 1U
                                                            : 
                                                           ((0x10U 
                                                             & (IData)(vlSelf->hmmm__DOT__Instr))
                                                             ? 1U
                                                             : 
                                                            ((8U 
                                                              & (IData)(vlSelf->hmmm__DOT__Instr))
                                                              ? 1U
                                                              : 
                                                             ((4U 
                                                               & (IData)(vlSelf->hmmm__DOT__Instr))
                                                               ? 1U
                                                               : 
                                                              ((2U 
                                                                & (IData)(vlSelf->hmmm__DOT__Instr))
                                                                ? 
                                                               ((1U 
                                                                 & (IData)(vlSelf->hmmm__DOT__Instr))
                                                                 ? 0x11U
                                                                 : 3U)
                                                                : 
                                                               ((1U 
                                                                 & (IData)(vlSelf->hmmm__DOT__Instr))
                                                                 ? 2U
                                                                 : 1U))))))))
                                                         : 
                                                        ((0x80U 
                                                          & (IData)(vlSelf->hmmm__DOT__Instr))
                                                          ? 1U
                                                          : 
                                                         ((0x40U 
                                                           & (IData)(vlSelf->hmmm__DOT__Instr))
                                                           ? 1U
                                                           : 
                                                          ((0x20U 
                                                            & (IData)(vlSelf->hmmm__DOT__Instr))
                                                            ? 1U
                                                            : 
                                                           ((0x10U 
                                                             & (IData)(vlSelf->hmmm__DOT__Instr))
                                                             ? 1U
                                                             : 
                                                            ((8U 
                                                              & (IData)(vlSelf->hmmm__DOT__Instr))
                                                              ? 1U
                                                              : 
                                                             ((4U 
                                                               & (IData)(vlSelf->hmmm__DOT__Instr))
                                                               ? 1U
                                                               : 
                                                              ((2U 
                                                                & (IData)(vlSelf->hmmm__DOT__Instr))
                                                                ? 
                                                               ((1U 
                                                                 & (IData)(vlSelf->hmmm__DOT__Instr))
                                                                 ? 0x11U
                                                                 : 3U)
                                                                : 
                                                               ((1U 
                                                                 & (IData)(vlSelf->hmmm__DOT__Instr))
                                                                 ? 2U
                                                                 : 0U))))))))))))))));
    VL_WRITEF("\n\n");
    vlSelf->hmmm__DOT__MemAdrSrc = 0U;
    vlSelf->hmmm__DOT__MemDataSrc = 0U;
    vlSelf->hmmm__DOT__MemWrite = 0U;
    vlSelf->hmmm__DOT__PcSrc = 0U;
    vlSelf->hmmm__DOT__RegSrc = 0U;
    vlSelf->hmmm__DOT__RegWrite = 0U;
    vlSelf->hmmm__DOT__aluop = 0U;
    if (((((((((5U == vlSelf->hmmm__DOT__instruction_type) 
               | (3U == vlSelf->hmmm__DOT__instruction_type)) 
              | (4U == vlSelf->hmmm__DOT__instruction_type)) 
             | (9U == vlSelf->hmmm__DOT__instruction_type)) 
            | (0x12U == vlSelf->hmmm__DOT__instruction_type)) 
           | (0x11U == vlSelf->hmmm__DOT__instruction_type)) 
          | (0x17U == vlSelf->hmmm__DOT__instruction_type)) 
         | (0xaU == vlSelf->hmmm__DOT__instruction_type))) {
        if (VL_UNLIKELY((5U == vlSelf->hmmm__DOT__instruction_type))) {
            VL_WRITEF("LOADR\n");
            vlSelf->hmmm__DOT__MemAdrSrc = 1U;
            vlSelf->hmmm__DOT__RegSrc = 1U;
            vlSelf->hmmm__DOT__RegWrite = 1U;
        } else if (VL_UNLIKELY((3U == vlSelf->hmmm__DOT__instruction_type))) {
            VL_WRITEF("WRITE\n");
            vlSelf->hmmm__DOT__MemAdrSrc = 1U;
        } else if (VL_UNLIKELY((4U == vlSelf->hmmm__DOT__instruction_type))) {
            VL_WRITEF("SETN\n");
            vlSelf->hmmm__DOT__MemAdrSrc = 1U;
            vlSelf->hmmm__DOT__RegWrite = 1U;
        } else if (VL_UNLIKELY((9U == vlSelf->hmmm__DOT__instruction_type))) {
            VL_WRITEF("LOADN\n");
            vlSelf->hmmm__DOT__MemAdrSrc = 0U;
            vlSelf->hmmm__DOT__RegSrc = 1U;
            vlSelf->hmmm__DOT__RegWrite = 1U;
        } else if (VL_UNLIKELY((0x12U == vlSelf->hmmm__DOT__instruction_type))) {
            VL_WRITEF("JUMPN\n");
            vlSelf->hmmm__DOT__PcSrc = 2U;
        } else if (VL_UNLIKELY((0x11U == vlSelf->hmmm__DOT__instruction_type))) {
            VL_WRITEF("JUMPR\n");
            vlSelf->hmmm__DOT__PcSrc = 3U;
        } else if ((0x17U == vlSelf->hmmm__DOT__instruction_type)) {
            VL_WRITEF("CALLN\n");
            vlSelf->hmmm__DOT__PcSrc = 3U;
            vlSelf->hmmm__DOT__RegSrc = 2U;
        } else {
            VL_WRITEF("STOREN\n");
            vlSelf->hmmm__DOT__MemDataSrc = 1U;
            vlSelf->hmmm__DOT__MemWrite = 1U;
        }
    } else if (VL_UNLIKELY((6U == vlSelf->hmmm__DOT__instruction_type))) {
        VL_WRITEF("$STORER\n");
        vlSelf->hmmm__DOT__MemAdrSrc = 1U;
        vlSelf->hmmm__DOT__MemDataSrc = 1U;
        vlSelf->hmmm__DOT__MemWrite = 1U;
    } else if ((0xcU == vlSelf->hmmm__DOT__instruction_type)) {
        vlSelf->hmmm__DOT__aluop = 0U;
    }
}

VL_INLINE_OPT void Vhmmm___024root___nba_comb__TOP__0(Vhmmm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhmmm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhmmm___024root___nba_comb__TOP__0\n"); );
    // Body
    vlSelf->__VdfgTmp_h79120594__0 = vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers
        [(0xfU & ((IData)(vlSelf->hmmm__DOT__Instr) 
                  >> 4U))];
    vlSelf->__VdfgTmp_h79043d9e__0 = vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers
        [(0xfU & ((IData)(vlSelf->hmmm__DOT__Instr) 
                  >> 8U))];
    vlSelf->hmmm__DOT__datapath__DOT__PcNext = ((IData)(vlSelf->reset)
                                                 ? 0U
                                                 : 
                                                (0xffU 
                                                 & ((2U 
                                                     & (IData)(vlSelf->hmmm__DOT__PcSrc))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlSelf->hmmm__DOT__PcSrc))
                                                      ? 
                                                     (0x1feU 
                                                      & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                                         << 1U))
                                                      : 
                                                     (((0U 
                                                        == 
                                                        (0xfU 
                                                         & ((IData)(vlSelf->hmmm__DOT__Instr) 
                                                            >> 8U)))
                                                        ? 0U
                                                        : 
                                                       (0xffU 
                                                        & (IData)(vlSelf->__VdfgTmp_h79043d9e__0))) 
                                                      << 1U))
                                                     : 
                                                    ((IData)(2U) 
                                                     + (IData)(vlSelf->hmmm__DOT__datapath__DOT__Pc)))));
}

void Vhmmm___024root___eval_nba(Vhmmm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhmmm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhmmm___024root___eval_nba\n"); );
    // Body
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vhmmm___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vhmmm___024root___nba_sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    if ((3ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vhmmm___024root___nba_comb__TOP__0(vlSelf);
    }
}

void Vhmmm___024root___eval_triggers__ico(Vhmmm___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vhmmm___024root___dump_triggers__ico(Vhmmm___024root* vlSelf);
#endif  // VL_DEBUG
void Vhmmm___024root___eval_triggers__act(Vhmmm___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vhmmm___024root___dump_triggers__act(Vhmmm___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vhmmm___024root___dump_triggers__nba(Vhmmm___024root* vlSelf);
#endif  // VL_DEBUG

void Vhmmm___024root___eval(Vhmmm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhmmm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhmmm___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<2> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        Vhmmm___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vhmmm___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("hmmm.sv", 40, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vhmmm___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vhmmm___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vhmmm___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("hmmm.sv", 40, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
                Vhmmm___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vhmmm___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("hmmm.sv", 40, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vhmmm___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vhmmm___024root___eval_debug_assertions(Vhmmm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhmmm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhmmm___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
