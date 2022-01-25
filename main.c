#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Lexer.h"
#include "friend.h"
#include "Parser.h"
#include "enum.h"

int main(int argc, char** argv){
    initLexer(argv[1]);

    FILE* f = get_file_pointer();
    char string[get_file_length()];
    char ch;
    int i = 0;
    while((ch = fgetc(f)) != EOF){
        string[i] = ch;
        i++;
    }

    for(int k = 0; k < i; k++){
        printf("%c", string[k]);
    }

    exitLexer();
    //initSymbolTable();

    printf("\n Compiling %d", 0);
    return 0;
}