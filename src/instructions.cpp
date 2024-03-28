#include <instructions.h>

// 0x00
 
// 0x01
void LD_BC_NN(CPU &cpu, MMU &mmu) {
    u8 lsb, msb;
    u16 nn;

    lsb = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;

    msb = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;

    nn = (lsb << 8) | msb;
    cpu.set_reg16_bc(nn);
}
 
// 0x02
void LD_BC_A(CPU &cpu, MMU &mmu) {
    mmu.bus_write(cpu.get_reg16_bc(), cpu.regs.A);
}
 
// 0x03
void INC_BC(CPU &cpu) {
    cpu.set_reg16_bc(cpu.get_reg16_bc() + 1);
}
 
// 0x04
void INC_B(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.B + 1;
    carry_per_bit = result;
    cpu.regs.B = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
}
 
// 0x05
void DEC_B(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.B - 1;
    carry_per_bit = result;
    cpu.regs.B = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 1;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
}
 
// 0x06
void LD_B_N(CPU &cpu, MMU &mmu) {
    cpu.regs.B = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;
}

// 0x07
 
// 0x08
void LD_NN_SP(CPU &cpu, MMU &mmu) {
    u8 lsb, msb;
    u8 sp_lsb, sp_msb;
    u16 nn;

    lsb = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;

    msb = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;

    nn = (lsb << 8) | msb;
    sp_lsb = cpu.regs.SP & 0xFF;
    sp_msb = (cpu.regs.SP >> 8) & 0xFF;

    mmu.bus_write(nn, sp_lsb);
    nn += 0x1;
    mmu.bus_write(nn, sp_msb);
}
 
// 0x09
void ADD_HL_BC(CPU &cpu) {
    u16 result, carry_per_bit;

    result = cpu.get_reg16_hl() + cpu.get_reg16_bc();
    carry_per_bit = result;
    cpu.set_reg16_hl(result);

    cpu.flags.N = 0;
    ((carry_per_bit >> 11) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 15) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}
 
// 0x0A
void LD_A_BC(CPU &cpu, MMU &mmu) {
    cpu.regs.A = mmu.bus_read(cpu.get_reg16_bc());
}
 
// 0x0B
void DEC_BC(CPU &cpu) {
    cpu.set_reg16_bc(cpu.get_reg16_bc() - 1);
}
 
// 0x0C
void INC_C(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.C + 1;
    carry_per_bit = result;
    cpu.regs.C = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
}
 
// 0x0D
void DEC_C(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.C - 1;
    carry_per_bit = result;
    cpu.regs.C = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 1;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
}
 
// 0x0E
void LD_C_N(CPU &cpu, MMU &mmu) {
    cpu.regs.C = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;
}
 
// 0x0F

// 0x10
 
// 0x11
void LD_DE_NN(CPU &cpu, MMU &mmu) {
    u8 lsb, msb;
    u16 nn;

    lsb = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;

    msb = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;

    nn = (lsb << 8) | msb;
    cpu.set_reg16_de(nn);
}
 
// 0x12
void LD_DE_A(CPU &cpu, MMU &mmu) {
    mmu.bus_write(cpu.get_reg16_de(), cpu.regs.A);
}
 
// 0x13
void INC_DE(CPU &cpu) {
    cpu.set_reg16_de(cpu.get_reg16_de() + 1);
}
 
// 0x14
void INC_D(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.D + 1;
    carry_per_bit = result;
    cpu.regs.D = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
}
 
// 0x15
void DEC_D(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.D - 1;
    carry_per_bit = result;
    cpu.regs.D = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 1;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
}
 
// 0x16
void LD_D_N(CPU &cpu, MMU &mmu) {
    cpu.regs.D = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;
}
 
// 0x17
 
// 0x18
 
// 0x19
void ADD_HL_DE(CPU &cpu) {
    u16 result, carry_per_bit;

    result = cpu.get_reg16_hl() + cpu.get_reg16_de();
    carry_per_bit = result;
    cpu.set_reg16_hl(result);

    cpu.flags.N = 0;
    ((carry_per_bit >> 11) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 15) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}
 
// 0x1A
void LD_A_DE(CPU &cpu, MMU &mmu) {
    cpu.regs.A = mmu.bus_read(cpu.get_reg16_de());
}
 
