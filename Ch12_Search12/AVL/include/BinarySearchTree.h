#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include "BinaryTree.h"

typedef BTData BSTData;

void BSTMakeAndInit(Tree** root);
BSTData BSTGetData(Tree* bst);
void BSTInsert(Tree** root, BSTData data);
Tree* BSTSearch(Tree* bst, BSTData target);
Tree* BSTRemove(Tree** root, BSTData target);
void BSTShowAll(Tree* bst);

#endif