#include "Vorian.hpp"
#include <cstdlib>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;




void Vorian::runFile(const std::string& path) {
    if(!fs::exists(path)){
        std::cerr << "File not found.\n";
        std::exit(66);
      }
    
      std::ifstream file(path, std::ios::binary | std::ios::ate);
      if(!file){
        std::cerr << "Permission error opening file.\n";
        std::exit(66);
      }
    
      std::streamsize size = file.tellg();
      file.seekg(0, std::ios::beg);
      std::vector<char> buffer(size);
    
      if(!file.read(buffer.data(), size)){
        std::cerr << "Error reading file.\n";
        std::exit(77);
      }
    
      std::string content(buffer.begin(), buffer.end());
      run(content);
}

void Vorian::runPrompt() {
    std::string line;
    std:: cout << "Vorian> ";
    for(;;){
        if(!std::getline(std::cin, line) || line == "exit"){
          break;;
        }
        run(line);
    std::cout << "\nvorian> ";
    } 
    
}


void Vorian::run(const std::string& source) {
    std::cout << source;;
}


