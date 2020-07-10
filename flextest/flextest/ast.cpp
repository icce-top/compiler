#include "stdafx.h"
#include "ast.h"

// "constructors"
Exp_t Exp_Int_new(int n)
{
	Exp_Int p = (Exp_Int)malloc(sizeof (*p));
	p->kind = EXP_INT;
	p->n = n;
	return (Exp_t)p;
}

Exp_t Exp_Add_new(Exp_t left, Exp_t right)
{
	Exp_Add p = (Exp_Add)malloc(sizeof (*p));
	p->kind = EXP_ADD;
	p->left = left;
	p->right = right;
	return (Exp_t)p;
}

Exp_t Exp_Minus_new(Exp_t left, Exp_t right)
{
	Exp_Minus p = (Exp_Minus)malloc(sizeof (*p));
	p->kind = EXP_MINUS;
	p->left = left;
	p->right = right;
	return (Exp_t)p;
}

Exp_t Exp_Times_new(Exp_t left, Exp_t right)
{
	Exp_Times p = (Exp_Times)malloc(sizeof (*p));
	p->kind = EXP_TIMES;
	p->left = left;
	p->right = right;
	return (Exp_t)p;
}

Exp_t Exp_Divide_new(Exp_t left, Exp_t right)
{
	Exp_Divide p = (Exp_Divide)malloc(sizeof (*p));
	p->kind = EXP_DIVIDE;
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
					 printf(")-(");
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
