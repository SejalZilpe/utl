#include<stdio.h>
#include<stdlib.h>
#define size 7

int is_sorted(int *,int);
void shuffle(int *,int);
void bogosort(int *, int);

int main()
{
	int number[size],i;
	printf("\n enter the element of array : ");
	for(i=0;i<size;i++)
	{
		scanf("%d",&number[i]);
	}
	bogosort(number,size);
	printf("\n The array after sorting is : ");
	for(i=0;i<size;i++)
	{
		printf("%d\n",number[i]);
	}
	printf("\n");
}

int is_sorted(int *a,int n)
{
	while(--n>=1)
	{	
		if(a[n] < a[n-1])
		{
			return 0;
		}
	}
	return 1;
}

void shuffle(int *a,int n)
{
	int i,t,temp;
	for(i=0;i<n;i++)
	{
	t=a[i];
	temp=rand()%n;
	a[i]=a[temp];
	a[temp]=t;
	}
}

void bogosort(int *a,int n)
{
	while(!is_sorted(a,n))
	{
		shuffle(a,n);
	}
}
