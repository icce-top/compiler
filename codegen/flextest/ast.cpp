#include "stdafx.h"
#include "ast.h"



////////////////////////////////////////
void Type_print(Type_t t)
{
	switch (t){
	case TYPE_INT:
		printf("int");
		break;
	case TYPE_BOOL:
		printf("bool");
		break;
	default:
		break;
	}
	return;
}

////////////////////////////////////////
// dec
Dec_t Dec_new(Type_t type, char *id)
{
	Dec_t p = (Dec_t)malloc(sizeof (*p));
	p->type = type;
	p->id = id;
	return p;
}

void Dec_print(Dec_t d)
{
	Type_print(d->type);
	printf(" %s;", d->id);
	return;
}

/////////////////////////////////////////
// n
Exp_t Exp_Int_new(int n)
{
	Exp_Int p = (Exp_Int)malloc(sizeof (*p));
	p->kind = EXP_INT;
	p->n = n;
	return (Exp_t)p;
}

// true
Exp_t Exp_True_new()
{
	Exp_True p = (Exp_True)malloc(sizeof (*p));
	p->kind = EXP_TRUE;
	return (Exp_t)p;
}

// false
Exp_t Exp_False_new()
{
	Exp_False p = (Exp_False)malloc(sizeof (*p));
	p->kind = EXP_FALSE;
	return (Exp_t)p;
}

// id
Exp_t Exp_Id_new(char *id)
{
	Exp_Id p = (Exp_Id)malloc(sizeof (*p));
	p->kind = EXP_ID;
	p->id = id;
	return (Exp_t)p;
}

// +
Exp_t Exp_Add_new(Exp_t left, Exp_t right)
{
	Exp_Add p = (Exp_Add)malloc(sizeof (*p));
	p->kind = EXP_ADD;
	p->left = left;
	p->right = right;
	return (Exp_t)p;
}

// -
Exp_t Exp_Minus_new(Exp_t left, Exp_t right)
{
	Exp_Minus p = (Exp_Minus)malloc(sizeof (*p));
	p->kind = EXP_MINUS;
	p->left = left;
	p->right = right;
	return (Exp_t)p;
}

// *
Exp_t Exp_Times_new(Exp_t left, Exp_t right)
{
	Exp_Times p = (Exp_Times)malloc(sizeof (*p));
	p->kind = EXP_TIMES;
	p->left = left;
	p->right = right;
	return (Exp_t)p;
}

// /
Exp_t Exp_Divide_new(Exp_t left, Exp_t right)
{
	Exp_Divide p = (Exp_Divide)malloc(sizeof (*p));
	p->kind = EXP_DIVIDE;
	p->left = left;
	p->right = right;
	return (Exp_t)p;
}

// &&
Exp_t Exp_And_new(Exp_t left, Exp_t right)
{
	Exp_And p = (Exp_And)malloc(sizeof (*p));
	p->kind = EXP_AND;
	p->left = left;
	p->right = right;
	return (Exp_t)p;
}

// ||
Exp_t Exp_Or_new(Exp_t left, Exp_t right)
{
	Exp_Or p = (Exp_Or)malloc(sizeof (*p));
	p->kind = EXP_OR;
	p->left = left;
	p->right = right;
	return (Exp_t)p;
}

// all operations on "Exp"
void Exp_print(Exp_t exp)
{
	if (!exp) return;
	switch (exp->kind){
	case EXP_INT:{
					 Exp_Int p = (Exp_Int)exp;
					 printf("%d", p->n);
					 return;
	}
	case EXP_TRUE:{
					  printf("true");
					  return;
	}
	case EXP_FALSE:{
					   printf("false");
					   return;
	}
	case EXP_ID:{
					Exp_Id p = (Exp_Id)exp;
					printf("%s", p->id);
					return;
	}
	case EXP_ADD:{
					 Exp_Add p = (Exp_Add)exp;
					 printf("(");
					 Exp_print(p->left);
					 printf(") + (");
					 Exp_print(p->right);
					 printf(")");
					 return;
	}
	case EXP_MINUS:{
					 Exp_Minus p = (Exp_Minus)exp;
					 printf("(");
					 Exp_print(p->left);
					 printf(") - (");
					 Exp_print(p->right);
					 printf(")");
					 return;
	}
	case EXP_TIMES:{
					   Exp_Times p = (Exp_Times)exp;
					   printf("(");
					   Exp_print(p->left);
					   printf(") * (");
					   Exp_print(p->right);
					   printf(")");
					   return;
	}
	case EXP_DIVIDE:{
						Exp_Divide p = (Exp_Divide)exp;
						printf("(");
						Exp_print(p->left);
						printf(") / (");
						Exp_print(p->right);
						printf(")");
						return;
	}
	case EXP_AND:{
					 Exp_And p = (Exp_And)exp;
					 printf("(");
					 Exp_print(p->left);
					 printf(") && (");
					 Exp_print(p->right);
					 printf(")");
					 return;
	}
	case EXP_OR:{
					Exp_Or p = (Exp_Or)exp;
					printf("(");
					Exp_print(p->left);
					printf(") || (");
					Exp_print(p->right);
					printf(")");
					return;
	}
	default:
		return;
	}
}

