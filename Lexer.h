#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    free(file_pointer);
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

bool lexan(char* string, int length){
    if(string == nullptr){return true;}
    char* sub = strtok(string,"\n");
    //if(sub == nullptr){return true;}
    bool next = lexan(sub, (int) strlen(sub));
    for(int i = 0; i < (int) strlen(sub); i++){
        printf("%c", sub[i]);
    }
    return true;
}

#endif