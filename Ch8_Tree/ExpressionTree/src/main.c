#include "../include/ExpressionTree.h"
#include <stdio.h>
int main(){
	char exp[] = "12+7*";
	Tree* tree = MakeExpTree(exp);

	// Show Expression
	printf("Prefix exp : ");
	ShowPrefixExp(tree);
	printf("\n");
	printf("Infix exp : ");
	ShowInfixExp(tree);
	printf("\n");
	printf("Postfix exp : ");
	ShowPostfixExp(tree);
	printf("\n");

	// Evaluate
	printf("result : %d\n", EvaluateExpTree(tree));
	return 0;
}