int Exp_numNodes(Exp_t exp){//求取树的规模
	if (!exp) return 0;
	switch (exp->kind){
	case EXP_INT:return 1;
	case EXP_ADD:
		return 1 + Exp_numNodes(((Exp_Add)exp)->right)
			+ Exp_numNodes(((Exp_Add)exp)->right);
	case EXP_MINUS:
		return 1 + Exp_numNodes(((Exp_Minus)exp)->right)
			+ Exp_numNodes(((Exp_Minus)exp)->right);
	case EXP_TIMES:
		return 1 + Exp_numNodes(((Exp_Times)exp)->right)
			+ Exp_numNodes(((Exp_Times)exp)->right);
	case EXP_DIVIDE:
		return 1 + Exp_numNodes(((Exp_Divide)exp)->right)
			+ Exp_numNodes(((Exp_Divide)exp)->right);
	default:
		printf("compile bug\n");
	
	}
}

////////////////////////////////////////
// stm
void Stm_print(Stm_t s)
{
	if (!s) return;
	switch (s->kind){
	case STM_ASSIGN:{
						Stm_Assign p = (Stm_Assign)s;
						printf("%s = ", p->id);
						Exp_print(p->exp);
						printf(";");
						break;
	}
	case STM_PRINTI:{
						Stm_Printi p = (Stm_Printi)s;
						printf("printi(");
						Exp_print(p->exp);
						printf(");");
						break;
	}
	case STM_PRINTB:{
						Stm_Printb p = (Stm_Printb)s;
						printf("printb(");
						Exp_print(p->exp);
						printf(");");
						break;
	}
	default:
		break;
	}
	return;
}

// x = e;
Stm_t Stm_Assign_new(char *id, Exp_t exp)
{
	Stm_Assign p = (Stm_Assign)malloc(sizeof (*p));
	p->kind = STM_ASSIGN;
	p->id = id;
	p->exp = exp;
	return (Stm_t)p;
}

// printi (e);
Stm_t Stm_Printi_new(Exp_t exp)
{
	Stm_Printi p = (Stm_Printi)malloc(sizeof (*p));
	p->kind = STM_PRINTI;
	p->exp = exp;
	return (Stm_t)p;
}

// printb (e);
Stm_t Stm_Printb_new(Exp_t exp)
{
	Stm_Printb p = (Stm_Printb)malloc(sizeof (*p));
	p->kind = STM_PRINTB;
	p->exp = exp;
	return (Stm_t)p;
}

///////////////////////////////////////
// prog
Prog_t Prog_new(List_t decs, List_t stms)
{
	Prog_t p = (Prog_t)malloc(sizeof (*p));
	p->decs = decs;
	p->stms = stms;
	return p;
}

void Prog_print(Prog_t prog)
{
	if (!prog) return;
	List_t decs = prog->decs;
	printf("{\n");
	while (decs){
		Dec_t d = (Dec_t)decs->data;
		printf("  ");
		Dec_print(d);
		printf("\n");
		decs = decs->next;
	}

	printf("\n");

	List_t stms = prog->stms;
	while (stms){
		Stm_t s = (Stm_t)stms->data;
		printf("  ");
		Stm_print(s);
		printf("\n");
		stms = stms->next;
	}
	printf("}\n");
	return;
}
