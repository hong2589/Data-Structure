#include "../include/BinaryTree.h"
#include <stdio.h>
void ShowIntData(int data){
	printf("%d ", data);
}

int main(void){
	Node* A = MakeNode();
	Node* B = MakeNode();
	Node* C = MakeNode();
	Node* D = MakeNode();
	Node* E = MakeNode();
	Node* F = MakeNode();

	SetData(A, 1);
	SetData(B, 2);
	SetData(C, 3);
	SetData(D, 4);
	SetData(E, 5);
	SetData(F, 6);

	MakeLeftSubTree(A, B);
	MakeRightSubTree(A, C);
	MakeLeftSubTree(B, D);
	MakeRightSubTree(B, E);
	MakeRightSubTree(C, F);

	PreorderTraverse(A, ShowIntData); printf("\n");
	InorderTraverse(A, ShowIntData); printf("\n");
	PostorderTraverse(A, ShowIntData); printf("\n");
	return 0;
}