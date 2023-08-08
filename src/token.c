#include <assert.h>
#include <string.h>

#include "token.h"


calc_token_type calc_get_operator_type(const char* _lexeme, uint32_t _len) {
    assert(_lexeme != NULL);
    assert(_len != 0);
    switch(_len) {
        case 1:
            if(strncmp(_lexeme, "+", _len) == 0) return CALC_TOK_TYPE_PLUS;
            if(strncmp(_lexeme, "-", _len) == 0) return CALC_TOK_TYPE_MINUS;
            if(strncmp(_lexeme, "*", _len) == 0) return CALC_TOK_TYPE_TIMES;
            if(strncmp(_lexeme, "/", _len) == 0) return CALC_TOK_TYPE_DIV;
            if(strncmp(_lexeme, "%", _len) == 0) return CALC_TOK_TYPE_MOD;
            if(strncmp(_lexeme, "^", _len) == 0) return CALC_TOK_TYPE_POW;
            if(strncmp(_lexeme, "=", _len) == 0) return CALC_TOK_TYPE_IS;
            if(strncmp(_lexeme, "<", _len) == 0) return CALC_TOK_TYPE_LT;
            if(strncmp(_lexeme, ">", _len) == 0) return CALC_TOK_TYPE_GT;
            if(strncmp(_lexeme, "!", _len) == 0) return CALC_TOK_TYPE_FACT;

            break;
        case 2:
            if(strncmp(_lexeme, "==", _len) == 0) return CALC_TOK_TYPE_EQU;
            if(strncmp(_lexeme, "!=", _len) == 0) return CALC_TOK_TYPE_NEQ;
            if(strncmp(_lexeme, "<=", _len) == 0) return CALC_TOK_TYPE_LEQ;
            if(strncmp(_lexeme, ">=", _len) == 0) return CALC_TOK_TYPE_GEQ;
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
            if(strncmp(_lexeme, "(", _len) == 0) return CALC_TOK_TYPE_RPAREN;
            if(strncmp(_lexeme, ")", _len) == 0) return CALC_TOK_TYPE_LPAREN;
            if(strncmp(_lexeme, "[", _len) == 0) return CALC_TOK_TYPE_RBRACKET;
            if(strncmp(_lexeme, "]", _len) == 0) return CALC_TOK_TYPE_LBRACKET;
            if(strncmp(_lexeme, "{", _len) == 0) return CALC_TOK_TYPE_RBRACE;
            if(strncmp(_lexeme, "}", _len) == 0) return CALC_TOK_TYPE_RBRACE;

            break;
        default:
            break;
    }

    return CALC_TOK_TYPE_UNKNOWN;
}

