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
void LD_A_HL(CPU &cpu) { cpu.regs.A = cpu.regs.HL; }

// 0x40
void LD_B_B(CPU &cpu) { cpu.regs.B = cpu.regs.B; }

// 0x41
void LD_B_C(CPU &cpu) { cpu.regs.B = cpu.regs.C; }

// 0x42
void LD_B_D(CPU &cpu) { cpu.regs.B = cpu.regs.D; }

// 0x43
void LD_B_E(CPU &cpu) { cpu.regs.B = cpu.regs.E; }

// 0x44
void LD_B_H(CPU &cpu) { cpu.regs.B = cpu.regs.H; }

// 0x45
void LD_B_L(CPU &cpu) { cpu.regs.B = cpu.regs.L; }

// 0x46
void LD_B_HL(CPU &cpu) { cpu.regs.B = cpu.regs.HL; }

// 0x48
void LD_C_B(CPU &cpu) { cpu.regs.C = cpu.regs.B; }

// 0x49
void LD_C_C(CPU &cpu) { cpu.regs.C = cpu.regs.C; }

// 0x4A
void LD_C_D(CPU &cpu) { cpu.regs.C = cpu.regs.D; }

// 0x4B
void LD_C_E(CPU &cpu) { cpu.regs.C = cpu.regs.E; }

// 0x4C
void LD_C_H(CPU &cpu) { cpu.regs.C = cpu.regs.H; }

// 0x4D
void LD_C_L(CPU &cpu) { cpu.regs.C = cpu.regs.L; }

// 0x4E
void LD_C_HL(CPU &cpu) { cpu.regs.C = cpu.regs.HL; }

// 0x50
void LD_D_B(CPU &cpu) { cpu.regs.D = cpu.regs.B; }

// 0x51
void LD_D_C(CPU &cpu) { cpu.regs.D = cpu.regs.C; }

// 0x52
void LD_D_D(CPU &cpu) { cpu.regs.D = cpu.regs.D; }

// 0x53
void LD_D_E(CPU &cpu) { cpu.regs.D = cpu.regs.E; }

// 0x54
void LD_D_H(CPU &cpu) { cpu.regs.D = cpu.regs.H; }

// 0x55
void LD_D_L(CPU &cpu) { cpu.regs.D = cpu.regs.L; }

// 0x56
void LD_D_HL(CPU &cpu) { cpu.regs.D = cpu.regs.HL; }

// 0x58
void LD_E_B(CPU &cpu) { cpu.regs.E = cpu.regs.B; }

// 0x59
void LD_E_C(CPU &cpu) { cpu.regs.E = cpu.regs.C; }

// 0x5A
void LD_E_D(CPU &cpu) { cpu.regs.E = cpu.regs.D; }

// 0x5B
void LD_E_E(CPU &cpu) { cpu.regs.E = cpu.regs.E; }

// 0x5C
void LD_E_H(CPU &cpu) { cpu.regs.E = cpu.regs.H; }

// 0x5D
void LD_E_L(CPU &cpu) { cpu.regs.E = cpu.regs.L; }

// 0x5E
void LD_E_HL(CPU &cpu) { cpu.regs.E = cpu.regs.HL; }

// 0x60
void LD_H_B(CPU &cpu) { cpu.regs.H = cpu.regs.B; }

// 0x61
void LD_H_C(CPU &cpu) { cpu.regs.H = cpu.regs.C; }

// 0x62
void LD_H_D(CPU &cpu) { cpu.regs.H = cpu.regs.D; }

// 0x63
void LD_H_E(CPU &cpu) { cpu.regs.H = cpu.regs.E; }

// 0x64
void LD_H_H(CPU &cpu) { cpu.regs.H = cpu.regs.H; }

// 0x65
void LD_H_L(CPU &cpu) { cpu.regs.H = cpu.regs.L; }

// 0x66
void LD_H_HL(CPU &cpu) { cpu.regs.H = cpu.regs.HL; }

// 0x68
void LD_L_B(CPU &cpu) { cpu.regs.L = cpu.regs.B; }

// 0x69
void LD_L_C(CPU &cpu) { cpu.regs.L = cpu.regs.C; }

// 0x6A
void LD_L_D(CPU &cpu) { cpu.regs.L = cpu.regs.D; }

// 0x6B
void LD_L_E(CPU &cpu) { cpu.regs.L = cpu.regs.E; }

// 0x6C
void LD_L_H(CPU &cpu) { cpu.regs.L = cpu.regs.H; }

// 0x6D
void LD_L_L(CPU &cpu) { cpu.regs.L = cpu.regs.L; }

// 0x6E
void LD_L_HL(CPU &cpu) { cpu.regs.L = cpu.regs.HL; }

// 0x70
void LD_HL_B(CPU &cpu) { cpu.regs.HL = cpu.regs.B; }

// 0x71
void LD_HL_C(CPU &cpu) { cpu.regs.HL = cpu.regs.C; }

// 0x72
void LD_HL_D(CPU &cpu) { cpu.regs.HL = cpu.regs.D; }

// 0x73
void LD_HL_E(CPU &cpu) { cpu.regs.HL = cpu.regs.E; }

// 0x74
void LD_HL_H(CPU &cpu) { cpu.regs.HL = cpu.regs.H; }

