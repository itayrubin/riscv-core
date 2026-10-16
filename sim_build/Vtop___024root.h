// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(op,2,0);
    CData/*2:0*/ alu__DOT__op;
    VL_IN(a,31,0);
    VL_IN(b,31,0);
    VL_OUT(result,31,0);
    IData/*31:0*/ alu__DOT__a;
    IData/*31:0*/ alu__DOT__b;
    IData/*31:0*/ alu__DOT__result;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr CData/*2:0*/ alu__DOT__OP_ADD = 0U;
    static constexpr CData/*2:0*/ alu__DOT__OP_SUB = 1U;
    static constexpr CData/*2:0*/ alu__DOT__OP_AND = 2U;
    static constexpr CData/*2:0*/ alu__DOT__OP_OR = 3U;
    static constexpr CData/*2:0*/ alu__DOT__OP_XOR = 4U;
    static constexpr CData/*2:0*/ alu__DOT__OP_SLL = 5U;
    static constexpr CData/*2:0*/ alu__DOT__OP_SRL = 6U;
    static constexpr CData/*2:0*/ alu__DOT__OP_SLT = 7U;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* namep);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
