#include<stdio.h>
#include<stdlib.h>
#define size 4
int s[size],f=-1,r=-1;
void enqueue(int x)
{
	if(f==-1&&r==-1)
		f=r=0;
	else
		r=r+1;
	s[r]=x;
}
void dequeue()
{
	if(f==-1)
	{
		printf("Queue is Empty");
	}
	else
	{
		f=f+1;
	}
}
void display()
{
	int i;
	for(i=f;i<=r;i++)
	{
		printf("%d ",s[i]);
	}
}
int main()
{
	int choice,n;
	while(1)
	{
		printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
		printf("Enter the Choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter the Element:");
				scanf("%d",&n);
				enqueue(n);
				display();
				break;
			case 2:
				dequeue();
				display();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default:
				printf("Please enter a valid choice");
				break;
		}
	}
}