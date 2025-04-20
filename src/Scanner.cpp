#include "../include/Scanner.hpp"
#include <string>
#include <unordered_map>




Scanner::Scanner(const std::string& source) : source(source) {
    this->start = 0;
    this->current = 0;
    this->line = 1;
}

std::vector<Token>Scanner::scanTokens(){
    while(!isAtEnd()){
        this->start = this->current;
        scanToken();
    }
    tokens.emplace_back(TokenType::VOR_EOF, "", nullptr, line);
    return tokens;
}

bool Scanner::isAtEnd() {
    return current >= static_cast<int>(source.length());
}

void Scanner::addToken(TokenType type) {
    std::string text = source.substr(start, current - start);
    tokens.emplace_back(type, text, std::any(), line);
}

void Scanner::addToken(TokenType type, std::any literal) {
    std::string text = source.substr(start, current - start);
    tokens.emplace_back(type, text, literal, line);
}

void Scanner::identifier() {
    while (isAlphaNumeric(peek())) {
        advance();
    }
    std::string text = source.substr(start, current - start);
    auto it = keywords.find(text);
   TokenType type = it == keywords.end() ? TokenType::IDENTIFIER : it ->second;
    addToken(type);
}

void Scanner::number() {
    while (isDigit(peek()));
    if (peek() == '.' && isDigit(peekNext())) {
        advance();
        while (isDigit(peek())) {
            advance();
        }
    }

   
 
}


void Scanner::string() {
    while (peek() != '"' && !isAtEnd()) {
        if (peek() == '\n') line++;
        advance();
    }

    if (isAtEnd()) {
        Debug::error(line, "Unterminated string.");
        return;
    }

    advance(); // Consume closing "
    
    // Trim the surrounding quotes
    std::string value = source.substr(start + 1, current - start - 2);
    addToken(TokenType::STRING, value);
}

std::string tokenTypeToString(TokenType type) {
    static const std::unordered_map<TokenType, std::string> typeNames = {
        {TokenType::LEFT_PAREN, "LEFT_PAREN"},
        {TokenType::RIGHT_PAREN, "RIGHT_PAREN"},
        
        {TokenType::STRING, "STRING"},
        {TokenType::VOR_EOF, "EOF"}
    };
    
    auto it = typeNames.find(type);
    return it != typeNames.end() ? it->second : "UNKNOWN";
}

void Scanner::printTokens() {
    for (const auto& token : tokens) {
        std::cout << tokenTypeToString(token.type) << " "
                  << token.lexeme << " ";
        
        // Handle literal display
        if (token.type == TokenType::STRING) {
            std::cout << "\"" << std::any_cast<std::string>(token.literal) << "\"";
        }
        else if (token.type == TokenType::NUMBER) {
            std::cout << std::any_cast<double>(token.literal);
        }
        else {
            std::cout << "null";
        }
        
        std::cout << " " << token.line << std::endl;
    }
}


bool Scanner::match(char expected) {
    if (isAtEnd()) return false;
    if (source[current] != expected) return false;
    current++;
    return true;
}
char Scanner::peek() {
    if(isAtEnd()) return '\0';
    return source[current];
}



char Scanner::peekNext() {
  if(current + 1 >= static_cast<int>(source.length())) return '\0';
  return source.at(current + 1);
}

bool Scanner::isAlpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

bool Scanner::isDigit(char c) {
    return c >= '0' && c <= '9';
}
bool Scanner::isAlphaNumeric(char c) {
    return isAlpha(c) || isDigit(c);
}

char Scanner::advance() {
   return source[current++];
}

void Scanner::scanToken(){
    char c = advance();

    switch(c){
        case '(': addToken(TokenType::LEFT_PAREN); break;
        case ')': addToken(TokenType::RIGHT_PAREN); break;
        case '{': addToken(TokenType::LEFT_BRACE); break;
        case '}': addToken(TokenType::RIGHT_BRACE); break;
        case ',': addToken(TokenType::COMMA); break;
        case '.': addToken(TokenType::DOT); break;
        case '-': addToken(TokenType::MINUS); break;
        case '+': addToken(TokenType::PLUS); break;
        case ';': addToken(TokenType::SEMICOLON); break;
        case '*': addToken(TokenType::STAR); break;
        case '[': addToken(TokenType::LEFT_BRACKET); break;
        case ']': addToken(TokenType::RIGHT_BRACKET); break;
        case '!':
                  addToken(match('=') ? TokenType::BANG_EQUAL : TokenType::BANG); break;
        case '=':
                  addToken(match('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL); break;
        case '<':
                  addToken(match('=') ? TokenType::LESS_EQUAL : TokenType::LESS); break;
        case '>':
                  addToken(match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER);
                  break;
        case '/':
                    if (match('/')) {
                        while (peek() != '\n' && !isAtEnd()) advance();
                    } else {
                        addToken(TokenType::SLASH);
                    }
                  break;
        case ' ':
        case '\r':
        case '\t':
                  break;
        case '\n':
                  break;
        case '"':
                    string();
                  break;
        default: 
                    if (isAlpha(c)) {
                        identifier();
                    } else if (isDigit(c)) {
                        number();
                    } else {
                        Debug::error(line, "Unexpected character.");
                    }
                  break;
      } 
      
}



