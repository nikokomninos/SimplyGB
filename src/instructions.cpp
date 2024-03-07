#include <instructions.h>

// 0x00
 
// 0x01
 
// 0x02
void LD_BC_A(CPU &cpu, MMU &mmu) {
    mmu.bus_write(cpu.get_reg16_bc(), cpu.regs.A);
}
 
// 0x03
 
// 0x04
 
// 0x05
 
// 0x06
void LD_B_N(CPU &cpu, MMU &mmu) {
    cpu.regs.B = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;
}

// 0x07
 
// 0x08
 
// 0x09
 
// 0x0A
void LD_A_BC(CPU &cpu, MMU &mmu) {
    cpu.regs.A = mmu.bus_read(cpu.get_reg16_bc());
}
 
// 0x0B
 
// 0x0C
 
// 0x0D
 
// 0x0E
void LD_C_N(CPU &cpu, MMU &mmu) {
    cpu.regs.C = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;
}
 
// 0x0F

// 0x10
 
// 0x11
 
// 0x12
void LD_DE_A(CPU &cpu, MMU &mmu) {
    mmu.bus_write(cpu.get_reg16_de(), cpu.regs.A);
}
 
// 0x13
 
// 0x14
 
// 0x15
 
// 0x16
void LD_D_N(CPU &cpu, MMU &mmu) {
    cpu.regs.D = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;
}
 
// 0x17
 
// 0x18
 
// 0x19
 
// 0x1A
void LD_A_DE(CPU &cpu, MMU &mmu) {
    cpu.regs.A = mmu.bus_read(cpu.get_reg16_de());
}
 
// 0x1B
 
// 0x1C
 
// 0x1D
 
// 0x1E
void LD_E_N(CPU &cpu, MMU &mmu) {
    cpu.regs.E = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;
}
 
// 0x1F

// 0x20

// 0x21

// 0x22

// 0x23

// 0x24

// 0x25

// 0x26
void LD_H_N(CPU &cpu, MMU &mmu) {
    cpu.regs.H = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;
}

// 0x27

// 0x28

// 0x29

// 0x2A

// 0x2B

// 0x2C

// 0x2D

// 0x2E
void LD_L_N(CPU &cpu, MMU &mmu) {
    cpu.regs.L = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;
}

// 0x2F

// 0x30

// 0x31

// 0x32

// 0x33

// 0x34

// 0x35

// 0x36
void LD_HL_N(CPU &cpu, MMU &mmu) {
    u8 n = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;
    mmu.bus_write(cpu.get_reg16_hl(), n);
}

// 0x37

// 0x38

// 0x39

// 0x3A

// 0x3B

// 0x3C

// 0x3D

// 0x3E

// 0x3F

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

// 0x81

// 0x82

// 0x83

// 0x84

// 0x85

// 0x86

// 0x87

// 0x88

// 0x89

// 0x8A

// 0x8B

// 0x8C

// 0x8D

// 0x8E

// 0x8F

// 0x90

// 0x91

// 0x92

// 0x93

// 0x94

// 0x95

// 0x96

// 0x97

// 0x98

// 0x99

// 0x9A

// 0x9B

// 0x9C

// 0x9D

// 0x9E

// 0x9F
 
// 0xA0

// 0xA1

// 0xA2

// 0xA3

// 0xA4

// 0xA5

// 0xA6

// 0xA7

// 0xA8

// 0xA9

// 0xAA

// 0xAB

// 0xAC

// 0xAD

// 0xAE

// 0xAF
 
// 0xB0

// 0xB1

// 0xB2

// 0xB3

// 0xB4

// 0xB5

// 0xB6

// 0xB7

// 0xB8

// 0xB9

// 0xBA

// 0xBB

// 0xBC

// 0xBD

// 0xBE

// 0xBF

// 0xC0

// 0xC1

// 0xC2

// 0xC3

// 0xC4

// 0xC5

// 0xC6

// 0xC7

// 0xC8

// 0xC9

// 0xCA

// 0xCB

// 0xCC

// 0xCD

// 0xCE

// 0xCF
 
// 0xD0

// 0xD1

// 0xD2

// 0xD3

// 0xD4

// 0xD5

// 0xD6

// 0xD7

// 0xD8

// 0xD9

// 0xDA

// 0xDB

// 0xDC

// 0xDD

// 0xDE

// 0xDF
 
// 0xE0

// 0xE1

// 0xE2
void LDH_C_A(CPU &cpu, MMU &mmu) {
    mmu.bus_write(0xFF00 | cpu.regs.C, cpu.regs.A);
}

// 0xE3

// 0xE4

// 0xE5

// 0xE6

// 0xE7

// 0xE8

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

// 0xEF
 
// 0xF0
void LDH_A_N(CPU &cpu, MMU &mmu) {
    u8 n = mmu.bus_read(cpu.regs.PC);
    cpu.regs.PC += 0x1;

    cpu.regs.A = mmu.bus_read(0xFF00 | n);
}

// 0xF1

// 0xF2
void LDH_A_C(CPU &cpu, MMU &mmu) {
    cpu.regs.A = mmu.bus_read(0xFF00 | cpu.regs.C);
}

// 0xF3

// 0xF4

// 0xF5

// 0xF6

// 0xF7

// 0xF8

// 0xF9

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

// 0xFF
