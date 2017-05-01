
#define ID_LENGTH 9
#define NAME_LENGTH 25


typedef struct student
{
	char id[ID_LENGTH];
	char name[NAME_LENGTH];
	float grade;
}student;

typedef student elementType;
#include"lib.h"

node *head1,*tail1;
node *head2,*tail2;

void show(node **head)
{
	if(*head == NULL)
	{
		printf("There's nothing to display!!!\n");
		return;
	}
	node *p = *head;
	int i=1;
	while(p != NULL)
	{
		printf("%d. %s - %s - %.2f\n",i,p->element.name, p->element.id, p->element.grade);
		i++;
		p = p->next;
	}
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
	while(fscanf(fin,"%s %s %f", e.name, e.id, &e.grade) != EOF)
	{
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

elementType input()
{
	elementType e;
	printf(" + Name: "); scanf("%s", e.name);
	printf(" + ID: "); scanf("%s", e.id);
	printf(" + Grade: "); scanf("%f", &e.grade);
	return e;
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
	node *p = head2;
    
	while(p != NULL)
	{
		if(p->element.grade == 7.5 && p == head2)
		{
			head2 = head2->next;
			head2->pre = NULL;
			node *tmp =p;
			p= p->next;
			tmp->pre =tail1;
			tail1->next = tmp;
			tmp->next = NULL;
			tail1= tmp;
		}
		else if(p->element.grade == 7.5 && p->next == NULL)
		{
			tail2 = tail2->pre;
			tail2->next =NULL;
			node *tmp =p;
			p= p->next;
			tmp->pre=tail1;
			tail1->next =tmp;
			tmp->next=NULL;
		   	tail1=tmp;
		}
		else if(p->element.grade == 7.5)
		{
		    
			p->pre->next = p->next;
			p->next->pre = p->pre;
		    node *tmp =p;
			p = p->next;
			tmp->pre=tail1;
			tail1->next =tmp;
			tmp->next=NULL;
			tail1=tmp;
		}
		else
		{
			p = p->next;
		}
	}
}

void concatenate()
{
	head2->pre = tail1;
	tail1->next = head2;
	tail1 = tail2;
}

int count(node **head)
{
	node *p = *head;
	int i =0;
	while (p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}

void swap(elementType* a, elementType* b)
{
	elementType t = *a;
	*a = *b;
	*b = t;
}

void sort()
{
	node *p1, *p2;
	int i,j;
	elementType tmp;
	p1 = p2 = head1;

	for(i = 0; i< count(&head1); i++)
	{
		tmp = p1->element;
		for (j = 0; j< i; j++)
			p2 = p2->next;
		for (j= i; j>0 && p2->pre->element.grade < tmp.grade; j--)
		{
			p2->element = p2->pre->element;
			p2 = p2->pre;
		}
		p2->element = tmp;
		p2 = head1;
		p1 = p1->next;
	}
}


void main()
{
	int x=0,y;
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
			show(&head1);
			break;
		case 5:
			show(&head2);
			break;
		case 6:
			concatenate();
			y = 1;
			break;
		case 7:
			while(y !=1)
			{
				concatenate();
			}
			sort();
			break;
		case 8:
			break;
		default:
			printf("Wrong input !!! Please try agian\n");
			break;
		}
	}
	freeall(&head1);
	freeall(&head2);
}
				
