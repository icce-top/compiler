#include "stdafx.h"
#include "semant.h"


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
	while (1);//ÔÝÍ£ÆÁÄ»
	return 0;
}