#include "../include/Debug.hpp"

#include <iostream>

void Debug::report(int line, const std::string& where,
                   const std::string& message)
{
  std::cerr << "[line " << line << "] Error" << where << ": " << message
            << std::endl;
  hadError = true;
}

/**
 * @brief Logs an error message with the specified line number.
 *
 * This function is used to report an error by providing the line number
 * where the error occurred and a descriptive error message.
 *
 * @param line The line number where the error occurred.
 * @param message A descriptive message detailing the error.
 */
void Debug::error(int line, const std::string& message)
{
  report(line, "", message);
}

void Debug::error(Token token, const std::string& message)
{
  if (token.type == TokenType::VOR_EOF) {
    report(token.line, "at end", message);

  } else {
    report(token.line, "at '" + token.lexeme + "'", message);
  }
}

static void runtimeError(const RuntimeError& error){
  std::cerr << error.what() << "\n[line " << error.token.line
            << "] Error: " << error.token.lexeme << std::endl;
 // Debug::hadError = true;
}

