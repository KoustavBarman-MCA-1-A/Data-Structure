#include <stdio.h>
#include <stdlib.h>

struct Node {
 int data;
 struct Node* prev;
 struct Node* next;
};

struct Node* createNode(int data) {
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 newNode->data = data;
 newNode->prev = newNode->next = NULL;
 return newNode;
}
struct Node* createList(struct Node* head, int data) {
 struct Node* newNode = createNode(data);
 if (head == NULL) {
 head = newNode;
 head->next = head;
 head->prev = head;
 } 
 else {
 struct Node* last = head->prev;
 newNode->next = head;
 head->prev = newNode;
 newNode->prev = last;
 last->next = newNode;
 }
 return head;
}

void displayList(struct Node* head) {
 if (head == NULL) {
 printf("List is empty.\n");
 return;
 }
 struct Node* temp = head;
 printf("Circular Doubly Linked List: ");
 do {
 printf("%d ", temp->data);
 temp = temp->next;
 } 
 while (temp != head);
 printf("\n");
}

struct Node* insertAtBeginning(struct Node* head, int data) {
 struct Node* newNode = createNode(data);
 if (head == NULL) {
 head = newNode;
 head->next = head;
 head->prev = head;
 } 
 else {
 struct Node* last = head->prev;
 newNode->next = head;
 newNode->prev = last;
 last->next = newNode;
 head->prev = newNode;
 head = newNode;
 }
 return head;
}

struct Node* insertAtEnd(struct Node* head, int data) {
 struct Node* newNode = createNode(data);
 if (head == NULL) {
 head = newNode;
 head->next = head;
 head->prev = head;
 } 
 else {
 struct Node* last = head->prev;
 newNode->next = head;
 newNode->prev = last;
 last->next = newNode;
 head->prev = newNode;
 }
 return head;
}

struct Node* deleteFromBeginning(struct Node* head) {
 if (head == NULL) {
 printf("List is empty.\n");
 return head;
 }
 if (head->next == head) {
 free(head);
 head = NULL;
 } 
 else {
 struct Node* last = head->prev;
 struct Node* temp = head;
 head = head->next;
 head->prev = last;
 last->next = head;
 free(temp);
 }
 return head;
}

struct Node* deleteFromEnd(struct Node* head) {
 if (head == NULL) {
 printf("List is empty.\n");
 return head;
 }
 if (head->next == head) {
 free(head);
 head = NULL;
 } 
 else {
 struct Node* last = head->prev;
 struct Node* secondLast = last->prev;
 secondLast->next = head;
 head->prev = secondLast;
 free(last);
 }
 return head;
}

struct Node* deleteAfterNode(struct Node* head, int afterData)
{
 if (head == NULL) {
 printf("List is empty.\n");
 return head;
 }
 struct Node* temp = head;
 do {
 if (temp->data == afterData) {
 struct Node* delNode = temp->next;
 if (delNode == head) {
 printf("No node after the last node.\n");
 return head;
 }
 temp->next = delNode->next;
 delNode->next->prev = temp;
 free(delNode);
 return head;
 }
 temp = temp->next;
 } 
 while (temp != head);
 printf("Node with data %d not found.\n", afterData);
 return head;
}

struct Node* deleteEntireList(struct Node* head) {
 if (head == NULL) {
 return head;
 }
 struct Node* temp = head;
 do {
 struct Node* next = temp->next;
 free(temp);
 temp = next;
 } 
 while (temp != head);
 head = NULL;
 return head;
}

int main() 
{
 struct Node* head = NULL;
 int choice, data, key;
 do {
 printf("1. Create a circular doubly linked list\n2. Display the list\n3. Insert a node at the beginning\n4. Insert a node at the end\n5. Delete a node from the beginning\n6. Delete a node from the end\n7. Delete a node after a given node\n8. Delete the entire list\n9. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter data: ");
 scanf("%d", &data);
 head = createList(head, data);
 break;
 case 2:
 displayList(head);
 break;
 case 3:
 printf("Enter data: ");
 scanf("%d", &data);
 head = insertAtBeginning(head, data);
 break;
 case 4:
 printf("Enter data: ");
 scanf("%d", &data);
 head = insertAtEnd(head, data);
 break;
 case 5:
 head = deleteFromBeginning(head);
 break;
 case 6:
 head = deleteFromEnd(head);
 break;
 case 7:
 printf("Enter the node after which to delete: ");
 scanf("%d", &key);
 head = deleteAfterNode(head, key);
 break;
 case 8:
 head = deleteEntireList(head);
 printf("List deleted.\n");
 break;
 case 9:
 printf("Exiting...\n");
 break;
 default:
 printf("Invalid choice! Please try again.\n");
 }
 } 
 while (choice != 9);
 return 0;
}