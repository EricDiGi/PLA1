#ifndef PARSE_H
#define PARSE_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "shared.h"


void printString(char* string){
    for(int i = 0; i < (int)strlen(string); i++){
        printf("%c", string[i]);
    }
}


bool isComment(char* string){
    //printf("PARSING: "); printString(string); printf("\n");
    if(string[0] == '~'){
    	return comment;
	}
	return -1*comment;
}

bool isMain(char* string){
    int is = 0;
    char first_five[5];
    char first_four[4];
    for(int i = 0; i < 5; i++){
        first_five[i] = string[i];
        if(i < 4)
            first_four[i] = first_five[i];
    }

    int diff5 = strcmp(first_five, "begin");
    int diff4 = strcmp(first_four, "end.");
    
    if((diff5==0)||(diff4==0)){return funcblock;}
    return -1*funcblock;
}


bool deep_parse(char* string){
	
	for(int i = 0; i < (int) strlen(string); i++){
		
	}
}


int parse(char* string){
	if((int)strlen(string) == 0){return -1;}

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
    char copy3[l];
    strncpy(copy1, &copy_sub[0], l);
    strncpy(copy2, &copy_sub[0], l);
    strncpy(copy3, &copy_sub[0], l);
    
    int comm = isComment(copy1);
	int m = isMain(copy2));
    int deep = deep_parse(copy3);
    int* resolve = {comm, m, deep};
    int unsafe = 0;
    for(int i = 0; i < 3; i++){
    	if(resolve[i] < 0)
    		safe += abs(resolve[i])*pow(10,3*i);
	}
    return unsafe;
}


#endif
