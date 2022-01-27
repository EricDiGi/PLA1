#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Parse.h"
#include "shared.h"

int file_length = 0;
FILE* file_pointer;


void initLexer(char* file_name){
    file_pointer = fopen(file_name, "r");

    fseek(file_pointer, 0, SEEK_END);
    file_length = ftell(file_pointer);
    fseek(file_pointer, 0, SEEK_SET);
}

FILE* get_file_pointer(){
    return file_pointer;
}

int get_file_length(){
    return file_length;
}

void exitLexer(){
    fclose(file_pointer);
}

void printFile(){
    //save file content to program memory
    char ch[file_length];
    int curr_ = 0;
    while((ch[curr_] = fgetc(file_pointer)) != EOF){ 
        printf("%c", ch[curr_]);
        curr_++;
    }
}

int find_next_token(char* string, char delim){
    for(int i = 0; i < (int) strlen(string); i++){
        if(string[i] == delim)
            return i;
    }
    return -1;
}

bool lexan(char* string, int length, int depth, int delim){
    if(delim > 5){return true;}

    int next_tok = find_next_token(string, prioritized_delim[delim]);
    if(next_tok > -1){
        char token[next_tok];
        char lookahead[length-next_tok];

        //Parse current token
        strncpy(token, &string[0], next_tok);
        printString(token); printf("\n");
        bool parse_resolute = lexan(token, (int) strlen(token), depth, delim+1);

        //Parse next token
        strncpy(lookahead, &string[next_tok+1], length);
        printString(lookahead); printf("\n");
        bool lexan_resolute = false;
        if((int) strlen(lookahead) > 0)
            lexan_resolute = lexan(lookahead, (int) strlen(lookahead), depth+1, delim);
         
        if(lexan_resolute && parse_resolute){
            return true;
        }
    }
    return false;
}

#endif
