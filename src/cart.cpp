#include <cart.h>
#include <stdexcept>

Cart::Cart(){};

/**
 * Load a ROM file
 *
 * @param rom ROM file name
 * @return 0 if successful, 1 otherwise
 */
void Cart::cart_load(std::string rom) {
    std::ifstream ifs;
    std::streamsize size;
    char *buffer;

    ifs.open(rom, std::fstream::binary | std::fstream::ate);

    //If file is empty, print error
    if(!ifs.is_open()){
        //std::cerr << "ERROR: File could not be opened" << std::endl;
        throw std::runtime_error("ERROR: File could not be opened");
    }

    //Get game ROM file size
    size = ifs.tellg();
    ifs.seekg(std::fstream::beg);

    //Copy ROM file data locally
    buffer = new char[size];
    data = new char[size];
    ifs.read(buffer, size);
    ifs.close();

    for(auto i = 0; i < size; ++i){
        //printf("%02hhx ", buffer[i]);
        data[i] = buffer[i];
    }

    delete[] buffer;
}

void Cart::cart_get_header(){
    std::cout << data[100] << std::endl;
}
