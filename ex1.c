#define max 60
#define max1 50
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
    t1.top=0;
	t2.top=0;
	result.top=0;
	printf("Enter the first number: ");
    scanf("%[^\n]%*c", n1);
	for(int i =0; i<strlen(n1); i++)
	{
		if(!full(&t1))
			push(&t1,n1[i]-'0');
		else {
			printf("Stack overflow!\n");
			break;
		}
	}
	printf("Enter the second number: ");
	scanf("%[^\n]%*c", n2);
	for(int j =0; j<strlen(n2); j++)
	{
		if(!full(&t2))
			push(&t2,n2[j]-'0');
		else {
			printf("Stack overflow!\n");
			break;
		}
	}
    int carry = 0;
	int s1,s2,sum;
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
		sum = s1 + s2 + carry;
		if(sum >=10)
		{
			push(&result,sum-10);
			carry =1;
		}
		else {
			push(&result,sum);
			carry =0;
		}	    
	}
    push(&result, carry);
	printf("The sum of 2 numbers: ");
	while(!empty(&result))
	{
		printf("%d",pop(&result));
		
	}
	printf("\n");
}
