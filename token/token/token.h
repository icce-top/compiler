#include "stdafx.h"
#define TOKEN_MAX_LENGTH 10
typedef int Status;
#define SUCCESS 1
#define ERROR 0

enum kind {IF,NUM,ID};
//定义位置
typedef struct Position{
	int line;
	int column;
}Position;
//定义单词记号
typedef struct PreToken{
	char s[TOKEN_MAX_LENGTH];
	int length;
	Position p;
}PreToken;

typedef struct Token{
	int k;
	PreToken pre_t;
	bool error;
}Token;

typedef struct Token_list{
	Token t;
	Token_list* next;
}Token_list;

Status Dfa(Token_list* p);//词法分析器
Status Tokenizer(char* code);//按空格和回车符分割字符流