/**
 * @file Scanner.cpp
 * @brief Implementation of the Scanner class for the Vorian programming
 * language.
 *
 * This file contains the implementation of the Scanner class, which is
 * responsible for tokenizing the source code of the Vorian programming
 * language. The Scanner processes the source code character by character,
 * identifies tokens such as keywords, identifiers, literals, and operators, and
 * stores them in a vector of Token objects. It also handles whitespace,
 * comments, and string literals.
 *
 * The Scanner class uses a finite state machine approach to recognize different
 * token types and manage the current position in the source code. It provides
 * methods for scanning tokens, checking for the end of the source, and printing
 * the tokens for debugging purposes.
 *
 * Key functionalities include:
 * - Scanning and categorizing tokens from the source code.
 * - Handling string literals, numeric literals, and identifiers.
 * - Managing multi-character tokens (e.g., `!=`, `==`, `<=`, `>=`).
 * - Skipping whitespace and comments.
 * - Reporting errors for unexpected characters or unterminated strings.
 *
 * The class maintains internal state variables such as the current position,
 * starting position, and line number to facilitate tokenization.
 *
 * @note This implementation assumes that the input source code is provided as
 *       a single string and processed sequentially.
 */
#include "../include/Scanner.hpp"

#include <string>
#include <unordered_map>

/**
 * @brief Constructs a Scanner object with the given source code.
 *
 * This constructor initializes the Scanner with the provided source code,
 * setting the starting position, current position, and line number to their
 * initial values.
 *
 * @param source The source code to be scanned.
 */

Scanner::Scanner(const std::string& source) : source(source)
{
  this->start = 0;
  this->current = 0;
  this->line = 1;
}

/**
 * @brief Scans the source code and generates a list of tokens.
 *
 * This method iterates through the source code, identifying and processing
 * individual tokens until the end of the source is reached. Each token is
 * added to the `tokens` vector. At the end of the scanning process, an
 * end-of-file (EOF) token is appended to signify the completion of the token
 * stream.
 *
 * @return std::vector<Token> A vector containing all the tokens identified
 *         in the source code, including an EOF token at the end.
 */
std::vector<Token> Scanner::scanTokens()
{
  while (!isAtEnd()) {
    this->start = this->current;
    scanToken();
  }
  tokens.emplace_back(TokenType::VOR_EOF, "", nullptr, line);
  return tokens;
}

bool Scanner::isAtEnd()
{
  return current >= static_cast<int>(source.length());
}

void Scanner::addToken(TokenType type)
{
  std::string text = source.substr(start, current - start);
  tokens.emplace_back(type, text, std::any(), line);
}

void Scanner::addToken(TokenType type, std::any literal)
{
  std::string text = source.substr(start, current - start);
  tokens.emplace_back(type, text, literal, line);
}

void Scanner::identifier()
{
  while (isAlphaNumeric(peek())) {
    advance();
  }
  std::string text = source.substr(start, current - start);
  auto it = keywords.find(text);
  TokenType type = it == keywords.end() ? TokenType::IDENTIFIER : it->second;
  addToken(type);
}

void Scanner::number()
{
  while (isDigit(peek()))
    ;
  if (peek() == '.' && isDigit(peekNext())) {
    advance();
    while (isDigit(peek())) {
      advance();
    }
  }
}

void Scanner::string()
{
  while (peek() != '"' && !isAtEnd()) {
    if (peek() == '\n')
      line++;
    advance();
  }

  if (isAtEnd()) {
    Debug::error(line, "Unterminated string.");
    return;
  }

  advance();  // Consume closing "

  // Trim the surrounding quotes
  std::string value = source.substr(start + 1, current - start - 2);
  addToken(TokenType::STRING, value);
}

std::string tokenTypeToString(TokenType type)
{
  static const std::unordered_map<TokenType, std::string> typeNames = {
      {TokenType::LEFT_PAREN, "LEFT_PAREN"},
      {TokenType::RIGHT_PAREN, "RIGHT_PAREN"},

      {TokenType::STRING, "STRING"},
      {TokenType::VOR_EOF, "EOF"}};

  auto it = typeNames.find(type);
  return it != typeNames.end() ? it->second : "UNKNOWN";
}

