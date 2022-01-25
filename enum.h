#ifndef ENUM_H
#define ENUM_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Region{
    int depth;
} Region;

typedef struct Line{
    int number;
    char* value;
    bool ignore;
} Line;

typedef enum { typeCon, typeId, typeOpr } nodeEnum; 
 
/* constants */ 
typedef struct { 
    nodeEnum type;              /* type of node */ 
    int value;                  /* value of constant */ 
} conNodeType; 
 
/* identifiers */ 
typedef struct { 
    nodeEnum type;              /* type of node */ 
    char name[50];                      /* subscript to ident array */ 
} idNodeType; 
 
/* operators */ 
typedef struct { 
    nodeEnum type;              /* type of node */ 
    int oper;                   /* operator */ 
    int nops;                   /* number of operands */ 
    union nodeTypeTag *op[1];   /* operands (expandable) */ 
} oprNodeType; 
 
typedef union nodeTypeTag { 
    nodeEnum type;              /* type of node */ 
    conNodeType con;            /* constants */ 
    idNodeType id;              /* identifiers */ 
    oprNodeType opr;            /* operators */ 
} nodeType; 

#endif