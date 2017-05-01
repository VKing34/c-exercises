#define max 99

typedef int eltype;
typedef struct StackRec
{
	eltype storage[max];
	int top;
}StackRec;

typedef struct StackRec StackType;

#include"stack.h"

StackRec s,tmp,input;
int carry;

void main()
{
	int x,num;
	initialize(&s);
	initialize(&tmp);
	initialize(&input);
	while(x != 5)
	{
		printf("---------------------------------------------------------------\n");
		printf("\t \t\t Undo\n");
		printf("---------------------------------------------------------------\n");
		printf("1. Add a number into the stack\n2. Show the top\n3. Pop up\n4. Undo\n5. Exit\nChoose one option: ");
		scanf("%d", &x);
		if(x == 1 || x == 3)
		{
			push(&input,x);
		}
		switch (x) {
		case 1: {
			printf("Input an integer number: "); scanf("%d", &num);
			push(&s,num);
			printf("-------------------Insertion is succesful----------------------\n");
			break;
		}
		case 2:
			if(!empty(&s))
				printf("Top: %d\n", s.storage[s.top]);
			else
				printf("There's no element!!!\n");
			break;
		case 3:
		    push(&tmp,pop(&s));
		    
			printf("-------------------Poping up is succesful----------------------\n");
			break;
		case 4:
			if(empty(&input))
				printf("Nothing to undo!!!\n");
			else
			{
			    if(pop(&input) == 1)
				{
					pop(&s);
				}
				else
					push(&s,pop(&tmp));
			}
			break;
		case 5:
			break;
		default:
			printf("Please choose 1, 2, 3, 4 or 5\nTry again!!!");
			break;
		}
	}
}
