#ifndef FRIEND_H
#define FRIEND_H

#include <stdio.h>
#include "enum.h"

void printLineType(Line l, FLIE* f){
    int begin = 0; int end = 0;
    fsetpos(f, l.segment.begin);
    begin = ftell(f);
    fsetpos(f, l.segment.end);
    end = ftell(f);

    int line_length = end - begin;
    char string[line_length];
    for(int i = begin; i <= end; i++){
        string[i-begin] = fgetc(f); 
    }
    
    printf("(%d,%d) %d: ", begin, end, l.number);
    for(int i = 0; i < line_length; i++){
        printf("%c", string[i]);
    }
    printf("\n");
}

#endif