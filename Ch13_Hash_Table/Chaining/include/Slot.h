#ifndef __SLOT_H__
#define __SLOT_H__
#include "Person.h"

typedef int Key;
typedef Person* Value;

// enum SlotStatus {EMPTY, DELETED, INUSE};


// close addressing -> do not need status variable
typedef struct _slot {
	Key key;
	Value val;
	// enum SlotStatus status;
} Slot;

#endif