// 0x1B
void DEC_DE(CPU &cpu) {
    cpu.set_reg16_de(cpu.get_reg16_de() - 1);
}
 
// 0x1C
void INC_E(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.E + 1;
    carry_per_bit = result;
    cpu.regs.E = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
}
 
// 0x1D
void DEC_E(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.E - 1;
    carry_per_bit = result;
    cpu.regs.E = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 1;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
}
 
// 0x1E
void LD_E_N(CPU &cpu, MMU &mmu) {
    cpu.regs.E = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;
}
 
// 0x1F

// 0x20

// 0x21
void LD_HL_NN(CPU &cpu, MMU &mmu) {
    u8 lsb, msb;
    u16 nn;

    lsb = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;

    msb = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;

    nn = (lsb << 8) | msb;
    cpu.set_reg16_hl(nn);
}

// 0x22
void LD_HL_PLUS_A(CPU &cpu, MMU &mmu) {
    mmu.bus_write(cpu.get_reg16_hl(), cpu.regs.A);
    cpu.set_reg16_hl(cpu.get_reg16_hl() + 1);
}

// 0x23
void INC_HL(CPU &cpu) {
    cpu.set_reg16_hl(cpu.get_reg16_hl() + 1);
}

// 0x24
void INC_H(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.H + 1;
    carry_per_bit = result;
    cpu.regs.H = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
}

// 0x25
void DEC_H(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.H - 1;
    carry_per_bit = result;
    cpu.regs.H = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 1;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
}

// 0x26
void LD_H_N(CPU &cpu, MMU &mmu) {
    cpu.regs.H = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;
}

// 0x27 TODO figure out implementation

// 0x28

