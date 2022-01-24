#ifndef ENUM_H
#define ENUM_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Segment{
    fpos_t begin;
    fpos_t end;
} Segment;

typedef struct Region{
    Segment segment;
    int depth;
} Region;

typedef struct Line{
    Segment segment;
    int number;
} Line;

void initSymbolTable(){}

#endif