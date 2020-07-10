%{
#include "stdafx.h"
#define NUM 1
#define ID 2
#define IF 3
#define ENT 4
int line=1;
int column=1;
%}


%%

[1-9][0-9]* {printf("%s",yytext);printf("(%d,%d)",line,column);column+=yyleng;}
[a-z_][a-z0-9_]*   {printf("%s",yytext);printf("(%d,%d)",line,column);column+=yyleng;}
"if"    {printf("%s",yytext);column+=yyleng;}
\n    {printf("\n");line++;column=1;}
" "    {column+=1;}
%%
int yywrap(){
	return 0;
}
int main(){
	FILE* fp = NULL;
	if (fopen_s(&fp, "code.txt", "r") == 0)
		yyin=fp;
	yylex();


	
	printf("success!\n");
	while(1);
	return 0;
}

