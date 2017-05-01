#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
	elementtype element[max];
	int front, rear;
}queue;
void makenullqueue( queue *q)
{
	q->front = -1;
	q->rear = -1;
}

int empty(queue q)
{
	return q.front == -1;
}

int fullqueue(queue q)
{
	return (q.rear - q.front+1)%max == 0;
}

void enqueue(queue *q,elementtype x)
{
	if(!fullqueue(*q))
	{
		if(empty(*q)) q->front=0;
		q->rear = (q->rear+1) % max;
		q->element[q->rear]= x;
	}
	else printf("Queue is full!\n");
}

elementtype dequeue(queue *q)
{
	if(!empty(*q))
	{
		if(q->front == q->rear)
		{
			int x = q->element[q->front];
			makenullqueue(q);
			return x;
		}
		else
		{
			int x;
			x = q->element[q->front];
			q->front=(q->front+1) % max;
			return x;
		}
	}
	else printf("Queue is empty!\n");
}
