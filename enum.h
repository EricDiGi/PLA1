#ifndef ENUM_H
#define ENUM_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Segment{
    int begin;
    int end;
} Segment;

typedef struct Region{
    Segment segment;
    int depth;
    Region* parent = nullptr;
    Region* child = nullptr;
} Region;

void initSymbolTable(){}

#endif