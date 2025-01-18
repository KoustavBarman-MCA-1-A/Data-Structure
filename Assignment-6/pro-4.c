#include <stdio.h>
#include <string.h>
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
void reverse(char* exp) {
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[len - i - 1];
        exp[len - i - 1] = temp;
    }
}
void infixToPrefix(char* exp) {
    reverse(exp);
    char* e = exp;
    printf("Prefix expression: ");
    while (*e != '\0') {
        if (isalnum(*e))
            printf("%c", *e);
        else if (*e == ')')
            push(*e);
        else if (*e == '(') {
            while (stack[top] != ')')
                printf("%c", pop());
            pop();
        } 
		else {
            while (precedence(stack[top]) >= precedence(*e))
                printf("%c", pop());
            push(*e);
        }
        e++;
    }
    while (top != -1)
        printf("%c", pop());
    reverse(exp);
    printf("\n");
}
int main() 
{
    char exp[MAX];
    printf("Enter the infix expression: ");
    scanf("%s", exp);
    infixToPrefix(exp);
    return 0;
}