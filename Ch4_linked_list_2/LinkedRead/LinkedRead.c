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

	while(1){
		printf("input data : ");
		scanf("%d", &readData);
		if (readData < 1) break;

		// newNode
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		// head, tail
		if (head == NULL){
			head = newNode;
		}
		else {
			tail->next = newNode;
		}
		tail = newNode;
	}
	printf("\n");

	// print all
	if (head == NULL){
		printf("No data\n");
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

	// free all
	if (head == NULL){
		return 0;
	}
	else {
		Node* delNode = head;
		Node* delNextNode = head->next;
		printf("Delete %d\n", delNode->data);
		free(delNode);

		// sliding
		while (delNextNode != NULL){
			delNode = delNextNode;
			delNextNode = delNextNode->next;
			printf("Delete %d\n", delNode->data);
			free(delNode);
		}
	}
	return 0;
}