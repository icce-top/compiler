#ifndef STACK_MACHINE_H
#define STACK_MACHINE_H

#include "stdafx.h"
#include "list.h"

/////////////////////////////////////
// instructions
enum Stack_Instr_Kind_t{
	STACK_INSTR_PUSH,
	STACK_INSTR_LOAD,
	STACK_INSTR_STORE,
	STACK_INSTR_ADD,
	STACK_INSTR_MINUS,
	STACK_INSTR_TIMES,
	STACK_INSTR_DIV,
	STACK_INSTR_AND,
	STACK_INSTR_OR,
	STACK_INSTR_PRINTI,
	STACK_INSTR_PRINTB
};

typedef struct STACK_Instr_t{
	enum Stack_Instr_Kind_t kind;
}*Stack_Instr_t;;
void Stack_Instr_print(Stack_Instr_t);

// push n
typedef struct STACK_Instr_Push{
	enum Stack_Instr_Kind_t kind;
	int n;
}*Stack_Instr_Push;;
Stack_Instr_t Stack_Instr_Push_new(int n);

// load x
typedef struct STACK_Instr_Load{
	enum Stack_Instr_Kind_t kind;
	char *x;
}*Stack_Instr_Load;;
Stack_Instr_t Stack_Instr_Load_new(char *);

// store x
typedef struct STACK_Instr_Store{
	enum Stack_Instr_Kind_t kind;
	char *x;
}*Stack_Instr_Store;;
Stack_Instr_t Stack_Instr_Store_new(char *);

// add
typedef struct STACK_Instr_Add{
	enum Stack_Instr_Kind_t kind;
}*Stack_Instr_Add;;
Stack_Instr_t Stack_Instr_Add_new();

// minus
typedef struct STACK_Instr_Minus{
	enum Stack_Instr_Kind_t kind;
}*Stack_Instr_Minus;;
Stack_Instr_t Stack_Instr_Minus_new();

// times
typedef struct STACK_Instr_Times{
	enum Stack_Instr_Kind_t kind;
}*Stack_Instr_Times;;
Stack_Instr_t Stack_Instr_Times_new();

// divide
typedef struct STACK_Instr_Divide{
	enum Stack_Instr_Kind_t kind;
}*Stack_Instr_Divide;;
Stack_Instr_t Stack_Instr_Divide_new();

// and
typedef struct STACK_Instr_And{
	enum Stack_Instr_Kind_t kind;
}*Stack_Instr_And;;
Stack_Instr_t Stack_Instr_And_new();

// or
typedef struct STACK_Instr_Or{
	enum Stack_Instr_Kind_t kind;
}*Stack_Instr_Or;;
Stack_Instr_t Stack_Instr_Or_new();

// printi
typedef struct STACK_Instr_Printi{
	enum Stack_Instr_Kind_t kind;
}*Stack_Instr_Printi;;
Stack_Instr_t Stack_Instr_Printi_new();

// printb
typedef struct STACK_Instr_Printb{
	enum Stack_Instr_Kind_t kind;
}*Stack_Instr_Printb;;
Stack_Instr_t Stack_Instr_Printb_new();

/////////////////////////////////////
// prog
typedef struct STACK_Prog_t{
	List_t ids;  // List_t<char *>
	List_t instrs;   // List_t<Stm_t>
}*Stack_Prog_t;;
Stack_Prog_t Stack_Prog_new(List_t, List_t);
void Stack_Prog_print(Stack_Prog_t);

#endif