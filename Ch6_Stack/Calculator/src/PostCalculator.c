#include "../include/ListBaseStack.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int EvalRPNExp(char exp[]){
	Stack stack;
	int expLen = strlen(exp);
	char tok, op1, op2;
	for (int i = 0; i < expLen; i++){
		tok = exp[i];
		if (isdigit(tok)){
			Push(&stack, tok-'0');
		}
		else {
			op2 = Pop(&stack);
			op1 = Pop(&stack);
			switch (tok){
				case '+':
					Push(&stack, op1 + op2);
					break;
				case '-':
					Push(&stack, op1 - op2);
					break;
				case '*':
					Push(&stack, op1 * op2);
					break;
				case '/':
					Push(&stack, op1 / op2);
					break;
			}
		}
	}
	return Pop(&stack);
}