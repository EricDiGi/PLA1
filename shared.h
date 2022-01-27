#ifndef SHARED_H
#define SHARED_H

#include <stdio.h>


enum Node {nameNode=100, Op, formula, eol, identifier, comment, funcblock};
enum pos {assign=200, add, subt, mult, divi, under};
enum pos_struct {paren=300, brace, brack};
char pos_[6] = {'=','+','-','*','/','_'};
char pos_struct_[3][2] = {{'(',')'},{'{','}'},{'[',']'}};
char prioritized_delim[4] = {'\n','~',';','=', 0};
typedef struct String{
	char* str;
	int length;
}string;

typedef struct someNode {
	string str;
	enum Node nodetype;
	bool isValid;
	
}node;

bool has_begun = false;

node nodeList[150];
int nodeListSize = 0;

#endif




