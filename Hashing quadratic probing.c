#include<stdio.h>
#define m 10
int H[m]={0};
void insert(int key)
{
	int hash=key%m;
	if(H[hash]==0)
		H[hash]=key;
	else
	{
		int i=1,count=0;
		while(count<=m*m)
		{
			hash=(hash+i*i)%m;
			if(H[hash]==0)
			{
				H[hash]=key;
				return;
			}
			i++;
			count++;
		}
	
	}
}
void delete_key(int key)
{
	int hash=key%m;
	if(H[hash]==key)
		H[hash]=0;
	else
	{
		int i=1,count=0;
		while(count<=m*m)
		{
			hash=(hash+i*i)%m;
			if(H[hash]==key)
			{
				H[hash]=0;
				return;
			}
			i++;
			count++;
		}
		printf("Element not found");
	}
}
int search(int key)
{
	int hash=key%m;
	if(H[hash]==key)
		return hash;
	else
	{
		int i=1,count=0;
		while(count<=m*m)
		{
			hash=(hash+i*i)%m;
			if(H[hash]==key)
			{
				return hash;
			}
			i++;
			count++;
		}
		printf("Element not found");
		return -1;
	}
}
int main()
{
	int n,i,val;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&val);
		insert(val);
	}
	for(i=0;i<m;i++)
	{
		printf("%d->%d\n",i,H[i]);
	}
	delete_key(49);
	for(i=0;i<m;i++)
	{
		printf("%d->%d\n",i,H[i]);
	}
	printf("%d",search(58));
}
