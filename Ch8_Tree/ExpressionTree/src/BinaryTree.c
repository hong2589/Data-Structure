#include "../include/BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>

Tree* MakeTree(void){
	Tree* newTree = (Tree*)malloc(sizeof(Tree));
	newTree->left = NULL;
	newTree->right = NULL;
	return newTree;
}

BTData GetData(Tree* Tree){
	return Tree->data;
}

void SetData(Tree* Tree, BTData data){
	Tree->data = data;
}

Tree* GetLeftSubTree(Tree* Tree){
	return Tree->left;
}

Tree* GetRightSubTree(Tree* Tree){
	return Tree->right;
}

void MakeLeftSubTree(Tree* main, Tree* sub){
	if (main->left != NULL){
		free(main->left);
	}
	main->left = sub;
}

void MakeRightSubTree(Tree* main, Tree* sub){
	if (main->right != NULL){
		free(main->right);
	}
	main->right = sub;
}

void DeleteTree(Tree* Tree){
	// Use post-traverse
	if (Tree == NULL) return;
	DeleteTree(Tree->left);
	DeleteTree(Tree->right);
	free(Tree);
}

void InorderTraverse(Tree* Tree, VisitFuncPtr action){
	if (Tree == NULL) return;
	if (Tree->left != NULL) printf("( ");
	InorderTraverse(Tree->left, action);
	action(Tree->data);
	InorderTraverse(Tree->right, action);
	if (Tree->left != NULL) printf(") ");
}

void PreorderTraverse(Tree* Tree, VisitFuncPtr action){
	if (Tree == NULL) return;
	action(Tree->data);
	PreorderTraverse(Tree->left, action);
	PreorderTraverse(Tree->right, action);
}

void PostorderTraverse(Tree* Tree, VisitFuncPtr action){
	if (Tree == NULL) return;
	PostorderTraverse(Tree->left, action);
	PostorderTraverse(Tree->right, action);
	action(Tree->data);
}