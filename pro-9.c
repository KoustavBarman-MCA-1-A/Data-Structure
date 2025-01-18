//Write a C program to check duplicate number in array.

#include<stdio.h>
int main()
{
	int arr[50],n,i,j,dup=0;
	printf("Enter array size: ");
	scanf("%d",&n);
	printf("Enter %d array elements:\n",n);
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i]==arr[j])
			{
				dup=1;
				printf("Duplicate found: %d\n",arr[i]);
				break;
			}
		}
		if(dup)
		break;
	}
	if(!dup)
	printf("No duplicates found");
	return 0;
}