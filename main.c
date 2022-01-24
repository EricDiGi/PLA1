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
    fpos_t begin_;
    fpos_t curr_;
    int line_num = 0;
    char last_char;
    while((ch = fgetc(f)) == EOF){
        if((line_num == 0) || (last_char == '\n')){
            printf("%d: begin\n",ftell(f));
            fgetpos(f, &begin_);
        }
        if(ch == '\n'){
            Line line;
            printf("%d:end\n",ftell(f));
            fgetpos(f, &curr_);
            line.number = line_num;
            line.segment.begin = begin_;
            line.segment.end = curr_;

            lines[line_num] = line;
            line_num++;
        }
        last_char = ch;
    }

    printLineType(lines[1], f);
    
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

