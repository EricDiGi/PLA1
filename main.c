#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void extend(char &input){
    
}


int main(int argc, char **argv){
    FILE* file_pointer;
    file_pointer = fopen(argv[1], "r");

    fseek(file_pointer, 0, SEEK_END);
    int file_length = ftell(file_pointer);
    fseek(file_pointer, 0, SEEK_SET);

    char ch[file_length];
    int curr_ = 0;
    while((ch[curr_] = fgetc(file_pointer)) != EOF){ curr_++;}
    fclose(file_pointer);
    for(int i = 0; i < curr_; i++){
        printf("%c", ch[i]);
    }
}