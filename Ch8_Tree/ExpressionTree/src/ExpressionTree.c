#include "../include/Expressiontree.h"
#include "../include/ListBaseStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

Tree* MakeExpTree(char exp[]){
	Stack stack;
	char tok;
	Tree* newTree;
	int expLen = strlen(exp);
	
	Init(&stack);
	for (int i = 0; i < expLen; i++){
		tok = exp[i];
		newTree = MakeTree();
		if (isdigit(tok)){
			SetData(newTree, tok-'0');
		}
		else {
			MakeRightSubTree(newTree, Pop(&stack));
			MakeLeftSubTree(newTree, Pop(&stack));
			SetData(newTree, tok);
		}
		Push(&stack, newTree);
	}
	return Pop(&stack);
}

int EvaluateExpTree(Tree* expTree){
	int op1, op2;
	if (GetLeftSubTree(expTree) == NULL && GetRightSubTree(expTree) == NULL){
		// terminal node
		return GetData(expTree);
	}
	op1 = EvaluateExpTree(GetLeftSubTree(expTree));
	op2 = EvaluateExpTree(GetRightSubTree(expTree));
	switch (GetData(expTree)){
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '*':
			return op1 * op2;
		case '/':
			return op1 / op2;
	}
	return 0;
}

void ShowNodeData(int data){
	if (data >= 0 && data <= 9){
		printf("%d ", data);
	}
	else {
		printf("%c ", data);
	}
}

void ShowPrefixExp(Tree* tree){
	PreorderTraverse(tree, ShowNodeData);
}

void ShowInfixExp(Tree* tree){
	InorderTraverse(tree, ShowNodeData);
}

void ShowPostfixExp(Tree* tree){
	PostorderTraverse(tree, ShowNodeData);
}

