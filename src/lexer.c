#include <assert.h>
#include <stdlib.h>
#include <stdint.h>

#include "lexer.h"


struct calc_lexer {
    const char* buffer;
    uint32_t offset;
};


static int calc_is_locase(int _c);
static int calc_is_upcase(int _c);
static int calc_is_variable(int _c);
static int calc_is_whitespace(int _c);
static int calc_lexer_curr(const calc_lexer* _lexer);
#if 0
static int calc_lexer_next(const calc_lexer* _lexer);
#endif
static int calc_lexer_advance(calc_lexer* _lexer);
static char* calc_lexer_create_lexeme(calc_lexer* _lexer, uint32_t _start);
static void calc_lexer_skip_whitespace(calc_lexer* _lexer);
static calc_token* calc_lexer_collect_variable(calc_lexer* _lexer);


static int calc_is_locase(int _c) {
    return ((_c >= 'a') && (_c <= 'z'));
}

static int calc_is_upcase(int _c) {
    return ((_c >= 'A') && (_c <= 'Z'));
}

static int calc_is_variable(int _c) {
    return (calc_is_upcase(_c) || calc_is_locase(_c));
}

static int calc_is_whitespace(int _c) {
    return (
        (_c == '\n') || (_c == '\t') || _c == (_c == '\r') ||
        (_c == ' ')
    );
}

static int calc_lexer_curr(const calc_lexer* _lexer) {
    assert(_lexer != NULL);
    return _lexer->buffer[_lexer->offset];
}

#if 0
static int calc_lexer_next(const calc_lexer* _lexer) {
    assert(_lexer != NULL);
    return _lexer->buffer[_lexer->offset + 1];
}
#endif

static int calc_lexer_advance(calc_lexer* _lexer) {
    assert(_lexer != NULL);
    if(!calc_lexer_curr(_lexer)) return 0;

    _lexer->offset++;
    return 1;
}

static char* calc_lexer_create_lexeme(calc_lexer* _lexer, uint32_t _start) {
    assert(_lexer != NULL);
    uint32_t len = _lexer->offset - _start;
    char* lexeme = (char*) malloc(len);
    if(!lexeme) return NULL; 

    for(uint32_t i = 0; i < len; i++) {
        lexeme[i] = _lexer->buffer[_start + i];
    }

    lexeme[len] = '\0';
    return lexeme;
}

static void calc_lexer_skip_whitespace(calc_lexer* _lexer) {
    do {
        if(!calc_is_whitespace(calc_lexer_curr(_lexer))) return;
    } while(calc_lexer_advance(_lexer));
}

static calc_token* calc_lexer_collect_variable(calc_lexer* _lexer) {
    assert(_lexer != NULL);
    calc_token* token = (calc_token*) malloc(sizeof(*token));
    if(!token) return NULL;

    token->offset = _lexer->offset;

    do {
        if(!calc_is_variable(calc_lexer_curr(_lexer))) {
            token->type = CALC_TOK_TYPE_VARIABLE;
            break;
        }
    } while(calc_lexer_advance(_lexer));

    token->lexeme = calc_lexer_create_lexeme(_lexer, token->offset);
    if(!token->lexeme) {
        free(token);
        return NULL;
    }

    return token;
}
calc_lexer* calc_create_lexer(const char* _buffer) { 
    assert(_buffer != NULL);
    calc_lexer* lexer = (calc_lexer*) malloc(sizeof(*lexer));
    if(!lexer) return NULL;

    lexer->buffer = _buffer;
    lexer->offset = 0;
    return lexer;
}

void calc_destroy_lexer(calc_lexer* _lexer) {
    assert(_lexer != NULL);
    free(_lexer);
    _lexer = NULL;
}

calc_token* calc_lexer_lex(calc_lexer* _lexer) {
    assert(_lexer != NULL);
    if(calc_is_whitespace(calc_lexer_curr(_lexer))) {
        calc_lexer_skip_whitespace(_lexer);
    }

    if(calc_is_variable(calc_lexer_curr(_lexer))) {
        return calc_lexer_collect_variable(_lexer);
    }

    return NULL;
}
