#define max 60
#define max1 50
#define greater 1
#define less 2
#include<string.h>

typedef int eltype;
typedef struct StackRec
{
	eltype storage[max];
	int top;
}StackRec;

typedef struct StackRec StackType;

#include"stack.h"

StackRec t1;
StackRec t2;
StackRec result;
void main()
{
	char n1[max1], n2[max1];
    initialize(&t1);
	initialize(&t2);
	initialize(&result);
	int situation;
	printf("---------------------------------------------------------------\n");
	printf("\t Calculate a subtraction with two big number\n");
	printf("---------------------------------------------------------------\n");
	printf("Enter the first number: ");
    scanf("%[^\n]%*c", n1);
	printf("Enter the second number: ");
	scanf("%[^\n]%*c", n2);
	if(strlen(n1) > strlen(n2))
	{
		situation = 1;
	}
	else if( strlen(n1) < strlen(n2))
	{
		situation = 2;
	}
	else {
		int x;
		x = strcmp(n1, n2);
		if(x > 0) // s1 < s2
		{
			situation = 1;
		}
		else if ( x < 0) { // s1 > s2
			situation = 2;
		}
		else {
			printf("The result of the subtract: 0\n");
			return;
		}
	}
	for(int i =0; i<strlen(n1); i++)
	{
		if(!full(&t1))
			push(&t1,n1[i]-'0');
		else {
		    printf("Stack overflow!\n");
			break;
		}
	}
	for(int j =0; j<strlen(n2); j++)
	{
		if(!full(&t2))
			push(&t2,n2[j]-'0');
		else 
			
	    {
			printf("Stack overflow!\n");
			break;
		}
	}
	int s1, s2,carry =0;
	switch (situation)
	{
	case 1:
	{
		while(!empty(&t1) || !empty(&t2))
		{
			if(!empty(&t1))
			s1 = pop(&t1);
			else
				s1 =0;
			if(!empty(&t2))
				s2 = pop(&t2);
			else {
				s2=0;
			}
			if(s1-carry >= s2)
			{
				push(&result, s1-carry-s2);
				carry =0;
			}
			else
			{
				push(&result, 10+s1-carry-s2);
				carry=1;
			}
		}
		while(result.storage[result.top] == 0)
		{
			pop(&result);
		}
		printf("The result of the substraction: ");
		while(!empty(&result))
		{
			printf("%d",pop(&result));
		}
		printf("\n");
		
		break;
	}
	case 2:
	{
		while(!empty(&t1) || !empty(&t2))
		{
			if(!empty(&t1))
				s1 = pop(&t1);
			else
				s1 =0;
			if(!empty(&t2))
				s2 = pop(&t2);
			else {
				s2=0;
			}
			if(s1 <= s2-carry)
			{
				push(&result, s2-carry -s1);
				carry=0;
			}
			else {
				push(&result, 10+s2-carry-s1);
				carry=1;
			}
		}
		while(result.storage[result.top] == 0)
		{
			pop(&result);
		}
		printf("The result of the substraction: -");
		while(!empty(&result))
		{
			printf("%d",pop(&result));
		}
		printf("\n");	
		
		break;
	}
	}
}
