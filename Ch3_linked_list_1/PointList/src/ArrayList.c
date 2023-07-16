#include "../include/ArrayList.h"
#include <stdio.h>
void ListInit(List* plist){
	plist->numOfData = 0;
	plist->curPos = -1;
}

void LInsert(List* plist, LData data){
	if (plist->numOfData == LIST_LEN){
		printf("CANNOT PUT IN MORE DATA\n");
		return;
	}
	plist->arr[plist->numOfData] = data;
	plist->numOfData += 1;
}

int LFirst(List* plist, LData* pdata){
	if (plist->numOfData == 0){
		return FALSE;
	}
	plist->curPos = 0;
	*pdata = plist->arr[0];
	return TRUE;
}

int LNext(List* plist, LData* pdata){
	if ((plist->curPos+1) >= plist->numOfData){
		return FALSE;
	}
	plist->curPos += 1;
	*pdata = plist->arr[plist->curPos];
	return TRUE;
}

LData LRemove(List* plist){
	LData rm_data = plist->arr[plist->curPos];
	for (int i = plist->curPos; i < plist->numOfData; i++){
		plist->arr[i] = plist->arr[i+1];
	}
	plist->numOfData -= 1;
	plist->curPos -= 1;
	return rm_data;
}

int LCount(List* plist){
	return plist->numOfData;
}