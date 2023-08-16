#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int Data;

typedef struct _node {
	Data data;
	struct _node* left;
	struct _node* right;
} Node;

Node* MakeNode(void);
Data GetData(Node* node);
void SetData(Node* node, Data data);

Node* GetLeftSubTree(Node* node);
Node* GetRightSubTree(Node* node);

void MakeLeftSubTree(Node* main, Node* sub);
void MakeRightSubTree(Node* main, Node* sub);
void DeleteTree(Node* node);

// Traverse
typedef void (*VisitFuncPtr)(Data data);
void PreorderTraverse(Node* node, VisitFuncPtr action);
void InorderTraverse(Node* node, VisitFuncPtr action);
void PostorderTraverse(Node* node, VisitFuncPtr action);

#endif