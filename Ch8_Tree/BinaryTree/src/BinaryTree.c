#include "../include/BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>

Node* MakeNode(void){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

Data GetData(Node* node){
	return node->data;
}

void SetData(Node* node, Data data){
	node->data = data;
}

Node* GetLeftSubTree(Node* node){
	return node->left;
}

Node* GetRightSubTree(Node* node){
	return node->right;
}

void MakeLeftSubTree(Node* main, Node* sub){
	if (main->left != NULL){
		free(main->left);
	}
	main->left = sub;
}

void MakeRightSubTree(Node* main, Node* sub){
	if (main->right != NULL){
		free(main->right);
	}
	main->right = sub;
}

void DeleteTree(Node* node){
	// Use post-traverse
	if (node == NULL) return;
	DeleteTree(node->left);
	DeleteTree(node->right);
	free(node);
}

void InorderTraverse(Node* node, VisitFuncPtr action){
	if (node == NULL) return;
	InorderTraverse(node->left, action);
	action(node->data);
	InorderTraverse(node->right, action);
}

void PreorderTraverse(Node* node, VisitFuncPtr action){
	if (node == NULL) return;
	action(node->data);
	PreorderTraverse(node->left, action);
	PreorderTraverse(node->right, action);
}

void PostorderTraverse(Node* node, VisitFuncPtr action){
	if (node == NULL) return;
	PostorderTraverse(node->left, action);
	PostorderTraverse(node->right, action);
	action(node->data);
}