#pragma once

#include <any>
#include <iostream>
#include <sstream>

#include "TokenType.hpp"

class Token {
public:
  TokenType type;
  std::string lexeme;
  std::any literal;
  int line;

  Token(TokenType type, std::string, std::any, int);
  std::string toString();
};
