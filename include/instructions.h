#pragma once

#include <common.h>
#include <cpu.h>

// 0x00
void LD_BC_NN(CPU &cpu, MMU &mmu); // 0x01
void LD_BC_A(CPU &cpu, MMU &mmu); // 0x02
void INC_BC(CPU &cpu); // 0x03
void INC_B(CPU &cpu); // 0x04
void DEC_B(CPU &cpu); // 0x05
void LD_B_N(CPU &cpu, MMU &mmu); // 0x06
// 0x07
void LD_NN_SP(CPU &cpu, MMU &mmu); // 0x08
void ADD_HL_BC(CPU &cpu); // 0x09
void LD_A_BC(CPU &cpu, MMU &mmu); // 0x0A
void DEC_BC(CPU &cpu); // 0x0B
void INC_C(CPU &cpu); // 0x0C
void DEC_C(CPU &cpu); // 0x0D
void LD_C_N(CPU &cpu, MMU &mmu); // 0x0E
// 0x0F
// 0x10
void LD_DE_NN(CPU &cpu, MMU &mmu); // 0x11
void LD_DE_A(CPU &cpu, MMU &mmu); // 0x12
void INC_DE(CPU &cpu); // 0x13
void INC_D(CPU &cpu); // 0x14
void DEC_D(CPU &cpu); // 0x15
void LD_D_N(CPU &cpu, MMU &mmu); // 0x16
// 0x17
// 0x18
void ADD_HL_DE(CPU &cpu); // 0x19
void LD_A_DE(CPU &cpu, MMU &mmu); // 0x1A
void DEC_DE(CPU &cpu); // 0x1B
void INC_E(CPU &cpu); // 0x1C
void DEC_E(CPU &cpu); // 0x1D
void LD_E_N(CPU &cpu, MMU &mmu); // 0x1E
// 0x1F
// 0x20
void LD_HL_NN(CPU &cpu, MMU &mmu); // 0x21
// 0x22
void INC_HL(CPU &cpu); // 0x23
void INC_H(CPU &cpu); // 0x24
void DEC_H(CPU &cpu); // 0x25
void LD_H_N(CPU &cpu, MMU &mmu); // 0x26
// 0x27
// 0x28
void ADD_HL_HL(CPU &cpu); // 0x29
// 0x2A
void DEC_HL(CPU &cpu); // 0x2B
void INC_L(CPU &cpu); // 0x2C
void DEC_L(CPU &cpu); // 0x2D
void LD_L_N(CPU &cpu, MMU &mmu); // 0x2E
void CPL(CPU & cpu); // 0x2F
// 0x30
void LD_SP_NN(CPU &cpu, MMU &mmu); // 0x31
// 0x32
void INC_SP(CPU &cpu); // 0x33
void INC_HL(CPU &cpu, MMU &mmu); // 0x34
// 0x35
void LD_HL_N(CPU &cpu, MMU &mmu); // 0x36
void SCF(CPU &cpu); // 0x37
// 0x38
void ADD_HL_SP(CPU &cpu); // 0x39
// 0x3A
void DEC_SP(CPU &cpu); // 0x3B
void INC_A(CPU &cpu); // 0x3C
void DEC_A(CPU &cpu); // 0x3D
// 0x3E
void CCF(CPU &cpu); // 0x3F
void LD_B_B(CPU &cpu); // 0x40
void LD_B_C(CPU &cpu); // 0x41
void LD_B_D(CPU &cpu); // 0x42
void LD_B_E(CPU &cpu); // 0x43
void LD_B_H(CPU &cpu); // 0x44
void LD_B_L(CPU &cpu); // 0x45
void LD_B_HL(CPU &cpu, MMU &mmu); // 0x46
// 0x47
void LD_C_B(CPU &cpu); // 0x48
void LD_C_C(CPU &cpu); // 0x49
void LD_C_D(CPU &cpu); // 0x4A
void LD_C_E(CPU &cpu); // 0x4B
void LD_C_H(CPU &cpu); // 0x4C
void LD_C_L(CPU &cpu); // 0x4D
void LD_C_HL(CPU &cpu, MMU &mmu); // 0x4E
// 0x4F
void LD_D_B(CPU &cpu); // 0x50
void LD_D_C(CPU &cpu); // 0x51
void LD_D_D(CPU &cpu); // 0x52
void LD_D_E(CPU &cpu); // 0x53
void LD_D_H(CPU &cpu); // 0x54
void LD_D_L(CPU &cpu); // 0x55
void LD_D_HL(CPU &cpu, MMU &mmu); // 0x56
// 0x57
void LD_E_B(CPU &cpu); // 0x58
void LD_E_C(CPU &cpu); // 0x59
void LD_E_D(CPU &cpu); // 0x5A
void LD_E_E(CPU &cpu); // 0x5B
void LD_E_H(CPU &cpu); // 0x5C
void LD_E_L(CPU &cpu); // 0x5D
void LD_E_HL(CPU &cpu, MMU &mmu); // 0x5E
// 0x5F
void LD_H_B(CPU &cpu); // 0x60
void LD_H_C(CPU &cpu); // 0x61
void LD_H_D(CPU &cpu); // 0x62
void LD_H_E(CPU &cpu); // 0x63
void LD_H_H(CPU &cpu); // 0x64
void LD_H_L(CPU &cpu); // 0x65
void LD_H_HL(CPU &cpu, MMU &mmu); // 0x66
// 0x67
void LD_L_B(CPU &cpu); // 0x68
void LD_L_C(CPU &cpu); // 0x69
void LD_L_D(CPU &cpu); // 0x6A
void LD_L_E(CPU &cpu); // 0x6B
void LD_L_H(CPU &cpu); // 0x6C
void LD_L_L(CPU &cpu); // 0x6D
void LD_L_HL(CPU &cpu, MMU &mmu); // 0x6E
// 0x6F
void LD_HL_B(CPU &cpu, MMU &mmu); // 0x70
void LD_HL_C(CPU &cpu, MMU &mmu); // 0x71
void LD_HL_D(CPU &cpu, MMU &mmu); // 0x72
void LD_HL_E(CPU &cpu, MMU &mmu); // 0x73
void LD_HL_H(CPU &cpu, MMU &mmu); // 0x74
void LD_HL_L(CPU &cpu, MMU &mmu); // 0x75
// 0x76
// 0x77
void LD_A_B(CPU &cpu); // 0x78
void LD_A_C(CPU &cpu); // 0x79
void LD_A_D(CPU &cpu); // 0x7A
void LD_A_E(CPU &cpu); // 0x7B
void LD_A_H(CPU &cpu); // 0x7C
void LD_A_L(CPU &cpu); // 0x7D
void LD_A_HL(CPU &cpu, MMU &mmu); // 0x7E
void LD_A_A(CPU &cpu); // 0x7F
void ADD_A_B(CPU &cpu); // 0x80
void ADD_A_C(CPU &cpu); // 0x81
void ADD_A_D(CPU &cpu); // 0x82
void ADD_A_E(CPU &cpu); // 0x83
void ADD_A_H(CPU &cpu); // 0x84
void ADD_A_L(CPU &cpu); // 0x85
void ADD_A_HL(CPU &cpu, MMU &mmu); // 0x86
void ADD_A_A(CPU &cpu); // 0x87
void ADC_A_B(CPU &cpu); // 0x88
void ADC_A_C(CPU &cpu); // 0x89
void ADC_A_D(CPU &cpu); // 0x8A
void ADC_A_E(CPU &cpu); // 0x8B
void ADC_A_H(CPU &cpu); // 0x8C
void ADC_A_L(CPU &cpu); // 0x8D
void ADC_A_HL(CPU &cpu, MMU &mmu); // 0x8E
void ADC_A_A(CPU &cpu); // 0x8F
void SUB_A_B(CPU &cpu); // 0x90
void SUB_A_C(CPU &cpu); // 0x91
void SUB_A_D(CPU &cpu); // 0x92
void SUB_A_E(CPU &cpu); // 0x93
void SUB_A_H(CPU &cpu); // 0x94
void SUB_A_L(CPU &cpu); // 0x95
void SUB_A_HL(CPU &cpu, MMU &mmu); // 0x96
void SUB_A_A(CPU &cpu); // 0x97
void SBC_A_B(CPU &cpu); // 0x98
void SBC_A_C(CPU &cpu); // 0x99
void SBC_A_D(CPU &cpu); // 0x9A
void SBC_A_E(CPU &cpu); // 0x9B
void SBC_A_H(CPU &cpu); // 0x9C
void SBC_A_L(CPU &cpu); // 0x9D
void SBC_A_HL(CPU &cpu, MMU &mmu); // 0x9E
void SBC_A_A(CPU &cpu); // 0x9F
void AND_B(CPU &cpu); // 0xA0
void AND_C(CPU &cpu); // 0xA1
void AND_D(CPU &cpu); // 0xA2
void AND_E(CPU &cpu); // 0xA3
void AND_H(CPU &cpu); // 0xA4
void AND_L(CPU &cpu); // 0xA5
void AND_HL(CPU &cpu, MMU &mmu); // 0xA6
void AND_A(CPU &cpu); // 0xA7
void XOR_B(CPU &cpu); // 0xA8
void XOR_C(CPU &cpu); // 0xA9
void XOR_D(CPU &cpu); // 0xAA
void XOR_E(CPU &cpu); // 0xAB
void XOR_H(CPU &cpu); // 0xAC
void XOR_L(CPU &cpu); // 0xAD
void XOR_HL(CPU &cpu, MMU &mmu); // 0xAE
void XOR_A(CPU &cpu); // 0xAF
void OR_B(CPU &cpu); // 0xB0
void OR_C(CPU &cpu); // 0xB1
void OR_D(CPU &cpu); // 0xB2
void OR_E(CPU &cpu); // 0xB3
void OR_H(CPU &cpu); // 0xB4
void OR_L(CPU &cpu); // 0xB5
void OR_HL(CPU &cpu, MMU &mmu); // 0xB6
void OR_A(CPU &cpu); // 0xB7
void CP_B(CPU &cpu); // 0xB8
void CP_C(CPU &cpu); // 0xB9
void CP_D(CPU &cpu); // 0xBA
void CP_E(CPU &cpu); // 0xBB
void CP_H(CPU &cpu); // 0xBC
void CP_L(CPU &cpu); // 0xBD
// 0xBE
void CP_A(CPU &cpu); // 0xBF
// 0xC0
void POP_BC(CPU &cpu); // 0xC1
// 0xC2
// 0xC3
// 0xC4
void PUSH_BC(CPU &cpu); // 0xC5
void ADD_A_N(CPU &cpu, MMU &mmu); // 0xC6
// 0xC7
// 0xC8
// 0xC9
// 0xCA
// 0xCB
// 0xCC
// 0xCD
void ADC_A_N(CPU &cpu, MMU &mmu); // 0xCE
// 0xCF
// 0xD0
void POP_DE(CPU &cpu); // 0xD1
// 0xD2
// 0xD3
// 0xD4
void PUSH_DE(CPU &cpu); // 0xD5
void SUB_A_N(CPU &cpu, MMU &mmu); // 0xD6
// 0xD7
// 0xD8
// 0xD9
// 0xDA
// 0xDB
// 0xDC
// 0xDD
void SBC_A_N(CPU &cpu, MMU &mmu); // 0xDE
// 0xDF
// 0xE0
void POP_HL(CPU &cpu); // 0xE1
void LDH_C_A(CPU &cpu, MMU &mmu); // 0xE2
// 0xE3
// 0xE4
void PUSH_HL(CPU &cpu); // 0xE5
void AND_N(CPU &cpu, MMU &mmu); // 0xE6
// 0xE7
void ADD_SP_E(CPU &cpu, MMU &mmu); // 0xE8
// 0xE9
void LD_NN_A(CPU &cpu, MMU &mmu); // 0xEA
// 0xEB
// 0xEC
// 0xED
void XOR_N(CPU &cpu, MMU &mmu); // 0xEE
// 0xEF
void LDH_A_N(CPU &cpu, MMU &mmu); // 0xF0
void POP_AF(CPU &cpu); // 0xF1
void LDH_A_C(CPU &cpu, MMU &mmu); // 0xF2
// 0xF3
// 0xF4
void PUSH_AF(CPU &cpu); // 0xF5
void OR_N(CPU &cpu, MMU &mmu); // 0xF6
// 0xF7
void LD_HL_SP_PLUS_E(CPU &cpu, MMU &mmu); // 0xF8
void LD_SP_HL(CPU &cpu, MMU &mmu); // 0xF9
void LD_A_NN(CPU &cpu, MMU &mmu); // 0xFA
// 0xFB
// 0xFC
// 0xFD
void CP_N(CPU &cpu, MMU &mmu); // 0xFE
// 0xFF
