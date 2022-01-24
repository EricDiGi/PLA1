#ifndef ENUM_H
#define ENUM_H

#include <stdio.h>
#include <stdlib.h>


typedef enum {Segment, Line, typeConstant, typeId, typeOperator, Comment} nodeEnum;

// Constants
typedef struct{
    nodeEnum type;
    int value;
} constantNodeType;

// Identifiers
typedef struct{
    nodeEnum type;
    char name[50];
} idNodeType;

// Operators
typedef struct{
    nodeEnum type;
    int operator;
    int numOps;
    union nodeTypeTag *op[1];
} operandNodeType;


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
    nodeEnum type;
} Comment;

void initSymbolTable

#endif