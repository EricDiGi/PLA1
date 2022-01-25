#ifndef FRIEND_H
#define FRIEND_H

#include <stdio.h>
#include "enum.h"

void printLineType(Line l, FILE* f){
    printf("%d", l.number);
    for(int i = 0; i < strlen(l.value); i++){
        printf("%c", l.value[i]);
    }
    printf("\n");
}

#endif