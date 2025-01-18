//Write a C program to check wheather a given string is Palindrome or not.

#include<stdio.h>
#include<string.h>
int main()
{
	int len,i,pal=1;
	char str[50],revstr[50];
	printf("Enter a string: ");
	gets(str);
	len=strlen(str);
	for(i=0;i<len;i++)
		revstr[i]=str[len-i-1];
	revstr[len]='\0';
	for(i=0;i<len;i++)
	{
		if(str[i]!=revstr[i])
		{
			pal=0;
			break;
		}
	}
	if(pal)
	printf("Palindrome String");
	else
	printf("Not a Palindrome String");
	return 0;
}