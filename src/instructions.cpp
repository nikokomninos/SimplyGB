#include <instructions.h>

/*---- 8-BIT LOADS ----*/

/*-- LD nn, n --*/
/* Put value nn into n */

// 0x06
void LD_B_N(CPU &cpu, u8 n) { cpu.regs.B = n; }

// 0x0E
void LD_C_N(CPU &cpu, u8 n) { cpu.regs.C = n; }

// 0x16
void LD_D_N(CPU &cpu, u8 n) { cpu.regs.D = n; }

// 0x1E
void LD_E_N(CPU &cpu, u8 n) { cpu.regs.E = n; }

// 0x26
void LD_H_N(CPU &cpu, u8 n) { cpu.regs.H = n; }

// 0x2E
void LD_L_N(CPU &cpu, u8 n) { cpu.regs.L = n; }


/*-- LD r1, r2 --*/
/* Put value r2 into r1 */

// 0x7F
void LD_A_A(CPU &cpu) { cpu.regs.A = cpu.regs.A; }

// 0x78
void LD_A_B(CPU &cpu) { cpu.regs.A = cpu.regs.B; }

// 0x79
void LD_A_C(CPU &cpu) { cpu.regs.A = cpu.regs.C; }

// 0x7A
void LD_A_D(CPU &cpu) { cpu.regs.A = cpu.regs.D; }

// 0x7B
void LD_A_E(CPU &cpu) { cpu.regs.A = cpu.regs.E; }

// 0x7C
void LD_A_H(CPU &cpu) { cpu.regs.A = cpu.regs.H; }

// 0x7D
void LD_A_L(CPU &cpu) { cpu.regs.A = cpu.regs.L; }

// 0x7E
void LD_A_HL(CPU &cpu) { cpu.regs.A = (cpu.regs.H << 8) | cpu.regs.L; }

// 0x40
void LD_B_B(CPU &cpu) { cpu.regs.B = cpu.regs.B; }

// 0x41
void LD_B_C(CPU &cpu) { cpu.regs.B = cpu.regs.C; }

// 0x42
void LD_B_D(CPU &cpu) { cpu.regs.B = cpu.regs.D; }
