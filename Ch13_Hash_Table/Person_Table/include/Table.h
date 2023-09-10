#ifndef __TABLE_H__
#define __TABLE_H__

#include "Slot.h"

#define MAX_TBL 100

typedef int (*HashFunc)(Key k);

typedef struct _table {
	Slot tbl[MAX_TBL];
	HashFunc hf;
} Table;

void Init(Table* table, HashFunc hf);
void Insert(Table* table, Key key, Value val);
Value Delete(Table* table, Key key);
Value Search(Table* table, Key key);

#endif

