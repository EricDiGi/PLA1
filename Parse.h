#ifndef PARSE_H
#define PARSE_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct funcBlock{
    int begin = 0;
    int end = 0;
} main_;

void printString(char* string){
    for(int i = 0; i < (int)strlen(string); i++){
        printf("%c", string[i]);
    }
}


bool isComment(char* string){
    return string[0] == '~';
}

bool isMain(char* string){
    int is = 0;
    char first_five[5];
    char first_four[4];
    for(int i = 0; i < 5; i++){
        first_five[i] = string[i];
        if(i < 3)
            first_four[i] = string[i];
    }
    int diff5 = strcmp(first_five, "begin");
    int diff4 = strcmp(first_four, "end.");
    if((diff5 == 0)||(diff4 == 0)){is++; printf(">>> Found Begin/End\n");}
    if(is > 0)
        return true;
    return false;
}


bool parse(char* string){
    printf("PARSING: "); printString(string); printf("\n");
    char copy[(int) strlen(string)];
    for(int i = 0; i < (int)strlen(string); i++){
        copy[i] = 0;
        if(string[i] != ' ')
            copy[i] = string[i];
    }

    if(isComment(copy)||isMain(copy)){return true;}
    
    return false;
}

#endif