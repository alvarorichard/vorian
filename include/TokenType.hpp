/**
 * @file TokenType.hpp
 * @brief Defines the enumeration of token types used in the lexical and syntax analyzer
 *        for the Vorian programming language.
 *
 * This file contains the `TokenType` enum class, which categorizes all possible tokens
 * that can be encountered during the lexical analysis phase of the Vorian language.
 * 
 * The tokens are divided into the following categories:
 * 
 * - **Single-character tokens**: Includes symbols like parentheses, braces, commas, etc.
 * - **One or two character tokens**: Includes operators and comparison symbols.
 * - **Literals**: Includes identifiers, strings, and numbers.
 * - **Keywords**: Reserved words in the Vorian language such as `if`, `else`, `while`, etc.
 * - **Special tokens**: Includes the `EOF` token to signify the end of a declaration.
 */


enum class TokenType{
    //Tokens de Caracteres Únicos
LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,LEFT_BRACKET,RIGHT_BRACKET,

// Tokens de um ou dois Caracteres
BANG, BANG_EQUAL,
EQUAL, EQUAL_EQUAL,
GREATER, GREATER_EQUAL,
LESS, LESS_EQUAL,

//  Tokens literais
IDENTIFIER, STRING, NUMBER,

// Palavras-chave
AND, CLASS, ELSE, FALSE, DEF, FOR, IF, NONE, OR,
PRINT, RETURN, SUPER, SELF, TRUE, WHILE,
// Token para final de declaração
VOR_EOF


};