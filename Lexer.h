#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Parse.h"

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

void printString(char* string){
    for(int i = 0; i < (int)strlen(string); i++){
        printf("%c", string[i]);
    }
}

bool lexan(char* string, int length, int depth){
    int next_tok = find_next_token(string, '\n');
    if(next_tok > -1){
        char token[next_tok];
        char remainder[length-next_tok];
        printf("next token: %d\n", next_tok);

        strncpy(token, &string[0], next_tok);
        printf("token: "); printString(token);

        strncpy(remainder, &string[next_tok+1], length);
        printf("\nremainder: "); printString(remainder);

        bool lexan_resolute = false;
        if((int) strlen(remainder) > 0)
            lexan_resolute = lexan(remainder, (int) strlen(remainder), depth+1);
        /*
        if(lexan_resolute){
            if(!parse(string)){
                printf("Error on line: %d", depth);
            }
            return true;
        }*/
    }
    return true;
}

#endif