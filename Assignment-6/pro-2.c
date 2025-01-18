#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* top = NULL;

void push(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
    printf("%d pushed into stack.\n", data);
}
void pop() {
    if (top == NULL)
        printf("Stack underflow\n");
	else {
        struct Node* temp = top;
        printf("%d popped from stack.\n", top->data);
        top = top->next;
        free(temp);
    }
}
void peek() {
    if (top == NULL)
        printf("Stack is empty.\n");
	else
        printf("Topmost element is %d\n", top->data);
}
void display() {
    if (top == NULL)
        printf("Stack is empty.\n");
	else {
        struct Node* temp = top;
        printf("Stack elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
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