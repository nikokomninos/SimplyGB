#include <gameboy.h>

Gameboy::Gameboy(){}

void Gameboy::gameboy_initialize(std::string file){
    cart.cart_load(file);
    cart.cart_get_header();
    mmu.bus_load_rom(cart);
}
