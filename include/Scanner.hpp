#pragma once


#include <unordered_map>
#include <vector>


#include "Token.hpp"

/**
 * @class Scanner
 * @brief A lexical scanner for tokenizing source code into a sequence of
 * tokens.
 *
 * The Scanner class is responsible for reading the source code, identifying
 * lexemes, and converting them into tokens that can be used by a parser or
 * interpreter. It supports keywords, identifiers, literals, and various
 * operators.
 *
 * @note This class assumes the source code is provided as a single string.
 */
class Scanner {
  private:
  int start = 0;
    int current = 0;
    int line = 1;
    std::string source;
    std::vector<Token> tokens;
    std::unordered_map<std::string, TokenType> keywords ={
      {"and", TokenType::AND},       {"class", TokenType::CLASS},
      {"else", TokenType::ELSE},     {"false", TokenType::FALSE},
      {"def", TokenType::DEF},       {"for", TokenType::FOR},
      {"if", TokenType::IF},         {"none", TokenType::NONE},
      {"or", TokenType::OR},         {"print", TokenType::PRINT},
      {"return", TokenType::RETURN}, {"super", TokenType::SUPER},
      {"self", TokenType::SELF},     {"true", TokenType::TRUE},
      {"while", TokenType::WHILE}};

      bool isAlpha(char c);
      bool isDigit(char c);
      bool isAlphaNumeric(char c);
      bool match(char expected);
      void scanToken();
      char advance();
      void addToken(TokenType type);
      void addToken(TokenType type, std::any literal);
      char peek();
      char peekNext();
      void string();
      void number();
      void identifier();
      void printTokens();
  
    public:
      Scanner(const std::string&);
      bool isAtEnd();
      std::vector<Token> scanTokens();
};