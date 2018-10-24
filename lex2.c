
/*
 ============================================================================
 Name        : lex.c
 Author      : akmalZ
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include<stdio.h>
#include<ctype.h>
#include<string.h>




char keywords[6][10]={"int","main","return","printf","include","stdio"};

int isKeyword(char exp[10])
{
	int i,flag=0;
	for(i=0;i<6;i++)
	{
		if(strcmp(exp,keywords[i])==0)
		{
			flag=1;
			break;
		}
	}
	return flag;
}


int main()
{
	
	FILE *fp,*fp2,*fp3,*fp4;
	int i,j=0;
	char ch,buffer[10],operators[6]={'+','*','/','-','^','='};
	fp=fopen("add.txt","r");
	fp2=fopen("operator.txt","w");
	fp3=fopen("keyword.txt","w");
	fp4=fopen("identifier.txt","w");

	if(fp==NULL||fp2==NULL||fp3==NULL||fp4==NULL)
	{
		printf("\nError in opening file\n");
	}
	else
	{
		printf("\nFile Opened Successfully\n");
	}
	fprintf(fp2,"**********************************************\n");
	fprintf(fp2,"INPUT		ORIGIN\n");
	fprintf(fp2,"**********************************************\n");

	fprintf(fp3,"**********************************************\n");
	fprintf(fp3,"INPUT		ORIGIN\n");
	fprintf(fp3,"**********************************************\n");

	fprintf(fp4,"**********************************************\n");
	fprintf(fp4,"INPUT		ORIGIN\n");
	fprintf(fp4,"**********************************************\n");


	while(ch=fgetc(fp))
	{
		if(ch=='"')
		{
			while(ch=fgetc(fp))
			{
				if(ch=='"')
					break;
			}
		}
		
		for(i=0;i<6;i++)
		{
			if(ch==operators[i])
			{
				printf("\n%cIt is a operator",ch);
				fprintf(fp2,"%c		OPERATOR\n",ch);
			}
		}
		/*if(!isalpha(ch))
		{
			printf("\n%cIt is a terminal",ch);
			fprintf(fp2,"%c		TERMINAl\n",ch);

		}*/
		if(ch==EOF)
		break;
		else if(isalpha(ch))
		{
			buffer[j++]=ch;
		}
		else if(ch=='\n'||ch==' '||ch=='<'||ch=='('||ch=='.')
		{
			buffer[j]='\0';
			j=0;
			printf("\n%s",buffer);
			if(isKeyword(buffer)==1)
			{
				printf("\nIt is Keyword");
				fprintf(fp3,"%s		KEYWORD\n",buffer);
			}
			else /*if(ch!='\n'||ch!=' '||ch!='<'||ch!='('||ch!='.')*/
			{
				printf("\nIt is identifier");
				fprintf(fp4,"%s		IDENTIFIER\n",buffer);

			}
		}

	
	}	

	fclose(fp4);
	fclose(fp3);
	fclose(fp2);
	fclose(fp);
	return 0;
}
