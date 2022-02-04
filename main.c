#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#include "common.h"
#include "lex.h"
#include "parse.h"
#include "table.h"


void printParse();


int main(int argc, char** argv){
	
	printf(">>>\tCompiling...\n\n");
	
	if((in_fp = fopen(argv[1], "r")) == NULL){
		printf("Error cannot open %s", argv[1]);
	}
	else{
		getChar();
		expr();
		do{
			lex();
			expr();
		} while (nextToken != EOF);		
		if(!has_begun){printf("Error - Program has no beginning\n");}
		if(!has_ended){printf("Error - Program has no end\n");}
		
	}
	if(!has_errors){
		printf(">>>\tSUCCESS!\n\n>>>\tSYMBOL TABLE\n\n>>>\n");
		printTable();
	}

	return 0;
}

void printParse(){
	int i;
	for(i = 0; i < parse_iter; i++){
		printf("Token: %d\n", parse[i]);
	}
}
