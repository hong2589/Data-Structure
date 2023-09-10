#include "../include/Table.h"
#include <stdio.h>

void Init(Table* table, HashFunc hf){
	table->hf = hf;
	for (int i = 0; i < MAX_TBL; i++){
		(table->tbl[i]).status = EMPTY;
	}
}

void Insert(Table* table, Key key, Value val){
	int hv = table->hf(key);
	table->tbl[hv].key = key;
	table->tbl[hv].val = val;
	table->tbl[hv].status = INUSE;
}

Value Delete(Table* table, Key key){
	int hv = table->hf(key);
	if (table->tbl[hv].status != INUSE){
		return NULL;
	}
	else {
		table->tbl[hv].status = DELETED;
		return table->tbl[hv].val;
	}
}

Value Search(Table* table, Key key){
	int hv = table->hf(key);
	if (table->tbl[hv].status != INUSE){
		return NULL;
	}
	else {
		return table->tbl[hv].val;
	}
}