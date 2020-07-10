#include "stdafx.h"
#include "ast.h"
#include "semant.h"
#include "stack-machine.h"
#include "gen-stack.h"
#include "stack2x86.h"



extern int yyparse();
extern Prog_t tree;

int main(int argc, char **argv)
{
	printf("lex and parse starting...\n");
	yyparse();
	printf("lex and parse finished\n");

	printf("print the AST starting...\n");
	Prog_print(tree);
	printf("print the AST finished\n");

	printf("semantic analysis starting...\n");
	Semant_check(tree);
	printf("semantic analysis finished\n");

	printf("stack machine code generation starting...\n");
	Stack_Prog_t stack = Gen_stack(tree);
	printf("stack machine code generation finished\n");

	printf("stack machine code output starting...\n");
	Stack_Prog_print(stack);
	printf("stack machine code output finished\n");

	printf("x86 code generation starting...\n");
	Stack2x86_print(stack);
	printf("x86 code generation finished (writing to file \"temp.txt\")\n");
	//system("cat temp.s");

	while (1);//ÔÝÍ£ÆÁÄ»
	return 0;
}