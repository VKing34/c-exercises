#include<string.h>
#define max 999

typedef char eltype;
typedef struct StackRec
{
	eltype storage[max];
	int top;
}StackRec;

typedef struct StackRec StackType;

#include"stack.h"

StackRec check;

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Wrong syntax!!!\nSyntax: ./programname filename.txt");
		return 1;
	}
	FILE *fin;
	if((fin = fopen(argv[1],"r")) == NULL)
	{
		printf("Can't open %s\n", argv[1]);
		return 1;
	}
	initialize(&check);
	char c;
	int row=1,col =0,x,y;
	while((c=fgetc(fin)) != EOF)
	{
		col++;
		if(c == '\n')
		{
			row++;
			col =0;
		    
		}
		if(check.storage[check.top] == '[' && c == '[')
		{
			x = row;
			y = col;
		    printf("%s:%d:%d: error: a symbol ] was expected after [\n",argv[1],x,y );
			return 0;
		}
		if(c == '{' || c == '(' || c == '[')
		{
			push(&check,c);
			x = row;
			y = col;
		    
		}
		
		if(check.storage[check.top-1] == '(' && check.storage[check.top] == '[' && c == ')' )
		{
			printf("%s:%d:%d: error: a symbol ] was expected after [ \n",argv[1],x,y );
			return 0;
		}
		if(check.storage[check.top] != '[' && c == ']')
		{
			x = row;
			y = col;
		    printf("%s:%d:%d: error: a symbol [ was expected befor ] \n",argv[1],x,y );
			return 0;
		}
	    
		if( check.storage[check.top] == '[' && c == ']')
			pop(&check);
		
		if(check.storage[check.top-1] == '{' && check.storage[check.top] == '(' && c == '}' )
		{
			printf("%s:%d:%d: error: a symbol ) was expected after ( \n",argv[1],x,y );
			return 0;
		}
		if(check.storage[check.top] != '(' && c == ')')
		{
			x = row;
			y = col;
		    printf("%s:%d:%d: error: a symbol ( was expected befor )\n",argv[1],x,y );
			return 0;
		}
		if ( check.storage[check.top] == '(' && c == ')')
			pop(&check);
		if(check.storage[check.top] != '{' && c == '}')
		{
			x = row;
			y = col;
		    printf("%s:%d:%d: error: a symbol { was expected befor }\n",argv[1],x,y );
			return 0;
		}
		if ( check.storage[check.top] == '{' && c == '}')
			pop(&check);
		
		
	}
	if(check.storage[check.top] == '{')
		printf("%s:%d:%d: error: a symbol } was expected after { \n",argv[1],x,y );
	else if(check.storage[check.top] == '(')
		printf("%s:%d:%d: error: a symbol ) was expected after ( \n",argv[1],x,y );
	else if(check.storage[check.top] == '[')
		printf("%s:%d:%d: error: a symbol ] was expected after [ \n",argv[1],x,y );
    else if(empty(&check))
	{
		printf("The source codes are symmetric \\(^.^)/\n");
	}
	fclose(fin);
	return 0;
}
