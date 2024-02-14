#include <cpu.h>

CPU::CPU(){
    regs.PC = 0x100;
    regs.SP = 0;
}

void CPU::cpu_fetch(u16 addr, MMU& mmu){
    curr_opcode = (mmu.bus_read(addr) << 8) | mmu.bus_read(addr+1);
    std::cout << std::hex << std::setw(4) << std::setfill('0')
              << curr_opcode << std::endl;
}

void CPU::cpu_decode_exec(MMU &mmu){
    //TODO
}
