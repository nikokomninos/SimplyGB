#pragma once

#include <common.h>
#include <cart.h>
#include <mmu.h>

class Gameboy {
public:
    Gameboy();
    void gameboy_initialize(std::string file);

private:
    Cart cart;
    friend class Cart;

    MMU mmu;
    friend class MMU;
};
