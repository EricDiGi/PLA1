#include <iostream>
#include <stdio.h>
#include <stdlib.h>


void extend(char &input){
    
}


int main(int argc, char **argv){
    FILE* file_pointer;
    file_pointer = fopen(argv[1], "r");

    char* ch = new char(1);
    char* next = new char(0);
    int curr_ = 0;
    while((ch[curr_] = fgetc(file_pointer)) != EOF)
        // send to storage?
        printf("%c", ch[curr_]);
        next = new char(curr_+2);
        for(int i = 0; i <= curr_; i++)
            next[i] = ch[i];
        ch = next;
        //delete next;
    fclose(file_pointer);

    for(int i = 0; i <= curr_; i++)
        printf("%c",ch[i]);

}