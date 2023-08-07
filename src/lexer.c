#include <assert.h>
#include <stdlib.h>
#include <stdint.h>

#include "lexer.h"


struct calc_lexer {
    const char* buffer;
    uint32_t offset;
};


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
