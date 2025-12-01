#include<stdio.h>
#include<conio.h>
int tsize;
int hasht(int key)
{
	int i;
	i=key%tsize;
	return i;
}
int rehashq(int key,int j)
{
	int i;
	i=(key+(j*j))%tsize;
	return i;
}
void main()
{
	int key,arr[20],hash[20],i,n,s,op,j,k;
	printf("enter the size of the hash table:");
	scanf("%d",&tsize);
	printf("\n enter the number of elements:");
	scanf("%d",&n);
	for(i=0;i<tsize;i++)
	hash[i]=-1;
}
	printf("enter elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",arr[i]);
	}
	for(k=0;k<n;k++)
	{
		j=1;
		key=arr[k];
		i=hasht(key);
		while(hash[i]!=-1)
		{
			i=rehashq(i,j);
	    j++;		}		hash[i]=key;
	}
	printf("\n the elements in the array are:");
	for(i=0;i<tsize;i++)
	{
		printf("\n elements at poistion%d:%d",i,hash[i]);
	}
