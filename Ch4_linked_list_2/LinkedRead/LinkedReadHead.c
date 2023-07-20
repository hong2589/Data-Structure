#include <stdio.h>
#include <stdlib.h>
typedef struct _node {
	int data;
	struct _node* next;
} Node;

int main(){
	Node* head = NULL;
	Node* tail = NULL;
	Node* cur = NULL;

	Node* newNode = NULL;
	int readData;

	// 1. Input
	while (1){
		printf("Input data : ");
		scanf("%d", &readData);
		if (readData < 1) break;

		// new node
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		if (tail == NULL){
			tail = newNode;
			head = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
	}
	printf("\n");

	// 2. print all
	if (tail == NULL){
		printf("No Data\n");
	}
	else {
		cur = head;
		printf("%d ", cur->data);
		while (cur->next != NULL){
			cur = cur->next;
			printf("%d ", cur->data);
		}
	}
	printf("\n\n");

	// 3. Free all
	if (tail == NULL) return 0;
	else {
		Node* delNode = head;
		Node* delNextNode = head->next;
		printf("Delete %d\n", delNode->data);
		free(delNode);
		while (delNextNode != NULL){
			delNode = delNextNode;
			delNextNode = delNextNode->next;
			printf("Delete %d\n", delNode->data);
			free(delNode);
		}
	}
	return 0;
}