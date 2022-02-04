#ifndef PARSE_H
#define PARSE_H

#include <stdio.h>
#include <stdbool.h>
#include "common.h"
//#include "lex.h"

void expr();
void eval();
void term();
void missingOpError();

void term(){
	if(nextToken == IDENT || nextToken == INT_LIT){
		lex();
	}
	else if(nextToken == LEFT_PAREN){
		lex();
		expr();
		if(nextToken == RIGHT_PAREN){
			lex();
		}
		else{
			printf("Error - Line %d - Mismatched Parenthesis\n", lineno);
			has_errors++;
		}
	}
}


void expr(){
	term();
	while(nextToken == ADD_OP || nextToken == SUB_OP || nextToken == MULT_OP || nextToken == DIV_OP){
		lex();
		term();
	}
}

void eval(){
	//printf("In Eval\n");
	if(priorToken == RIGHT_PAREN && nextToken == LEFT_PAREN){ missingOpError(); has_errors++;}
	else if((priorToken == IDENT || priorToken == INT_LIT)&&(nextToken == IDENT || nextToken == INT_LIT)){  missingOpError(); has_errors++;	}
	else if((priorToken == IDENT || priorToken == INT_LIT)&&(nextToken == LEFT_PAREN)){missingOpError(); has_errors++;}
	else if((priorToken == RIGHT_PAREN)&&(nextToken == IDENT || nextToken == INT_LIT)){ missingOpError(); has_errors++;	}
	else if((priorToken == ASSIGN_OP && nextToken == SEMICOLON)){printf("Error - Line %d - Dangling assignment operator\n", lineno); has_errors++;}
	else if(nextToken == BEGIN_PROG){has_begun = true;	}
	else if(nextToken == END_PROG){has_ended = true;}
	
}


void missingOpError(){
	printf("Error - Line %d - Missing operator\n", lineno);
}

#endif
