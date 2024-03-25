#include <cpu.h>

CPU::CPU(){
    regs.PC = 0x100;
    regs.SP = STACK_SIZE - 1;
}

void CPU::cpu_fetch(u16 addr, MMU& mmu) {
    //curr_opcode = (mmu.bus_read(addr) << 8) | mmu.bus_read(addr+1);
    curr_opcode = mmu.bus_read(addr);
    regs.PC += 0x1;
    //std::cout << std::hex << std::setw(2) << std::setfill('0')
    //          << curr_opcode << std::endl;
    std::printf("%02hhx\n", curr_opcode);
    sleep(1);
}

void CPU::cpu_decode_exec(MMU &mmu) {
    //TODO
}

u16 CPU::get_reg16_af() {
    return (regs.A) << 8 | regs.F;
}

void CPU::set_reg16_af(u16 nn) {
    regs.A = (nn & 0xFF00 >> 8);
    regs.F = (nn & 0x00FF);
}

u16 CPU::get_reg16_bc() {
    return (regs.B) << 8 | regs.C;
}

void CPU::set_reg16_bc(u16 nn) {
    regs.B = (nn & 0xFF00 >> 8);
    regs.C = (nn & 0x00FF);
}

u16 CPU::get_reg16_de() {
    return (regs.D) << 8 | regs.E;
}

void CPU::set_reg16_de(u16 nn) {
    regs.D = (nn & 0xFF00 >> 8);
    regs.E = (nn & 0x00FF);
}

u16 CPU::get_reg16_hl() {
    return (regs.H) << 8 | regs.L;
}

void CPU::set_reg16_hl(u16 nn) {
    regs.H = (nn & 0xFF00 >> 8);
    regs.L = (nn & 0x00FF);
}

void CPU::stack_push(u8 n) {
    stack[regs.SP] = n;
    regs.SP -= 0x1;
}

u8 CPU::stack_pop() {
    u8 n = stack[regs.SP];
    stack[regs.SP] = 0x0;
    regs.SP += 0x1;
    return n;
}
