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
    int size = 1;
    int curr_ = 0;
    while((ch[curr_] = fgetc(file_pointer)) != EOF){
        size++;
        ch = (char*) malloc (size * sizeof(char));
    }
    for(int i = 0; i <= curr_; i++)
        printf("%c",ch[i]);
    fclose(file_pointer);

}