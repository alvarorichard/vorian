#include <cstdlib>
#include "Vorian.hpp"



int main(int argc, char **argv) {
    if (argc > 2) {
        std::cerr << "Usage: " << argv[0] << "file.vor" << std::endl;
        return EXIT_FAILURE;
    }

    if (argc == 2) {
        Vorian::runFile(argv[1]);
    
    } else{
        Vorian::runPrompt();
    }
    return EXIT_SUCCESS;
}