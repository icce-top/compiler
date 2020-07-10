#include "ast.h"
#include "exp.tab.h"
extern Exp_t tree;
int yyparse();

// Data structures for the Stack language.
enum Stack_Kind_t { STACK_ADD, STACK_PUSH };
struct Stack_t
{
	enum Stack_Kind_t kind;
};

struct Stack_Add
{
	enum Stack_Kind_t kind;
};

struct Stack_Push
{
	enum Stack_Kind_t kind;
	int i;
};

// "constructors"
struct Stack_t *Stack_Add_new()
{
	struct Stack_Add *p = (struct Stack_Add*)malloc(sizeof(*p));
	p->kind = STACK_ADD;
	return (struct Stack_t *)p;
}

struct Stack_t *Stack_Push_new(int i)
{
	struct Stack_Push *p = (struct Stack_Push*)malloc(sizeof(*p));
	p->kind = STACK_PUSH;
	p->i = i;
	return (struct Stack_t *)p;
}

/// instruction list
struct List_t
{
	struct Stack_t *instr;
	struct List_t *next;
};

struct List_t *List_new(struct Stack_t *instr, struct List_t *next)
{
	struct List_t *p = (struct List_t *)malloc(sizeof(*p));
	p->instr = instr;
	p->next = next;
	return p;
}

// "printer"
void List_reverse_print(struct List_t *list)
{
	while (list){
		switch (list->instr->kind){
		case STACK_ADD:
			printf("STACK ADD\n"); break;
		case STACK_PUSH:
			printf("STACK PUSH %d\n", ((struct Stack_Push *)(list->instr))->i); break;
		}
		list = list->next;

	}
}

//////////////////////////////////////////////////
// a compiler from Sum to Stack
struct List_t *all = 0;

void emit(struct Stack_t *instr)
{
	all = List_new(instr, all);
}

void compile(Exp_t exp)
{
	switch (exp->kind){
	case EXP_INT:{
					 Exp_Int p = (Exp_Int)exp;
					 emit(Stack_Push_new(p->n));
					 break;
	}
	case EXP_ADD:{
					 Exp_Add p = (Exp_Add)exp;
					 compile((Exp_t)p->left); compile((Exp_t)p->right);
					 emit(Stack_Add_new());
					 break;
	}
	default:
		break;
	}
}

int main(int argc, char **argv)
{
	yyparse();
	Exp_print(tree);
	compile(tree);
	// print out the generated Stack instructons:
	printf("\n");
	List_reverse_print(all);
	printf("\nCompile finished\n");
	while (1);//ÔÝÍ£ÆÁÄ»
	return 0;
}
