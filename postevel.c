#define max 60
#include<string.h>

typedef int eltype;
typedef struct StackRec
{
	eltype storage[max];
	int top;
}StackRec;

typedef struct StackRec StackType;

#include"stack.h"

StackRec s;

void main()
{
	initialize(&s);
	char exp[max];
	char c;
	int i;
	printf("Input postfix expression: "); scanf("[^\n]%*c", exp);
	for(i =0; i< strlen(exp); i++)
	{
		if( exp[i] == 32 )
			continue;
		if( exp[i] > 47)
		{
			push(&s, exp[i]-'0');
		}
		else
		{
			c = exp[i];
			switch (c) {
			case +: {
				push(&s, pop(&s) + pop(&s));
				break;
			}
			case -:
				int n2 = pop(&s);
				int n1 = pop(&s);
				push(&s, n1 - n2);
				break;
			case *:
				push(&s, pop(&s)*pop(&s));
				break;
			case /:
				int n2 = pop(&s);
				int n1 = pop(&s);
				push(&s, n1/n2);
				break;
			default:
				printf("Wrong syntax!!!\n");
				break;
			}
		}
		
	}

}
