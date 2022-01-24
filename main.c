#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Lexer.h"
#include "Parser.h"
#include "enum.h"

void analysis(char* file_content);

int main(int argc, char** argv){
    initLexer(argv[1]);
    
    struct Region document;
    document.depth = 0;
    document.seg.begin = 0;
    document.seg.end = get_file_length();

    printf("%d", document.seg.end);

    exitLexer();
    //initSymbolTable();

    printf("\n Compiling %");
    return 0;
}

//////____________________________________________

/*void analysis(char* file_content){
    for(int i = 0; i < file_length; i++){
        printf("%c", ch[i]);
    }
}*/

