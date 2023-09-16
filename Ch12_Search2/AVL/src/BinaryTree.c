#include "../include/BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>

Tree* MakeBTree(void){
	Tree* newTree = (Tree*)malloc(sizeof(Tree));
	newTree->left = NULL;
	newTree->right = NULL;
	return newTree;
}

BTData GetData(Tree* bt){ return bt->data; }

void SetData(Tree* bt, BTData data){ bt->data = data; }

Tree* GetLeftSubTree(Tree* bt){ return bt->left; }

Tree* GetRightSubTree(Tree* bt){ return bt->right; }

void MakeLeftSubTree(Tree* main, Tree* sub){
	if (main->left != NULL) free(main->left);
	main->left = sub;
}

void MakeRightSubTree(Tree* main, Tree* sub){
	if (main->right != NULL) free(main->right);
	main->right = sub;
}

void PreorderTraverse(Tree* bt, VisitFuncPtr action){
	if (bt == NULL) return;
	action(bt->data);
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}

void InorderTraverse(Tree* bt, VisitFuncPtr action){
	if (bt == NULL) return;
	InorderTraverse(bt->left, action);
	action(bt->data);
	InorderTraverse(bt->right, action);
}

void PostorderTraverse(Tree* bt, VisitFuncPtr action){
	if (bt == NULL) return;
	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data);
}

Tree* RemoveLeftSubTree(Tree* bt){
	Tree* delNode;
	if (bt != NULL){
		delNode = bt->left;
		bt->left = NULL;
	}
	return delNode;
}

Tree* RemoveRightSubTree(Tree* bt){
	Tree* delNode;
	if (bt != NULL){
		delNode = bt->right;
		bt->right = NULL;
	}
	return delNode;
}

void ChangeLeftSubTree(Tree* main, Tree* sub){
	main->left = sub;
}

void ChangeRightSubTree(Tree* main, Tree* sub){
	main->right = sub;
}