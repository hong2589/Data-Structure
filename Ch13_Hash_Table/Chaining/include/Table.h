#ifndef __TABLE_H__
#define __TABLE_H__

#include "Slot.h"
#include "LinkedList.h"

#define MAX_TBL 100

typedef int (*HashFunc)(Key key);

typedef struct _table {
	List tbl[MAX_TBL];
	HashFunc hf;
} Table;

void TBLInit(Table* table, HashFunc hf);
void TBLInsert(Table* table, Key key, Value val);
Value TBLDelete(Table* table, Key key);
Value TBLSearch(Table* table, Key key);

#endif