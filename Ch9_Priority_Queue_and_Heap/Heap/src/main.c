#include <stdio.h>
#include "../include/Heap.h"
int CompChar(char ch1, char ch2){
	return ch2 - ch1;
}
int main(){
	Heap heap;
	Init(&heap, CompChar);

	Insert(&heap, 'A');
	Insert(&heap, 'B');
	Insert(&heap, 'C');
	printf("delete : %c\n", Delete(&heap));

	Insert(&heap, 'A');
	Insert(&heap, 'B');
	Insert(&heap, 'C');
	printf("delete : %c\n", Delete(&heap));

	while (!IsEmpty(&heap)){
		printf("delete : %c\n", Delete(&heap));
	}
	return 0;

}