// 0x29
void ADD_HL_HL(CPU &cpu) {
    u16 result, carry_per_bit;

    result = cpu.get_reg16_hl() + cpu.get_reg16_hl();
    carry_per_bit = result;
    cpu.set_reg16_hl(result);

    cpu.flags.N = 0;
    ((carry_per_bit >> 11) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 15) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0x2A
void LD_A_HL_PLUS(CPU &cpu, MMU &mmu) {
    cpu.regs.A = mmu.bus_read(cpu.get_reg16_hl());
    cpu.set_reg16_hl(cpu.get_reg16_hl() + 1);
}

// 0x2B
void DEC_HL(CPU &cpu) {
    cpu.set_reg16_hl(cpu.get_reg16_hl() - 1);
}

// 0x2C
void INC_L(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.L + 1;
    carry_per_bit = result;
    cpu.regs.L = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
}

// 0x2D
void DEC_L(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.L - 1;
    carry_per_bit = result;
    cpu.regs.L = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 1;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
}

// 0x2E
void LD_L_N(CPU &cpu, MMU &mmu) {
    cpu.regs.L = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;
}

// 0x2F
void CPL(CPU & cpu) {
    cpu.regs.A = ~cpu.regs.A;
    cpu.flags.N = 1;
    cpu.flags.H = 1;
}

// 0x30

// 0x31
void LD_SP_NN(CPU &cpu, MMU &mmu) {
    u8 lsb, msb;
    u16 nn;

    lsb = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;

    msb = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;

    nn = (lsb << 8) | msb;
    cpu.regs.SP = nn;
}

// 0x32
void LD_HL_MINUS_A(CPU &cpu, MMU &mmu) {
    mmu.bus_write(cpu.get_reg16_hl(), cpu.regs.A);
    cpu.set_reg16_hl(cpu.get_reg16_hl() - 1);
}

// 0x33
void INC_SP(CPU &cpu) {
    cpu.regs.SP += 0x1;
}

// 0x34
void INC_HL(CPU &cpu, MMU &mmu) {
    u8 result, carry_per_bit;

    result = mmu.bus_read(cpu.get_reg16_hl()) + 1;
    carry_per_bit = result;
    mmu.bus_write(cpu.get_reg16_hl(), result);

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
}

// 0x35
void DEC_HL(CPU &cpu, MMU &mmu) {
    u8 result, carry_per_bit;

    result = mmu.bus_read(cpu.get_reg16_hl()) - 1;
    carry_per_bit = result;
    mmu.bus_write(cpu.get_reg16_hl(), result);

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 1;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
}

// 0x36
void LD_HL_N(CPU &cpu, MMU &mmu) {
    u8 n = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;
    mmu.bus_write(cpu.get_reg16_hl(), n);
}

// 0x37
void SCF(CPU &cpu) {
    cpu.flags.N = 0;
    cpu.flags.H = 0;
    cpu.flags.C = 1;
}

// 0x38

// 0x39
void ADD_HL_SP(CPU &cpu) {
    u16 result, carry_per_bit;

    result = cpu.get_reg16_hl() + cpu.regs.SP;
    carry_per_bit = result;
    cpu.set_reg16_hl(result);

    cpu.flags.N = 0;
    ((carry_per_bit >> 11) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 15) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0x3A
void LD_A_HL_MINUS(CPU &cpu, MMU &mmu) {
    cpu.regs.A = mmu.bus_read(cpu.get_reg16_hl());
    cpu.set_reg16_hl(cpu.get_reg16_hl() - 1);
}

// 0x3B
void DEC_SP(CPU &cpu) {
    cpu.regs.SP -= 0x1;
}

// 0x3C
void INC_A(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A + 1;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
}

// 0x3D
void DEC_A(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A - 1;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 1;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
}

// 0x3E

// 0x3F
void CCF(CPU &cpu) {
    cpu.flags.N = 0;
    cpu.flags.H = 0;
    cpu.flags.C = ~cpu.flags.C;
}

// 0x40
void LD_B_B(CPU &cpu) {
    cpu.regs.B = cpu.regs.B;
}

// 0x41
void LD_B_C(CPU &cpu) {
    cpu.regs.B = cpu.regs.C;
}

// 0x42
void LD_B_D(CPU &cpu) {
    cpu.regs.B = cpu.regs.D;
}

// 0x43
void LD_B_E(CPU &cpu) {
    cpu.regs.B = cpu.regs.E;
}

// 0x44
void LD_B_H(CPU &cpu) {
    cpu.regs.B = cpu.regs.H;
}

// 0x45
void LD_B_L(CPU &cpu) {
    cpu.regs.B = cpu.regs.L;
}

// 0x46
void LD_B_HL(CPU &cpu, MMU &mmu) {
    cpu.regs.B = mmu.bus_read(cpu.get_reg16_hl());
}

// 0x47

// 0x48
void LD_C_B(CPU &cpu) {
    cpu.regs.C = cpu.regs.B;
}

// 0x49
void LD_C_C(CPU &cpu) {
    cpu.regs.C = cpu.regs.C;
}

// 0x4A
void LD_C_D(CPU &cpu) {
    cpu.regs.C = cpu.regs.D;
}

// 0x4B
void LD_C_E(CPU &cpu) {
    cpu.regs.C = cpu.regs.E;
}

// 0x4C
void LD_C_H(CPU &cpu) {
    cpu.regs.C = cpu.regs.H;
}

// 0x4D
void LD_C_L(CPU &cpu) {
    cpu.regs.C = cpu.regs.L;
}

// 0x4E
void LD_C_HL(CPU &cpu, MMU &mmu) {
    cpu.regs.C = mmu.bus_read(cpu.get_reg16_hl());
}

// 0x4F

// 0x50
void LD_D_B(CPU &cpu) {
    cpu.regs.D = cpu.regs.B;
}

// 0x51
void LD_D_C(CPU &cpu) {
    cpu.regs.D = cpu.regs.C;
}

// 0x52
void LD_D_D(CPU &cpu) {
    cpu.regs.D = cpu.regs.D;
}

// 0x53
void LD_D_E(CPU &cpu) {
    cpu.regs.D = cpu.regs.E;
}

// 0x54
void LD_D_H(CPU &cpu) {
    cpu.regs.D = cpu.regs.H;
}

// 0x55
void LD_D_L(CPU &cpu) {
    cpu.regs.D = cpu.regs.L;
}

// 0x56
void LD_D_HL(CPU &cpu, MMU &mmu) {
    cpu.regs.D = mmu.bus_read(cpu.get_reg16_hl());
}

// 0x57

// 0x58
void LD_E_B(CPU &cpu) {
    cpu.regs.E = cpu.regs.B;
}

// 0x59
void LD_E_C(CPU &cpu) {
    cpu.regs.E = cpu.regs.C;
}

// 0x5A
void LD_E_D(CPU &cpu) {
    cpu.regs.E = cpu.regs.D;
}

// 0x5B
void LD_E_E(CPU &cpu) {
    cpu.regs.E = cpu.regs.E;
}

// 0x5C
void LD_E_H(CPU &cpu) {
    cpu.regs.E = cpu.regs.H;
}

// 0x5D
void LD_E_L(CPU &cpu) {
    cpu.regs.E = cpu.regs.L;
}

// 0x5E
void LD_E_HL(CPU &cpu, MMU &mmu) {
    cpu.regs.E = mmu.bus_read(cpu.get_reg16_hl());
}

// 0x5F

// 0x60
void LD_H_B(CPU &cpu) {
    cpu.regs.H = cpu.regs.B;
}

// 0x61
void LD_H_C(CPU &cpu) {
    cpu.regs.H = cpu.regs.C;
}

// 0x62
void LD_H_D(CPU &cpu) {
    cpu.regs.H = cpu.regs.D;
}

// 0x63
void LD_H_E(CPU &cpu) {
    cpu.regs.H = cpu.regs.E;
}

// 0x64
void LD_H_H(CPU &cpu) {
    cpu.regs.H = cpu.regs.H;
}

// 0x65
void LD_H_L(CPU &cpu) {
    cpu.regs.H = cpu.regs.L;
}

// 0x66
void LD_H_HL(CPU &cpu, MMU &mmu) {
    cpu.regs.H = mmu.bus_read(cpu.get_reg16_hl());
}

// 0x67

// 0x68
void LD_L_B(CPU &cpu) {
    cpu.regs.L = cpu.regs.B;
}

// 0x69
void LD_L_C(CPU &cpu) {
    cpu.regs.L = cpu.regs.C;
}

// 0x6A
void LD_L_D(CPU &cpu) {
    cpu.regs.L = cpu.regs.D;
}

// 0x6B
void LD_L_E(CPU &cpu) {
    cpu.regs.L = cpu.regs.E;
}

// 0x6C
void LD_L_H(CPU &cpu) {
    cpu.regs.L = cpu.regs.H;
}

// 0x6D
void LD_L_L(CPU &cpu) {
    cpu.regs.L = cpu.regs.L;
}

// 0x6E
void LD_L_HL(CPU &cpu, MMU &mmu) {
    cpu.regs.L = mmu.bus_read(cpu.get_reg16_hl());
}

// 0x6F

// 0x70
void LD_HL_B(CPU &cpu, MMU &mmu) {
    mmu.bus_write(cpu.get_reg16_hl(), cpu.regs.B);
}

// 0x71
void LD_HL_C(CPU &cpu, MMU &mmu) {
    mmu.bus_write(cpu.get_reg16_hl(), cpu.regs.C);
}

// 0x72
void LD_HL_D(CPU &cpu, MMU &mmu) {
    mmu.bus_write(cpu.get_reg16_hl(), cpu.regs.D);
}

// 0x73
void LD_HL_E(CPU &cpu, MMU &mmu) {
    mmu.bus_write(cpu.get_reg16_hl(), cpu.regs.E);
}

// 0x74
void LD_HL_H(CPU &cpu, MMU &mmu) {
    mmu.bus_write(cpu.get_reg16_hl(), cpu.regs.H);
}

// 0x75
void LD_HL_L(CPU &cpu, MMU &mmu) {
    mmu.bus_write(cpu.get_reg16_hl(), cpu.regs.L);
}

// 0x76

// 0x77

// 0x78
void LD_A_B(CPU &cpu) {
    cpu.regs.A = cpu.regs.B;
}

// 0x79
void LD_A_C(CPU &cpu) {
    cpu.regs.A = cpu.regs.C;
}

// 0x7A
void LD_A_D(CPU &cpu) {
    cpu.regs.A = cpu.regs.D;
}

// 0x7B
void LD_A_E(CPU &cpu) {
    cpu.regs.A = cpu.regs.E;
}

// 0x7C
void LD_A_H(CPU &cpu) {
    cpu.regs.A = cpu.regs.H;
}

// 0x7D
void LD_A_L(CPU &cpu) {
    cpu.regs.A = cpu.regs.L;
}

// 0x7E
void LD_A_HL(CPU &cpu, MMU &mmu) {
    cpu.regs.A = mmu.bus_read(cpu.get_reg16_hl());
}

// 0x7F
void LD_A_A(CPU &cpu) {
    cpu.regs.A = cpu.regs.A;
}
 
// 0x80
void ADD_A_B(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A + cpu.regs.B;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0x81
void ADD_A_C(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A + cpu.regs.C;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0x82
void ADD_A_D(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A + cpu.regs.D;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0x83
void ADD_A_E(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A + cpu.regs.E;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0x84
void ADD_A_H(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A + cpu.regs.H;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0x85
void ADD_A_L(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A + cpu.regs.L;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0x86
void ADD_A_HL(CPU &cpu, MMU &mmu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A + mmu.bus_read(cpu.get_reg16_hl());
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0x87 FIXME result may need to be 16-bit
void ADD_A_A(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A + cpu.regs.A;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0x88
void ADC_A_B(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A + cpu.regs.B + cpu.flags.C;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0x89
void ADC_A_C(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A + cpu.regs.C + cpu.flags.C;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0x8A
void ADC_A_D(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A + cpu.regs.D + cpu.flags.C;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0x8B
void ADC_A_E(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A + cpu.regs.E + cpu.flags.C;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0x8C
void ADC_A_H(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A + cpu.regs.H + cpu.flags.C;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0x8D
void ADC_A_L(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A + cpu.regs.L + cpu.flags.C;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0x8E
void ADC_A_HL(CPU &cpu, MMU &mmu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A + mmu.bus_read(cpu.get_reg16_hl()) + cpu.flags.C;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0x8F
void ADC_A_A(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A + cpu.regs.A + cpu.flags.C;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0x90
void SUB_A_B(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A - cpu.regs.B;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0x91
void SUB_A_C(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A - cpu.regs.C;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0x92
void SUB_A_D(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A - cpu.regs.D;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0x93
void SUB_A_E(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A - cpu.regs.E;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0x94
void SUB_A_H(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A - cpu.regs.H;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0x95
void SUB_A_L(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A - cpu.regs.L;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0x96
void SUB_A_HL(CPU &cpu, MMU &mmu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A - mmu.bus_read(cpu.get_reg16_hl());
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0x97 FIXME would always give zero?
void SUB_A_A(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A - cpu.regs.A;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0x98
void SBC_A_B(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A - cpu.regs.B - cpu.flags.C;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0x99
void SBC_A_C(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A - cpu.regs.C - cpu.flags.C;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0x9A
void SBC_A_D(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A - cpu.regs.D - cpu.flags.C;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0x9B
void SBC_A_E(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A - cpu.regs.E - cpu.flags.C;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0x9C
void SBC_A_H(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A - cpu.regs.H - cpu.flags.C;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0x9D
void SBC_A_L(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A - cpu.regs.L - cpu.flags.C;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0x9E
void SBC_A_HL(CPU &cpu, MMU &mmu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A - mmu.bus_read(cpu.get_reg16_hl()) - cpu.flags.C;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0x9F
void SBC_A_A(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A - cpu.regs.A - cpu.flags.C;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}
 
// 0xA0
void AND_B(CPU &cpu) {
    u8 result = cpu.regs.A & cpu.regs.B;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    cpu.flags.H = 1;
    cpu.flags.C = 0;
}

// 0xA1
void AND_C(CPU &cpu) {
    u8 result = cpu.regs.A & cpu.regs.C;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    cpu.flags.H = 1;
    cpu.flags.C = 0;
}

// 0xA2
void AND_D(CPU &cpu) {
    u8 result = cpu.regs.A & cpu.regs.D;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    cpu.flags.H = 1;
    cpu.flags.C = 0;
}

// 0xA3
void AND_E(CPU &cpu) {
    u8 result = cpu.regs.A & cpu.regs.E;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    cpu.flags.H = 1;
    cpu.flags.C = 0;
}

// 0xA4
void AND_H(CPU &cpu) {
    u8 result = cpu.regs.A & cpu.regs.H;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    cpu.flags.H = 1;
    cpu.flags.C = 0;
}

// 0xA5
void AND_L(CPU &cpu) {
    u8 result = cpu.regs.A & cpu.regs.L;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    cpu.flags.H = 1;
    cpu.flags.C = 0;
}

// 0xA6
void AND_HL(CPU &cpu, MMU &mmu) {
    u8 result = cpu.regs.A & mmu.bus_read(cpu.get_reg16_hl());
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    cpu.flags.H = 1;
    cpu.flags.C = 0;
}

// 0xA7
void AND_A(CPU &cpu) {
    u8 result = cpu.regs.A & cpu.regs.A;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    cpu.flags.H = 1;
    cpu.flags.C = 0;
}

// 0xA8
void XOR_B(CPU &cpu) {
    u8 result = cpu.regs.A ^ cpu.regs.B;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    cpu.flags.H = 0;
    cpu.flags.C = 0;
}

// 0xA9
void XOR_C(CPU &cpu) {
    u8 result = cpu.regs.A ^ cpu.regs.C;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    cpu.flags.H = 0;
    cpu.flags.C = 0;
}

// 0xAA
void XOR_D(CPU &cpu) {
    u8 result = cpu.regs.A ^ cpu.regs.D;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    cpu.flags.H = 0;
    cpu.flags.C = 0;
}

// 0xAB
void XOR_E(CPU &cpu) {
    u8 result = cpu.regs.A ^ cpu.regs.E;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    cpu.flags.H = 0;
    cpu.flags.C = 0;
}

// 0xAC
void XOR_H(CPU &cpu) {
    u8 result = cpu.regs.A ^ cpu.regs.H;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    cpu.flags.H = 0;
    cpu.flags.C = 0;
}

// 0xAD
void XOR_L(CPU &cpu) {
    u8 result = cpu.regs.A ^ cpu.regs.L;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    cpu.flags.H = 0;
    cpu.flags.C = 0;
}

// 0xAE
void XOR_HL(CPU &cpu, MMU &mmu) {
    u8 result = cpu.regs.A ^ mmu.bus_read(cpu.get_reg16_hl());
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    cpu.flags.H = 0;
    cpu.flags.C = 0;
}

// 0xAF
void XOR_A(CPU &cpu) {
    u8 result = cpu.regs.A ^ cpu.regs.A;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    cpu.flags.H = 0;
    cpu.flags.C = 0;
}
 
// 0xB0
void OR_B(CPU &cpu) {
    u8 result = cpu.regs.A | cpu.regs.B;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    cpu.flags.H = 0;
    cpu.flags.C = 0;
}

// 0xB1
void OR_C(CPU &cpu) {
    u8 result = cpu.regs.A | cpu.regs.C;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    cpu.flags.H = 0;
    cpu.flags.C = 0;
}

// 0xB2
void OR_D(CPU &cpu) {
    u8 result = cpu.regs.A | cpu.regs.D;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    cpu.flags.H = 0;
    cpu.flags.C = 0;
}

// 0xB3
void OR_E(CPU &cpu) {
    u8 result = cpu.regs.A | cpu.regs.E;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    cpu.flags.H = 0;
    cpu.flags.C = 0;
}

// 0xB4
void OR_H(CPU &cpu) {
    u8 result = cpu.regs.A | cpu.regs.H;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    cpu.flags.H = 0;
    cpu.flags.C = 0;
}

// 0xB5
void OR_L(CPU &cpu) {
    u8 result = cpu.regs.A | cpu.regs.L;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    cpu.flags.H = 0;
    cpu.flags.C = 0;
}

// 0xB6
void OR_HL(CPU &cpu, MMU &mmu) {
    u8 result = cpu.regs.A | mmu.bus_read(cpu.get_reg16_hl());
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    cpu.flags.H = 0;
    cpu.flags.C = 0;
}

// 0xB7
void OR_A(CPU &cpu) {
    u8 result = cpu.regs.A | cpu.regs.A;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    cpu.flags.H = 0;
    cpu.flags.C = 0;
}

// 0xB8
void CP_B(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A - cpu.regs.B;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 1;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0xB9
void CP_C(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A - cpu.regs.C;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 1;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0xBA
void CP_D(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A - cpu.regs.D;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 1;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0xBB
void CP_E(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A - cpu.regs.E;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 1;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0xBC
void CP_H(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A - cpu.regs.H;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 1;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0xBD
void CP_L(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A - cpu.regs.L;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 1;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0xBE
void CP_HL(CPU &cpu, MMU &mmu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A - mmu.bus_read(cpu.get_reg16_hl());
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 1;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0xBF
void CP_A(CPU &cpu) {
    u8 result, carry_per_bit;

    result = cpu.regs.A - cpu.regs.A;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 1;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0xC0

// 0xC1
void POP_BC(CPU &cpu) {
    u16 nn;
    u8 lsb, msb;

    lsb = cpu.stack_pop();
    msb = cpu.stack_pop();
    nn = (lsb << 8) | msb;

    cpu.set_reg16_bc(nn);
}

// 0xC2

// 0xC3

// 0xC4

// 0xC5
void PUSH_BC(CPU &cpu) {
    u16 rr;
    u8 lsb, msb;

    rr = cpu.get_reg16_bc();
    lsb = rr & 0xFF;
    msb = (rr >> 8) & 0xFF;

    cpu.regs.SP -= 0x1;
    cpu.stack_push(lsb);
    cpu.stack_push(msb);
}

// 0xC6
void ADD_A_N(CPU &cpu, MMU &mmu) {
    u8 result, carry_per_bit, n;

    n = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;

    result = cpu.regs.A + n;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0xC7

// 0xC8

// 0xC9

// 0xCA

// 0xCB

// 0xCC

// 0xCD

// 0xCE
void ADC_A_N(CPU &cpu, MMU &mmu) {
    u8 result, carry_per_bit, n;

    n = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;

    result = cpu.regs.A + n + cpu.flags.C;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0xCF
 
// 0xD0

// 0xD1
void POP_DE(CPU &cpu) {
    u16 nn;
    u8 lsb, msb;

    lsb = cpu.stack_pop();
    msb = cpu.stack_pop();
    nn = (lsb << 8) | msb;

    cpu.set_reg16_de(nn);
}

// 0xD2

// 0xD3

// 0xD4

// 0xD5
void PUSH_DE(CPU &cpu) {
    u16 rr;
    u8 lsb, msb;

    rr = cpu.get_reg16_de();
    lsb = rr & 0xFF;
    msb = (rr >> 8) & 0xFF;

    cpu.regs.SP -= 0x1;
    cpu.stack_push(lsb);
    cpu.stack_push(msb);
}

// 0xD6
void SUB_A_N(CPU &cpu, MMU &mmu) {
    u8 result, carry_per_bit, n;

    n = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;

    result = cpu.regs.A - n;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0xD7

// 0xD8

// 0xD9

// 0xDA

// 0xDB

// 0xDC

// 0xDD

// 0xDE
void SBC_A_N(CPU &cpu, MMU &mmu) {
    u8 result, carry_per_bit, n;

    n = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;

    result = cpu.regs.A - n - cpu.flags.C;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0xDF
 
// 0xE0
void LDH_N_A(CPU &cpu, MMU &mmu) {
    u8 n = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;

    mmu.bus_write(0xFF00 | n, cpu.regs.A);
}

// 0xE1
void POP_HL(CPU &cpu) {
    u16 nn;
    u8 lsb, msb;

    lsb = cpu.stack_pop();
    msb = cpu.stack_pop();
    nn = (lsb << 8) | msb;

    cpu.set_reg16_hl(nn);
}

// 0xE2
void LDH_C_A(CPU &cpu, MMU &mmu) {
    mmu.bus_write(0xFF00 | cpu.regs.C, cpu.regs.A);
}

// 0xE3

// 0xE4

// 0xE5
void PUSH_HL(CPU &cpu) {
    u16 rr;
    u8 lsb, msb;

    rr = cpu.get_reg16_hl();
    lsb = rr & 0xFF;
    msb = (rr >> 8) & 0xFF;

    cpu.regs.SP -= 0x1;
    cpu.stack_push(lsb);
    cpu.stack_push(msb);
}

// 0xE6
void AND_N(CPU &cpu, MMU &mmu) {
    u8 result, n;

    n = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;

    result = cpu.regs.A & n;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    cpu.flags.H = 1;
    cpu.flags.C = 0;
}

// 0xE7

// 0xE8
void ADD_SP_E(CPU &cpu, MMU &mmu) {
    u16 result, carry_per_bit;
    i8 e;

    e = (i8)mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;

    result = cpu.regs.SP + e;
    carry_per_bit = result;
    cpu.regs.SP = result;

    cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0xE9

// 0xEA FIXME bit shift might be wrong, lsb might need swap with msb
void LD_NN_A(CPU &cpu, MMU &mmu) {
    u8 lsb, msb;
    u16 nn;

    lsb = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;

    msb = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;

    nn = (msb << 8) | lsb;
    mmu.bus_write(nn, cpu.regs.A);
}

// 0xEB

// 0xEC

// 0xED

// 0xEE
void XOR_N(CPU &cpu, MMU &mmu) {
    u8 result, n;

    n = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;

    result = cpu.regs.A ^ mmu.bus_read(cpu.get_reg16_hl());
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    cpu.flags.H = 0;
    cpu.flags.C = 0;
}

// 0xEF
 
// 0xF0
void LDH_A_N(CPU &cpu, MMU &mmu) {
    u8 n = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;

    cpu.regs.A = mmu.bus_read(0xFF00 | n);
}

// 0xF1
void POP_AF(CPU &cpu) {
    u16 nn;
    u8 lsb, msb;

    lsb = cpu.stack_pop();
    msb = cpu.stack_pop();
    nn = (lsb << 8) | msb;

    cpu.set_reg16_af(nn);
}

// 0xF2
void LDH_A_C(CPU &cpu, MMU &mmu) {
    cpu.regs.A = mmu.bus_read(0xFF00 | cpu.regs.C);
}

// 0xF3

// 0xF4

// 0xF5
void PUSH_AF(CPU &cpu) {
    u16 rr;
    u8 lsb, msb;

    rr = cpu.get_reg16_af();
    lsb = rr & 0xFF;
    msb = (rr >> 8) & 0xFF;

    cpu.regs.SP -= 0x1;
    cpu.stack_push(lsb);
    cpu.stack_push(msb);
}

// 0xF6
void OR_N(CPU &cpu, MMU &mmu) {
    u8 result, n;

    n = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;

    result = cpu.regs.A | n;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 0;
    cpu.flags.H = 0;
    cpu.flags.C = 0;
}

// 0xF7

// 0xF8
void LD_HL_SP_PLUS_E(CPU &cpu, MMU &mmu) {
    u16 result, carry_per_bit;
    i8 e;

    e = (i8)mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;

    result = cpu.regs.SP + e;
    carry_per_bit = result;
    cpu.set_reg16_hl(result);

    cpu.flags.Z = 0;
    cpu.flags.N = 0;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0xF9
void LD_SP_HL(CPU &cpu) {
    cpu.regs.SP = cpu.get_reg16_hl();
}

// 0xFA FIXME bit shift might be wrong, lsb might need swap with msb
void LD_A_NN(CPU &cpu, MMU &mmu) {
    u8 lsb, msb;
    u16 nn;

    lsb = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;

    msb = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;

    nn = (msb << 8) | lsb;
    cpu.regs.A = mmu.bus_read(nn);
}

// 0xFB

// 0xFC

// 0xFD

// 0xFE
void CP_N(CPU &cpu, MMU &mmu) {
    u8 result, carry_per_bit, n;

    n = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;

    result = cpu.regs.A - n;
    carry_per_bit = result;
    cpu.regs.A = result;

    (result == 0) ? cpu.flags.Z = 1 : cpu.flags.Z = 0;
    cpu.flags.N = 1;
    ((carry_per_bit >> 3) & 0x01) == 0x1 ? cpu.flags.H = 1 : cpu.flags.H = 0;
    ((carry_per_bit >> 7) & 0x01) == 0x1 ? cpu.flags.C = 1 : cpu.flags.C = 0;
}

// 0xFF
