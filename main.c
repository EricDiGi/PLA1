#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Lexer.h"
#include "Parser.h"

void analysis(char* file_content);

int main(int argc, char** argv){
    initLexer(argv[1]);
    //initSymbolTable();

    printf("\n Compiling %");
    return 0;
}

//////____________________________________________

/*void analysis(char* file_content){
    for(int i = 0; i < file_length; i++){
        printf("%c", ch[i]);
    }
*/}

