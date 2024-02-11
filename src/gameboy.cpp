#include <gameboy.h>

Gameboy::Gameboy(){}

void Gameboy::cart_load(std::string rom){
    cart.cart_load(rom);
}
