#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL,*tail=NULL;
void insert_begin(int x)
{
	struct node *n=(struct node *)malloc(sizeof(struct node));
	n->data=x;
	n->next=NULL;
	if(head==NULL)
		head=tail=n;
	else
	{
		n->next=head;
		head=n;
		
	}
}
void insert_end(int x)
{
	struct node *n=(struct node *)malloc(sizeof(struct node));
	n->data=x;
	n->next=NULL;
	if(head==NULL)
		head=tail=n;
	else
	{
		tail->next=n;
		tail=n;
	}
}
void delete_begin()
{
	if(head==NULL)
		printf("List is empty");
	else if(head==tail)
	{
		struct node *t=head;
		head=tail=NULL;
		free(t);
	}
	else
	{
		struct node *t=head;
		head=head->next;
		free(t);
	}
}
void delete_end()
{
	if(head==NULL)
		printf("List is empty");
	else if(head==tail)
	{
		struct node *t=head;
		head=tail=NULL;
		free(t);
	}
	else
	{
		struct node *i,*t=tail;
		for(i=head;i->next->next!=NULL;i=i->next);
		i->next=NULL;
		tail=i;
		free(t);
	}
}
void  display()
{
	if(head==NULL)
		printf("List is empty");
	else
	{
		struct node *i;
		for(i=head;i!=NULL;i=i->next)
		{
			printf("%d",i->data);
			if(i->next!=NULL)
				printf("->");
		}
	}
}
void fun1(struct node *head)
{
	if(head==NULL)
		return;
	fun1(head->next);
	printf("%d ",head->data);
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