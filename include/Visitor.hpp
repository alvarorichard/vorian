#pragma once

#include <any>
#include <memory>

struct Binary;
struct Grouping;
struct Literal;
struct Unary;
struct Variable;
struct Assign;

struct ExprVisitor {
  virtual std::any visitBinaryExpr(std::shared_ptr<Binary> expr) = 0;
  virtual std::any visitGroupingExpr(std::shared_ptr<Grouping> expr) = 0;
  virtual std::any visitLiteralExpr(std::shared_ptr<Literal> expr) = 0;
  virtual std::any visitUnaryExpr(std::shared_ptr<Unary> expr) = 0;
  virtual std::any visitVariableExpr(std::shared_ptr<Variable> expr) = 0;
  virtual std::any visitAssignExpr(std::shared_ptr<Assign> expr) = 0;
  virtual ~ExprVisitor() = default;
};

struct Expr {
  virtual std::any accept(ExprVisitor &visitor) = 0;
};
