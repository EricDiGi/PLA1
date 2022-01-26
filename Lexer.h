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

bool lexan(char* string, int length, int depth){
    int next_tok = find_next_token(string, 10);
    if(next_tok > -1){
        char token[next_tok];
        char remainder[length-next_tok];

        strncpy(token, &string[0], next_tok);
        //Do this line here
        int parse_resolute = parse(token);
        if(parse_resolute != -1)
            printf("Line %d contains error %d\n", depth, parse_resolute);

        strncpy(remainder, &string[next_tok+1], length);
        bool lexan_resolute = false;
        if((int) strlen(remainder) > 0)
            lexan_resolute = lexan(remainder, (int) strlen(remainder), depth+1);
        
        
        if(lexan_resolute && parse_resolute){
            return true;
        }
    }
    return false;
}

#endif
