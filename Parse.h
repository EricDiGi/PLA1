#ifndef PARSE_H
#define PARSE_H

bool isComment(char* string){
    return string[0] == '~';
}

bool parse(char* string){
    if(isComment(string)){return true;}
    return false;
}

#endif