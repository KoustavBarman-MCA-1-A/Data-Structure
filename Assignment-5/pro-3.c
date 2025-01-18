#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int cq[MAX];
int front = -1, rear = -1;

int isFull() {
    return (front == (rear + 1) % MAX);
}
int isEmpty() {
    return front == -1;
}
void enqueue(int data) {
    if (isFull())
        printf("Queue is full\n");
	else {
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        cq[rear] = data;
        printf("%d inserted into queue.\n", data);
    }
}
void dequeue() {
    if (isEmpty())
        printf("Queue is empty\n");
	else {
        printf("%d deleted from queue.\n", cq[front]);
        if (front == rear)
            front = rear = -1;
		else
            front = (front + 1) % MAX;
    }
}
void peep() {
    if (isEmpty())
        printf("Queue is empty.\n");
	else
        printf("Front element is %d\n", cq[front]);
}
void display() {
    if (isEmpty())
        printf("Queue is empty.\n");
	else {
        printf("Circular Queue elements: ");
        int i = front;
        while (i != rear) {
            printf("%d ", cq[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", cq[rear]);
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