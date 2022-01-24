#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void extend(char &input){
    
}


int main(int argc, char **argv){
    FILE* file_pointer;
    file_pointer = fopen(argv[1], "r");

    char ch[1];
    int curr_ = 0;
    while((ch[curr_] = fgetc(file_pointer)) != EOF){
        char next[curr_+1];
        for(int i = 0; i <= curr_; i++)
            next[i] = ch[i];
        strcpy(next, ch);
        //printf("%c", next[curr_]);
    }
    for(int i = 0; i <= curr_; i++)
        printf("%c",ch[i]);
    fclose(file_pointer);

}