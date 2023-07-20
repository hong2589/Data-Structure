#include "../include/CLinkedList.h"
#include "../include/Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Employee* WhoIsDuty(List* plist, char* name, int day){
	Employee* emp;
	Employee* target;
	LFirst(plist, &emp);
	if (!strcmp(emp->name, name)){
		target = emp;
	}
	else {
		for (int i = 0; i < LCount(plist)-1; i++){
			LNext(plist, &emp);
			if (!strcmp(emp->name, name)){
				target = emp;
			}
		}
	}
	for (int i = 0; i < day; i++){
		LNext(plist, &target);
	}
	return target;
}

int main(){
	List list;
	Employee* emp;
	ListInit(&list);

	// Insert to tail
	emp = (Employee*)malloc(sizeof(Employee));
	strcpy(emp->name, "Kim");
	emp->id = 1111;
	LInsert(&list, emp);
	emp = (Employee*)malloc(sizeof(Employee));
	strcpy(emp->name, "Hong");
	emp->id = 2222;
	LInsert(&list, emp);
	emp = (Employee*)malloc(sizeof(Employee));
	strcpy(emp->name, "Jeong");
	emp->id = 3333;
	LInsert(&list, emp);
	emp = (Employee*)malloc(sizeof(Employee));
	strcpy(emp->name, "Choi");
	emp->id = 4444;
	LInsert(&list, emp);

	// Show all the info
	LFirst(&list, &emp);
	ShowEmployeeInfo(emp);
	for (int i = 0; i < 3; i++){
		LNext(&list, &emp);
		ShowEmployeeInfo(emp);
	}

	// Print who is duty
	emp = WhoIsDuty(&list, "Kim", 2);
	ShowEmployeeInfo(emp);
	emp = WhoIsDuty(&list, "Kim", 3);
	ShowEmployeeInfo(emp);
	emp = WhoIsDuty(&list, "Kim", 4);
	ShowEmployeeInfo(emp);

	// Remove memory allocation
	int numNode = LCount(&list);
	LFirst(&list, &emp); 
	LRemove(&list);
	for (int i = 0; i < numNode-1; i++){
		LNext(&list, &emp);
		LRemove(&list);
	}
	free(emp);
	return 0;
	
}
