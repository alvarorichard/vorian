#pragma once

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

class Vorian {
    private:
      static void run(const std::string&);
    
       public:
       static void runFile(const std::string&);
       static void runPrompt();
};

