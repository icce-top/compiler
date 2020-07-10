#include "stdafx.h"
#include "semant.h"


//////////////////////////////////////
// the symbol table
List_t table = 0;

// lookup an "id" in the symbol table.
// return "type" on success; and -1 for failure
Type_t Table_lookup(char *id)
{
	List_t p = table;
	while (p){
		Dec_t d = (Dec_t)p->data;
		if (strcmp(d->id, id) == 0)
			return d->type;
		p = p->next;
	}
	return (Type_t)(-1);
}

void Table_insert(Dec_t dec)
{

	if (Table_lookup(dec->id) != -1){
		fprintf(stderr, "Error: the variable "
			"\"%s\" has been declared!\n", dec->id);
		return;
	}
	table = List_new(dec, table);
	return;
}

//////////////////////////////////////////
// dec
void check_dec(Dec_t d)
{
	Table_insert(d);
}

void check_decs(List_t decs)
{
	while (decs){
		Dec_t d = (Dec_t)decs->data;
		check_dec(d);
		decs = decs->next;
	}
	return;
}

////////////////////////////////////////
// exp

// Your job:
Type_t check_exp(Exp_t exp)
{
	if (!exp) 
		return (Type_t)(-1);
	Type_t t1, t2,t;
	switch (exp->kind){
	case EXP_INT:
		return TYPE_INT;
	case EXP_ID:
		t=Table_lookup(((Exp_Id)exp)->id);
		if (int(t)==-1)
			printf("id not found\n");
		else
			return t;
	case EXP_TRUE:
		return TYPE_BOOL;
	case EXP_FALSE:
		return TYPE_BOOL;
	case EXP_ADD:
		t1 = check_exp(((Exp_And)exp)->left);
		t2 = check_exp(((Exp_And)exp)->right);
		if (t1 != TYPE_INT || t2 != TYPE_INT)
			printf("type mismatch\n");
		else return TYPE_INT;
	case EXP_MINUS:
		t1 = check_exp(((Exp_Minus)exp)->left);
		t2 = check_exp(((Exp_Minus)exp)->right);
		if (t1 != TYPE_INT || t2 != TYPE_INT)
			printf("type mismatch\n");
		else return TYPE_INT;
	case EXP_TIMES:
		t1 = check_exp(((Exp_Times)exp)->left);
		t2 = check_exp(((Exp_Times)exp)->right);
		if (t1 != TYPE_INT || t2 != TYPE_INT)
			printf("type mismatch\n");
		else return TYPE_INT;
	case EXP_DIVIDE:
		t1 = check_exp(((Exp_Divide)exp)->left);
		t2 = check_exp(((Exp_Divide)exp)->right);
		if (t1 != TYPE_INT || t2 != TYPE_INT)
			printf("type mismatch\n");
		else return TYPE_INT;
	case EXP_AND:
		t1 = check_exp(((Exp_And)exp)->left);
		t2 = check_exp(((Exp_And)exp)->right);
		if (t1 != TYPE_BOOL || t2 != TYPE_BOOL)
			printf("type mismatch\n");
		else return TYPE_BOOL;
	case EXP_OR:
		t1 = check_exp(((Exp_Or)exp)->left);
		t2 = check_exp(((Exp_Or)exp)->right);
		if (t1 != TYPE_BOOL || t2 != TYPE_BOOL)
			printf("type mismatch\n");
		else return TYPE_BOOL;
	}
}

////////////////////////////////////////
// stm

// Your job:
void check_stm(Stm_t stm)
{
	Type_t t1, t2, t;
	if (!stm) 
		return;
	switch (stm->kind){
	case STM_ASSIGN:
		t1 = Table_lookup(((Stm_Assign)stm)->id);
		t2 = check_exp(((Stm_Assign)stm)->exp);
		if (t1 != t2)
			printf("type mismatch\n");
		else
			return ;
	case STM_PRINTI:
		t = check_exp(((Stm_Printi)stm)->exp);
		if (t!= TYPE_INT)
			printf("type mismatch\n");
		else
			return;
	case STM_PRINTB:
		t = check_exp(((Stm_Printb)stm)->exp);
		if (t != TYPE_BOOL)
			printf("type mismatch\n");
		else
			return;
	default:
		return;
	}

}

void check_stms(List_t stms)
{
	while (stms){
		Stm_t s = (Stm_t)stms->data;
		check_stm(s);
		stms = stms->next;
	}
	return;
	
}


void Semant_check(Prog_t prog)
{
	if (!prog) return;
	// create table
	check_decs(prog->decs);
	// check stm
	check_stms(prog->stms);
	return;
}
