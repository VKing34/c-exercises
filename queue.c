#include<stdio.h>
#include<stdlib.h>

#define max 10

typedef int elementtype;
#include"queue.h"


void main()
{
	int i=0;
	queue q;
	makenullqueue(&q);
	
    while(!fullqueue(q))
	{
		enqueue(&q,i);
		i++;
	}
	while(!empty(q))
	{
		printf("%d\n", dequeue(&q));
		
	}

	
	
	
}
