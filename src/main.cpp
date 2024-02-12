#include <cart.h>
#include <gameboy.h>

int main(int argc, char **argv){
    Gameboy gb;
    gb.gameboy_initialize(argv[1]);

    return 0;
}
