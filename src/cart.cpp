#include <cart.h>

Cart::Cart(){};

/**
 * Store the data of a ROM file into the Cart object
 *
 * @param rom ROM file name
 */
void Cart::cart_load(std::string rom) {
    std::ifstream ifs;
    std::streamsize size;
    char *buffer;

    ifs.open(rom, std::fstream::binary | std::fstream::ate);

    //If file is empty, print error
    if(!ifs.is_open()){
        throw std::runtime_error("ERROR: File could not be opened");
    }

    //Get game ROM file size
    size = ifs.tellg();
    ifs.seekg(std::fstream::beg);

    //Copy ROM file data locally
    buffer = new char[size];
    ifs.read(buffer, size);
    ifs.close();

    //Store ROM data into cart object
    for(auto i = 0; i < size; i++)
        data.push_back(buffer[i]);

    //Get and store ROM header info
    buffer = new char[sizeof(header_t)];
    int j = 0;

    for(auto i = 0x100; i < 0x150; i++){
        buffer[j] = data[i];
        j++;
    }

    header = (header_t *)buffer;
    delete[] buffer;
}

/**
 * Print the cart header information
 *
 * @param None
 * @return None
 */
void Cart::cart_get_header(){
    std::cout << "TITLE:            | " << header->title << std::endl;
    std::cout << "OLD LICENSEE:     | " << old_licensee_codes.find(header->old_licensee)->second << std::endl;
    std::cout << "NEW LICENSEE:     | " << new_licensee_codes.find(header->new_licensee)->second << std::endl;
    std::cout << "CART TYPE:        | " << cart_types.find(header->type)->second << std::endl;
    std::cout << "ROM SIZE:         | " << rom_sizes.find(header->rom_size)->second << std::endl;
    std::cout << "RAM SIZE:         | " << ram_sizes.find(header->ram_size)->second << std::endl;
    std::cout << "DESTINATION CODE: | " << destination_codes.find(header->destination)->second << std::endl;

    std::cout << std::endl;
}
