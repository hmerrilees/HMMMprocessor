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
    vlSelf->hmmm__DOT__datapath__DOT__pc_next = ((IData)(vlSelf->reset)
                                                  ? 0U
                                                  : 
                                                 (0xffU 
                                                  & ((((IData)(vlSelf->hmmm__DOT__pc_src) 
                                                       >> 1U) 
                                                      & ((0x15U 
                                                          == vlSelf->hmmm__DOT__instruction_type)
                                                          ? 
                                                         (0U 
                                                          == (IData)(vlSelf->hmmm__DOT__datapath__DOT__rf_read_data_x))
                                                          : 
                                                         ((0x16U 
                                                           == vlSelf->hmmm__DOT__instruction_type)
                                                           ? 
                                                          (0U 
                                                           != (IData)(vlSelf->hmmm__DOT__datapath__DOT__rf_read_data_x))
                                                           : 
                                                          ((0x17U 
                                                            == vlSelf->hmmm__DOT__instruction_type)
                                                            ? 
                                                           ((~ (IData)(vlSelf->hmmm__DOT__datapath__DOT__sign)) 
                                                            & (0U 
                                                               != (IData)(vlSelf->hmmm__DOT__datapath__DOT__rf_read_data_x)))
                                                            : 
                                                           ((0x18U 
                                                             != vlSelf->hmmm__DOT__instruction_type) 
                                                            | (IData)(vlSelf->hmmm__DOT__datapath__DOT__sign))))))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSelf->hmmm__DOT__pc_src))
                                                       ? 
                                                      ((0U 
                                                        == 
                                                        (0xfU 
                                                         & ((IData)(vlSelf->hmmm__DOT__instruction) 
                                                            >> 8U)))
                                                        ? 0U
                                                        : (IData)(vlSelf->__VdfgTmp_h1fe3baef__0))
                                                       : 
                                                      ((IData)(vlSelf->hmmm__DOT__instruction) 
                                                       << 1U))
                                                      : 
                                                     ((IData)(2U) 
                                                      + (IData)(vlSelf->hmmm__DOT__datapath__DOT__pc)))));
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
    CData/*7:0*/ __Vdlyvdim0__hmmm__DOT__datapath__DOT__mem__DOT__RAM__v0;
    __Vdlyvdim0__hmmm__DOT__datapath__DOT__mem__DOT__RAM__v0 = 0;
    SData/*15:0*/ __Vdlyvval__hmmm__DOT__datapath__DOT__mem__DOT__RAM__v0;
    __Vdlyvval__hmmm__DOT__datapath__DOT__mem__DOT__RAM__v0 = 0;
    CData/*0:0*/ __Vdlyvset__hmmm__DOT__datapath__DOT__mem__DOT__RAM__v0;
    __Vdlyvset__hmmm__DOT__datapath__DOT__mem__DOT__RAM__v0 = 0;
    // Body
    if (VL_UNLIKELY((((IData)(vlSelf->hmmm__DOT__rf_write_en_x) 
                      & (IData)(vlSelf->hmmm__DOT__rf_write_en_y)) 
                     & ((0xfU & ((IData)(vlSelf->hmmm__DOT__instruction) 
                                 >> 8U)) == (0xfU & 
                                             ((IData)(vlSelf->hmmm__DOT__instruction) 
                                              >> 4U)))))) {
        VL_WRITEF("WARNING: write to same register in same cycle. Second write channel takes priority.\n");
    }
    __Vdlyvset__hmmm__DOT__datapath__DOT__mem__DOT__RAM__v0 = 0U;
    VL_WRITEF("Instruction number: %10#\ninstruction: %x\n",
              32,((IData)(vlSelf->hmmm__DOT__datapath__DOT__pc) 
                  >> 1U),16,(IData)(vlSelf->hmmm__DOT__instruction));
    if (VL_UNLIKELY((3U == vlSelf->hmmm__DOT__instruction_type))) {
        VL_WRITEF("write: %b\n",16,vlSelf->hmmm__DOT__datapath__DOT__rf_read_data_x);
    } else if (VL_UNLIKELY((0U == vlSelf->hmmm__DOT__instruction_type))) {
        VL_WRITEF("halt\n");
        vlSelf->hmmm__DOT__datapath__DOT__unnamedblk1__DOT__i = 0x10U;
        VL_WRITEF("reg[          0]: %x\nreg[          1]: %x\nreg[          2]: %x\nreg[          3]: %x\nreg[          4]: %x\nreg[          5]: %x\nreg[          6]: %x\nreg[          7]: %x\nreg[          8]: %x\nreg[          9]: %x\nreg[         10]: %x\nreg[         11]: %x\nreg[         12]: %x\nreg[         13]: %x\nreg[         14]: %x\nreg[         15]: %x\n\n\n",
                  16,vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers
                  [0U],16,vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers
                  [1U],16,vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers
                  [2U],16,vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers
                  [3U],16,vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers
                  [4U],16,vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers
                  [5U],16,vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers
                  [6U],16,vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers
                  [7U],16,vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers
                  [8U],16,vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers
                  [9U],16,vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers
                  [0xaU],16,vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers
                  [0xbU],16,vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers
                  [0xcU],16,vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers
                  [0xdU],16,vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers
                  [0xeU],16,vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers
                  [0xfU]);
        vlSelf->hmmm__DOT__datapath__DOT__unnamedblk2__DOT__i = 0U;
        while (VL_GTS_III(32, 0x100U, vlSelf->hmmm__DOT__datapath__DOT__unnamedblk2__DOT__i)) {
            VL_WRITEF("mem[%11d]: %x\n",32,vlSelf->hmmm__DOT__datapath__DOT__unnamedblk2__DOT__i,
                      16,vlSelf->hmmm__DOT__datapath__DOT__mem__DOT__RAM
                      [(0xffU & vlSelf->hmmm__DOT__datapath__DOT__unnamedblk2__DOT__i)]);
            vlSelf->hmmm__DOT__datapath__DOT__unnamedblk2__DOT__i 
                = ((IData)(1U) + vlSelf->hmmm__DOT__datapath__DOT__unnamedblk2__DOT__i);
        }
        VL_FINISH_MT("hmmm.sv", 566, "");
    }
    if (vlSelf->hmmm__DOT__rf_write_en_x) {
        vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[(0xfU 
                                                              & ((IData)(vlSelf->hmmm__DOT__instruction) 
                                                                 >> 8U))] 
            = ((2U & (IData)(vlSelf->hmmm__DOT__rf_src_x))
                ? ((1U & (IData)(vlSelf->hmmm__DOT__rf_src_x))
                    ? (IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_result)
                    : (0xffU & ((IData)(2U) + (IData)(vlSelf->hmmm__DOT__datapath__DOT__pc))))
                : ((1U & (IData)(vlSelf->hmmm__DOT__rf_src_x))
                    ? vlSelf->hmmm__DOT__datapath__DOT__mem__DOT__RAM
                   [vlSelf->hmmm__DOT__datapath__DOT__mem_data_address]
                    : (IData)(vlSelf->hmmm__DOT__datapath__DOT__imm_ext)));
    }
    if (vlSelf->hmmm__DOT__rf_write_en_y) {
        vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers[(0xfU 
                                                              & ((IData)(vlSelf->hmmm__DOT__instruction) 
                                                                 >> 4U))] 
            = vlSelf->hmmm__DOT__datapath__DOT__alu_result;
    }
    if (vlSelf->hmmm__DOT__mem_write) {
        __Vdlyvval__hmmm__DOT__datapath__DOT__mem__DOT__RAM__v0 
            = ((IData)(vlSelf->hmmm__DOT__mem_data_src)
                ? (IData)(vlSelf->hmmm__DOT__datapath__DOT__rf_read_data_x)
                : (IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_result));
        __Vdlyvset__hmmm__DOT__datapath__DOT__mem__DOT__RAM__v0 = 1U;
        __Vdlyvdim0__hmmm__DOT__datapath__DOT__mem__DOT__RAM__v0 
            = vlSelf->hmmm__DOT__datapath__DOT__mem_data_address;
    }
    if (__Vdlyvset__hmmm__DOT__datapath__DOT__mem__DOT__RAM__v0) {
        vlSelf->hmmm__DOT__datapath__DOT__mem__DOT__RAM[__Vdlyvdim0__hmmm__DOT__datapath__DOT__mem__DOT__RAM__v0] 
            = __Vdlyvval__hmmm__DOT__datapath__DOT__mem__DOT__RAM__v0;
    }
    vlSelf->hmmm__DOT__datapath__DOT__pc = vlSelf->hmmm__DOT__datapath__DOT__pc_next;
    vlSelf->hmmm__DOT__instruction = vlSelf->hmmm__DOT__datapath__DOT__mem__DOT__RAM
        [(0xffU & ((IData)(vlSelf->hmmm__DOT__datapath__DOT__pc) 
                   >> 1U))];
    vlSelf->hmmm__DOT__datapath__DOT__imm_ext = ((0x80U 
                                                  & (IData)(vlSelf->hmmm__DOT__instruction))
                                                  ? 
                                                 (0xff00U 
                                                  | (0xffU 
                                                     & (IData)(vlSelf->hmmm__DOT__instruction)))
                                                  : 
                                                 (0xffU 
                                                  & (IData)(vlSelf->hmmm__DOT__instruction)));
    vlSelf->hmmm__DOT__datapath__DOT__rf_read_data_y 
        = ((0U == (0xfU & ((IData)(vlSelf->hmmm__DOT__instruction) 
                           >> 4U))) ? 0U : vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers
           [(0xfU & ((IData)(vlSelf->hmmm__DOT__instruction) 
                     >> 4U))]);
    vlSelf->__VdfgTmp_h1fe3baef__0 = vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers
        [(0xfU & ((IData)(vlSelf->hmmm__DOT__instruction) 
                  >> 8U))];
    if ((0x8000U & (IData)(vlSelf->hmmm__DOT__instruction))) {
        vlSelf->hmmm__DOT__instruction_type = ((0x4000U 
                                                & (IData)(vlSelf->hmmm__DOT__instruction))
                                                ? (
                                                   (0x2000U 
                                                    & (IData)(vlSelf->hmmm__DOT__instruction))
                                                    ? 
                                                   ((0x1000U 
                                                     & (IData)(vlSelf->hmmm__DOT__instruction))
                                                     ? 0x18U
                                                     : 0x17U)
                                                    : 
                                                   ((0x1000U 
                                                     & (IData)(vlSelf->hmmm__DOT__instruction))
                                                     ? 0x16U
                                                     : 0x15U))
                                                : (
                                                   (0x2000U 
                                                    & (IData)(vlSelf->hmmm__DOT__instruction))
                                                    ? 
                                                   ((0x1000U 
                                                     & (IData)(vlSelf->hmmm__DOT__instruction))
                                                     ? 
                                                    ((0x800U 
                                                      & (IData)(vlSelf->hmmm__DOT__instruction))
                                                      ? 0x19U
                                                      : 
                                                     ((0x400U 
                                                       & (IData)(vlSelf->hmmm__DOT__instruction))
                                                       ? 0x19U
                                                       : 
                                                      ((0x200U 
                                                        & (IData)(vlSelf->hmmm__DOT__instruction))
                                                        ? 0x19U
                                                        : 
                                                       ((0x100U 
                                                         & (IData)(vlSelf->hmmm__DOT__instruction))
                                                         ? 0x19U
                                                         : 0x14U))))
                                                     : 0x12U)
                                                    : 
                                                   ((0x1000U 
                                                     & (IData)(vlSelf->hmmm__DOT__instruction))
                                                     ? 0x11U
                                                     : 0x10U)));
    } else if ((0x4000U & (IData)(vlSelf->hmmm__DOT__instruction))) {
        if ((0x2000U & (IData)(vlSelf->hmmm__DOT__instruction))) {
            vlSelf->hmmm__DOT__instruction_type = (
                                                   (0x1000U 
                                                    & (IData)(vlSelf->hmmm__DOT__instruction))
                                                    ? 0xeU
                                                    : 0xcU);
        } else if ((0x1000U & (IData)(vlSelf->hmmm__DOT__instruction))) {
            vlSelf->hmmm__DOT__instruction_type = 0xbU;
        } else if (VL_UNLIKELY((8U & (IData)(vlSelf->hmmm__DOT__instruction)))) {
            VL_WRITEF("unknown instruction, defaulting to NOP\n");
            vlSelf->hmmm__DOT__instruction_type = 1U;
        } else if (VL_UNLIKELY((4U & (IData)(vlSelf->hmmm__DOT__instruction)))) {
            VL_WRITEF("unknown instruction, defaulting to NOP\n");
            vlSelf->hmmm__DOT__instruction_type = 1U;
        } else {
            vlSelf->hmmm__DOT__instruction_type = (
                                                   (2U 
                                                    & (IData)(vlSelf->hmmm__DOT__instruction))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelf->hmmm__DOT__instruction))
                                                     ? 8U
                                                     : 7U)
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelf->hmmm__DOT__instruction))
                                                     ? 6U
                                                     : 5U));
        }
    } else if ((0x2000U & (IData)(vlSelf->hmmm__DOT__instruction))) {
        vlSelf->hmmm__DOT__instruction_type = ((0x1000U 
                                                & (IData)(vlSelf->hmmm__DOT__instruction))
                                                ? 0xaU
                                                : 9U);
    } else if ((0x1000U & (IData)(vlSelf->hmmm__DOT__instruction))) {
        vlSelf->hmmm__DOT__instruction_type = 4U;
    } else if ((0x800U & (IData)(vlSelf->hmmm__DOT__instruction))) {
        if (VL_UNLIKELY((0x80U & (IData)(vlSelf->hmmm__DOT__instruction)))) {
            VL_WRITEF("unknown instruction, defaulting to NOP\n");
            vlSelf->hmmm__DOT__instruction_type = 1U;
        } else if (VL_UNLIKELY((0x40U & (IData)(vlSelf->hmmm__DOT__instruction)))) {
            VL_WRITEF("unknown instruction, defaulting to NOP\n");
            vlSelf->hmmm__DOT__instruction_type = 1U;
        } else if (VL_UNLIKELY((0x20U & (IData)(vlSelf->hmmm__DOT__instruction)))) {
            VL_WRITEF("unknown instruction, defaulting to NOP\n");
            vlSelf->hmmm__DOT__instruction_type = 1U;
        } else if (VL_UNLIKELY((0x10U & (IData)(vlSelf->hmmm__DOT__instruction)))) {
            VL_WRITEF("unknown instruction, defaulting to NOP\n");
            vlSelf->hmmm__DOT__instruction_type = 1U;
        } else if (VL_UNLIKELY((8U & (IData)(vlSelf->hmmm__DOT__instruction)))) {
            VL_WRITEF("unknown instruction, defaulting to NOP\n");
            vlSelf->hmmm__DOT__instruction_type = 1U;
        } else if (VL_UNLIKELY((4U & (IData)(vlSelf->hmmm__DOT__instruction)))) {
            VL_WRITEF("unknown instruction, defaulting to NOP\n");
            vlSelf->hmmm__DOT__instruction_type = 1U;
        } else if ((2U & (IData)(vlSelf->hmmm__DOT__instruction))) {
            vlSelf->hmmm__DOT__instruction_type = (
                                                   (1U 
                                                    & (IData)(vlSelf->hmmm__DOT__instruction))
                                                    ? 0x13U
                                                    : 3U);
        } else if (VL_LIKELY((1U & (IData)(vlSelf->hmmm__DOT__instruction)))) {
            vlSelf->hmmm__DOT__instruction_type = 2U;
        } else {
            VL_WRITEF("unknown instruction, defaulting to NOP\n");
            vlSelf->hmmm__DOT__instruction_type = 1U;
        }
    } else if ((0x400U & (IData)(vlSelf->hmmm__DOT__instruction))) {
        if (VL_UNLIKELY((0x80U & (IData)(vlSelf->hmmm__DOT__instruction)))) {
            VL_WRITEF("unknown instruction, defaulting to NOP\n");
            vlSelf->hmmm__DOT__instruction_type = 1U;
        } else if (VL_UNLIKELY((0x40U & (IData)(vlSelf->hmmm__DOT__instruction)))) {
            VL_WRITEF("unknown instruction, defaulting to NOP\n");
            vlSelf->hmmm__DOT__instruction_type = 1U;
        } else if (VL_UNLIKELY((0x20U & (IData)(vlSelf->hmmm__DOT__instruction)))) {
            VL_WRITEF("unknown instruction, defaulting to NOP\n");
            vlSelf->hmmm__DOT__instruction_type = 1U;
        } else if (VL_UNLIKELY((0x10U & (IData)(vlSelf->hmmm__DOT__instruction)))) {
            VL_WRITEF("unknown instruction, defaulting to NOP\n");
            vlSelf->hmmm__DOT__instruction_type = 1U;
        } else if (VL_UNLIKELY((8U & (IData)(vlSelf->hmmm__DOT__instruction)))) {
            VL_WRITEF("unknown instruction, defaulting to NOP\n");
            vlSelf->hmmm__DOT__instruction_type = 1U;
        } else if (VL_UNLIKELY((4U & (IData)(vlSelf->hmmm__DOT__instruction)))) {
            VL_WRITEF("unknown instruction, defaulting to NOP\n");
            vlSelf->hmmm__DOT__instruction_type = 1U;
        } else if ((2U & (IData)(vlSelf->hmmm__DOT__instruction))) {
            vlSelf->hmmm__DOT__instruction_type = (
                                                   (1U 
                                                    & (IData)(vlSelf->hmmm__DOT__instruction))
                                                    ? 0x13U
                                                    : 3U);
        } else if (VL_LIKELY((1U & (IData)(vlSelf->hmmm__DOT__instruction)))) {
            vlSelf->hmmm__DOT__instruction_type = 2U;
        } else {
            VL_WRITEF("unknown instruction, defaulting to NOP\n");
            vlSelf->hmmm__DOT__instruction_type = 1U;
        }
    } else if ((0x200U & (IData)(vlSelf->hmmm__DOT__instruction))) {
        if (VL_UNLIKELY((0x80U & (IData)(vlSelf->hmmm__DOT__instruction)))) {
            VL_WRITEF("unknown instruction, defaulting to NOP\n");
            vlSelf->hmmm__DOT__instruction_type = 1U;
        } else if (VL_UNLIKELY((0x40U & (IData)(vlSelf->hmmm__DOT__instruction)))) {
            VL_WRITEF("unknown instruction, defaulting to NOP\n");
            vlSelf->hmmm__DOT__instruction_type = 1U;
        } else if (VL_UNLIKELY((0x20U & (IData)(vlSelf->hmmm__DOT__instruction)))) {
            VL_WRITEF("unknown instruction, defaulting to NOP\n");
            vlSelf->hmmm__DOT__instruction_type = 1U;
        } else if (VL_UNLIKELY((0x10U & (IData)(vlSelf->hmmm__DOT__instruction)))) {
            VL_WRITEF("unknown instruction, defaulting to NOP\n");
            vlSelf->hmmm__DOT__instruction_type = 1U;
        } else if (VL_UNLIKELY((8U & (IData)(vlSelf->hmmm__DOT__instruction)))) {
            VL_WRITEF("unknown instruction, defaulting to NOP\n");
            vlSelf->hmmm__DOT__instruction_type = 1U;
        } else if (VL_UNLIKELY((4U & (IData)(vlSelf->hmmm__DOT__instruction)))) {
            VL_WRITEF("unknown instruction, defaulting to NOP\n");
            vlSelf->hmmm__DOT__instruction_type = 1U;
        } else if ((2U & (IData)(vlSelf->hmmm__DOT__instruction))) {
            vlSelf->hmmm__DOT__instruction_type = (
                                                   (1U 
                                                    & (IData)(vlSelf->hmmm__DOT__instruction))
                                                    ? 0x13U
                                                    : 3U);
        } else if (VL_LIKELY((1U & (IData)(vlSelf->hmmm__DOT__instruction)))) {
            vlSelf->hmmm__DOT__instruction_type = 2U;
        } else {
            VL_WRITEF("unknown instruction, defaulting to NOP\n");
            vlSelf->hmmm__DOT__instruction_type = 1U;
        }
    } else if ((0x100U & (IData)(vlSelf->hmmm__DOT__instruction))) {
        if (VL_UNLIKELY((0x80U & (IData)(vlSelf->hmmm__DOT__instruction)))) {
            VL_WRITEF("unknown instruction, defaulting to NOP\n");
            vlSelf->hmmm__DOT__instruction_type = 1U;
        } else if (VL_UNLIKELY((0x40U & (IData)(vlSelf->hmmm__DOT__instruction)))) {
            VL_WRITEF("unknown instruction, defaulting to NOP\n");
            vlSelf->hmmm__DOT__instruction_type = 1U;
        } else if (VL_UNLIKELY((0x20U & (IData)(vlSelf->hmmm__DOT__instruction)))) {
            VL_WRITEF("unknown instruction, defaulting to NOP\n");
            vlSelf->hmmm__DOT__instruction_type = 1U;
        } else if (VL_UNLIKELY((0x10U & (IData)(vlSelf->hmmm__DOT__instruction)))) {
            VL_WRITEF("unknown instruction, defaulting to NOP\n");
            vlSelf->hmmm__DOT__instruction_type = 1U;
        } else if (VL_UNLIKELY((8U & (IData)(vlSelf->hmmm__DOT__instruction)))) {
            VL_WRITEF("unknown instruction, defaulting to NOP\n");
            vlSelf->hmmm__DOT__instruction_type = 1U;
        } else if (VL_UNLIKELY((4U & (IData)(vlSelf->hmmm__DOT__instruction)))) {
            VL_WRITEF("unknown instruction, defaulting to NOP\n");
            vlSelf->hmmm__DOT__instruction_type = 1U;
        } else if ((2U & (IData)(vlSelf->hmmm__DOT__instruction))) {
            vlSelf->hmmm__DOT__instruction_type = (
                                                   (1U 
                                                    & (IData)(vlSelf->hmmm__DOT__instruction))
                                                    ? 0x13U
                                                    : 3U);
        } else if (VL_LIKELY((1U & (IData)(vlSelf->hmmm__DOT__instruction)))) {
            vlSelf->hmmm__DOT__instruction_type = 2U;
        } else {
            VL_WRITEF("unknown instruction, defaulting to NOP\n");
            vlSelf->hmmm__DOT__instruction_type = 1U;
        }
    } else if (VL_UNLIKELY((0x80U & (IData)(vlSelf->hmmm__DOT__instruction)))) {
        VL_WRITEF("unknown instruction, defaulting to NOP\n");
        vlSelf->hmmm__DOT__instruction_type = 1U;
    } else if (VL_UNLIKELY((0x40U & (IData)(vlSelf->hmmm__DOT__instruction)))) {
        VL_WRITEF("unknown instruction, defaulting to NOP\n");
        vlSelf->hmmm__DOT__instruction_type = 1U;
    } else if (VL_UNLIKELY((0x20U & (IData)(vlSelf->hmmm__DOT__instruction)))) {
        VL_WRITEF("unknown instruction, defaulting to NOP\n");
        vlSelf->hmmm__DOT__instruction_type = 1U;
    } else if (VL_UNLIKELY((0x10U & (IData)(vlSelf->hmmm__DOT__instruction)))) {
        VL_WRITEF("unknown instruction, defaulting to NOP\n");
        vlSelf->hmmm__DOT__instruction_type = 1U;
    } else if (VL_UNLIKELY((8U & (IData)(vlSelf->hmmm__DOT__instruction)))) {
        VL_WRITEF("unknown instruction, defaulting to NOP\n");
        vlSelf->hmmm__DOT__instruction_type = 1U;
    } else if (VL_UNLIKELY((4U & (IData)(vlSelf->hmmm__DOT__instruction)))) {
        VL_WRITEF("unknown instruction, defaulting to NOP\n");
        vlSelf->hmmm__DOT__instruction_type = 1U;
    } else {
        vlSelf->hmmm__DOT__instruction_type = ((2U 
                                                & (IData)(vlSelf->hmmm__DOT__instruction))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSelf->hmmm__DOT__instruction))
                                                    ? 0x13U
                                                    : 3U)
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelf->hmmm__DOT__instruction))
                                                    ? 2U
                                                    : 0U));
    }
    vlSelf->hmmm__DOT__datapath__DOT__sign = ((0U != 
                                               (0xfU 
                                                & ((IData)(vlSelf->hmmm__DOT__instruction) 
                                                   >> 8U))) 
                                              & ((IData)(vlSelf->__VdfgTmp_h1fe3baef__0) 
                                                 >> 0xfU));
    vlSelf->hmmm__DOT__datapath__DOT__rf_read_data_x 
        = ((0U == (0xfU & ((IData)(vlSelf->hmmm__DOT__instruction) 
                           >> 8U))) ? 0U : (IData)(vlSelf->__VdfgTmp_h1fe3baef__0));
    vlSelf->hmmm__DOT__mem_adr_src = 0U;
    vlSelf->hmmm__DOT__mem_data_src = 0U;
    vlSelf->hmmm__DOT__mem_write = 0U;
    vlSelf->hmmm__DOT__pc_src = 0U;
    vlSelf->hmmm__DOT__rf_src_x = 0U;
    vlSelf->hmmm__DOT__rf_write_en_x = 0U;
    vlSelf->hmmm__DOT__alu_op = 0U;
    vlSelf->hmmm__DOT__alu_src_a = 0U;
    vlSelf->hmmm__DOT__alu_src_b = 0U;
    VL_WRITEF("\n\n");
    if (((((((((5U == vlSelf->hmmm__DOT__instruction_type) 
               | (2U == vlSelf->hmmm__DOT__instruction_type)) 
              | (3U == vlSelf->hmmm__DOT__instruction_type)) 
             | (4U == vlSelf->hmmm__DOT__instruction_type)) 
            | (9U == vlSelf->hmmm__DOT__instruction_type)) 
           | (0x14U == vlSelf->hmmm__DOT__instruction_type)) 
          | (0x13U == vlSelf->hmmm__DOT__instruction_type)) 
         | (0x15U == vlSelf->hmmm__DOT__instruction_type))) {
        if (VL_UNLIKELY((5U == vlSelf->hmmm__DOT__instruction_type))) {
            VL_WRITEF("LOADR\n");
            vlSelf->hmmm__DOT__mem_adr_src = 1U;
            vlSelf->hmmm__DOT__rf_src_x = 1U;
            vlSelf->hmmm__DOT__rf_write_en_x = 1U;
        } else if (VL_UNLIKELY((2U == vlSelf->hmmm__DOT__instruction_type))) {
            VL_WRITEF("READ\nWARNING: READ unimplemented.\n");
        } else if (VL_UNLIKELY((3U == vlSelf->hmmm__DOT__instruction_type))) {
            VL_WRITEF("WRITE\n");
        } else if (VL_UNLIKELY((4U == vlSelf->hmmm__DOT__instruction_type))) {
            VL_WRITEF("SETN\n");
            vlSelf->hmmm__DOT__rf_src_x = 0U;
            vlSelf->hmmm__DOT__rf_write_en_x = 1U;
        } else if (VL_UNLIKELY((9U == vlSelf->hmmm__DOT__instruction_type))) {
            VL_WRITEF("LOADN\n");
            vlSelf->hmmm__DOT__mem_adr_src = 0U;
            vlSelf->hmmm__DOT__rf_src_x = 1U;
            vlSelf->hmmm__DOT__rf_write_en_x = 1U;
        } else if (VL_UNLIKELY((0x14U == vlSelf->hmmm__DOT__instruction_type))) {
            VL_WRITEF("JUMPN\n");
            vlSelf->hmmm__DOT__pc_src = 2U;
        } else if ((0x13U == vlSelf->hmmm__DOT__instruction_type)) {
            VL_WRITEF("JUMPR\n");
            vlSelf->hmmm__DOT__pc_src = 3U;
        } else {
            VL_WRITEF("JEQZN\n");
            vlSelf->hmmm__DOT__pc_src = 2U;
        }
    } else if (((((((((0x16U == vlSelf->hmmm__DOT__instruction_type) 
                      | (0x17U == vlSelf->hmmm__DOT__instruction_type)) 
                     | (0x18U == vlSelf->hmmm__DOT__instruction_type)) 
                    | (0x19U == vlSelf->hmmm__DOT__instruction_type)) 
                   | (0xaU == vlSelf->hmmm__DOT__instruction_type)) 
                  | (6U == vlSelf->hmmm__DOT__instruction_type)) 
                 | (7U == vlSelf->hmmm__DOT__instruction_type)) 
                | (8U == vlSelf->hmmm__DOT__instruction_type))) {
        if (VL_UNLIKELY((0x16U == vlSelf->hmmm__DOT__instruction_type))) {
            VL_WRITEF("JNEZN\n");
            vlSelf->hmmm__DOT__pc_src = 2U;
        } else if (VL_UNLIKELY((0x17U == vlSelf->hmmm__DOT__instruction_type))) {
            VL_WRITEF("JGTZN\n");
            vlSelf->hmmm__DOT__pc_src = 2U;
        } else if (VL_UNLIKELY((0x18U == vlSelf->hmmm__DOT__instruction_type))) {
            VL_WRITEF("JLTZN\n");
            vlSelf->hmmm__DOT__pc_src = 2U;
        } else if (VL_UNLIKELY((0x19U == vlSelf->hmmm__DOT__instruction_type))) {
            VL_WRITEF("CALLN\n");
            vlSelf->hmmm__DOT__pc_src = 2U;
            vlSelf->hmmm__DOT__rf_src_x = 2U;
            vlSelf->hmmm__DOT__rf_write_en_x = 1U;
        } else if (VL_UNLIKELY((0xaU == vlSelf->hmmm__DOT__instruction_type))) {
            VL_WRITEF("STOREN\n");
            vlSelf->hmmm__DOT__mem_adr_src = 0U;
            vlSelf->hmmm__DOT__mem_data_src = 1U;
            vlSelf->hmmm__DOT__mem_write = 1U;
        } else if (VL_UNLIKELY((6U == vlSelf->hmmm__DOT__instruction_type))) {
            VL_WRITEF("STORER\n");
            vlSelf->hmmm__DOT__mem_data_src = 1U;
            vlSelf->hmmm__DOT__mem_adr_src = 1U;
            vlSelf->hmmm__DOT__mem_write = 1U;
        } else if ((7U == vlSelf->hmmm__DOT__instruction_type)) {
            VL_WRITEF("POPR\n");
            vlSelf->hmmm__DOT__alu_src_a = 0U;
            vlSelf->hmmm__DOT__alu_src_b = 3U;
            vlSelf->hmmm__DOT__alu_op = 1U;
            vlSelf->hmmm__DOT__rf_write_en_y = 1U;
            vlSelf->hmmm__DOT__mem_adr_src = 2U;
            vlSelf->hmmm__DOT__rf_src_x = 1U;
            vlSelf->hmmm__DOT__rf_write_en_x = 1U;
        } else {
            VL_WRITEF("PUSHR\n");
            vlSelf->hmmm__DOT__mem_data_src = 1U;
            vlSelf->hmmm__DOT__mem_adr_src = 1U;
            vlSelf->hmmm__DOT__mem_write = 1U;
            vlSelf->hmmm__DOT__alu_src_a = 0U;
            vlSelf->hmmm__DOT__alu_src_b = 3U;
            vlSelf->hmmm__DOT__alu_op = 0U;
            vlSelf->hmmm__DOT__rf_write_en_y = 1U;
        }
    } else if ((((0xcU == vlSelf->hmmm__DOT__instruction_type) 
                 | (0xdU == vlSelf->hmmm__DOT__instruction_type)) 
                | (1U == vlSelf->hmmm__DOT__instruction_type))) {
        if (VL_UNLIKELY((0xcU == vlSelf->hmmm__DOT__instruction_type))) {
            VL_WRITEF("ADD\n");
        } else if (VL_UNLIKELY((0xdU == vlSelf->hmmm__DOT__instruction_type))) {
            VL_WRITEF("COPY\n");
        } else if (VL_UNLIKELY((1U == vlSelf->hmmm__DOT__instruction_type))) {
            VL_WRITEF("NOP\n");
        }
        vlSelf->hmmm__DOT__alu_src_a = 0U;
        vlSelf->hmmm__DOT__alu_src_b = 0U;
        vlSelf->hmmm__DOT__alu_op = 0U;
        vlSelf->hmmm__DOT__rf_src_x = 3U;
        vlSelf->hmmm__DOT__rf_write_en_x = 1U;
    } else if (VL_UNLIKELY((0xbU == vlSelf->hmmm__DOT__instruction_type))) {
        VL_WRITEF("ADDN\n");
        vlSelf->hmmm__DOT__alu_src_a = 1U;
        vlSelf->hmmm__DOT__alu_src_b = 1U;
        vlSelf->hmmm__DOT__alu_op = 0U;
        vlSelf->hmmm__DOT__rf_src_x = 3U;
        vlSelf->hmmm__DOT__rf_write_en_x = 1U;
    } else if (((0xeU == vlSelf->hmmm__DOT__instruction_type) 
                | (0xfU == vlSelf->hmmm__DOT__instruction_type))) {
        if (VL_UNLIKELY((0xeU == vlSelf->hmmm__DOT__instruction_type))) {
            VL_WRITEF("SUB\n");
        } else if (VL_UNLIKELY((0xfU == vlSelf->hmmm__DOT__instruction_type))) {
            VL_WRITEF("NEG\n");
        }
        vlSelf->hmmm__DOT__alu_src_a = 0U;
        vlSelf->hmmm__DOT__alu_src_b = 0U;
        vlSelf->hmmm__DOT__alu_op = 1U;
        vlSelf->hmmm__DOT__rf_src_x = 3U;
        vlSelf->hmmm__DOT__rf_write_en_x = 1U;
    } else if (VL_UNLIKELY((0x10U == vlSelf->hmmm__DOT__instruction_type))) {
        VL_WRITEF("MUL\n");
        vlSelf->hmmm__DOT__alu_src_a = 0U;
        vlSelf->hmmm__DOT__alu_src_b = 0U;
        vlSelf->hmmm__DOT__alu_op = 2U;
        vlSelf->hmmm__DOT__rf_src_x = 3U;
        vlSelf->hmmm__DOT__rf_write_en_x = 1U;
    } else if (VL_UNLIKELY((0x11U == vlSelf->hmmm__DOT__instruction_type))) {
        VL_WRITEF("DIV\n");
        vlSelf->hmmm__DOT__alu_src_a = 0U;
        vlSelf->hmmm__DOT__alu_src_b = 0U;
        vlSelf->hmmm__DOT__alu_op = 3U;
        vlSelf->hmmm__DOT__rf_src_x = 3U;
        vlSelf->hmmm__DOT__rf_write_en_x = 1U;
    } else if (VL_UNLIKELY((0x12U == vlSelf->hmmm__DOT__instruction_type))) {
        VL_WRITEF("MOD\n");
        vlSelf->hmmm__DOT__alu_src_a = 0U;
        vlSelf->hmmm__DOT__alu_src_b = 0U;
        vlSelf->hmmm__DOT__alu_op = 4U;
        vlSelf->hmmm__DOT__rf_src_x = 3U;
        vlSelf->hmmm__DOT__rf_write_en_x = 1U;
    }
    vlSelf->hmmm__DOT__datapath__DOT__pc_next = ((IData)(vlSelf->reset)
                                                  ? 0U
                                                  : 
                                                 (0xffU 
                                                  & ((((IData)(vlSelf->hmmm__DOT__pc_src) 
                                                       >> 1U) 
                                                      & ((0x15U 
                                                          == vlSelf->hmmm__DOT__instruction_type)
                                                          ? 
                                                         (0U 
                                                          == (IData)(vlSelf->hmmm__DOT__datapath__DOT__rf_read_data_x))
                                                          : 
                                                         ((0x16U 
                                                           == vlSelf->hmmm__DOT__instruction_type)
                                                           ? 
                                                          (0U 
                                                           != (IData)(vlSelf->hmmm__DOT__datapath__DOT__rf_read_data_x))
                                                           : 
                                                          ((0x17U 
                                                            == vlSelf->hmmm__DOT__instruction_type)
                                                            ? 
                                                           ((~ (IData)(vlSelf->hmmm__DOT__datapath__DOT__sign)) 
                                                            & (0U 
                                                               != (IData)(vlSelf->hmmm__DOT__datapath__DOT__rf_read_data_x)))
                                                            : 
                                                           ((0x18U 
                                                             != vlSelf->hmmm__DOT__instruction_type) 
                                                            | (IData)(vlSelf->hmmm__DOT__datapath__DOT__sign))))))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSelf->hmmm__DOT__pc_src))
                                                       ? 
                                                      ((0U 
                                                        == 
                                                        (0xfU 
                                                         & ((IData)(vlSelf->hmmm__DOT__instruction) 
                                                            >> 8U)))
                                                        ? 0U
                                                        : (IData)(vlSelf->__VdfgTmp_h1fe3baef__0))
                                                       : 
                                                      ((IData)(vlSelf->hmmm__DOT__instruction) 
                                                       << 1U))
                                                      : 
                                                     ((IData)(2U) 
                                                      + (IData)(vlSelf->hmmm__DOT__datapath__DOT__pc)))));
    vlSelf->hmmm__DOT__datapath__DOT__alu_input_a = 
        ((IData)(vlSelf->hmmm__DOT__alu_src_a) ? (IData)(vlSelf->hmmm__DOT__datapath__DOT__rf_read_data_x)
          : (IData)(vlSelf->hmmm__DOT__datapath__DOT__rf_read_data_y));
    vlSelf->hmmm__DOT__datapath__DOT__alu_input_b = 
        ((2U & (IData)(vlSelf->hmmm__DOT__alu_src_b))
          ? ((1U & (IData)(vlSelf->hmmm__DOT__alu_src_b))
              ? 1U : 0U) : ((1U & (IData)(vlSelf->hmmm__DOT__alu_src_b))
                             ? (IData)(vlSelf->hmmm__DOT__datapath__DOT__imm_ext)
                             : ((0U == (0xfU & (IData)(vlSelf->hmmm__DOT__instruction)))
                                 ? 0U : vlSelf->hmmm__DOT__datapath__DOT__rf__DOT__registers
                                [(0xfU & (IData)(vlSelf->hmmm__DOT__instruction))])));
    if ((0U == vlSelf->hmmm__DOT__alu_op)) {
        vlSelf->hmmm__DOT__datapath__DOT__alu_result 
            = (0xffffU & ((IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_input_a) 
                          + (IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_input_b)));
    } else if ((1U == vlSelf->hmmm__DOT__alu_op)) {
        vlSelf->hmmm__DOT__datapath__DOT__alu_result 
            = (0xffffU & ((IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_input_a) 
                          - (IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_input_b)));
    } else if ((2U == vlSelf->hmmm__DOT__alu_op)) {
        vlSelf->hmmm__DOT__datapath__DOT__alu_result 
            = (0xffffU & ((IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_input_a) 
                          * (IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_input_b)));
    } else if ((3U == vlSelf->hmmm__DOT__alu_op)) {
        vlSelf->hmmm__DOT__datapath__DOT__alu_result 
            = (0xffffU & VL_DIV_III(16, (IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_input_a), (IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_input_b)));
    } else if ((4U == vlSelf->hmmm__DOT__alu_op)) {
        vlSelf->hmmm__DOT__datapath__DOT__alu_result 
            = (0xffffU & VL_MODDIV_III(16, (IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_input_a), (IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_input_b)));
    }
    if ((0U == (IData)(vlSelf->hmmm__DOT__mem_adr_src))) {
        vlSelf->hmmm__DOT__datapath__DOT__mem_data_address 
            = (0xffU & (IData)(vlSelf->hmmm__DOT__instruction));
    } else if ((1U == (IData)(vlSelf->hmmm__DOT__mem_adr_src))) {
        vlSelf->hmmm__DOT__datapath__DOT__mem_data_address 
            = (0xffU & (IData)(vlSelf->hmmm__DOT__datapath__DOT__rf_read_data_y));
    } else if ((2U == (IData)(vlSelf->hmmm__DOT__mem_adr_src))) {
        vlSelf->hmmm__DOT__datapath__DOT__mem_data_address 
            = (0xffU & (IData)(vlSelf->hmmm__DOT__datapath__DOT__alu_result));
    }
}

void Vhmmm___024root___eval_nba(Vhmmm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhmmm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhmmm___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vhmmm___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
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
    VlTriggerVec<1> __VpreTriggered;
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
                VL_FATAL_MT("hmmm.sv", 44, "", "Input combinational region did not converge.");
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
                    VL_FATAL_MT("hmmm.sv", 44, "", "Active region did not converge.");
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
                VL_FATAL_MT("hmmm.sv", 44, "", "NBA region did not converge.");
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
