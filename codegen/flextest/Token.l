
%%

.|\n       ECHO;

%%

int yywrap(void)

{  

  return 1;    //�������0���ʾҪ������һ��������,����1��ʾ����.

} 

int main(int argc, char** argv)

{

	freopen("1.txt","r",stdin);

    yylex();

    return 0;

}