#ifndef CALC_TOKEN_H
#define CALC_TOKEN_H


#include <stdint.h>


typedef struct calc_token calc_token;


typedef enum {
    CALC_TOK_TYPE_EOF,
    CALC_TOK_TYPE_UNKNOWN,  // unknown
    CALC_TOK_TYPE_VAR,      // variable
    CALC_TOK_TYPE_INT,      // integer
    CALC_TOK_TYPE_LPAREN,   // (
    CALC_TOK_TYPE_RPAREN,   // )
    CALC_TOK_TYPE_LBRACKET, // [
    CALC_TOK_TYPE_RBRACKET, // ]
    CALC_TOK_TYPE_LBRACE,   // {
    CALC_TOK_TYPE_RBRACE,   // }
    CALC_TOK_TYPE_PLUS,     // +
    CALC_TOK_TYPE_MINUS,    // -
    CALC_TOK_TYPE_TIMES,    // *
    CALC_TOK_TYPE_DIV,      // /
    CALC_TOK_TYPE_MOD,      // %
    CALC_TOK_TYPE_POW,      // ^
    CALC_TOK_TYPE_IS,       // =
    CALC_TOK_TYPE_LT,       // <
    CALC_TOK_TYPE_GT,       // >
    CALC_TOK_TYPE_FACT,     // !
    CALC_TOK_TYPE_EQU,      // ==
    CALC_TOK_TYPE_NEQ,      // !=
    CALC_TOK_TYPE_LEQ,      // <=
    CALC_TOK_TYPE_GEQ       // >=
} calc_token_type;


struct calc_token {
    char* lexeme;
    calc_token_type type;
    uint32_t offset;
    uint32_t len;
};


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
calc_token_type calc_get_operator_type(const char* lexeme, uint32_t _len);
calc_token_type calc_get_separator_type(const char* _lexeme, uint32_t _len);
#ifdef __cplusplus
}
#endif // __cplusplus

#endif // CALC_TOKEN_H
