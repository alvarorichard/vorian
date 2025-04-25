#include "../include/Parser.hpp"
#include <memory>
#define assert(E)

Parser::Parser(const std::vector<Token>& tokens) : tokens(tokens) {}

std::shared_ptr<Expr> Parser::parse()
{
  try {
    return expression();
  } catch (const std::exception& e) {
    //std::cerr << "Parsing error: " << e.what() << std::endl;
    return nullptr;
  }
}

std::shared_ptr<Expr> Parser::expression()
{
  return equality();
}

std::shared_ptr<Expr> Parser:: equality()
{
   std::shared_ptr<Expr> expr = comparison();
    while (match(TokenType::BANG_EQUAL, TokenType::EQUAL_EQUAL)) {
      Token oper = previous();
      std::shared_ptr<Expr> right = comparison();
      expr = std::make_shared<Binary>(expr, oper, right);
    }
}

std::shared_ptr<Expr> Parser:: comparison()
{
   std::shared_ptr<Expr> expr = term();
    while (match(TokenType::GREATER, TokenType::GREATER_EQUAL,
                 TokenType::LESS, TokenType::LESS_EQUAL)) {
      Token oper = previous();
      std::shared_ptr<Expr> right = term();
      expr = std::make_shared<Binary>(expr, oper, right);
    }
    return expr;
}


std::shared_ptr<Expr> Parser:: term()
{
   std::shared_ptr<Expr> expr = factor();
    while (match(TokenType::MINUS, TokenType::PLUS)) {
      Token oper = previous();
      std::shared_ptr<Expr> right = factor();
      expr = std::make_shared<Binary>(expr, oper, right);
    }
    return expr;
}

std::shared_ptr<Expr> Parser:: factor()
{
   std::shared_ptr<Expr> expr = unary();
    while (match(TokenType::SLASH, TokenType::STAR)) {
      Token oper = previous();
      std::shared_ptr<Expr> right = unary();
      expr = std::make_shared<Binary>(expr, oper, right);
    }
    return expr;
}


std::shared_ptr<Expr> Parser:: unary()
{
    while (match(TokenType::BANG, TokenType::MINUS)) {
      Token oper = previous();
      std::shared_ptr<Expr> right = unary();
    return std::make_shared<Unary>( oper, right);
    }
    return primary();
}

std::shared_ptr<Expr> Parser:: primary()
{
    if (match(TokenType::FALSE)) return std::make_shared<Literal>(false);
    if (match(TokenType::TRUE)) return std::make_shared<Literal>(true);
    if (match(TokenType::NONE)) return std::make_shared<Literal>(nullptr);

    if (match(TokenType::NUMBER, TokenType::STRING)) {
      return std::make_shared<Literal>(previous().literal);
    }

    if (match(TokenType::LEFT_PAREN)) {
      std::shared_ptr<Expr> expr = expression();
      consume(TokenType::RIGHT_PAREN, "Expect ')' after expression.");
      return std::make_shared<Grouping>(expr);
    }

    throw error(peek(), "Expect expression.");
}

template <class... T>
bool Parser::match(T... types)
{
  assert((...&& std::is_same_v<T, TokenType>));
  if((... || check(types))) {
    advance();
    return true;
  }
  return false;
}


Token Parser::consume(const TokenType& type, const std::string& message)
{
  if (check(type)) return advance();
  throw error(peek(), message);
}
bool Parser::check(const TokenType& type)
{
  if (isAtEnd()) return false;
  return peek().type == type;
}

bool Parser::isAtEnd()
{
  return peek().type == TokenType::VOR_EOF;
}

Token Parser::peek()
{
  return tokens.at(current);
}

Token Parser::advance()
{
  if (!isAtEnd()) current++;
  return previous();
}

Token Parser::previous()
{
  return tokens.at(current - 1);
}

Parser::ParseError Parser::error(const Token& token, const std::string& message)
{
 Debug::error(token, message);
  return ParseError(message);
}

void Parser::synchronize()
{
    advance();
    
    while (!isAtEnd()) {
        if (previous().type == TokenType::SEMICOLON) return;
    
        switch (peek().type) {
        case TokenType::CLASS:
        case TokenType::DEF:
        case TokenType::FOR:
        case TokenType::IF: 
        case TokenType::PRINT:
        case TokenType::RETURN:
        case TokenType::WHILE:
            return;
        default:
            
            // Do nothing, just consume the token
            break;
        }  
         
}

    advance();
  }

