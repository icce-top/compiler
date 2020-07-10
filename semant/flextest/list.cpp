#include <stdlib.h>
#include "list.h"

List_t List_new(void *data, List_t tail)
{
	List_t p = (List_t)malloc(sizeof (*p));
	p->data = data;
	p->next = tail;
	return p;
}
