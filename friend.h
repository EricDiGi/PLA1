#ifndef FRIEND_H
#define FRIEND_H

#include <stdio.h>
#include "enum.h"

void printLineType(Line l, FILE* f){

    int line_length = l.segment.end - l.segment.begin;
    char string[line_length];
    for(int i = l.segment.begin; i <= l.segment.end; i++){
        string[i-l.segment.begin] = fgetc(f); 
    }
    
    printf("(%d,%d) %d: ",l.segment.begin, l.segment.end, l.number);
    for(int i = 0; i < line_length; i++){
        printf("%c", string[i]);
    }
    printf("\n");
}

#endif