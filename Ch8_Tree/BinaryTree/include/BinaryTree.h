#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int Data;

typedef struct _tree {
	Data data;
	struct _tree* left;
	struct _tree* right;
} Tree;

Tree* MakeTree(void);
Data GetData(Tree* node);
void SetData(Tree* node, Data data);

Tree* GetLeftSubTree(Tree* node);
Tree* GetRightSubTree(Tree* node);

void MakeLeftSubTree(Tree* main, Tree* sub);
void MakeRightSubTree(Tree* main, Tree* sub);
void DeleteTree(Tree* node);

// Traverse
typedef void (*VisitFuncPtr)(Data data);
void PreorderTraverse(Tree* node, VisitFuncPtr action);
void InorderTraverse(Tree* node, VisitFuncPtr action);
void PostorderTraverse(Tree* node, VisitFuncPtr action);

#endif