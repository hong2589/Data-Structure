#include "../include/BinaryTree.h"
#include <stdio.h>

Tree* RotateLL(Tree* bst){
	Tree* pNode;
	Tree* cNode;

	pNode = bst;
	cNode = GetLeftSubTree(pNode);

	ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
	ChangeRightSubTree(cNode, pNode);

	return cNode;
}

Tree* RotateRR(Tree* bst){
	Tree* pNode;
	Tree* cNode;

	pNode = bst;
	cNode = GetRightSubTree(pNode);

	ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
	ChangeLeftSubTree(cNode, pNode);

	return cNode;
}

Tree* RotateLR(Tree* bst){
	Tree* pNode;
	Tree* cNode;

	pNode = bst;
	cNode = GetLeftSubTree(pNode);

	ChangeLeftSubTree(pNode, RotateRR(cNode));
	return RotateLL(pNode);
}

Tree* RotateRL(Tree* bst){
	Tree* pNode;
	Tree* cNode;

	pNode = bst;
	cNode = GetRightSubTree(pNode);

	ChangeRightSubTree(pNode, RotateLL(cNode));
	return RotateRR(pNode);
}

int GetHeight(Tree* bst){
	int leftH;
	int rightH;

	if (bst == NULL){
		return 0;
	}

	leftH = GetHeight(GetLeftSubTree(bst));
	rightH = GetHeight(GetRightSubTree(bst));

	if (leftH > rightH){
		return leftH + 1;
	}
	else {
		return rightH + 1;
	}
}

int GetHeightDiff(Tree* bst){
	int leftH;
	int rightH;

	if (bst == NULL){
		return 0;
	}

	leftH = GetHeight(GetLeftSubTree(bst));
	rightH = GetHeight(GetRightSubTree(bst));

	return leftH - rightH;
}

Tree* Rebalance(Tree** pRoot){
	int bf = GetHeightDiff(*pRoot);

	if (bf >= 2){
		if (GetHeightDiff(GetLeftSubTree(*pRoot)) > 0) 
			*pRoot = RotateLL(*pRoot); // LL
		else 
			*pRoot = RotateLR(*pRoot); // LR
	}
	else if (bf <= -2){
		if (GetHeightDiff(GetRightSubTree(*pRoot)) < 0)
			*pRoot = RotateRR(*pRoot); // RR
		else
			*pRoot = RotateRL(*pRoot); // RL
	}
	return *pRoot;
}