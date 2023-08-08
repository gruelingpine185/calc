#include <assert.h>
#include <string.h>

#include "token.h"


static const char* token_str[20] = {
    "+",  "-",  "*",  "/",  // 3
    "%",  "^",  "=",  "<",  // 7
    ">",  "!",  "==", "!=", // 11
    "<=", ">=", "(",  ")",  // 15
    "[",  "]",  "{",  "}"   // 19
};


calc_token_type calc_get_operator_type(const char* _lexeme, uint32_t _len) {
    assert(_lexeme != NULL);
    assert(_len != 0);
    switch(_len) {
        case 1:
            if(strncmp(_lexeme, token_str[0], _len) == 0) {
                return CALC_TOK_TYPE_PLUS;
            }

            if(strncmp(_lexeme, token_str[1], _len) == 0) {
				return CALC_TOK_TYPE_MINUS;
            }

            if(strncmp(_lexeme, token_str[2], _len) == 0) {
				return CALC_TOK_TYPE_TIMES;
            }

            if(strncmp(_lexeme, token_str[3], _len) == 0) {
				return CALC_TOK_TYPE_DIV;
            }

            if(strncmp(_lexeme, token_str[4], _len) == 0) {
				return CALC_TOK_TYPE_MOD;
            }

            if(strncmp(_lexeme, token_str[5], _len) == 0) {
				return CALC_TOK_TYPE_POW;
            }

            if(strncmp(_lexeme, token_str[6], _len) == 0) {
				return CALC_TOK_TYPE_IS;
            }

            if(strncmp(_lexeme, token_str[7], _len) == 0) {
				return CALC_TOK_TYPE_LT;
            }

            if(strncmp(_lexeme, token_str[8], _len) == 0) {
				return CALC_TOK_TYPE_GT;
            }

            if(strncmp(_lexeme, token_str[9], _len) == 0) {
				return CALC_TOK_TYPE_FACT;
            }

            break;
        case 2:
            if(strncmp(_lexeme, token_str[10], _len) == 0) {
				return CALC_TOK_TYPE_EQU;
            }

            if(strncmp(_lexeme, token_str[11], _len) == 0) {
				return CALC_TOK_TYPE_NEQ;
            }

            if(strncmp(_lexeme, token_str[12], _len) == 0) {
				return CALC_TOK_TYPE_LEQ;
            }

            if(strncmp(_lexeme, token_str[13], _len) == 0) {
				return CALC_TOK_TYPE_GEQ;
            }

            break;
        default:
            break;
    }

    return CALC_TOK_TYPE_UNKNOWN;
}

calc_token_type calc_get_separator_type(const char* _lexeme, uint32_t _len) {
    assert(_lexeme != NULL);
    assert(_len != 0);
    switch(_len) {
        case 1:
            if(strncmp(_lexeme, token_str[14], _len) == 0) {
				return CALC_TOK_TYPE_RPAREN;
            }

            if(strncmp(_lexeme, token_str[15], _len) == 0) {
				return CALC_TOK_TYPE_LPAREN;
            }

            if(strncmp(_lexeme, token_str[16], _len) == 0) {
				return CALC_TOK_TYPE_RBRACKET;
            }

            if(strncmp(_lexeme, token_str[17], _len) == 0) {
				return CALC_TOK_TYPE_LBRACKET;
            }

            if(strncmp(_lexeme, token_str[18], _len) == 0) {
				return CALC_TOK_TYPE_RBRACE;
            }

            if(strncmp(_lexeme, token_str[19], _len) == 0) {
				return CALC_TOK_TYPE_RBRACE;
            }

            break;
        default:
            break;
    }

    return CALC_TOK_TYPE_UNKNOWN;
}
