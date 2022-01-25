#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Lexer.h"

int main(int argc, char** argv){
    initLexer(argv[1]);

    FILE* f = get_file_pointer();

    char string[get_file_length()];
    int curr_ = 0;
    char ch;
    int actual = 0;
    while((ch = fgetc(f)) != EOF){
        if((ch != ' ')&&(ch != '\t')){
            string[actual] = ch;
            printf("%c", string[actual]);
            actual++;
        }
    }

    exitLexer();
    //initSymbolTable();

    printf("\n Compiling %d", 0);
    return 0;
}