#include "../include/Vorian.hpp"
#include <cstdlib>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;




/**
 * @brief Executes the contents of a file specified by its path.
 * 
 * This function checks if the file exists and is accessible. If the file 
 * does not exist or there is a permission issue, the program exits with 
 * an appropriate error code. The file is read in binary mode, and its 
 * contents are passed to the `run` method for further processing.
 * 
 * @param path The file path as a string.
 * 
 * @throws std::exit with code 66 if the file does not exist or cannot be opened.
 * @throws std::exit with code 77 if there is an error reading the file.
 */
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
      if (Debug::hadError) {
        std::exit(65);
      
      }
}

/**
 * @brief Runs the interactive prompt for the Vorian application.
 * 
 * This method continuously displays a prompt ("Vorian> ") to the user,
 * reads input from the standard input, and processes the input using the
 * `run` method. The loop terminates when the user enters "exit" or when
 * the input stream is closed.
 * 
 * @note The method ensures that the prompt is displayed after each command
 *       execution, except when the loop is terminated.
 */
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
    Scanner scanner(source);
    std::vector<Token> tokens = scanner.scanTokens();
    for ( auto& t : tokens) {
        std::cout << t.toString() << std::endl;
    }
}


