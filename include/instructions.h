#pragma once

#include <common.h>
#include <cpu.h>

void LD_B_N(CPU& cpu, u8 n);
void LD_C_N(CPU& cpu, u8 n);
void LD_D_N(CPU& cpu, u8 n);
void LD_E_N(CPU& cpu, u8 n);
void LD_H_N(CPU& cpu, u8 n);
void LD_L_N(CPU& cpu, u8 n);

void LD_A_A(CPU& cpu);
void LD_A_B(CPU& cpu);
void LD_A_C(CPU& cpu);
void LD_A_D(CPU& cpu);
void LD_A_E(CPU& cpu);
void LD_A_H(CPU& cpu);
void LD_A_HL(CPU& cpu);

void LD_B_B(CPU& cpu);
void LD_B_C(CPU& cpu);
void LD_B_D(CPU& cpu);
