#include "../include/Expr.hpp"

/**
 * @brief Constructs a Binary expression node.
 * 
 * @param left A shared pointer to the left-hand side expression.
 * @param oper The operator token representing the binary operation.
 * @param right A shared pointer to the right-hand side expression.
 */
Binary::Binary(std::shared_ptr<Expr> left, Token oper,
               std::shared_ptr<Expr> right)
    : left(std::move(left)), Oper(std::move(oper)), right(std::move(right))
{
}
std::any Binary::accept(ExprVisitor *visitor)
{
  return visitor->visitBinaryExpr(shared_from_this());
}
Grouping::Grouping(std::shared_ptr<Expr> expression)
    : expression(std::move(expression))
{
}
std::any Grouping::accept(ExprVisitor *visitor)
{
  return visitor->visitGroupingExpr(shared_from_this());
}
Literal::Literal(std::any value) : value(std::move(value))
{
}
std::any Literal::accept(ExprVisitor *visitor)
{
  return visitor->visitLiteralExpr(shared_from_this());
}
Unary::Unary(Token oper, std::shared_ptr<Expr> right)
    : Oper(std::move(oper)), right(std::move(right))
{
}
std::any Unary::accept(ExprVisitor *visitor)
{
  return visitor->visitUnaryExpr(shared_from_this());
}
