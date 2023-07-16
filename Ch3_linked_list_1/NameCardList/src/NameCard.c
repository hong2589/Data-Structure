#include "../include/NameCard.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

NameCard* MakeNameCard(char* name, char* phone){
	NameCard* pcard = (NameCard*)malloc(sizeof(NameCard));
	strcpy(pcard->name, name);
	strcpy(pcard->phone, phone);
	return pcard;
}

void ShowNameCardInfo(NameCard* pcard){
	printf("[%s, %s]\n", pcard->name, pcard->phone);
}

int NameComp(NameCard* pcard1, NameCard* pcard2){
	int comp = strcmp(pcard1->name, pcard2->name);
	return comp;
}

void ChangePhoneNum(NameCard* pcard, char* phone){
	strcpy(pcard->phone, phone);
}

