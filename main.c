#include <iostream>
#include <stdio.h>
#include <stdlib.h>


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
        char ch[curr_+1] = next;
    }
    fclose(file_pointer);

    for(int i = 0; i <= curr_; i++)
        printf("%c",ch[i]);

}