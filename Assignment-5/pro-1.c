#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int isFull() {
    return rear == MAX - 1;
}
int isEmpty() {
    return front == -1 || front > rear;
}
void enqueue(int data) {
    if (isFull()) {
        printf("Queue is full. Cannot insert element.\n");
    } 
	else {
        if (front == -1) front = 0;
        queue[++rear] = data;
        printf("%d inserted into queue.\n", data);
    }
}
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot delete element.\n");
    } 
	else {
        printf("%d deleted from queue.\n", queue[front]);
        front++;
    }
}
void peep() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } 
	else {
        printf("Front element is %d\n", queue[front]);
    }
}
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } 
	else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
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