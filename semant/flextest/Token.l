
%%

.|\n       ECHO;

%%

int yywrap(void)

{  

  return 1;    //如果返回0则表示要处理下一个输入流,返回1表示结束.

} 

int main(int argc, char** argv)

{

	freopen("1.txt","r",stdin);

    yylex();

    return 0;

}