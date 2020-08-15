#include<stdio.h>
int binary_search(int first ,int last,int a[50],int target)
{
	int pos = -1,mid;
	if(first <= last)
	{
		mid = (first + last) / 2;
		if(a[mid] == target)
		{
			return mid;
		}
		else if(a[mid] > target)
		{
			binary_search(first,mid - 1,a,target);
		}
		else 
			binary_search(mid + 1,last,a,target);
	}
	else
		return -1;
}
int main()
{
	int i,n,target,pos;
	scanf("%d",&n);
	int a[50];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&target);
	pos = binary_search(0,n-1,a,target);
	if(pos == -1)
		printf("element not present");
	else
		printf("element present at %d location",pos+1);
}