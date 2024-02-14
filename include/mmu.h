#pragma once

#include <common.h>
#include <cart.h>

class MMU{
public:
    MMU();
    u16 bus_read(u16 addr);
    void bus_write(u16 addr, u16 data);
    void bus_swap_bank(std::vector<u8> bank);
    void bus_load_rom(Cart& cart);

    std::vector<u8> bus;
};
