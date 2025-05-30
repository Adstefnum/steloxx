#include "tokenizer.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *validTokens[500];
char *invalidTokens[500];
int validTokensSize = 0;
int invalidTokensSize = 0;
char error[256];

void tokenize(char *file_contents) {
    char *line = strtok(file_contents,"\n");
    int line_count = 1;
    
    while(line) {
        for (int i =0; line[i] != '\0'; i++) {
            char token = line[i];
            switch (token) {
                case '(':  addToken("LEFT_PAREN (", validTokens, &validTokensSize); break;
                case ')': addToken("RIGHT_PAREN )", validTokens, &validTokensSize); break;
                case '{':  addToken("LEFT_BRACE {", validTokens, &validTokensSize); break;
                case '}': addToken("RIGHT_BRACE }", validTokens, &validTokensSize); break;
                case ',':  addToken("COMMA ,", validTokens, &validTokensSize); break;
                case '.': addToken("DOT .", validTokens, &validTokensSize); break;
                case '-':  addToken("MINUS -", validTokens, &validTokensSize); break;
                case '+': addToken("PLUS +", validTokens, &validTokensSize); break;
                case ';': addToken("SEMICOLON ;", validTokens, &validTokensSize); break;
                case '/':  addToken("SLASH /", validTokens, &validTokensSize); break;
                case '*': addToken("STAR *", validTokens, &validTokensSize); break;
                case '=': {
                            if(line[i+1] =='=') {
                                addToken("EQUAL_EQUAL ==", validTokens, &validTokensSize); 
                                i++;
                                break;
                            }
                                addToken("EQUAL =", validTokens, &validTokensSize); break;
                            }                
                default: {
                            sprintf(error,"[line %d] Error: Unexpected character: %c", line_count, token);
                            addToken(error, invalidTokens, &invalidTokensSize);
                        }
            }
        }
        line_count +=1;
        line = strtok(NULL,"\n");
    }
}

void printTokens() {
    for(int i=0; i<invalidTokensSize; i++) {
        fprintf(stderr,"%s\n",invalidTokens[i]);
    }
    for(int i=0; i<validTokensSize; i++) {
        printf("%s %s\n",validTokens[i],"null");
    }
    printf("EOF  null");
    if(invalidTokensSize > 0){
        exit(65);
    }

}

void addToken(char *token, char *tokens[], int *tokensSize) {
    tokens[(*tokensSize)++] = strdup(token);
}

void freeTokens() {
    for (int i = 0; i < validTokensSize; i++) {
        free(validTokens[i]);
    }
    for (int i = 0; i < invalidTokensSize; i++) {
        free(invalidTokens[i]);
    }
}