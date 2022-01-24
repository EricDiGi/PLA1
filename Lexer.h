#ifndef LEXER_H
#define LEXER_H
#include <stdio.h>
#include <stdlib.h>


int file_length = 0;

void initLexer(){
    FILE* file_pointer;
    file_pointer = fopen(argv[1], "r");

    //get file length
    fseek(file_pointer, 0, SEEK_END);
    file_length = ftell(file_pointer);
    fseek(file_pointer, 0, SEEK_SET);


    //save file content to program memory
    char ch[file_length];
    int curr_ = 0;
    while((ch[curr_] = fgetc(file_pointer)) != EOF){ curr_++;}
    fclose(file_pointer);
}

#endif