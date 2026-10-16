// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"

extern const VlVarTableEntry Vtop___024root__VpiVarTable0[];
extern const VlVarTableEntry Vtop___024root__VpiVarTable1[];
extern const VlScopeTableEntry Vtop__Syms__VpiScopeTable[];


// VPI VARIABLE/SCOPE TABLES
#if defined(__GNUC__)
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Winvalid-offsetof"
#endif
extern const VlVarTableEntry Vtop___024root__VpiVarTable0[] = {
    {"a", offsetof(Vtop___024root, a), VLVT_UINT32, (VLVD_IN|VLVF_PUB_RW|VLVF_NET), 0, 1, {31, 0, 0, 0, 0, 0}},
    {"b", offsetof(Vtop___024root, b), VLVT_UINT32, (VLVD_IN|VLVF_PUB_RW|VLVF_NET), 0, 1, {31, 0, 0, 0, 0, 0}},
    {"op", offsetof(Vtop___024root, op), VLVT_UINT8, (VLVD_IN|VLVF_PUB_RW|VLVF_NET), 0, 1, {2, 0, 0, 0, 0, 0}},
    {"result", offsetof(Vtop___024root, result), VLVT_UINT32, (VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY), 0, 1, {31, 0, 0, 0, 0, 0}},
};
extern const VlVarTableEntry Vtop___024root__VpiVarTable1[] = {
    {"a", offsetof(Vtop___024root, alu__DOT__a), VLVT_UINT32, (VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY|VLVF_NET), 0, 1, {31, 0, 0, 0, 0, 0}},
    {"b", offsetof(Vtop___024root, alu__DOT__b), VLVT_UINT32, (VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY|VLVF_NET), 0, 1, {31, 0, 0, 0, 0, 0}},
    {"op", offsetof(Vtop___024root, alu__DOT__op), VLVT_UINT8, (VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY|VLVF_NET), 0, 1, {2, 0, 0, 0, 0, 0}},
    {"result", offsetof(Vtop___024root, alu__DOT__result), VLVT_UINT32, (VLVD_NODIR|VLVF_PUB_RW), 0, 1, {31, 0, 0, 0, 0, 0}},
};
extern const VlScopeTableEntry Vtop__Syms__VpiScopeTable[] = {
    {offsetof(Vtop__Syms, __Vscopep_TOP), "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER},
    {offsetof(Vtop__Syms, __Vscopep_alu), "alu", "alu", "alu", -9, VerilatedScope::SCOPE_MODULE},
};
#if defined(__GNUC__)
# pragma GCC diagnostic pop
#endif
Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    , __Vm_didInit{modelp->m_didInit}
    // Setup top module instance
    , TOP{this, namep}
{
    // Check resources
    Verilated::stackCheck(92);
    // Setup sub module instances
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    VerilatedScope::scopesConstructFromTable(Vtop__Syms__VpiScopeTable, 2, this);
    // Set up scope hierarchy
    __Vhier.add(0, __Vscopep_alu);
    // Setup export functions - final: 0
    // Setup export functions - final: 1
    // Setup public variables
    __Vscopep_TOP->varsInsertFromTable(Vtop___024root__VpiVarTable0, 4, &(TOP));
    __Vscopep_alu->varsInsertFromTable(Vtop___024root__VpiVarTable1, 4, &(TOP));
    __Vscopep_alu->varInsert("OP_ADD", const_cast<void*>(static_cast<const void*>(&(TOP.alu__DOT__OP_ADD))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_alu->varInsert("OP_AND", const_cast<void*>(static_cast<const void*>(&(TOP.alu__DOT__OP_AND))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_alu->varInsert("OP_OR", const_cast<void*>(static_cast<const void*>(&(TOP.alu__DOT__OP_OR))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_alu->varInsert("OP_SLL", const_cast<void*>(static_cast<const void*>(&(TOP.alu__DOT__OP_SLL))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_alu->varInsert("OP_SLT", const_cast<void*>(static_cast<const void*>(&(TOP.alu__DOT__OP_SLT))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_alu->varInsert("OP_SRL", const_cast<void*>(static_cast<const void*>(&(TOP.alu__DOT__OP_SRL))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_alu->varInsert("OP_SUB", const_cast<void*>(static_cast<const void*>(&(TOP.alu__DOT__OP_SUB))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_alu->varInsert("OP_XOR", const_cast<void*>(static_cast<const void*>(&(TOP.alu__DOT__OP_XOR))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
}

Vtop__Syms::~Vtop__Syms() {
    // Tear down scope hierarchy
    __Vhier.remove(0, __Vscopep_alu);
    // Clear keys from hierarchy map after values have been removed
    __Vhier.clear();
    // Tear down scopes
    VL_DO_CLEAR(delete __Vscopep_TOP, __Vscopep_TOP = nullptr);
    VL_DO_CLEAR(delete __Vscopep_alu, __Vscopep_alu = nullptr);
    // Tear down sub module instances
}
