#pragma once

#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Scanner.hpp"
#include "Parser.hpp"
#include "Interpreter.hpp"
#include "Debug.hpp"
#include "RuntimeError.hpp"
#include "Expr.hpp"

class Vorian {
 private:
  static void run(const std::string&);

 public:
  static void runFile(const std::string&);
  static void runPrompt();
};
