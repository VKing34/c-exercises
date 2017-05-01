

typedef int elementType;

#include"libqueue.h"

node *head, *tail;

void main()
{
	int i=0;
	for(i=0; i<10;i++)
	{
		enqueue(i,&head,&tail);
	}
    while(!empty(&head,&tail))
	{
		printf("%d\n", dequeue(&head,&tail));
	}
}
