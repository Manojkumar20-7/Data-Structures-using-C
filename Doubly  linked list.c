#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head=NULL,*tail=NULL;
void insert_begin(int x)
{
	struct node *n=(struct node *)malloc(sizeof(struct node));
	n->data=x;
	n->next=NULL;
	n->prev=NULL;
	if(head==NULL)
		head=tail=n;
	else
	{
		n->next=head;
		head->prev=n;
		head=n;
	}
}
void insert_end(int x)
{
	struct node *n=(struct node *)malloc(sizeof(struct node));
	n->data=x;
	n->next=NULL;
	n->prev=NULL;
	if(head==NULL)
		head=tail=n;
	else
	{
		tail->next=n;
		n->prev=tail;
		tail=n;
	}
}
void delete_begin()
{
	if(head==NULL)
		printf("List is empty");
	else if(head==tail)
		head=tail=NULL;
	else
	{
		struct node *t=head;
		head=head->next;
		head->prev=NULL;
		free(t);
	}
}
void delete_end()
{
	if(head==NULL)
		printf("List is empty");
	else if(head==tail)
		head=tail=NULL;
	else
	{
		struct node *t=tail;
		tail->prev->next=NULL;
		tail=tail->prev;
		free(t);
	}
}
void display()
{
	if(head==NULL)
	{
		printf("List is empty");
		return;
	}
	int x;
	struct node *i;
	printf("1.FORWARD\n2.REVERSE");
	scanf("%d",&x);
	switch(x)
	{
		case 1:
			for(i=head;i!=NULL;i=i->next)
			{
				printf("%d",i->data);
				if(i->next!=NULL)
				{
					printf("->");
				}
			}
			break;
		case 2:
			for(i=tail;i!=NULL;i=i->prev)
			{
				printf("%d",i->data);
				if(i->prev!=NULL)
				{
					printf("<-");
				}	
			}
			break;	
	}
}
int main()
{
	int choice,val;
	while(1)
	{
		printf("\n1.INSERT AT BEGIN\n2.INSERT AT END\n3.DELETE AT BEGIN\n4.DELETE AT END\n5.DISPLAY\n6.EXIT\n");
		printf("Enter the choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the  element:");
				scanf("%d",&val);
				insert_begin(val);
				break;
			case 2:
				printf("Enter the  element:");
				scanf("%d",&val);
				insert_end(val);
				break;
			case 3:
				delete_begin();
				display();
				break;
			case 4:
				delete_end();
				display();
				break;
			case 5:
				display();
				break;
			case 6:
				printf("Thank you :)");
				exit(0);
			default:
				printf("Please, Enter a valid character!");
		}
	}
}
