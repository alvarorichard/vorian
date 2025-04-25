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
 * The Parser class takes a vector of tokens and processes them according to the grammar rules
 * to produce a structured representation of the input. It provides methods for handling
 * different levels of precedence and constructs in the grammar.
 */
class Parser {
 public:
  /**
       * @struct ParseError
       * @brief Exception type for handling parsing errors.
       * 
       * This exception is thrown when the parser encounters an error in the input.
       */
  struct ParseError : public std::runtime_error {
    using std::runtime_error::runtime_error;
  };

  /**
       * @brief Constructs a Parser object.
       * @param tokens A vector of tokens to be parsed.
       */
  Parser(const std::vector<Token>& tokens);

  /**
       * @brief Parses the tokens and returns the root of the abstract syntax tree (AST).
       * @return A shared pointer to the root expression of the AST.
       */
  std::shared_ptr<Expr> parse();

 private:
  /**
       * @brief Reports a parsing error.
       * @param token The token where the error occurred.
       * @param message A description of the error.
       * @return A ParseError exception.
       */
  ParseError error(const Token& token, const std::string& message);

  /**
       * @brief Synchronizes the parser state after encountering an error.
       * 
       * This method skips tokens until it reaches a point where parsing can continue.
       */
  void synchronize();

  /**
       * @brief Checks if the parser has reached the end of the token stream.
       * @return True if at the end, false otherwise.
       */
  bool isAtEnd();

  /**
       * @brief Checks if the current token matches the given type.
       * @param type The token type to check.
       * @return True if the current token matches, false otherwise.
       */
  bool check(const TokenType& type);

  /**
       * @brief Attempts to match the current token with any of the given types.
       * @tparam T Variadic template for token types.
       * @param types The token types to match.
       * @return True if a match is found, false otherwise.
       */
  template <class... T>
  bool match(T... types);

  /**
       * @brief Returns the previous token.
       * @return The previous token.
       */
  Token previous();

  /**
       * @brief Returns the current token without consuming it.
       * @return The current token.
       */
  Token peek();

  /**
       * @brief Advances the parser to the next token.
       * @return The token that was just consumed.
       */
  Token advance();

  /**
       * @brief Consumes the current token if it matches the given type.
       * @param type The expected token type.
       * @param message The error message if the token does not match.
       * @return The consumed token.
       * @throws ParseError if the token does not match the expected type.
       */
  Token consume(const TokenType& type, const std::string& message);

  /**
       * @brief Parses an expression.
       * @return A shared pointer to the parsed expression.
       */
  std::shared_ptr<Expr> expression();

  /**
       * @brief Parses an equality expression.
       * @return A shared pointer to the parsed equality expression.
       */
  std::shared_ptr<Expr> equality();

  /**
       * @brief Parses a comparison expression.
       * @return A shared pointer to the parsed comparison expression.
       */
  std::shared_ptr<Expr> comparison();

  /**
       * @brief Parses a term expression (e.g., addition or subtraction).
       * @return A shared pointer to the parsed term expression.
       */
  std::shared_ptr<Expr> term();

  /**
       * @brief Parses a factor expression (e.g., multiplication or division).
       * @return A shared pointer to the parsed factor expression.
       */
  std::shared_ptr<Expr> factor();

  /**
       * @brief Parses a unary expression (e.g., negation or logical NOT).
       * @return A shared pointer to the parsed unary expression.
       */
  std::shared_ptr<Expr> unary();

  /**
       * @brief Parses a primary expression (e.g., literals or grouped expressions).
       * @return A shared pointer to the parsed primary expression.
       */
  std::shared_ptr<Expr> primary();
};