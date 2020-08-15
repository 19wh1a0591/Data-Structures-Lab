#include<stdio.h>
static int linear_search(int n,int a[50],int target)
{
	static int i,pos;
	if(a[i] == target)
	{
		pos = i;
		return i;
	}
	else if (i<n)
	{
		i++;
		linear_search(a,n,target);
	}
	else
		return -1;
}
int main()
{
	int i,pos,target,n,a[50];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	scanf("%d",&target);
	pos = linear_search(n,a,target);
	if(pos == -1)
	printf("element not present");
	else
	printf("element present at %d location",pos+1);
}