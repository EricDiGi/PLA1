#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdlib.h>

#include "enum.h"

#define int DONE = 1;

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

int lexan(){
    int lineno = 0;
    int ignore = false;
    char ch;
    while(1){
        ch = fgetc(file_pointer);
        if(ch == 10){lineno++; ignore=false;}
        else if(ch == '~'){ignore=true;}
        else if(ch >= 48 && ch <= 57 && !ignore){
            /* is digit*/
        }
        else if(!ignore && (((ch >= 65)&&(ch <= 90))||((ch >= 97)&&(ch <= 122)))){
            /* is character */
        }
        else if(ch == EOF){
            return DONE;
        }
        else
            continue
    }
    return 
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

#endif