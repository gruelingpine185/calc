#ifndef CALC_LEXER_H
#define CALC_LEXER_H


#include "token.h"


typedef struct calc_lexer calc_lexer;


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
calc_lexer* calc_create_lexer(const char* _buffer);
void calc_destroy_lexer(calc_lexer* _lexer);
#ifdef __cplusplus
}
#endif // __cplusplus

#endif // CALC_LEXER_H
