#include <cart.h>
#include <gameboy.h>

int main(int argc, char **argv){
    Gameboy gb;
    gb.cart.cart_load(argv[1]);
    gb.cart.cart_get_header();

    return 0;
}
