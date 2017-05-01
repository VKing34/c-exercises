#include<stdio.h>
#include<stdlib.h>

void initialize(StackType *stack)
{
	stack->top=0;
}

int empty(StackType *stack)
{
    if(stack->top == 0)
	{
		return 1;
	}
	return 0;
}

int full(StackType *stack)
{
	if(stack->top == max-1)
		return 1;
	return 0;
}

void push(StackType *stack, eltype e)
{
    stack->top = stack->top+1;
	stack->storage[stack->top]=e;
}

eltype pop(StackType *stack)
{
	int x;
	x = stack->storage[stack->top];
	stack->top = stack->top-1;
	return x;
}
