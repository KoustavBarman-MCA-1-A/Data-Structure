#include <stdio.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}
char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}
int precedence(char x) {
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}
void infixToPostfix(char* exp) {
    char* e, x;
    e = exp;
    printf("Postfix expression: ");
    while (*e != '\0') {
        if (isalnum(*e))
            printf("%c", *e);
        else if (*e == '(')
            push(*e);
        else if (*e == ')') {
            while ((x = pop()) != '(')
                printf("%c", x);
        } 
		else {
            while (precedence(stack[top]) >= precedence(*e))
                printf("%c", pop());
            push(*e);
        }
        e++;
    }
    while (top != -1) {
        printf("%c", pop());
    }
    printf("\n");
}
int main() 
{
    char exp[MAX];
    printf("Enter the infix expression: ");
    scanf("%s", exp);
    infixToPostfix(exp);
    return 0;
}