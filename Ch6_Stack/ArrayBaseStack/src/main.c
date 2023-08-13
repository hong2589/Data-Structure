#include <stdio.h>
#include "../include/ArrayBaseStack.h"
int main(void){
	Stack stack;
	Init(&stack);

	Push(&stack, 1);
	Push(&stack, 2);
	Push(&stack, 3);
	Push(&stack, 4);
	Push(&stack, 5);

	while (!IsEmpty(&stack)){
		printf("%d ", Pop(&stack));
	}
	printf("\n");
	return 0;
}