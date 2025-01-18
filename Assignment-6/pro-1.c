#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int stack[MAX];
int top = -1;
int isFull() {
    return top == MAX - 1;
}
int isEmpty() {
    return top == -1;
}
void push(int data) {
    if (isFull())
        printf("Stack overflow\n");
	else {
        stack[++top] = data;
        printf("%d pushed into stack.\n", data);
    }
}
void pop() {
    if (isEmpty())
        printf("Stack underflow\n");
	else {
        printf("%d popped from stack\n", stack[top--]);
    }
}
void peek() {
    if (isEmpty())
        printf("Stack is empty.\n");
	else
        printf("Topmost element is %d\n", stack[top]);
}
void display() {
    if (isEmpty())
        printf("Stack is empty.\n");
	else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}
int main() 
{
    int choice, data;
    do {
        printf("1. Push\n2. Pop\n3. Peek (Topmost Element)\n4. Display Stack\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data to push: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);
    return 0;
}