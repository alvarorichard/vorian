#pragma once

#include <stdexcept>
#include <vector>
#include "Debug.hpp"
#include "Expr.hpp"
#include "Scanner.hpp"
#include "Token.hpp"

/**
 * @class Parser
 * @brief A class responsible for parsing a sequence of tokens into an abstract syntax tree (AST).
 * 
 * The Parser class takes a vector of tokens and provides methods to parse them into expressions
 * following a specific grammar. It includes error handling and synchronization mechanisms to
 * recover from parsing errors.
 */

/**
 * @struct ParseError
 * @brief Exception type for handling parsing errors.
 * 
 * Inherits from std::runtime_error and is used to signal errors encountered during parsing.
 */

/**
 * @fn Parser::Parser(const std::vector<Token>& tokens)
 * @brief Constructs a Parser object with a given sequence of tokens.
 * @param tokens A vector of tokens to be parsed.
 */

/**
 * @fn std::shared_ptr<Expr> Parser::parse()
 * @brief Initiates the parsing process and returns the resulting expression.
 * @return A shared pointer to the root expression of the parsed syntax tree.
 */

/**
 * @fn Parser::ParseError Parser::error(const Token& token, const std::string& message)
 * @brief Creates a ParseError exception with a specific token and error message.
 * @param token The token where the error occurred.
 * @param message A description of the error.
 * @return A ParseError exception.
 */

/**
 * @fn void Parser::synchronize()
 * @brief Synchronizes the parser state after encountering an error to continue parsing.
 */

/**
 * @fn bool Parser::isAtEnd()
 * @brief Checks if the parser has reached the end of the token sequence.
 * @return True if the parser is at the end, false otherwise.
 */

/**
 * @fn bool Parser::check(const TokenType& type)
 * @brief Checks if the current token matches the given type without consuming it.
 * @param type The token type to check.
 * @return True if the current token matches the type, false otherwise.
 */

/**
 * @fn template<class...T> bool Parser::match(T...types)
 * @brief Checks if the current token matches any of the given types and consumes it if true.
 * @tparam T Variadic template parameter for token types.
 * @param types The token types to match.
 * @return True if a match is found, false otherwise.
 */

/**
 * @fn Token Parser::previous()
 * @brief Retrieves the most recently consumed token.
 * @return The previous token.
 */

/**
 * @fn Token Parser::peek()
 * @brief Retrieves the current token without consuming it.
 * @return The current token.
 */

/**
 * @fn Token Parser::advance()
 * @brief Consumes the current token and moves to the next one.
 * @return The consumed token.
 */

/**
 * @fn Token Parser::consume(const TokenType& type, const std::string& message)
 * @brief Consumes the current token if it matches the given type, otherwise throws a ParseError.
 * @param type The expected token type.
 * @param message The error message if the token does not match.
 * @return The consumed token.
 */

/**
 * @fn std::shared_ptr<Expr> Parser::expression()
 * @brief Parses an expression.
 * @return A shared pointer to the parsed expression.
 */

/**
 * @fn std::shared_ptr<Expr> Parser::equality()
 * @brief Parses an equality expression.
 * @return A shared pointer to the parsed equality expression.
 */

/**
 * @fn std::shared_ptr<Expr> Parser::comparison()
 * @brief Parses a comparison expression.
 * @return A shared pointer to the parsed comparison expression.
 */

/**
 * @fn std::shared_ptr<Expr> Parser::term()
 * @brief Parses a term expression.
 * @return A shared pointer to the parsed term expression.
 */

/**
 * @fn std::shared_ptr<Expr> Parser::factor()
 * @brief Parses a factor expression.
 * @return A shared pointer to the parsed factor expression.
 */

/**
 * @fn std::shared_ptr<Expr> Parser::unary()
 * @brief Parses a unary expression.
 * @return A shared pointer to the parsed unary expression.
 */

/**
 * @fn std::shared_ptr<Expr> Parser::primary()
 * @brief Parses a primary expression.
 * @return A shared pointer to the parsed primary expression.
 */
class Parser {
 public:  // private
  struct ParseError : public std::runtime_error {
    using std::runtime_error::runtime_error;
  };

  const std::vector<Token> tokens;
  int current = 0;

  ParseError error(const Token&, const std::string&);

  void synchronize();

  bool isAtEnd();
  bool check(const TokenType&);
  template <class... T>
  bool match(T... types);

  Token previous();
  Token peek();
  Token advance();
  Token consume(const TokenType&, const std::string&);

  std::shared_ptr<Expr> expression();
  std::shared_ptr<Expr> equality();
  std::shared_ptr<Expr> comparison();
  std::shared_ptr<Expr> term();
  std::shared_ptr<Expr> factor();
  std::shared_ptr<Expr> unary();
  std::shared_ptr<Expr> primary();

 public:
  Parser(const std::vector<Token>&);
  std::shared_ptr<Expr> parse();
};
