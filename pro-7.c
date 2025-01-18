//Write a C program to reverse array.

#include<stdio.h>
int main()
{
	int i,s,temp,arr[]={1,2,3,4,5};
	s=sizeof(arr)/sizeof(arr[0]);
	printf("Original Array:\n");
	for(i=0;i<s;i++)
	printf("%d ",arr[i]);
	for(i=0;i<s/2;i++)
	{
		temp=arr[i];
		arr[i]=arr[s-1-i];
		arr[s-1-i]=temp;
	}
	printf("\nReversed Array:\n");
	for(i=0;i<s;i++)
	printf("%d ",arr[i]);
	return 0;
}