// 0x75
void LD_HL_L(CPU &cpu) { cpu.regs.HL = cpu.regs.L; }

// 0x76
void LD_HL_HL(CPU &cpu) { cpu.regs.HL = cpu.regs.HL; }

// 0x36
void LD_HL_N(CPU &cpu, u8 n) { cpu.regs.HL = n; }


/*-- LD A,n --*/
/* Put value n into A */
/* Some opcode are already defined in LD r1r2 */

// 0x0A
void LD_A_BC(CPU &cpu) {cpu.regs.A = cpu.regs.BC; }

// 0x1A
void LD_A_DE(CPU &cpu) {cpu.regs.A = cpu.regs.DE; }

// 0xFA TODO
void LD_A_NN(CPU &cpu, u16 nn) {cpu.regs.A = nn; }

// 0x3E TODO
void LD_A_N(CPU &cpu, u8 n) {cpu.regs.A = n; }


/*-- LD n,A --*/
/* Put value A into n */
/* Some opcode are already defined in LD r1r2 */

// 0x47
void LD_B_A(CPU &cpu) { cpu.regs.B = cpu.regs.A; }

// 0x4F
void LD_C_A(CPU &cpu) { cpu.regs.C = cpu.regs.A; }

// 0x57
void LD_D_A(CPU &cpu) { cpu.regs.D = cpu.regs.A; }

// 0x5F
void LD_E_A(CPU &cpu) { cpu.regs.E = cpu.regs.A; }

// 0x67
void LD_H_A(CPU &cpu) { cpu.regs.H = cpu.regs.A; }

// 0x6F
void LD_L_A(CPU &cpu) { cpu.regs.L = cpu.regs.A; }

// 0x02
void LD_BC_A(CPU &cpu) { cpu.regs.BC = cpu.regs.A; }

// 0x12
void LD_DE_A(CPU &cpu) { cpu.regs.DE = cpu.regs.A; }

// 0x77
void LD_HL_A(CPU &cpu) { cpu.regs.HL = cpu.regs.A; }

//EA TODO
void LD_NN_A(CPU &cpu) {}


/*-- LD A,(C) --*/
/* Put value at address $FF00 + register C into A */

// 0xF2
void LD_A_PAREN_C(CPU &cpu, MMU &mmu) { cpu.regs.A = mmu.bus_read(0xFF00+cpu.regs.C); }


/*-- LD(C),A --*/
/* Put A into address $FF00 + register C */

// 0xE2
void LD_PAREN_C_A(CPU &cpu, MMU &mmu) { mmu.bus_write(0xFF00+cpu.regs.C, cpu.regs.A); }


/*-- LDD A,(HL) --*/
/* Put value at address HL into A. Decrement HL */

// 0x3A
void LDD_A_PAREN_HL(CPU &cpu, MMU &mmu) {
    cpu.regs.A = mmu.bus_read(cpu.regs.HL);
    cpu.regs.HL--;
}

/*-- LDD (HL),A --*/
/* Put A into memory address HL. Decrement HL */

// 0x32
void LDD_PAREN_HL_A(CPU &cpu, MMU &mmu) {
    mmu.bus_write(cpu.regs.HL, cpu.regs.A);
    cpu.regs.HL--;
}


/*-- LDI A,(HL)*/
/* Put value at address HL into A. Increment HL */

// 0x2A
void LDI_A_PAREN_HL(CPU &cpu, MMU &mmu) {
    cpu.regs.A = mmu.bus_read(cpu.regs.HL);
    cpu.regs.HL++;
}


/*-- LDI (HL),A*/
/* Put A into memory address HL. Increment HL */

// 0x22
void LDI_PAREN_HL_A(CPU &cpu, MMU &mmu) {
    mmu.bus_write(cpu.regs.HL, cpu.regs.A);
    cpu.regs.HL++;
}


/*-- LDH (n),A --*/
/* Put A into memory address $FF00+n */

// 0xE0
void LDH_PAREN_N_A(CPU &cpu, MMU &mmu, u8 n) { mmu.bus_write(0xFF00+n, cpu.regs.A); }


/*-- LDH A,(n) --*/
/* Put memory address $FF00+n into A */

// 0xF0
void LDH_A_PAREN_N(CPU &cpu, MMU &mmu, u8 n) { cpu.regs.A = mmu.bus_read(0xFF00+n); }


/*---- 16-BIT LOADS ----*/

/*-- LD n,nn --*/
/* Put value nn into n */

// 0x01
void LD_BC_NN(CPU &cpu, u16 nn) { cpu.regs.BC = nn; }

// 0x11
void LD_DE_NN(CPU &cpu, u16 nn) { cpu.regs.DE = nn; }

// 0x21
void LD_HL_NN(CPU &cpu, u16 nn) { cpu.regs.HL = nn; }

// 0x31
void LD_SP_NN(CPU &cpu, u16 nn) { cpu.regs.SP = nn; }


/*-- LD SP,HL --*/
/* Put HL into SP */

// 0xF9
void LD_SP_HL(CPU &cpu) { cpu.regs.SP = cpu.regs.HL; }


/*-- LDHL SP, n --*/
/* Put SP+n effective address into HL. n is SIGNED */

// 0xF8 TODO Set flags
void LDHL_SP_N(CPU &cpu, i8 n) {
    cpu.regs.SP += n;
}
