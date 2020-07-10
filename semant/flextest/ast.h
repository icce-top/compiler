#include "stdafx.h"
#include "list.h"

typedef char *string;
/////////////////////////////
// type
typedef enum Type_Kind_t{
	TYPE_INT,
	TYPE_BOOL
} Type_t;
void Type_print(Type_t);

//////////////////////////////
// dec
typedef struct DEC_t{
	Type_t type;
	char *id;
}*Dec_t;;
Dec_t Dec_new(Type_t, char *);
void Dec_print(Dec_t);

///////////////////////////////
// exp
enum Exp_Kind_t{
	EXP_INT,
	EXP_TRUE,
	EXP_FALSE,
	EXP_ID,
	EXP_ADD,
	EXP_MINUS,
	EXP_TIMES,
	EXP_DIVIDE,
	EXP_AND,
	EXP_OR
};

/*
E -> n
| E + E
| E * E
*/
 typedef struct EXP_t{
	enum Exp_Kind_t kind;
	
 }*Exp_t;

 // all operations on "Exp"
 void Exp_print(Exp_t exp);
 int Exp_numNodes(Exp_t exp);

 // n
 typedef struct EXP_Int{
	 enum Exp_Kind_t kind;
	 int n;
 }*Exp_Int;
Exp_t Exp_Int_new(int n);

// id
typedef struct EXP_Id{
	enum Exp_Kind_t kind;
	char *id;
}*Exp_Id;
Exp_t Exp_Id_new(char *id);

// true
typedef struct EXP_True{
	enum Exp_Kind_t kind;
}*Exp_True;
Exp_t Exp_True_new();

// false
typedef struct EXP_False{
	enum Exp_Kind_t kind;
}*Exp_False;
Exp_t Exp_False_new();

// +
 typedef struct EXP_Add{
	 enum Exp_Kind_t kind;
	 Exp_t left;
	 Exp_t right;
 }*Exp_Add;
 Exp_t Exp_Add_new(Exp_t left, Exp_t right);

 // -
 typedef struct EXP_Minus{
	 enum Exp_Kind_t kind;
	 Exp_t left;
	 Exp_t right;
 }*Exp_Minus;
 Exp_t Exp_Minus_new(Exp_t left, Exp_t right);

 // *
 typedef struct EXP_Times{
	 enum Exp_Kind_t kind;
	 Exp_t left;
	 Exp_t right;
 }*Exp_Times;
 Exp_t Exp_Times_new(Exp_t left, Exp_t right);

 // /
 typedef struct EXP_Divide{
	 enum Exp_Kind_t kind;
	 Exp_t left;
	 Exp_t right;
 }*Exp_Divide;
 Exp_t Exp_Divide_new(Exp_t left, Exp_t right);

 // &&
 typedef struct EXP_And{
	 enum Exp_Kind_t kind;
	 Exp_t left;
	 Exp_t right;
 }*Exp_And;
 Exp_t Exp_And_new(Exp_t left, Exp_t right);

 // &&
 typedef struct EXP_Or{
	 enum Exp_Kind_t kind;
	 Exp_t left;
	 Exp_t right;
 }*Exp_Or;
 Exp_t Exp_Or_new(Exp_t left, Exp_t right);

 /////////////////////////////////////
 // stm

 enum Stm_Kind_t{
	 STM_ASSIGN,
	 STM_PRINTI,
	 STM_PRINTB
 };
 typedef struct STM_t{
	 enum Stm_Kind_t kind;
 }*Stm_t;;
 void Stm_print(Stm_t);

 // x = e;
 typedef struct STM_Assign{
	 enum Stm_Kind_t kind;
	 char *id;
	 Exp_t exp;
 }*Stm_Assign;;
 Stm_t Stm_Assign_new(char *, Exp_t);

 // printi (exp)
 typedef struct STM_Printi{
	 enum Stm_Kind_t kind;
	 Exp_t exp;
 }*Stm_Printi;;
 Stm_t Stm_Printi_new(Exp_t);

 // printb (exp)
 typedef struct STM_Printb{
	 enum Stm_Kind_t kind;
	 Exp_t exp;
 }*Stm_Printb;;
 Stm_t Stm_Printb_new(Exp_t);

 /////////////////////////////////////
 // prog
 typedef struct PROG_t{
	 List_t decs;  // List_t<Dec_t>
	 List_t stms;   // List_t<Stm_t>
 }*Prog_t;;
 Prog_t Prog_new(List_t, List_t);
 void Prog_print(Prog_t);
