//Write a C program to sort an array.

#include<stdio.h>
int main()
{
	int arr[50],n,i,j,temp;
	printf("Enter array size: ");
	scanf("%d",&n);
	printf("Enter %d array elements:\n",n);
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("Sorted array:\n");
	for(i=0;i<n;i++)
	printf("%d ",arr[i]);
	return 0;
}