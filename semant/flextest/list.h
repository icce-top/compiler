#include "stdafx.h"

typedef struct LIST_t{
	void *data;
	struct LIST_t *next;
} *List_t;

List_t List_new(void *data, List_t tail);
