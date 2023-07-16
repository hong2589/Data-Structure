#include "../include/NameCard.h"
#include "../include/ArrayList.h"
#include <stdio.h>

int main(){
	List list;
	NameCard* pcard;

	ListInit(&list);

	// 1. store 3 NameCard
	printf("1. Init...\n");
	pcard = MakeNameCard("Kim", "010-1111-1111");
	LInsert(&list, pcard);
	pcard = MakeNameCard("Lee", "010-2222-2222");
	LInsert(&list, pcard);
	pcard = MakeNameCard("Hong", "010-3333-3333");
	LInsert(&list, pcard);
	printf("\n");

	// 2. searching with name -> Show info
	printf("2. Searching with name \"Hong\"\n");
	NameCard* comp_pcard = MakeNameCard("Hong", "010-3333-3333");
	if (LFirst(&list, &pcard)){
		if (NameComp(pcard, comp_pcard) == 0){
			ShowNameCardInfo(pcard);
		}
		while (LNext(&list, &pcard)){
			if (NameComp(pcard, comp_pcard) == 0){
				ShowNameCardInfo(pcard);
			}
		}
	}
	printf("\n");

	// 3. Change phone number 
	printf("3. Change phone number\n");
	NameCard* phone_pcard = MakeNameCard("Kim", "010-1111-1111");
	if (LFirst(&list, &pcard)){
		if (NameComp(pcard, phone_pcard) == 0){
			ChangePhoneNum(pcard, "010-4444-4444");
		}
		while (LNext(&list, &pcard)){
			if (NameComp(pcard, phone_pcard) == 0){
				ChangePhoneNum(pcard, "010-4444-4444");
			}
		}
	}
	printf("\n");

	// 4. Remove Namecard
	printf("4. Remove Namecard\n");
	NameCard* rm_pcard = MakeNameCard("Lee", "010-2222-2222");
	if (LFirst(&list, &pcard)){
		if (NameComp(pcard, rm_pcard) == 0){
			LRemove(&list);
		}
		while (LNext(&list, &pcard)){
			if (NameComp(pcard, rm_pcard) == 0){
				LRemove(&list);
			}
		}
	}
	printf("\n");

	// 5. Show all the NameCard info
	printf("5. Show all info\n");
	if (LFirst(&list, &pcard)){
		ShowNameCardInfo(pcard);
		while (LNext(&list, &pcard)){
			ShowNameCardInfo(pcard);
		}
	}
	return 0;
}