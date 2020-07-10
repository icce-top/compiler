#include "stdafx.h"
#define TOKEN_MAX_LENGTH 10
typedef int Status;
#define SUCCESS 1
#define ERROR 0

enum kind {IF,NUM,ID};
//����λ��
typedef struct Position{
	int line;
	int column;
}Position;
//���嵥�ʼǺ�
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

Status Dfa(Token_list* p);//�ʷ�������
Status Tokenizer(char* code);//���ո�ͻس����ָ��ַ���