#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <stdlib.h>

#include "enum.h"

bool next_region(int begin, int end, FILE* fp){
    int next_begin;
    int next_end;
    for(int i = begin; i < end; i++){
        //Do some decision for beginning of next section
    }
    for(int i = end; i > begin; i++){
        // Do some decision for end of next section
    }
    //If lower branch resolves as true (safe) then check this section
    // results to be true or false(unsafe)
    if( next_region(next_begin, next_end,string_content) ){

    }
    return false;
}

#endif