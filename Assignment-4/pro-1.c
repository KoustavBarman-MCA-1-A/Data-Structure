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
 newNode->prev = NULL;
 newNode->next = NULL;
 return newNode;
}

struct Node* createList(struct Node* head, int data) {
 struct Node* newNode = createNode(data);
 if (head == NULL) {
 head = newNode;
 } 
 else {
 struct Node* temp = head;
 while (temp->next != NULL) {
 temp = temp->next;
 }
 temp->next = newNode;
 newNode->prev = temp;
 }
 return head;
}

void displayList(struct Node* head) {
 if (head == NULL) {
 printf("List is empty.\n");
 return;
 }
 struct Node* temp = head;
 printf("Doubly Linked List: ");
 while (temp != NULL) {
 printf("%d ", temp->data);
 temp = temp->next;
 }
 printf("\n");
}

struct Node* insertAtBeginning(struct Node* head, int data) {
 struct Node* newNode = createNode(data);
 if (head == NULL) {
 head = newNode;
 } 
 else {
 newNode->next = head;
 head->prev = newNode;
 head = newNode;
 }
 return head;
}

struct Node* insertAtEnd(struct Node* head, int data) {
 struct Node* newNode = createNode(data);
 if (head == NULL) {
 head = newNode;
 } 
 else {
 struct Node* temp = head;
 while (temp->next != NULL) {
 temp = temp->next;
 }
 temp->next = newNode;
 newNode->prev = temp;
 }
 return head;
}

struct Node* insertBeforeNode(struct Node* head, int
beforeData, int data) {
 struct Node* newNode = createNode(data);
 struct Node* temp = head;
 while (temp != NULL && temp->data != beforeData) {
 temp = temp->next;
 }
 if (temp == NULL) {
 printf("Node with data %d not found.\n", beforeData);
 } else {
 newNode->next = temp;
 newNode->prev = temp->prev;
 if (temp->prev != NULL) {
 temp->prev->next = newNode;
 } else {
 head = newNode;
 }
 temp->prev = newNode;
 }
 return head;
}

struct Node* insertAfterNode(struct Node* head, int afterData,
int data) {
 struct Node* newNode = createNode(data);
 struct Node* temp = head;
 while (temp != NULL && temp->data != afterData) {
 temp = temp->next;
 }
 if (temp == NULL) {
 printf("Node with data %d not found.\n", afterData);
 } 
 else {
 newNode->next = temp->next;
 newNode->prev = temp;
 if (temp->next != NULL) {
 temp->next->prev = newNode;
 }
 temp->next = newNode;
 }
 return head;
}

struct Node* deleteFromBeginning(struct Node* head) {
 if (head == NULL) {
 printf("List is empty.\n");
 return head;
 }
 struct Node* temp = head;
 head = head->next;
 if (head != NULL) {
 head->prev = NULL;
 }
 free(temp);
 return head;
}

struct Node* deleteFromEnd(struct Node* head) {
 if (head == NULL) {
 printf("List is empty.\n");
 return head;
 }
 struct Node* temp = head;
 while (temp->next != NULL) {
 temp = temp->next;
 }
 if (temp->prev != NULL) {
 temp->prev->next = NULL;
 } 
 else {
 head = NULL;
 }
 free(temp);
 return head;
}

struct Node* deleteAfterNode(struct Node* head, int afterData)
{
 struct Node* temp = head;
 while (temp != NULL && temp->data != afterData) {
 temp = temp->next;
 }
 if (temp == NULL || temp->next == NULL) {
 printf("Node with data %d not found or no node to delete after.\n", afterData);
 } 
 else {
 struct Node* delNode = temp->next;
 temp->next = delNode->next;
 if (delNode->next != NULL) {
 delNode->next->prev = temp;
 }
 free(delNode);
 }
 return head;
}

struct Node* deleteEntireList(struct Node* head) {
 struct Node* temp = head;
 while (head != NULL) {
 temp = head;
 head = head->next;
 free(temp);
 }
 return head;
}
int main() 
{
 struct Node* head = NULL;
 int choice, data, key;
 do {
 printf("1. Create a doubly linked list\n2. Display the list\n3. Insert a node at the beginning\n4. Insert a node at the end\n5. Insert a node before a given node\n6. Insert a node after a given node\n7. Delete a node from the beginning\n8. Delete a node from the end\n9. Delete a node after a given node\n10. Delete the entire list\n11. Exit\n");
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
 printf("Enter the node before which to insert: ");
 scanf("%d", &key);
 printf("Enter data to insert: ");
 scanf("%d", &data);
 head = insertBeforeNode(head, key, data);
 break;
 case 6:
 printf("Enter the node after which to insert: ");
 scanf("%d", &key);
 printf("Enter data to insert: ");
 scanf("%d", &data);
 head = insertAfterNode(head, key, data);
 break;
 case 7:
 head = deleteFromBeginning(head);
 break;
 case 8:
 head = deleteFromEnd(head);
 break;
 case 9:
 printf("Enter the node after which to delete: ");
 scanf("%d", &key);
 head = deleteAfterNode(head, key);
 break;
 case 10:
 head = deleteEntireList(head);
 printf("List deleted.\n");
 break;
 case 11:
 printf("Exiting...\n");
 break;
 default:
 printf("Invalid choice! Please try again.\n");
 }
 } while (choice != 11);
 return 0;
}