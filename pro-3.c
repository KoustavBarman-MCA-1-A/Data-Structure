//Write a C program to convert temperature from degree Centigrade to Fahrenheit.

#include<stdio.h>
int main()
{
	float c,fa;
	printf("Enter temperature in Centigrade: ");
	scanf("%f",&c);
	fa=(c*9/5)+32;
	printf("Temperature in Fahrenheit: %f",fa);
	return 0;
}