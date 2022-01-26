#ifndef PARSE_H
#define PARSE_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
enum node{comment, main}

typedef struct main{
    bool begin = false;
    bool end = false;
} main;

bool isComment(char* string){
    return string[0] == '~';
}



bool parse(char* string){
    char copy[(int) strlen(string)];
    for(int i = 0; i < (int)strlen(string); i++){
        copy[i] = 0;
        if(string[i] != ' ')
            copy[i] = string[i];
    }

    if(isComment(copy)){return true;}
    
    return false;
}

#endif