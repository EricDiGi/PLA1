#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Lexer.h"
#include "friend.h"
#include "Parser.h"
#include "enum.h"

void analysis(char* file_content);

int main(int argc, char** argv){
    Line lines[50];
    initLexer(argv[1]);

    FILE* f = get_file_pointer();
    char ch;
    int begin_;
    int curr_;
    int line_num = 0;
    char last_char;
    while((ch = fgetc(f)) == EOF){
        if((line_num == 0) || (last_char == '\n')){
            printf("%d: begin\n",ftell(f));
            begin_ = ftell(f);
        }
        if(ch == '\n'){
            Line line;
            printf("%d:end\n",ftell(f));
            curr_ = ftell(f);
            line.number = line_num;
            line.segment.begin = begin_;
            line.segment.end = curr_;

            lines[line_num] = line;
            line_num++;
        }
        last_char = ch;
    }
    for(int i = 0; i < 1; i++)
        printLineType(lines[i], f);
    
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

