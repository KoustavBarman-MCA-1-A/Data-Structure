#include<stdio.h>
int main()
{
	int i,s,arr[]={1,2,3,4,5};
	s=sizeof(arr)/sizeof(arr[0]);
	printf("The array is:\n");
	for(i=0;i<s;i++)
	printf("%d ",arr[i]);
	return 0;
}