#include "../include/Debug.hpp"
#include <iostream> 

void Debug::report(int line, const std::string& where, const std::string& message) {
    std::cerr << "[line " << line << "] Error" << where << ": " << message << std::endl;
    hadError = true;
}


void Debug::error(int line, const std::string& message) {
    report(line, "", message);
}