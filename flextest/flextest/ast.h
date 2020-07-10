#include "stdafx.h"

enum Exp_Kind_t{
	EXP_INT,
	EXP_ADD,
	EXP_MINUS,
	EXP_TIMES,
	EXP_DIVIDE,
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

 typedef struct EXP_Int{
	 enum Exp_Kind_t kind;
	 int n;
 }*Exp_Int;
Exp_t Exp_Int_new(int n);

 typedef struct EXP_Add{
	 enum Exp_Kind_t kind;
	 Exp_t left;
	 Exp_t right;
 }*Exp_Add;
 Exp_t Exp_Add_new(Exp_t left, Exp_t right);

 typedef struct EXP_Minus{
	 enum Exp_Kind_t kind;
	 Exp_t left;
	 Exp_t right;
 }*Exp_Minus;
 Exp_t Exp_Minus_new(Exp_t left, Exp_t right);

 typedef struct EXP_Times{
	 enum Exp_Kind_t kind;
	 Exp_t left;
	 Exp_t right;
 }*Exp_Times;
 Exp_t Exp_Times_new(Exp_t left, Exp_t right);

 typedef struct EXP_Divide{
	 enum Exp_Kind_t kind;
	 Exp_t left;
	 Exp_t right;
 }*Exp_Divide;
 Exp_t Exp_Divide_new(Exp_t left, Exp_t right);
