//Parser.y
%{

#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define YYSTYPE  double

void yyerror(const char *text);

int yylex(void);
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section
// place any declarations here

%token NUMBER

%left '+' '-'
%left '*' '/'
%right '^'
%%

/////////////////////////////////////////////////////////////////////////////
// rules section
// place your YACC rules here (there must be at least one)
command : exp {printf("%lf\n",$1);}
    ;

exp     : NUMBER         {$$ = $1;}
       | exp '+' exp     {$$ = $1 + $3;}
       | exp '-' exp     {$$ = $1 - $3;}
       | exp '*' exp     {$$ = $1 * $3;}
       | exp '/' exp     {
                            if(0 != $3)
                            {
                               $$ = $1 / $3;
                            }
                            else
                            {
                               $$=0;
                            }
                        }
       | exp '^' exp     {$$ = pow($1,$3);}
       | '(' exp ')'     {$$ = $2;}
    ;
%%

/////////////////////////////////////////////////////////////////////////////
// programs section

int yylex(void)
{
   // place your token retrieving code here
   int c = 0;

   while( (c = getchar()) == ' ');
   if( isdigit(c) )
   {
       ungetc(c,stdin);
       scanf_s("%lf",&yylval);
       return (NUMBER);
   }

   if( '\n' == c )
   {
       return 0;
   }
   return c;
}

int main(void)
{
    yyparse();
    system("PAUSE");
    return 0;
}

void yyerror(const char *text)
{
   fprintf(stderr,"%s\n",text);
}