#include "../include/BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>

Tree* MakeTree(void){
	Tree* newNode = (Tree*)malloc(sizeof(Tree));
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

Data GetData(Tree* node){
	return node->data;
}

void SetData(Tree* node, Data data){
	node->data = data;
}

Tree* GetLeftSubTree(Tree* node){
	return node->left;
}

Tree* GetRightSubTree(Tree* node){
	return node->right;
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

void DeleteTree(Tree* node){
	// Use post-traverse
	if (node == NULL) return;
	DeleteTree(node->left);
	DeleteTree(node->right);
	free(node);
}

void InorderTraverse(Tree* node, VisitFuncPtr action){
	if (node == NULL) return;
	InorderTraverse(node->left, action);
	action(node->data);
	InorderTraverse(node->right, action);
}

void PreorderTraverse(Tree* node, VisitFuncPtr action){
	if (node == NULL) return;
	action(node->data);
	PreorderTraverse(node->left, action);
	PreorderTraverse(node->right, action);
}

void PostorderTraverse(Tree* node, VisitFuncPtr action){
	if (node == NULL) return;
	PostorderTraverse(node->left, action);
	PostorderTraverse(node->right, action);
	action(node->data);
}