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
    //printf("PARSING: "); printString(string); printf("\n");
    return string[0] == '~';
}

bool isMain(char* string){
    //printf("PARSING: "); printString(string); printf("\n");
    int is = 0;
    char first_five[5];
    char first_four[4];
    for(int i = 0; i < 5; i++){
        first_five[i] = string[i];
        if(i < 4)
            first_four[i] = first_five[i];
    }

    printString(first_four); printf("\n");

    int diff5 = strcmp(first_five, "begin");
    int diff4 = strcmp(first_four, "end.");
    if((diff5 == 0)||(diff4 == 0)){is++; 
        printf(">>> Found Begin/End\n");
    }
    if(is > 0)
        return true;
    return false;
}


bool parse(char* string){
    char copy_sub[(int) strlen(string)];
    int l = 0;
    for(int i = 0; i < (int)strlen(string); i++){
        copy_sub[i] = 0;
        if(string[i] != ' '){
            copy_sub[i] = string[i];
            l++;
        }
    }
    char copy1[l];
    char copy2[l];
    strncpy(copy1, &copy_sub[0], l);
    strncpy(copy2, &copy_sub[0], l);
    if(isComment(copy1)||isMain(copy2)){return true;}
    
    return false;
}

#endif