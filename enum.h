#ifndef ENUM_H
#define ENUM_H

#include <stdio.h>
#include <stdlib.h>


//Other stuctures
typedef struct{
    int begin;
    int end;
} Segment;

typedef struct{
    union Segment seg;
    int id;
} Line;

typedef struct{
    union Segment seg;
    int depth;
    union Region* parent = nullptr;
    union Region* child = nullptr;
} Region;

// Parts-of-speech
typedef struct{
    union Segment seg;
    //nodeEnum type;
} Comment;

void initSymbolTable(){}

#endif