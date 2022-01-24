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
    
    Region region;
    region.segment.begin = 0;
    region.segment.end = get_file_length();
    region.depth = 0;

    printf(region.segment.end);

    exitLexer();
    //initSymbolTable();

    printf("\n Compiling %d", 0);
    return 0;
}

//////____________________________________________

/*void analysis(char* file_content){
    for(int i = 0; i < file_length; i++){
        printf("%c", ch[i]);
    }
}*/

