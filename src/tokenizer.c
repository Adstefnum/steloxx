#include "tokenizer.h"
#include <stdio.h>

char *tokens[100];
int size = 0;

void tokenize(char *file_contents) {
    for (int i =0; file_contents[i] != '\0'; i++) {
        char token = file_contents[i];
        switch (token) {
            case '(':  addToken("LEFT_PAREN ("); break;
            case ')': addToken("RIGHT_PAREN )"); break;
            default: addToken("EOF");
        }
    }
}

void printTokens() {
    for(int i=0; i<size; i++) {
        setvbuf (stdout, NULL, _IONBF, 0);
        printf("%s %s\n",tokens[i], "null");
    }
    printf("EOF  null");

}

void addToken(char *token) {
    tokens[size++] = token;
}