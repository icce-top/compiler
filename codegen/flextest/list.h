#ifndef LIST_H
#define LIST_H
#include "stdafx.h"

typedef struct LIST_t{
	void *data;
	struct LIST_t* next;
}*List_t;

List_t List_new(void *data, List_t tail);
List_t List_rev(List_t);

#endif