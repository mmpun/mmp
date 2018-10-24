#include<stdio.h>
#include<ctype.h>
#include<string.h>

void Tprime();
void Eprime();
void E();
void Check();
void T();

char expression[10];
int count,flag;

int main()
{
count=0;
flag=0;

printf("enter an algebric expression");
scanf("%s",expression);
E();

	if(strlen(expression)==count&&flag==0)
		{
		printf("\n the expression %s is valid",expression);
		}
	else
		{
		printf("\n the expression %s is invalid",expression);
		}
}
void E()
{
T();
Eprime();
}
void T()
{
Check();
Tprime();
}


void Tprime()
{
if(expression[count]=='*')
	{
	count++;
	Check();
	Tprime();
	}
}
void Check()
{
if(isalnum(expression[count]))
	{
	count++;
	}
	else if(expression[count]=='(')
	{
	count++;	
	E();
	if(expression[count]==')')
		{
		count++;
		}
	else
		{
		flag=1;
		}
		
	}	
	else
	{
	flag=1;
	}
}
void Eprime()
{
	if(expression[count]=='+')
	{
	count++;
	T();
	Eprime();
	}
}


/*student@student-Inspiron-300:~$ ./a.out
enter an algebric expression2+3+(4*5+5)

 the expression 2+3+(4*5+5) is valid
*/







