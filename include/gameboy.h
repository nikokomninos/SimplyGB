#pragma once

#include <common.h>
#include <cart.h>
#include <mmu.h>
#include <cpu.h>

class Gameboy {
public:
        Gameboy();
        void gameboy_initialize(std::string file);
        void gameboy_mainloop();

private:
        Cart cart;
        friend class Cart;

        MMU mmu;
        friend class MMU;

        CPU cpu;
        friend class CPU;
};
