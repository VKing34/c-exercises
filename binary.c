#define max 50

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
	int x;
	initialize(&s);
	printf("Convert from an integer number to a binary number\n");
	printf("Enter an integer number: "); scanf("%d", &x);

	while(x!=0)
	{
		if(!full(&s))
		{
			push(&s,x%2);
			x=x/2;
		}
		else
		{
			printf("Stack overflow\n");
			return;
		}
	}
	printf("The binary number: ");
	while (!empty(&s))
	{
		printf("%d",pop(&s));
	}
	printf("\n");
}
