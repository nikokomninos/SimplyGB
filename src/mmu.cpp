#include <mmu.h>

MMU::MMU() {
    bus.resize(0xFFFF);
}

u16 MMU::bus_read(u16 addr){
    return bus[addr];
}

void MMU::bus_write(u16 addr, u16 data){
    bus[addr] = data;
}

void MMU::bus_swap_bank(std::vector<u8> bank){
    throw std::runtime_error("ERROR: Not yet implemented");
}

void MMU::bus_load_rom(Cart& cart){
    for(auto i = 0x0; i < 0x8000; i++)
        bus[i] = cart.data[i];
}
