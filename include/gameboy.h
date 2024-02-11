#pragma once

#include <common.h>
#include <cart.h>

class Gameboy {
public:
    Gameboy();
    void cart_load(std::string rom);

    Cart cart;
    friend class Cart;

private:
};
