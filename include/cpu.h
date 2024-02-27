#pragma once

#include <common.h>
#include<mmu.h>

typedef struct {
    u8 A;
    u8 B, C;
    u8 D, E;
    u8 H, L;
    u16 AF;
    u16 BC;
    u16 DE;
    u16 HL;
    u16 SP;
    u16 PC;
} registers;

typedef struct {
    bool Z, N, H, C;
} register_flags;

class CPU{
public:
        CPU();
        void cpu_fetch(u16 addr, MMU& mmu);
        void cpu_decode_exec(MMU& mmu);

        registers regs;
        register_flags flags;
        std::stack<u8> stack;
        u16 curr_opcode;
};
