#include "tokenizer.h"
#include <stdio.h>
#include <string.h>

char *tokens[100];
int size = 0;

void tokenize(char *file_contents) {
    char *line = strtok(file_contents,"\n");
    int line_count = 1;
    char *error[256];
//can rewrite this to have a token data structure and not add error to tokens
    while(line) {
        for (int i =0; line[i] != '\0'; i++) {
            char token = line[i];
            switch (token) {
                case '(':  addToken("LEFT_PAREN ( null"); break;
                case ')': addToken("RIGHT_PAREN ) null"); break;
                case '{':  addToken("LEFT_BRACE { null"); break;
                case '}': addToken("RIGHT_BRACE } null"); break;
                case ',':  addToken("COMMA , null"); break;
                case '.': addToken("DOT . null"); break;
                case '-':  addToken("MINUS - null"); break;
                case '+': addToken("PLUS + null"); break;
                case ';': addToken("SEMICOLON ; null"); break;
                case '/':  addToken("SLASH / null"); break;
                case '*': addToken("STAR * null"); break;
                default: snprintf(error, sizeof(error),"[line %d] Error: Unexpected character: %c", line_count, token);addToken(error);
            }
        }
        line_count +=1;
        line = strtok(NULL,"\n");
    }
}

void printTokens() {
    for(int i=0; i<size; i++) {
        setvbuf (stdout, NULL, _IONBF, 0);
        printf("%s\n",tokens[i]);
    }
    printf("EOF  null");

}

void addToken(char *token) {
    tokens[size++] = token;
}