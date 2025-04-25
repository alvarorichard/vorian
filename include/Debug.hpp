#pragma once
#include <iostream>

#include "RuntimeError.hpp"
#include "Token.hpp"


/**
 * @class Debug
 * @brief A utility class for handling and reporting errors in the application.
 *
 * The Debug class provides static methods for error reporting and tracking
 * whether any errors have occurred during the execution of the program.
 */
 class Debug {
  private:
    static void report(int, const std::string&, const std::string&);

  public:
    inline static bool hadError = false;
    inline static bool hadRuntimeError = false;
    static void error(int line, const std::string&);
    static void error(Token token, const std::string&);
    static void runtimeError(const RuntimeError& error);
};


