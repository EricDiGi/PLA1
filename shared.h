#ifndef SHARED_H
#define SHARED_H

enum Node {nameNode=100, Op, formula, eol, identifier, comment, funcblock};
enum pos {assign=200, add, subt, mult, div, under};
enum pos_struct {paren=300, brace, brack};
char* pos_ = {'=','+','-','*','/','_'};
char** pos_struct_ = {{'(',')'},{'{','}'},{'[',']'}};

typedef struct String{
	char* str;
	int length;
}string;

typedef struct someNode {
	string str;
	enum Node;
	bool isValid;
}node;

bool has_begun = false;

node nodeList[150];
int nodeListSize = 0;

#endif
