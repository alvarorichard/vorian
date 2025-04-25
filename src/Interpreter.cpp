#include "../include/Interpreter.hpp"
#include "../include/RuntimeError.hpp" // Added to resolve RuntimeError issues
#include <string> // Retain only necessary includes
#include <iostream> // Added for std::cout and std::endl

Interpreter::Interpreter() {}

std::any Interpreter::visitLiteralExpr(std::shared_ptr<Literal> expr){
  return expr->value;
}

std::any Interpreter::visitUnaryExpr(std::shared_ptr<Unary> expr){
  std::any right = evaluate(expr->right);

  switch(expr->oper.type){
    case TokenType::BANG:
      return !isTruthy(right);
    case TokenType::MINUS:
      checkNumberOperand(expr->oper, right);
      return -std::any_cast<double>(right);
    default:
      return {};
  }
}

bool Interpreter::isTruthy(const std::any& object){
  if(object.type() == typeid(nullptr)) return false;
  if(object.type() == typeid(bool)){
    return std::any_cast<bool>(object);
  }
  return true;
}

void Interpreter::checkNumberOperand(const Token& oper, const std::any& operand){
  if(operand.type() == typeid(double)) return;
  //if(operand.type() == typeid(int)) return;
  //if(operand.type() == typeid(float)) return;
  throw RuntimeError{oper, "Operand must be a number."};
}

void Interpreter::checkNumberOperands(const Token& oper, const std::any& left, const std::any& right){
  if(left.type() == typeid(double) && right.type() == typeid(double)) return;
  // verificar float e int
  throw RuntimeError{oper, "Operand must be a number."};
}

bool Interpreter::isEqual(const std::any& a, const std::any& b){
  if(a.type() == typeid(nullptr) && b.type() == typeid(nullptr)){
    return true;
  }

  if(a.type() == typeid(nullptr) || b.type() == typeid(nullptr)){
    return false;
  }

  if(a.type() == typeid(double) && b.type() == typeid(double)){
    return std::any_cast<double>(a) == std::any_cast<double>(b);
  }

  if(a.type() == typeid(std::string) && b.type() == typeid(std::string)){
    return std::any_cast<std::string>(a) == std::any_cast<std::string>(b);
  }

  if(a.type() == typeid(bool) && b.type() == typeid(bool)){
    return std::any_cast<bool>(a) == std::any_cast<bool>(b);
  }

  return false;
}

std::string Interpreter::stringify(const std::any& object){
  if(object.type() == typeid(nullptr)) return "nil";
  
  if(object.type() == typeid(double)){
    std::string text = std::to_string(std::any_cast<double>(object));
    if(text[text.length() - 7] == '.' && text[text.length() - 6] == '0'){
      text = text.substr(0, text.length() - 7);
    }
    return text;
  }

  if(object.type() == typeid(std::string)){
    return std::any_cast<std::string>(object);
  }

  if(object.type() == typeid(bool)){
     if(std::any_cast<bool>(object)){
       std::string result{"true"};
       return result;
     }else{
       std::string result{"false"};
       return result;
     }
  }

  return "stringify: cannot reconize type";
}

std::any Interpreter::visitGroupingExpr(std::shared_ptr<Grouping> expr){
  return evaluate(expr->expression);
}

std::any Interpreter::evaluate(std::shared_ptr<Expr> expr) {
  std::cout << "Evaluating expression." << std::endl;
  return expr->accept(*this);
}

std::any Interpreter::visitBinaryExpr(std::shared_ptr<Binary> expr){
  std::any left = evaluate(expr->left);
  std::any right = evaluate(expr->right);

  switch (expr->oper.type) {
    case TokenType::GREATER:
      checkNumberOperands(expr->oper, left, right);
      return std::any_cast<double>(left) > std::any_cast<double>(right);
    case TokenType::GREATER_EQUAL:
      checkNumberOperands(expr->oper, left, right);
      return std::any_cast<double>(left) >= std::any_cast<double>(right);
    case TokenType::LESS:
      checkNumberOperands(expr->oper, left, right);
      return std::any_cast<double>(left) < std::any_cast<double>(right);
    case TokenType::LESS_EQUAL:
      checkNumberOperands(expr->oper, left, right);
      return std::any_cast<double>(left) <= std::any_cast<double>(right);
    case TokenType::MINUS:
      checkNumberOperands(expr->oper, left, right);
      return std::any_cast<double>(left) - std::any_cast<double>(right);
    case TokenType::PLUS:

      if(left.type() == typeid(double) && right.type() == typeid(double)){
        return std::any_cast<double>(left) + std::any_cast<double>(right);
      }

      if(left.type() == typeid(std::string) && right.type() == typeid(std::string)){
        return std::any_cast<std::string>(left) + std::any_cast<std::string>(right);
      }
      
      throw RuntimeError{expr->oper, "Operands not a same type"};

    case TokenType::STAR:
      checkNumberOperands(expr->oper, left, right);
      return std::any_cast<double>(left) * std::any_cast<double>(right);
    case TokenType::SLASH:
      checkNumberOperands(expr->oper, left, right);
      if (std::any_cast<double>(right) == 0) {
        throw RuntimeError{expr->oper, "Division by zero."};
      }
      return std::any_cast<double>(left) / std::any_cast<double>(right);
    case TokenType::BANG_EQUAL:
      checkNumberOperands(expr->oper, left, right);
      return !isEqual(left, right);
    case TokenType::EQUAL_EQUAL:
      return isEqual(left, right);
    default:
      return {};
  }
}

std::any Interpreter::visitVariableExpr(std::shared_ptr<Variable> expr) {
  // Placeholder implementation for visitVariableExpr
  return {}; // Replace with actual logic
}

std::any Interpreter::visitAssignExpr(std::shared_ptr<Assign> expr) {
  // Placeholder implementation for visitAssignExpr
  return {}; // Replace with actual logic
}



