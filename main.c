#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int file_length = 0;

int main(int argc, char **argv){
    FILE* file_pointer;
    file_pointer = fopen(file_name, "r");

    fseek(file_pointer, 0, SEEK_END);
    file_length = ftell(file_pointer);
    fseek(file_pointer, 0, SEEK_SET);

    char ch[file_length];
    int curr_ = 0;
    while((ch[curr_] = fgetc(file_pointer)) != EOF){ curr_++;}
    fclose(file_pointer);

    for(int i = 0; i < file_length; i++){
        printf("%c", ch[i]);
    }
}