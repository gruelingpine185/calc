#ifndef CALC_TOKEN_H
#define CALC_TOKEN_H


#include <stdint.h>


typedef struct calc_token calc_token;


typedef enum {
    CALC_TOK_TYPE_VARIABLE,
    CALC_TOK_TYPE_NUMBER,
    CALC_TOK_TYPE_SEPARATOR,
    CALC_TOK_TYPE_OPERATOR
} calc_token_type;


struct calc_token {
    calc_token_type type;
    char* lexeme;
    uint32_t offset;
};

#endif // CALC_TOKEN_H
