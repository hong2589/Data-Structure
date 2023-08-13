#include "../include/InfixToPostfix.h"
#include "../include/PostCalculator.h"
#include <string.h>
#include <stdlib.h>
int EvalInfixExp(char exp[]){
	int len = strlen(exp);
	char* expcpy = (char*)malloc(len+1);
	int result;
	
	strcpy(expcpy, exp);
	ConvToRPNExp(expcpy);
	result = EvalRPNExp(expcpy);

	free(expcpy);
	return result;
}