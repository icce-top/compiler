// token.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "token.h"
#include "string.h"
//          	a	��	z	_	0	��	9
//state0:��ʼ	2	��	2	2	0	1	1
//state1��NUM	0	0	0	0	1	1	1
//state2��ID	2	2	2	2	2	2	2

int dfa[3][37] = {
	{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 },
};

Status Tokenizer(char* code){//���ո�ͻس����ָ��ַ���,ĩβ����\0
	int line = 1, column = 1;
	Token_list* p=NULL; int length = 0;
	while (*code != EOF){
		if (p){
			p->t.pre_t.s[length] = *code;
			if (*code == '\n' || *code == ' '){//�ָ�
				p->t.pre_t.s[length] = '\0';
				p->t.pre_t.p.column = column-length;
				p->t.pre_t.p.line = line;
				p->t.pre_t.length = length;
				//printf("%s\n", p->t.pre_t.s);
				Dfa(p);
				if (*code == '\n'){
					line += 1; column = 0;
				}
				while (*code == ' ' || *code == '\n'){
					code += 1; column += 1;
				}
				if (*code == EOF)
					return SUCCESS;
				p->next = (Token_list*)malloc(sizeof(Token_list));
				p = p->next;
				length = 0;
				p->t.pre_t.s[length] = *code;
			}//if
		}//if	
		else {
			p = (Token_list*)malloc(sizeof(Token_list));
			p->t.pre_t.s[length] = *code;

		}
		code += 1; column += 1; length += 1;
	}
	p->t.pre_t.s[length] = '\0';
	p->t.pre_t.p.column = column-length;
	p->t.pre_t.p.line = line;
	p->t.pre_t.length = length;
	//printf("%s\n", p->t.pre_t.s);
	Dfa(p);
	p->next = NULL;
	return SUCCESS;
}
Status Dfa(Token_list* p){//�ʷ�������
	int state = 0;
	//ʶ��һ�����ʼǺ�
	char *code = p->t.pre_t.s;
	//0;1-9;a-z;_����Ϊ����
	int length = 0;
	while (length <p->t.pre_t.length-1){
		int k = 0;
		if (*code == '0')
			k = 1;
		else if (*code >= '1'&&*code <= '9')
			k = 2;
		else if (*code >= 'a'&&*code <= 'z')
			k = 3;
		else if (*code == '_')
			k = 4;
		switch (k){
		case 1://27
			state = dfa[state][27]; break;
		case 2://49-28=11
			state = dfa[state][(int)(*code - '1')+28]; break;
		case 3://97-0=97
			state = dfa[state][(int)*code - 97]; break;
		case 4://26
			state = dfa[state][26]; break;
		}//switch
		length += 1; code += 1;
		if (state == 0){//ʶ�����
			p->t.error = true; break;
		}
	}//while

	if (state != 0 && length == p->t.pre_t.length-1){//�ɹ�ʶ��һ�����ʺ����
		p->t.error = false;
		if (state == 1){
			p->t.k = NUM;
			printf("NUM(%s)  (%d,%d)\n", p->t.pre_t.s, p->t.pre_t.p.line, p->t.pre_t.p.column);
		}
		else if (state == 2){
			if (strcmp(p->t.pre_t.s, "if") == 0){//ʶ��ؼ���IF
				p->t.k = IF;
				printf("IF  (%d,%d)\n", p->t.pre_t.p.line, p->t.pre_t.p.column);
			}
			else{
				p->t.k = ID;
				printf("ID(%s)  (%d,%d)\n", p->t.pre_t.s, p->t.pre_t.p.line, p->t.pre_t.p.column);
			}
			
		}
		
	}
	return SUCCESS;
}


int _tmain(int argc, _TCHAR* argv[])
{
	//���ļ�
	FILE* fp = NULL;
	if (fopen_s(&fp, "code.txt", "r+") == 0){
		printf("��ʼ��ȡ��������\n");
		//�涨�����ַ������Ȳ�����1024
		char code[1024];
		int i = 0; char c;
		c = code[i] = fgetc(fp);
		i += 1;
		while (c != EOF){
			c=code[i] = fgetc(fp);
			i++;
		}
		code[i] = '\0';
		if (fclose(fp) == 0){
			printf("�ɹ���ȡ��������\n");
		}
		//�ʷ�����
		printf("compile code:\n%s\n", code);
		printf("ת��Ϊ�Ǻ���:\n");
		if(Tokenizer(code))
			printf("���������ɹ�ת����\n");
	}

	while (1);
	return 0;
}

