#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ID_LENGTH 9
#define NAME_LENGTH 25


typedef struct student
{
	char id[ID_LENGTH];
	char name[NAME_LENGTH];
	float grade;
}student;

typedef student elementType;
typedef struct {
	struct node* pre;
	elementType element;
	struct node* next;
}node;

typedef node** doublelist;

doublelist *head1, *tail1, *head2, *tail2;


void makeNULL(doublelist *head)
{
	(*head) = NULL;
}

int empty(doublelist head)
{
	return (head == NULL);
}

node* makenewnode(elementType e)
{
	node* new = (node*)malloc(sizeof(node));
	new->element = e;
	new->pre = NULL;
	new->next = NULL;
	return new;
}

void insertAtHead(elementType e,doublelist head, doublelist tail)
{
	if(head == NULL)
	{
		head = makenewnode(e);
		tail = head;
		return;
	}
	node* new = makenewnode(e);
	new->next = head;
	head->pre = new;
	head = new;
}

void insertAtTail(elementType e, doublelist head, doublelist tail)
{
	if(tail == NULL)
	{
		tail = makenewnode(e);
		head = tail;
		return;
	}
	node* new = makenewnode(e);
	new->pre = tail;
	tail->next = new;
	tail = new;
}

void insertAtMid(elementType e, doublelist head, doublelist tail)
{
	int order;
input:
	{
		printf("Enter the position you want to insert: "); scanf("%d", &order);
	}
	if(head == NULL || order == 0)
	{
		insertAtHead(e,&head,&tail);
		return;
	}
		
	node *p = head;
	for(int i = 0; i< order -1; i++)
	{
		if(p == NULL)
		{
			printf("Invalid number!!!\n");
			goto input;
		}
		p = p->next;
	}
	node* new = makenewnode(e);
	new->next = p->next;
	p->next->pre = new;
	new->pre = p;
	p->next = new;
	
}

void delfirst(doublelist head, doublelist tail)
{
	if(head == NULL)
	{
		printf("There's nothing to delete!\n");
		return;
	}
	node *p = head;
	head = head->next;
	head->pre = NULL;
	free(p);
}

void deltail(doublelist head, doublelist tail)
{
	if(tail == NULL)
	{
		printf("There's nothing to delete!\n");
		return;
	}
	node *p = tail;
	tail = tail->pre;
	*tail->next = NULL;
	free(p);
}

void delposition(doublelist head, doublelist tail){
	if(head == NULL)
	{
	    printf("There's nothing to delete!\n");
		return;
	}
	int order;
	printf("Enter the position you want to delete: "); scanf("%d", &order);
 
	if(order == 0)
	{
		delfirst(&head,&tail);
		return;
	}
	node *p = head;
	for(int i=0; i< order;i++)
	{
		if(p->next == NULL)
		{
			deltail(&head,&tail);
			return;
		}
		p = p->next;
	}
	if(p == head)
	{
		delfirst(&head,&tail);
		return;
	}
	p->pre->next = p->next;
	p->next->pre = p->pre;
	free(p);
}

void import()
{
	FILE *fin;
	if((fin = fopen("grade.txt", "r")) == NULL)
	{
		printf("Can't open grade.txt!!!\n");
		return;
	}
	student e;
	while(fin != EOF)
	{
		fscanf("%s %s %f", e.name, e.id, &e.grade);
	    if(e.grade > 8)
		{
			insertAtTail(e,&head1,&tail1);
		}
		else {
			insertAtTail(e,&head2,&tail2);
		}
	}
	fclose(fin);
}

void add()
{
	student e;
	printf(" + Name: "); scanf("%s", e.name);
	printf(" + ID: "); scanf("%s", e.id);
	printf(" + Grade: "); scanf("%f", &e.grade);
	if(e.grade > 8)
		{
			insertAtTail(e,&head1,&tail1);
		}
	else {
		insertAtTail(e,&head2,&tail2);
	}
}

void move()
{
	
}

void show1()
{
	if(*head1 == NULL)
	{
		printf("There's nothing to display!!!\n");
		return;
	}
	node *p = *head1;
	int i = 1;
	while(p != NULL)
	{
		printf("%d. %s - %s - %.2f\n",i,p->element.name, p->element.id, p->element.grade);
		i++;
		p = p->next;
	}
}

void show2()
{
	if(*head2 == NULL)
	{
		printf("There's nothing to display!!!\n");
		return;
	}
	node *p = *head2;
	int i = 1;
	while(p != NULL)
	{
		printf("%d. %s - %s - %.2f\n",i,p->element.name, p->element.id, p->element.grade);
		i++;
		p = p->next;
	}
}

void concatenate()
{
	
}

void sort()
{
	
}

void main()
{
	int x=0;
	while(x != 8)
	{
		printf("------------------------------------------------\n");
		printf("\t \t  Grade\n");
		printf("------------------------------------------------\n");
		printf("1. Import from grade.txt\n");
		printf("2. Add a student\n");
		printf("3. Move students (7.5)\n");
		printf("4. Show List 1\n");
		printf("5. Show List 2\n");
		printf("6. Concatenate\n");
		printf("7. Concatenate and sort (grade)\n");
		printf("8. Quit\n");
		printf("Choose one option: "); scanf("%d", &x);
		switch (x) {
		case 1: {
			import();
			break;
		}
		case 2:
			add();
			break;
		case 3:
			move();
			break;
		case 4:
			show1();
			break;
		case 5:
			show2();
			break;
		case 6:
			concatenate();
			break;
		case 7:
			concatenate();
			sort();
			break;
		case 8:
			break;
		default:
			printf("Wrong input !!! Please try agian\n");
			break;
		}
	}
}
