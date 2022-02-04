#ifndef TABLE_H
#define TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include <math.h>

/*****************************
 My table has O(1) lookup
******************************/

int categories = 6;

char tab[6][10][20] = {
	{"<LETTER>","<DIGIT>","<UNKNOWN>"},
	{"<INT_LIT>","<IDENT>"},
	{"<COMMENT>","<WHITESPACE>","<NEWLINE>"},
	{"<UNDERSCORE>","<SEMICOLON>"},
	{"<ASSIGN_OP>","<ADD_OP>","<SUB_OP>","<MULT_OP>","<DIV_OP>","<LEFT_PAREN>","<RIGHT_PAREN>"},
	{"<BEGIN_PROG>","<END_PROG>"}
};

int lens[6] = {3,2,3,2,7,2};


void printNode(struct node* n);

void node_push(int op, char* ident, int loc){
	struct node* chain_link = (struct node*) malloc(sizeof(struct node));
	chain_link->op_code = op;
	strcpy(chain_link->lexeme, ident);
	chain_link->loc = loc;
	strcpy(chain_link->pos, tab[((op - (op%10))/10)-1][op%10]);

	chain_link->next = head;
	head = chain_link;
}

void printTable(){
	printf("Position\t\tIdentifier\t\tCode\t\tP.O.S\n");
	
	struct node* temp = head;
	while(temp != NULL){
		printf("%d\t\t\t%s\t\t\t%d\t\t%s\n", temp->loc, temp->lexeme,temp->op_code, temp->pos);
		temp = temp->next;
	}
}

void printSymbol(int op, char* actual){
	int index_x = op%10;
	int index_y = ((op - (op%10))/10)-1;
	int limit = lens[index_y];
	if(index_x >= 0 && index_x < limit){
		printf("%s\t%s\t%d\n", tab[index_y][index_x], actual, op);
	}
}

void printNode(struct node* n){
	printf("%d\t\t\t%s\t\t%d\t\t\t%s\n", n->loc, n->lexeme,n->op_code, n->pos);
}
#endif
