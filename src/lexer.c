#include <assert.h>
#include <stdlib.h>
#include <stdint.h>

#include "lexer.h"


struct calc_lexer {
    const char* buffer;
    uint32_t offset;
};


static int calc_is_whitespace(int _c);
static int calc_lexer_curr(const calc_lexer* _lexer);
#if 0
static int calc_lexer_next(const calc_lexer* _lexer);
#endif
static int calc_lexer_advance(calc_lexer* _lexer);
static void calc_lexer_skip_whitespace(calc_lexer* _lexer);


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
static void calc_lexer_skip_whitespace(calc_lexer* _lexer) {
    do {
        if(!calc_is_whitespace(calc_lexer_curr(_lexer))) return;
    } while(calc_lexer_advance(_lexer));
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

    return NULL;
}
