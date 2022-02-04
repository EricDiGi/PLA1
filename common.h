#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

enum Token {
	LETTER=10, DIGIT, UNKNOWN, 
	INT_LIT = 20, IDENT, 
	COMMENT = 30, WHITESPACE, NEWLINE, 
	UNDERSCORE = 40, SEMICOLON, 
	ASSIGN_OP = 50, ADD_OP, SUB_OP, MULT_OP, DIV_OP, LEFT_PAREN, RIGHT_PAREN,
	BEGIN_PROG = 60, END_PROG
};


struct node{
	int op_code;
	char lexeme[256];
	char pos[20];
	int loc;
	struct node* next;
};

int parse[256];
int parse_iter = 0;

char nextChar;
int lexLen;
int token;
int nextToken;
int priorToken;
int lineno = 0;


int has_errors = 0;
bool doPrint = false;

bool has_begun = false;
bool has_ended = false;

struct node* head = NULL;

#endif

