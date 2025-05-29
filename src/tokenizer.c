#include "tokenizer.h"

char *tokens[100];
int size = 0;

void *tokenize(char *file_contents) {
    for (int i =0; file_contents[i] != '\0'; i++) {
        char token = '(';
        switch (token) {
            case '(':  addToken("LEFT_PAREN"); break;
            case ')': addToken("RIGHT_PAREN"); break;
            default: addToken("EOF");
        }
    }
}

char *printTokens(char *token_list) {

}

char *addToken(char *token) {
    tokens[size] = token;
}