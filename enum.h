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
    Segment seg;
    int id;
} Line;

typedef struct{
    Segment seg;
    int depth;
    Region* parent = nullptr;
    Region* child = nullptr;
} Region;

// Parts-of-speech
typedef struct{
    Segment seg;
    //nodeEnum type;
} Comment;

void initSymbolTable(){}

#endif