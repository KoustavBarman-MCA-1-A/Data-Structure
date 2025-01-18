//Write a C program to print the largest and second largest element of the array.

#include<stdio.h>
int main()
{
	int arr[50],n,i,lar,slar;
	printf("Enter array size: ");
	scanf("%d",&n);
	printf("Enter %d array elements:\n",n);
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	if(arr[0]>arr[1])
	{
		lar=arr[0];
		slar=arr[1];
	}
	else
	{
		lar=arr[1];
		slar=arr[0];
	}
	for(i=2;i<n;i++)
	{
		if(arr[i]>lar)
		{
			slar=lar;
			lar=arr[i];
		}
		else if(arr[i]>slar&&arr[i]!=lar)
		slar=arr[i];
	}
	printf("Largest element: %d\n",lar);
	printf("Second largest element: %d\n",slar);
	return 0;
}