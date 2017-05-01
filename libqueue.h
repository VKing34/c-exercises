#include<stdio.h>
#include<stdlib.h>

typedef struct list{
	elementType element;
	struct list *pre;
	struct list *next;
}node;

int empty(node **head, node **tail)
{
	return ((*head) == NULL);
}
void makenullqueue(node **head, node **tail)
{
	(*head) = NULL;
	(*tail) = NULL;
}

node* makenewnode(elementType e)
{
	node* new = (node*)malloc(sizeof(node));
	new->element = e;
	new->pre = NULL;
	new->next = NULL;
	return new;
}

void enqueue(elementType e,node **head,node **tail)
{
	if(*head == NULL)
	{
		*head = makenewnode(e);
		*tail = *head;
		return;
	}
	node* new = makenewnode(e);
	new->next = *head;
	(*head)->pre = new;
	*head = new;
}


elementType dequeue(node **head, node **tail)
{   
	if(*tail == *head)
	{
		elementType x; x = (*tail)->element;
	    makenullqueue(head,tail);
		return x;
	}
	elementType x = (*tail)->element;
	node *p = *tail;
	*tail = (*tail)->pre;
	(*tail)->next = NULL;
	free(p);
	return x;
	
}

void delfirst(node **head, node **tail)
{
	if(*head == NULL)
	{
		printf("There's nothing to delete!\n");
		return;
	}
	if(*head == *tail)
{
free(*head);
(*head)=NULL;
(*tail)=NULL;
return;
}
	node *p = *head;
	*head = (*head)->next;
	(*head)->pre = NULL;
	free(p);
}

void deltail(node **head, node **tail)
{
	if(*tail == NULL)
	{
		printf("There's nothing to delete!\n");
		return;
	}
	node *p = *tail;
	*tail = (*tail)->pre;
	(*tail)->next = NULL;
	free(p);
}

void delpoint(node **p, node **head, node **tail)
{
	if(*head == *tail)
	{
		free(*p);
		(*head)=NULL;
		(*tail)=NULL;
		return;
	}
	if(*p == *head)
	{
		delfirst(head,tail);
		return;
	}
        if(*p == *tail)
	{
		deltail(head,tail);
		return;
	}
	
	(*p)->pre->next = (*p)->next;
	(*p)->next->pre = (*p)->pre;
	free(*p);
	
}

void delatmid(int order,node **head, node **tail)
{
	if(*tail == NULL)
	{
		printf("There's nothing to delete!!!\n");
		return;
	}
    if(order <= 1)
	{
		deltail(head,tail);
		return;
	}

	node *p = *tail;
	for(int i = 0; i< order -1; i++)
	{
		if(p->next == NULL)
		{
		    delfirst(head,tail);
			return;
		}
		p = p->next;
	}
	p->pre->next = p->next;
	p->next->pre = p->pre;
	free(p);
}

void freeall(node **head)
{
	node *p;
	while(*head != NULL)
	{
		p=*head;
		(*head)=(*head)->next;
		free(p);
	}
}
