#include "stdafx.h"
#include "stack-machine.h"

/////////////////////////////////////
// instructions

void Stack_Instr_print(Stack_Instr_t s)
{
	switch (s->kind){
	case STACK_INSTR_PUSH:{
							  Stack_Instr_Push p = (Stack_Instr_Push)s;
							  printf("push %d", p->n);
							  break;
	}
	case STACK_INSTR_LOAD:{
							  Stack_Instr_Load p = (Stack_Instr_Load)s;
							  printf("load %s", p->x);
							  break;
	}
	case STACK_INSTR_STORE:{
							   Stack_Instr_Store p = (Stack_Instr_Store)s;
							   printf("store %s", p->x);
							   break;
	}
	case STACK_INSTR_ADD:{
							 printf("add");
							 break;
	}
	case STACK_INSTR_MINUS:{
							 printf("minus");
							 break;
	}
	case STACK_INSTR_TIMES:{
							   printf("times\n");
							   break;
	}
	case STACK_INSTR_DIV:{
							 printf("div");
							 break;
	}
	case STACK_INSTR_AND:{
							   printf("and");
							   break;
	}
	case STACK_INSTR_OR:{
							 printf("or");
							 break;
	}
	case STACK_INSTR_PRINTI:{
								printf("printi");
								break;
	}
	case STACK_INSTR_PRINTB:{
								printf("printb");
								break;
	}
	default:
		break;
	}
}

// push 
Stack_Instr_t Stack_Instr_Push_new(int n)
{
	Stack_Instr_Push p = (Stack_Instr_Push)malloc(sizeof(*p));
	p->kind = STACK_INSTR_PUSH;
	p->n = n;
	return (Stack_Instr_t)p;
}

// load x
Stack_Instr_t Stack_Instr_Load_new(char *x)
{
	Stack_Instr_Load p = (Stack_Instr_Load)malloc(sizeof(*p));
	p->kind = STACK_INSTR_LOAD;
	p->x = x;
	return (Stack_Instr_t)p;
}

// store x
Stack_Instr_t Stack_Instr_Store_new(char *x)
{
	Stack_Instr_Store p = (Stack_Instr_Store)malloc(sizeof(*p));
	p->kind = STACK_INSTR_STORE;
	p->x = x;
	return (Stack_Instr_t)p;
}

// add
Stack_Instr_t Stack_Instr_Add_new()
{
	Stack_Instr_Add p = (Stack_Instr_Add)malloc(sizeof(*p));
	p->kind = STACK_INSTR_ADD;
	return (Stack_Instr_t)p;
}

// Minus
Stack_Instr_t Stack_Instr_Minus_new()
{
	Stack_Instr_Minus p = (Stack_Instr_Minus)malloc(sizeof(*p));
	p->kind = STACK_INSTR_MINUS;
	return (Stack_Instr_t)p;
}

// times
Stack_Instr_t Stack_Instr_Times_new()
{
	Stack_Instr_Times p = (Stack_Instr_Times)malloc(sizeof(*p));
	p->kind = STACK_INSTR_TIMES;
	return (Stack_Instr_t)p;
}

// divide
Stack_Instr_t Stack_Instr_Divide_new()
{
	Stack_Instr_Divide p = (Stack_Instr_Divide)malloc(sizeof(*p));
	p->kind = STACK_INSTR_DIV;
	return (Stack_Instr_t)p;
}

// and
Stack_Instr_t Stack_Instr_And_new()
{
	Stack_Instr_And p = (Stack_Instr_And)malloc(sizeof(*p));
	p->kind = STACK_INSTR_AND;
	return (Stack_Instr_t)p;
}

// or
Stack_Instr_t Stack_Instr_Or_new()
{
	Stack_Instr_Or p = (Stack_Instr_Or)malloc(sizeof(*p));
	p->kind = STACK_INSTR_OR;
	return (Stack_Instr_t)p;
}


// printi
Stack_Instr_t Stack_Instr_Printi_new()
{
	Stack_Instr_Printi p = (Stack_Instr_Printi)malloc(sizeof(*p));
	p->kind = STACK_INSTR_PRINTI;
	return (Stack_Instr_t)p;
}

// printb
Stack_Instr_t Stack_Instr_Printb_new()
{
	Stack_Instr_Printb p = (Stack_Instr_Printb)malloc(sizeof(*p));
	p->kind = STACK_INSTR_PRINTB;
	return (Stack_Instr_t)p;
}

///////////////////////////////////////
// prog
Stack_Prog_t Stack_Prog_new(List_t ids, List_t instrs)
{
	Stack_Prog_t p = (Stack_Prog_t)malloc(sizeof (*p));
	p->ids = ids;
	p->instrs = instrs;
	return p;
}

void Stack_Prog_print(Stack_Prog_t prog)
{
	List_t ids = prog->ids;
	printf("{\n");
	while (ids){
		char *id = (char *)ids->data;
		printf("  .int %s\n", id);
		ids = ids->next;
	}

	printf("\n");

	List_t instrs = prog->instrs;
	while (instrs){
		Stack_Instr_t s = (Stack_Instr_t)instrs->data;
		printf("  ");
		Stack_Instr_print(s);
		printf("\n");
		instrs = instrs->next;
	}
	printf("}\n");
	return;
}