#include "../include/Token.hpp"

#include <any>
#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>

#include "../include/magic_enum.hpp"

Token::Token(TokenType type, std::string lexeme, std::any literal, int line)
    : type(type), lexeme(lexeme), literal(literal), line(line)
{}

/**
 * @brief Converts the Token object to a string representation.
 *
 * This method generates a string that represents the Token object by combining
 * its type, lexeme, literal value (if present), and the line number where the
 * token was found. The type is converted to a string using the `magic_enum`
 * library, and the literal value is extracted and formatted based on its type
 * using `std::any_cast`.
 *
 * @return A string representation of the Token object in the format:
 *         "<type> <lexeme> <literal> <line>"
 *         - `<type>`: The string representation of the token type.
 *         - `<lexeme>`: The lexeme associated with the token.
 *         - `<literal>`: The literal value if present, or "[no literal]" if
 * absent.
 *         - `<line>`: The line number where the token was found.
 */
std::string Token::toString()
{
  const std::string str_enum = magic_enum::enum_name(this->type).data();

  std::stringstream ss_literal;
  if (literal.has_value()) {
    const std::type_info& type_any = literal.type();

    if (type_any == typeid(std::string)) {
      ss_literal << std::any_cast<std::string>(literal);
    } else if (type_any == typeid(int)) {
      ss_literal << std::any_cast<int>(literal);
    } else if (type_any == typeid(float)) {
      ss_literal << std::any_cast<float>(literal);
    } else if (type_any == typeid(double)) {
      ss_literal << std::any_cast<double>(literal);
    } else if (type_any == typeid(bool)) {
      ss_literal << std::any_cast<bool>(literal);
    } else {
      ss_literal << "Unknown type";
    }
  } else {
    ss_literal << "[no literal]";
  }
  return str_enum + " " + lexeme + " " + ss_literal.str() + " " +
         std::to_string(line);
}
