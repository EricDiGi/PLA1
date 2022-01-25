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
    while((ch = fgets(f)) != EOF){
        string[i] = ch;
        i++
    }

    for(int i = 0; i < i+1; i++){
        printf("%c", string[i]);
    }

    exitLexer();
    //initSymbolTable();

    printf("\n Compiling %d", 0);
    return 0;
}