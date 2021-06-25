#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node* makeNode();
void createList(int n);
struct node* Insertbeg(struct node *start);
struct node* Addend(struct node *start);
struct node* Addbefore(struct node* start);
struct node* Addafter(struct node* start);
struct node* Delbeg(struct node *start);
struct node* Delend(struct node *start);
struct node* Delbefore(struct node *start);
struct node* Delafter(struct node *start);
void display();

struct node *start=NULL;

int main()
{
	int opt,n;
	while ( opt!=11 )
	{
		printf(" \n OPTIONS \n");
		printf(" ------- \n");
		printf(" 1. createList \n");
		printf(" 2. Insertbeg \n");
		printf(" 3. Addend \n");
		printf(" 4. Addbefore \n");
		printf(" 5. Addafter \n");
		printf(" 6. Delbeg \n");
		printf(" 7. Delend \n");
		printf(" 8. Delbefore \n");
		printf(" 9. Delafter \n");
		printf(" 10. Display \n\n");
		printf(" Enter your option : ");
		scanf("%d",&opt);
	
		switch(opt)
	
		{
			case 1:
				printf(" Enter the size of the linklist : ");
				scanf("%d",&n);
				createList(n);
				break;
				
			case 2:
				Insertbeg(start);
				break;
				
			case 3:
				Addend(start);
				break;
				
			case 4:
				Addbefore(start);
				break;
				
			case 5:
				Addafter(start);
				break;
				
			case 6:
				Delbeg(start);
				break;
				
			case 7:
				Delend(start);
				break;
				
			case 8:
				Delbefore(start);
				break;
				
			case 9:
				Delafter(start);
				break;
				
			case 10:
				display();
				break;									
		}
	}
		getch();
	
	return 0;
}

void createList(int n)
{
	int i;
	struct node *NewNode;
	struct node *temp;
	
	for ( i=0; i<n; i++ )
	{
		NewNode = makeNode();
		if ( start==NULL )
		{
			start=NewNode;
		}
		else
		{
			temp=start;
			while ( temp->next!=NULL )
			{
				temp=temp->next;
				temp->next=NewNode;
			}
		}
	}
}

struct node* makeNode()
{
	struct node *NewNode;
	NewNode=(struct node*)malloc(sizeof(struct node));
	printf(" Enter data : ");
	scanf("%d",&NewNode->data);
	NewNode->next=NULL;
	return NewNode;
}

struct node* Insertbeg(struct node *start)
{
	struct node *NewNode;
	NewNode=(struct node*)malloc(sizeof(struct node));
	printf(" Enter the data : ");
	scanf("%d",&NewNode->data);
	NewNode->next=start;
	start=NewNode;
	return start;
}

struct node* Addend(struct node *start)
{
	int num;
	struct node *NewNode,*ptr;
	NewNode=(struct node*)malloc(sizeof(struct node));
	printf(" Enter the data : ");
	scanf("%d",&num);
	NewNode->data = num;
	NewNode->next = NULL;
	ptr = start;
	while ( ptr->next != NULL )
	{
		ptr = ptr->next;
		ptr->next = NewNode;
	}
	return start;
}

struct node* Addbefore(struct node* start)
{
	int num,val;
	struct node *NewNode,*ptr,*preptr;
	printf(" Enter the value before which the data has to be added : ");
	scanf("%d",&val);
	printf(" Enter the data : ");
	scanf("%d",&num);
	NewNode=(struct node*)malloc(sizeof(struct node));
	NewNode->data = num;
	ptr=start;
	while( ptr->data != val )
	{
		preptr = ptr;
		ptr = ptr->next;
	}
	preptr->next = NewNode;
	NewNode->next = ptr;
	return start;
}

struct node* Addafter(struct node* start)
{
	int num,val;
	struct node *NewNode,*ptr,*preptr;
	printf(" Enter the value after which the data has to be added : ");
	scanf("%d",&val);
	printf(" Enter the data : ");
	scanf("%d",&num);
	NewNode=(struct node*)malloc(sizeof(struct node));
	NewNode->data = num;
	ptr=start;
	preptr=ptr;
	while( ptr->data != val )
	{
		preptr = ptr;
		ptr = ptr->next;
	}
	preptr->next = NewNode;
	NewNode->next = ptr;
	return start;
}

struct node* Delbeg(struct node *start)
{
	struct node *ptr;
	ptr=start;
	start=start->next;
	free(ptr);
	return start;
}

struct node* Delend(struct node *start)
{
	struct node *ptr,*preptr;
	ptr=start;
	while ( ptr->next!=NULL )
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=NULL;
	return start;
}

struct node* Delbefore(struct node *start)
{
	struct node *ptr,*preptr;
	int val;
	printf(" Enter the Value of the node which has to be deleted : ");
	scanf("%d",&val);
	ptr=start;
	while ( ptr->data!=val )
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
	return start;
}

struct node* Delafter(struct node *start)
{
	struct node *ptr,*preptr;
	int val;
	printf(" Enter the Value of the node which has to be deleted : ");
	scanf("%d",&val);
	ptr=start;
	preptr=ptr;
	while ( ptr->data!=val )
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
	return start;
}

void display()
{
	struct node *ptr;
	if ( start==NULL )
	{
		printf(" List is empty ");
	}
	else
	{
		ptr = start;
		while ( ptr!=NULL )
		{
			printf("%d\t",ptr->data);
			ptr = ptr->next;
		}
	}
}

