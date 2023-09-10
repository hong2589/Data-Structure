#include <stdio.h>
#include <stdlib.h>
#include "../include/Person.h"
#include "../include/Table.h"

int MyHashFunc(int k){
	return k % 100;
}

int main(){
	Table myTbl;
	Person* np;
	Person* sp;
	Person* rp;

	TBLInit(&myTbl, MyHashFunc);

	// 1. Insert
	printf("1. Insert\n");
	np = MakePersonData(900254, "Lee", "Seoul");
	TBLInsert(&myTbl, GetSSN(np), np);
	np = MakePersonData(900139, "Kim", "Jeju");
	TBLInsert(&myTbl, GetSSN(np), np);
	np = MakePersonData(900827, "Han", "Kangwon");
	TBLInsert(&myTbl, GetSSN(np), np);

	// 2. Search
	printf("2. Search\n");
	sp = TBLSearch(&myTbl, 900254);
	if (sp != NULL) ShowPersonInfo(sp);
	sp = TBLSearch(&myTbl, 900139);
	if (sp != NULL) ShowPersonInfo(sp);
	sp = TBLSearch(&myTbl, 900827);
	if (sp != NULL) ShowPersonInfo(sp);

	// 3. Remove
	printf("3. Remove\n");
	rp = TBLDelete(&myTbl, 900254);
	if (rp != NULL) free(rp);
	rp = TBLDelete(&myTbl, 900139);
	if (rp != NULL) free(rp);
	rp = TBLDelete(&myTbl, 900827);
	if (rp != NULL) free(rp);

	return 0;
}