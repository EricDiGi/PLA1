#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int file_length = 0;

char* file_read(char* file_name){
    FILE* file_pointer;
    file_pointer = fopen(file_name, "r");

    fseek(file_pointer, 0, SEEK_END);
    file_length = ftell(file_pointer);
    fseek(file_pointer, 0, SEEK_SET);

    char ch[file_length];
    int curr_ = 0;
    while((ch[curr_] = fgetc(file_pointer)) != EOF){ curr_++;}
    fclose(file_pointer);

    return ch;
}


int main(int argc, char **argv){

    char* file_content = file_read(argv[1]);

    for(int i = 0; i < file_length; i++){
        printf("%c", file_content[i]);
    }
}