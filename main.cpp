#include <cstdlib>
#include <iostream>


int main(int argc, char** argv) {
    if (argc > 2) {
        std::cerr << "Usage: " << argv[0] << "file.vor" << std::endl;
        return EXIT_FAILURE;
    }

    if (argc == 2) {
        std::cout << "Lets go to read file" << std::endl;
    
    } else{
        std::cout << "Lets go REPL" << std::endl;
    }
    return EXIT_SUCCESS;
}