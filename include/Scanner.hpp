#pragma once

#include <iostream>

#include <vector>

#include <unordered_map>
#include "Debug.hpp"
#include "Token.hpp"

class Scanner {
    private:
    int start = 0;
    int current = 0;
    int line = 1;
    std::string source;
    std::vector<Token> tokens;
    std::unordered_map<std::string, TokenType> keywords = {
        {"and", TokenType::AND},
        {"class", TokenType::CLASS},
        {"else", TokenType::ELSE},
        {"false", TokenType::FALSE},
        {"def", TokenType::DEF},
        {"for", TokenType::FOR},
        {"if", TokenType::IF},
        {"none", TokenType::NONE},
        {"or", TokenType::OR},
        {"print", TokenType::PRINT},
        {"return", TokenType::RETURN},
        {"super", TokenType::SUPER},
        {"self", TokenType::SELF},
        {"true", TokenType::TRUE},
        {"while", TokenType::WHILE}
    };

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
    Scanner(const std::string& source);
    bool isAtEnd();
    std::vector<Token> scanTokens();

};