#include <gameboy.h>

Gameboy::Gameboy(){}

void Gameboy::gameboy_initialize(std::string file){
    cart.cart_load(file);
    cart.cart_get_header();
    mmu.bus_load_rom(cart);
}

void Gameboy::gameboy_mainloop(){
    cpu.cpu_fetch(cpu.regs.SP, mmu);
    cpu.regs.SP += 0x2;
}
