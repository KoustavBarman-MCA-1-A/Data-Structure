#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}
int pop() {
    return stack[top--];
}
int evaluatePostfix(char* exp) {
    char* e = exp;
    int num1, num2;
    while (*e != '\0') {
        if (isdigit(*e)) {
            push(*e - '0');
        } 
		else {
            num2 = pop();
            num1 = pop();
            switch (*e) {
                case '+': push(num1 + num2); break;
                case '-': push(num1 - num2); break;
                case '*': push(num1 * num2); break;
                case '/': push(num1 / num2); break;
            }
        }
        e++;
    }
    return pop();
}
int main() 
{
    char exp[MAX];
    printf("Enter the postfix expression: ");
    scanf("%s", exp);
    printf("Result: %d\n", evaluatePostfix(exp));
    return 0;
}