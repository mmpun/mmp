%{
#include "y.tab.h"
#include <stdio.h>
#include <math.h>
%}

%union
{
	double dval;
}

%token <dval> NUMBER
%left '+''-'
%left '*''/'
%type <dval> E

%%
SL       :     S '\n';

S	:	E	{printf("=%f\n",$1);};

E	:	 E'+' E{$$=$1+$3;}
		|E '-' E {$$=$1-$3;}
		|E '*' E {$$=$1*$3;}		
		|E '/' E {
				if($3==0)
				printf("Error! Divide by zero!!");
				else
				$$=$1/$3;
				printf("Division is");
			}
		|NUMBER {$$=$1;};
%%
extern FILE*yyin;

int main()
{
	do{
yyparse();
	}while(!feof(yyin));
}

yyerror(char*a)
{
	fprintf(stderr,"parse error!!!");
}
/*student@student-Inspiron-300:~/Desktop/shubham$ ./a.out
2+3
=5.000000
*/
