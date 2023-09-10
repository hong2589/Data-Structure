#include "../include/Person.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int GetSSN(Person* p){
	return p->ssn;
}

void ShowPersonInfo(Person* p){
	printf("SSN : %d\n", p->ssn);
	printf("Name : %s\n", p->name);
	printf("Addr : %s\n", p->addr);
	printf("\n");
}

Person* MakePersonData(int ssn, char* name, char* addr){
	Person* newPer = (Person*)malloc(sizeof(Person));
	newPer->ssn = ssn;
	strcpy(newPer->name, name);
	strcpy(newPer->addr, addr);
	return newPer;
}