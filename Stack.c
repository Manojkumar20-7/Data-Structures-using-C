#include<stdio.h>
#define size 10
int s[size],top=-1;
void push(int x)
{
	if(top==size-1)
		printf("Overflow");
	else
	{
		top++;
		s[top]=x;
	}
}
int pop()
{
	int x;
	if(top==-1)
		printf("Underflow");
	else
	{
		x=s[top];
		top--;
		return x;
	}
}
int peak()
{
	int x;
	if(top==-1)
		printf("Underflow");
	else
	{
		x=s[top];
		return x;
	}
}
void display()
{
	int i;
	for(i=top;i>=0;i--)
	{
		printf("%d ",s[i]);
	}
}
int main()
{
	int choice,n;
	while(1)
	{
		printf("\n1.PUSH\n2.POP\n3,PEAK\n4.DISPLAY\n5.EXIT");
		printf("\nEnter the Choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the Number:");
				scanf("%d",&n);
				push(n);
				break;
			case 2:
				printf("%d is poped out",pop());
				break;
			case 3:
				printf("%d is the peak value",peak());
				break;
			case 4:
				display();
				break;
			case 5:
				printf("Thank you :)");
				exit(0);
			deafult:
				printf("Please Enter the Valid Choice");
		}
	}
		return 0;
}
