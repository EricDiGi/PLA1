#ifndef LEX_H
#define LEX_H

#include <stdio.h>
#include "parse.h"
#include "common.h"
#include "table.h"

int charClass;
char lexeme[256];
int lexeme_loc = 0;

FILE *in_fp, *fopen();


void addChar(){
	if( lexLen <= 255){
		lexeme[lexLen++] = nextChar;
		lexeme[lexLen] = 0;
	}
	else{
		printf("Error - lexeme is too long");
	}
}

void getChar(){
	if((nextChar = getc(in_fp)) != EOF){
		if(isalpha(nextChar) || nextChar == '_' || nextChar == '.'){
			charClass = LETTER;
		}
		else if(isdigit(nextChar)){
			charClass = DIGIT;
		}
		else if(nextChar == '~'){
			charClass = COMMENT;
		}
		else if (nextChar == 10){
			charClass = NEWLINE;
		}
		else{ charClass = UNKNOWN; }
	}
	else{
		charClass = EOF;
	}
}

void getNonBlank(int mode){
	switch(mode){
		case COMMENT:
			while(nextChar != 10){ getChar(); }
			break;
		case WHITESPACE:
			while(isspace(nextChar)){ getChar(); }
			break;
	}
}


int lookup(char c){
	switch(c){
		case '~':
			addChar();
			nextToken = COMMENT;
			break;
		case '=':
			addChar();
			nextToken = ASSIGN_OP;
			break;
		case '(':
			addChar();
			nextToken = LEFT_PAREN;
			break;
		case ')':
			addChar();
			nextToken = RIGHT_PAREN;
			break;
		case '+':
			addChar();
			nextToken = ADD_OP;
			break;
		case '-':
			addChar();
			nextToken = SUB_OP;
			break;
		case '*':
			addChar();
			nextToken = MULT_OP;
			break;
		case '/':
			addChar();
			nextToken = DIV_OP;
			break;
		case ';':
			addChar();
			nextToken = SEMICOLON;
			break;
		default:
			addChar();
			nextToken = EOF;
			break;
	}
	return nextToken;
}

int lex(){
	if(nextToken != NEWLINE)
		priorToken = nextToken;
	
	lexLen = 0;
	getNonBlank(WHITESPACE);

	
	switch(charClass){
		case LETTER:
			addChar();
			getChar();
			while(charClass == LETTER || charClass == DIGIT || charClass == UNDERSCORE){
				addChar(); getChar();
			}
			nextToken = IDENT;
			break;
		case DIGIT:
			addChar();
			getChar();
			while(charClass == LETTER || charClass == DIGIT){
				addChar(); getChar();
			}
			nextToken = INT_LIT;
			break;
		case COMMENT:
			getNonBlank(COMMENT);
			break;
		case NEWLINE:
			getNonBlank(WHITESPACE);
			break;
		case UNKNOWN:
			lookup(nextChar);
			getChar();
			break;
		case EOF:
			nextToken = EOF;
			lexeme[0] = 'E';
			lexeme[1] = 'O';
			lexeme[2] = 'F';
			lexeme[3] = 0;
			break;
	}
	
	if(strcmp(lexeme, "begin") == 0){
		nextToken = BEGIN_PROG;
	}
	else if(strcmp(lexeme,"end.") == 0){
		nextToken = END_PROG;
	}
	
	if(charClass == NEWLINE){
		lineno++;
	}
	else{
		parse[parse_iter] = nextToken;
		parse_iter++;
	}
	
	eval();
	
	lexeme_loc++;
	
	if(nextToken == IDENT)
		node_push(nextToken,lexeme, lexeme_loc);
	//printSymbol(nextToken,lexeme);
	//printf("Next token is: %d, Next lexeme is %s, Line Number %d\n", nextToken, lexeme, lineno);
	return nextToken;
}


#endif
