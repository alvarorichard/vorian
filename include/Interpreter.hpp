#pragma once
#include "Token.hpp"
#include "Expr.hpp"
#include "Visitor.hpp"

#include <memory>

class Interpreter : public ExprVisitor {
 public:
  // Removed duplicate declaration of interpret method
  std::any visitBinaryExpr(std::shared_ptr<Binary> expr) override;
  std::any visitGroupingExpr(std::shared_ptr<Grouping> expr) override;
  std::any visitLiteralExpr(std::shared_ptr<Literal> expr) override;
  std::any visitUnaryExpr(std::shared_ptr<Unary> expr) override;
  std::any visitVariableExpr(std::shared_ptr<Variable> expr) override;
  std::any visitAssignExpr(std::shared_ptr<Assign> expr) override;

  void interpret(std::shared_ptr<Expr> expr);
  Interpreter();

  void checkNumberOperand(const Token& oper, const std::any& operand);
    void checkNumberOperands(const Token& oper, const std::any& left, const std::any& right);
    bool isTruthy(const std::any& object);
    bool isEqual(const std::any& a, const std::any& b);
    std::string stringify(const std::any& object);
    std::any evaluate(std::shared_ptr<Expr> expr);



};