void Scanner::printTokens()
{
  for (const auto& token : tokens) {
    std::cout << tokenTypeToString(token.type) << " " << token.lexeme << " ";

    // Handle literal display
    if (token.type == TokenType::STRING) {
      std::cout << "\"" << std::any_cast<std::string>(token.literal) << "\"";
    } else if (token.type == TokenType::NUMBER) {
      std::cout << std::any_cast<double>(token.literal);
    } else {
      std::cout << "null";
    }

    std::cout << " " << token.line << std::endl;
  }
}

bool Scanner::match(char expected)
{
  if (isAtEnd())
    return false;
  if (source[current] != expected)
    return false;
  current++;
  return true;
}
char Scanner::peek()
{
  if (isAtEnd())
    return '\0';
  return source[current];
}

char Scanner::peekNext()
{
  if (current + 1 >= static_cast<int>(source.length()))
    return '\0';
  return source.at(current + 1);
}

bool Scanner::isAlpha(char c)
{
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

bool Scanner::isDigit(char c)
{
  return c >= '0' && c <= '9';
}
/**
 * @brief Checks if a character is alphanumeric.
 *
 * This function determines whether the given character is either
 * an alphabetic character (a-z, A-Z) or a numeric digit (0-9).
 *
 * @param c The character to check.
 * @return true if the character is alphanumeric, false otherwise.
 */
bool Scanner::isAlphaNumeric(char c)
{
  return isAlpha(c) || isDigit(c);
}

char Scanner::advance()
{
  return source[current++];
}

/**
 * @brief Scans a single token from the input source and categorizes it into a
 * specific token type.
 *
 * This function processes the next character in the input source and determines
 * its meaning based on predefined rules. Depending on the character, it may:
 * - Add a token of a specific type (e.g., parentheses, braces, operators,
 * etc.).
 * - Handle multi-character tokens (e.g., `!=`, `==`, `<=`, `>=`).
 * - Skip whitespace and newlines.
 * - Parse string literals, identifiers, or numeric literals.
 * - Report an error for unexpected characters.
 *
 * The function uses helper methods such as `advance()`, `match()`, `peek()`,
 * `isAlpha()`, `isDigit()`, `string()`, `identifier()`, and `number()` to
 * perform its operations.
 *
 * @note This function assumes that the input source is being processed
 * sequentially and maintains internal state to track the current position and
 * line number.
 */
void Scanner::scanToken()
{
  char c = advance();

  switch (c) {
    case '(':
      addToken(TokenType::LEFT_PAREN);
      break;
    case ')':
      addToken(TokenType::RIGHT_PAREN);
      break;
    case '{':
      addToken(TokenType::LEFT_BRACE);
      break;
    case '}':
      addToken(TokenType::RIGHT_BRACE);
      break;
    case ',':
      addToken(TokenType::COMMA);
      break;
    case '.':
      addToken(TokenType::DOT);
      break;
    case '-':
      addToken(TokenType::MINUS);
      break;
    case '+':
      addToken(TokenType::PLUS);
      break;
    case ';':
      addToken(TokenType::SEMICOLON);
      break;
    case '*':
      addToken(TokenType::STAR);
      break;
    case '[':
      addToken(TokenType::LEFT_BRACKET);
      break;
    case ']':
      addToken(TokenType::RIGHT_BRACKET);
      break;
    case '!':
      addToken(match('=') ? TokenType::BANG_EQUAL : TokenType::BANG);
      break;
    case '=':
      addToken(match('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL);
      break;
    case '<':
      addToken(match('=') ? TokenType::LESS_EQUAL : TokenType::LESS);
      break;
    case '>':
      addToken(match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER);
      break;
    case '/':
      if (match('/')) {
        while (peek() != '\n' && !isAtEnd())
          advance();
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
