
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;

int isEmpty() {
    return front == NULL;
}
void enqueue(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (rear == NULL)
        front = rear = newNode;
	else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d inserted into queue.\n", data);
}
void dequeue() {
    if (isEmpty())
        printf("Queue is empty. Cannot delete element.\n");
	else {
        struct Node* temp = front;
        printf("%d deleted from queue.\n", front->data);
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        free(temp);
    }
}
void peep() {
    if (isEmpty())
        printf("Queue is empty.\n");
	else
        printf("Front element is %d\n", front->data);
}
void display() {
    if (isEmpty())
        printf("Queue is empty.\n");
	else {
        struct Node* temp = front;
        printf("Queue elements: ");
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
        printf("1. Enqueue\n2. Dequeue\n3. Peep (Front Element)\n4. Display Queue\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peep();
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
