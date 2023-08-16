#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

#include "BinaryTree.h"

Tree* MakeExpTree(char exp[]);
int EvaluateExpTree(Tree* expTree);

void ShowPrefixExp(Tree* tree);
void ShowInfixExp(Tree* tree);
void ShowPostfixExp(Tree* tree);

#endif