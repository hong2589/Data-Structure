#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#define TRUE 1
#define FALSE 0

typedef int BTData;

typedef struct _btree {
	BTData data;
	struct _btree* left;
	struct _btree* right;
} BTree;

typedef BTree Tree;

Tree* MakeBTree(void);

// Get & Set Data
BTData GetData(Tree* bt);
void SetData(Tree* bt, BTData data);

// Subtree
Tree* GetLeftSubTree(Tree* bt);
Tree* GetRightSubTree(Tree* bt);
void MakeLeftSubTree(Tree* main, Tree* sub);
void MakeRightSubTree(Tree* main, Tree* sub);

// Traverse
typedef void (*VisitFuncPtr)(BTData data);
void PreorderTraverse(Tree* bt, VisitFuncPtr action);
void InorderTraverse(Tree* bt, VisitFuncPtr action);
void PostorderTraverse(Tree* bt, VisitFuncPtr action);

// FOR BST
Tree* RemoveLeftSubTree(Tree* bt);
Tree* RemoveRightSubTree(Tree* bt);
void ChangeLeftSubTree(Tree* main, Tree* sub);
void ChangeRightSubTree(Tree* main, Tree* sub);

#endif