#include "../include/BinarySearchTree.h"
#include "../include/BinaryTree.h"
#include "../include/AVLRebalance.h"
#include <stdio.h>
#include <stdlib.h>

void BSTMakeAndInit(Tree** root){
	*root = NULL;
}

BSTData BSTGetData(Tree* bst){
	return GetData(bst);
}

void BSTInsert(Tree** root, BSTData data){
	Tree* pNode = NULL; // parent node
	Tree* cNode = *root; // current node
	Tree* nNode = NULL; // new node

	while (cNode != NULL){
		if (data == GetData(*root)){
			return; // it doesn't allow duplicated key value
		}
		pNode = cNode;
		if (GetData(cNode) > data){
			cNode = GetLeftSubTree(cNode);
		}
		else {
			cNode = GetRightSubTree(cNode);
		}
	}

	nNode = MakeBTree();
	SetData(nNode, data);

	if (pNode != NULL){
		if (data < GetData(pNode)){
			MakeLeftSubTree(pNode, nNode);
		}
		else {
			MakeRightSubTree(pNode, nNode);
		}
	}
	else {
		*root = nNode;
	}
	*root = Rebalance(root);
}

Tree* BSTSearch(Tree* bst, BSTData target){
	Tree* cNode = bst;
	BSTData cd;
	while (cNode != NULL){
		cd = GetData(cNode);
		if (cd == target){
			return cNode;
		}
		else if (target < cd){
			cNode = GetLeftSubTree(cNode);
		}
		else {
			cNode = GetRightSubTree(cNode);
		}
	}
	return NULL;
}

Tree* BSTRemove(Tree** root, BSTData target){
	Tree* vRoot = MakeBTree(); // virtual node
	Tree* pNode = vRoot;
	Tree* cNode = *root;
	Tree* dNode;

	ChangeRightSubTree(vRoot, *root);

	while (cNode != NULL && GetData(cNode) != target){
		pNode = cNode;
		if (target < GetData(cNode)){
			cNode = GetLeftSubTree(cNode);
		}
		else {
			cNode = GetRightSubTree(cNode);
		}
	}

	if (cNode == NULL){ // no target 
		return NULL;
	}

	dNode = cNode;

	// CASE 1: dNode is terminal node
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL){
		if (GetLeftSubTree(pNode) == dNode){
			RemoveLeftSubTree(pNode);
		}
		else {
			RemoveRightSubTree(pNode);
		}
	}
	
	// CASE 2: dNode has only one child node
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL){
		Tree* dcNode;
		if (GetLeftSubTree(dNode) != NULL) dcNode = GetLeftSubTree(dNode);
		else dcNode = GetRightSubTree(dNode);

		if (GetLeftSubTree(pNode) == dNode) ChangeLeftSubTree(pNode, dcNode);
		else ChangeRightSubTree(pNode, dcNode);
	}

	// CASE 3: dNode has both two child nodes
	else {
		Tree* mNode = GetRightSubTree(dNode);
		Tree* mpNode = dNode;
		BSTData delData;

		while (GetLeftSubTree(mNode) != NULL){
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}

		// Replace dNode data with the data of mNode
		delData = GetData(dNode);
		SetData(dNode, GetData(mNode));

		if (GetLeftSubTree(mpNode) == mNode) ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		else ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

		dNode = mNode;
		SetData(dNode, delData);
	}

	if (GetRightSubTree(vRoot) != *root){ // dNode == *root
		*root = GetRightSubTree(vRoot); // NULL
	}
	free(vRoot);
	*root = Rebalance(root);
	return dNode;
}

void ShowIntData(int data){
	printf("%d ", data);
}

void BSTShowAll(Tree* bst){
	PreorderTraverse(bst, ShowIntData);
	printf("\n");
}