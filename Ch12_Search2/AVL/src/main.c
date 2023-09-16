#include <stdio.h>
#include "../include/BinarySearchTree.h"
int main(){
	Tree* avlRoot;
	
	// Insert
	// 1. Check RR
	BSTMakeAndInit(&avlRoot);
	printf("==== 1. Check RR =====\n");
	for (int k = 1; k <= 9; k++){
		BSTInsert(&avlRoot, k);
	}
	printf("Root Node : %d\n", GetData(avlRoot));
	BSTShowAll(avlRoot);
	printf("\n");

	// 2. Check LL
	BSTMakeAndInit(&avlRoot);
	printf("===== 2. Check LL =====\n");
	for (int k = 9; k >= 1; k--){
		BSTInsert(&avlRoot, k);
	}
	printf("Root Node : %d\n", GetData(avlRoot));
	BSTShowAll(avlRoot);
	printf("\n");

	// 3. Check LR
	BSTMakeAndInit(&avlRoot);
	printf("===== 3. Check LR =====\n");
	BSTInsert(&avlRoot, 3);
	BSTInsert(&avlRoot, 1);
	BSTInsert(&avlRoot, 2);
	printf("Root Node : %d\n", GetData(avlRoot));
	BSTShowAll(avlRoot);
	printf("\n");

	// 4. Check RL
	BSTMakeAndInit(&avlRoot);
	printf("===== 4. Check RL =====\n");
	BSTInsert(&avlRoot, 1);
	BSTInsert(&avlRoot, 3);
	BSTInsert(&avlRoot, 2);
	printf("Root Node : %d\n", GetData(avlRoot));
	BSTShowAll(avlRoot);
	printf("\n");

	return 0;
}