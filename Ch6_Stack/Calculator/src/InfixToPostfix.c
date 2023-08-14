#include "../include/ListBaseStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int GetOpPrec(char op){
	switch(op){
		case '*': case '/':
			return 3;
		case '+': case '-':
			return 2;
		case '(':
			return 1;
	}
	return -1;
}

int WhoPrecOp(char op1, char op2){
	int prec1 = GetOpPrec(op1);
	int prec2 = GetOpPrec(op2);
	if (prec1 > prec2) return 1;
	else if (prec1 < prec2) return -1;
	else return 0;
}

void ConvToRPNExp(char exp[]){
	Stack opStack;
	int expLen = strlen(exp);
	char* convExp = (char*)malloc(expLen+1);
	int idx = 0;
	char tok;
	char popOp;

	// Init
	memset(convExp, 0, expLen+1);
	Init(&opStack);

	// Convert
	for (int i = 0; i < expLen; i++){
		tok = exp[i];
		if (isdigit(tok)){
			convExp[idx++] = tok;
		}
		else {
			if (tok == '('){ // '(' -> just push into opStack
				Push(&opStack, tok);
			}
			else if (tok == ')'){ // ')' -> pop all the operator including '(', copy it into convExp 
				while(1){
					popOp = Pop(&opStack);
					if (popOp == '(') break;
					convExp[idx++] = popOp;
				}
			}
			else if (tok == ' '){
				continue;
			}
			else { // '+', '-', '*', '/' -> Pop if the operator of the opStack precedes tok, push tok into opStack
				while (!IsEmpty(&opStack) && WhoPrecOp(Peek(&opStack), tok) >= 0){
					popOp = Pop(&opStack);
					convExp[idx++] = popOp;
				}
				Push(&opStack, tok);
			}
		}
	}
	// copy the rest of elements of stack
	while (!IsEmpty(&opStack)){
		popOp = Pop(&opStack);
		convExp[idx++] = popOp;
	}
	strcpy(exp, convExp);
	free(convExp);
}

