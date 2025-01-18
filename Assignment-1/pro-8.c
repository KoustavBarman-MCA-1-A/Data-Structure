//Write a C program to check the sum of all elements of an array.

#include<stdio.h>
int main()
{
	int i,s=0,n,arr[]={1,2,3,4,5};
	n=sizeof(arr)/sizeof(arr[0]);
	for(i=0;i<n;i++)
	s+=arr[i];
	printf("Sum of all array elements is: %d ",s);
	return 0;
}