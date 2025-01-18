//Write a C program to display Fibonacci series.

#include<stdio.h>
int main()
{
	int n,i,t1=0,t2=1,nt;
	printf("Enter no. of terms: ");
	scanf("%d",&n);
	for(i=0;i<=n;++i)
	{
		printf("%d ",t1);
		nt=t1+t2;
		t1=t2;
		t2=nt;
	}
	return 0;
}