#include "../include/Table.h"
#include <stdio.h>
void TBLInit(Table* table, HashFunc hf){
	table->hf = hf;
	for (int i = 0; i < MAX_TBL; i++){
		LInit(&(table->tbl[i]));
	}
}

void TBLInsert(Table* table, Key key, Value val){
	int hashVal = table->hf(key);
	Slot ns = {key, val};

	if (TBLSearch(table, key) != NULL){ // collision
		printf("Collision happened\n");
		return;
	}
	else {
		LInsert(&(table->tbl[hashVal]), &ns);
	}
}

Value TBLDelete(Table* table, Key key){
	int hashVal = table->hf(key);
	Slot* cSlot;

	if (LFirst(&(table->tbl[hashVal]), &cSlot)){
		if (cSlot->key == key){
			LRemove(&(table->tbl[hashVal]));
			return cSlot->val;
		}
		else {
			while (LNext(&(table->tbl[hashVal]), &cSlot)){
				if (cSlot->key == key){
					LRemove(&(table->tbl[hashVal]));
					return cSlot->val;
				}
			}
		}
	}
	return NULL;
}

Value TBLSearch(Table* table, Key key){
	int hashVal = table->hf(key);
	Slot* cSlot;
	if (LFirst(&(table->tbl[hashVal]), &cSlot)){
		if (cSlot->key == key){
			return cSlot->val;
		}
		else {
			while (LNext(&(table->tbl[hashVal]), &cSlot)){
				if (cSlot->key == key){
					return cSlot->val;
				}
			}
		}
	}
	return NULL;
}

