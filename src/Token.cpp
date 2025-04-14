#include "../include/Token.hpp"
#include "../include/magic_enum.hpp"
#include <sstream>
#include <string>
#include <typeinfo>
#include <iostream>
#include <any>




Token::Token(TokenType type, std::string lexeme, std::any literal, int line) : 
  type(type), lexeme(lexeme), literal(literal), line(line) {
    
}

std::string Token::toString(){
    const std::string str_enum = magic_enum::enum_name(this->type).data();

    std::stringstream ss_literal;
    if(literal.has_value()){
      const std::type_info& type_any = literal.type();
  
        
        if(type_any == typeid(std::string)){

            ss_literal << std::any_cast<std::string>(literal);
        } else if (type_any == typeid(int)){
            ss_literal << std::any_cast<int>(literal);
        } else if (type_any == typeid(float)){
            ss_literal << std::any_cast<float>(literal);
        } else if (type_any == typeid(double)){
            ss_literal << std::any_cast<double>(literal);
        } else if (type_any == typeid(bool)){
            ss_literal << std::any_cast<bool>(literal);
        } else {
            ss_literal << "Unknown type";
        }
    }else{
        ss_literal << "[no literal]";

    }
    return str_enum + " " + lexeme + " " + ss_literal.str() + " " + std::to_string(line);
}




