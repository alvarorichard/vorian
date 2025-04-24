#pragma once
#include <memory>
#include <utility>
#include <vector>

#include "../include/Token.hpp"
#include "../include/Visitor.hpp"

/**
 * @brief Represents a binary expression in the abstract syntax tree (AST).
 *
 * This class is a final implementation of the `Expr` interface and is used to
 * represent binary operations (e.g., addition, subtraction, etc.) in the AST.
 * It contains the left and right operands as well as the operator token.
 *
 * @note Inherits from `std::enable_shared_from_this<Binary>` to allow the
 * creation of shared pointers to the current instance.
 */
struct Binary final : Expr, public std::enable_shared_from_this<Binary> {
  std::shared_ptr<Expr> left;
  Token Oper;
  std::shared_ptr<Expr> right;
  Binary(std::shared_ptr<Expr> left, Token oper, std::shared_ptr<Expr> right);
  std::any accept(ExprVisitor *visitor) override;
  ~Binary() = default;
};

/**
 * @brief Represents a grouping expression in the abstract syntax tree (AST).
 *
 * This class is a final implementation of the `Expr` interface and is used to
 * encapsulate an expression within parentheses or similar grouping constructs.
 * It also inherits from `std::enable_shared_from_this` to allow the creation
 * of shared pointers to itself.
 */
struct Grouping final : Expr, public std::enable_shared_from_this<Grouping> {
  std::shared_ptr<Expr> expression;

  std::shared_ptr<Expr> right;
  Grouping(std::shared_ptr<Expr> expression);
  std::any accept(ExprVisitor *visitor) override;
  ~Grouping() = default;
};

struct Literal final : Expr, public std::enable_shared_from_this<Literal> {
  std::any value;

  std::shared_ptr<Expr> right;
  Literal(std::any value);
  std::any accept(ExprVisitor *visitor) override;
  ~Literal() = default;
};

struct Unary final : Expr, public std::enable_shared_from_this<Unary> {
  Token Oper;
  std::shared_ptr<Expr> right;
  Unary(Token oper, std::shared_ptr<Expr> right);
  std::any accept(ExprVisitor *visitor) override;
  ~Unary() = default;
};
