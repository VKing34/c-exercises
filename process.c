

typedef struct program{
	char name[24];
	int ram;
	int id;
}program;

typedef program elementType;

#include"libqueue.h"

node *head1, *tail1; // waiting
node *head2, *tail2; // running


int maxram;           // memory capacity
int n;               // the number of parallel process OS can run
int count=0;           // the number of programs running
int order;             // count the processes

         


elementType input()
{
	elementType e;
	printf(" + Program's name: "); scanf("%s",e.name);
	printf(" + Necessary memory (MB): "); scanf("%d", &e.ram);
	printf(" + ID: "); scanf("%d",&e.id);
	return e;
}

int running(node **head2, node **tail2) // currently ram using
{
	if(*head2 == NULL)
		return 0;
	int sum=0;
	node *p = *head2;
	while(p != NULL)
	{
		sum += p->element.ram;
		p = p->next;
	}
	return sum;
}


void turn(node **head1, node **tail1, node **head2, node **tail2)
{
	
	if(empty(head1,tail1))
		return;
	if((*tail1)->element.ram + running(head2,tail2) <= maxram && count <= n-1)
	{
		enqueue(dequeue(head1,tail1),head2,tail2);
		count++;
	}
}

void show(node **tail1, node **tail2)
{
	order = 0;
	printf("<> Process(es) running: \n");
	if(*tail2 == NULL)
		printf("   No process is running!!!\n");
	else {
		node *p = *tail2;
		while ( p != NULL)
		{
			order++;
			printf(" %d. %s - %d (MB) - ID: %d\n",order, p->element.name, p->element.ram, p->element.id);
			p = p->pre;
		    
		}
		
	}
	printf("-------------------------------------------\n");
	printf("<> Process(es) waiting :\n");
	if(*tail1 == NULL)
		printf("   No process is waiting!!!\n");
	else
	{
		node *m = *tail1;
		while ( m != NULL)
		{
			order++;
			printf(" %d. %s - %d (MB) - ID: %d\n",order, m->element.name, m->element.ram, m->element.id);
			m = m->pre;
	    
		}
	}
}

void kill(node **head1, node **tail1, node **head2, node **tail2)
{
	int did;
	node *killp;
	printf("Enter ID: "); scanf("%d", &did);
	killp = *head2;
	while(killp !=NULL)
	{
		if(killp->element.id == did)
		{
			count--;
			delpoint(&killp,head2,tail2);
			printf("-----------------------Successful---------------------\n");
			return;
		}
		killp = killp->next;
	}
	killp = *head1;
	while(killp !=NULL)
	{
		if(killp->element.id == did)
		{
			delpoint(&killp,head1,tail1);
			printf("-----------------------Successful---------------------\n");
		return;
		}
		killp = killp->next;
	}
	printf("Wrong ID!!! Please try agian!!\n");
    
}


void main()
{
	while(n <= 0)
	{
		printf("Enter the number of parallel process OS can run: "); scanf("%d", &n);
		if(n<=0)
		{
			printf("The number must be greater than 0!!!\n");
		}
	}
	while(maxram <= 0)
	{
		printf("Enter the memory capacity (MB): "); scanf("%d", &maxram);
		if(maxram <= 0)
		{
			printf("The memory capacity must be greater than 0 MB!!!\n");
		}
	}
	int x;
	while(x!=4)
	{
		printf("--------------------------------------------------------\n");
		printf("\t \t \t Processes\n");
		printf("--------------------------------------------------------\n");
		printf("1. Create a new program\n2. Kill a program\n3. Show processes\n4. Exit\nChoose one option: "); scanf("%d", &x);
		switch (x) {
		case 1: {
			enqueue(input(),&head1,&tail1);
			turn(&head1,&tail1,&head2,&tail2);
			printf("-----------------------Successful---------------------\n");
			break;
		}
		case 2:
			
	
			kill(&head1,&tail1,&head2,&tail2);
			turn(&head1,&tail1,&head2,&tail2);
	    
			break;
		case 3:
			show(&tail1,&tail2);
			break;
		case 4:
			break;
		default:
			printf("Enter 1, 2, 3 or 4\nPlease try again!!!\n");
			break;
			
		}
	}
	freeall(&head1);
	freeall(&head2);
}
