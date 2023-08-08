#include <stdio.h>
#include <stdlib.h>

#include "lexer.h"
#include "token.h"

static void destroy_tok(calc_token* _token);


static void destroy_tok(calc_token* _token) {
    free(_token->lexeme);
    free(_token);
    _token = NULL;
}


int main(int _argc, char** _argv) {
    if(_argc == 1) return 1;

    calc_lexer* lexer = calc_create_lexer(_argv[1]);
    if(!lexer) return 1;

    calc_token* tok = NULL;
    while((tok = calc_lexer_lex(lexer))) {
        if(tok->type == CALC_TOK_TYPE_EOF) {
            printf("offset: %u, type: %d, val: EOF\n",
                tok->offset,
                tok->type);
            break;
        }

        printf("offset: %u, type: %d, val: \'%s\'\n",
                tok->offset,
                tok->type,
                tok->lexeme);
        destroy_tok(tok);
    }

    destroy_tok(tok);
    calc_destroy_lexer(lexer);
    return 0;
}
