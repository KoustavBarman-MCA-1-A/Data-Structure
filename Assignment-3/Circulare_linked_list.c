#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* last = NULL;

// Function prototypes
void createList(int n);
void displayList();
void insbeg(int data);
void insend(int data);
void delbeg();
void delend();
void delaft(int adata);
void dellist();

int main() {
    int choice, data, n, adata;

    while(1) {
        printf("\nMenu:\n");
        printf("1. Create a circular linked list\n");
        printf("2. Display the elements of the list\n");
        printf("3. Insert a node at the beginning\n");
        printf("4. Insert a node at the end\n");
        printf("5. Delete a node from the beginning\n");
        printf("6. Delete a node from the end\n");
        printf("7. Delete a node after a given node\n");
        printf("8. Delete the entire list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2:
                displayList();
                break;
            case 3:
                printf("Enter the data to insert at the beginning: ");
                scanf("%d", &data);
                insbeg(data);
                break;
            case 4:
                printf("Enter the data to insert at the end: ");
                scanf("%d", &data);
                insend(data);
                break;
            case 5:
                delbeg();
                break;
            case 6:
                delend();
                break;
            case 7:
                printf("Enter the data of the node after which to delete: ");
                scanf("%d", &adata);
                delaft(adata);
                break;
            case 8:
                dellist();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to create a circular linked list
void createList(int n) {
    int data;
    struct Node *newNode, *temp;

    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if(!newNode) {
            printf("Memory allocation error!\n");
            return;
        }

        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;

        if(last == NULL) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }
    printf("Circular linked list created successfully!\n");
}

// Function to display the elements of the list
void displayList() {
    struct Node *temp;

    if(last == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = last->next;
    printf("The elements in the circular linked list are:\n");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != last->next);
    printf(" (back to start)\n");
}

// Function to insert a node at the beginning of the list
void insbeg(int data) {
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    if(!newNode) {
        printf("Memory allocation error!\n");
        return;
    }

    newNode->data = data;
    if(last == NULL) {
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }

    printf("Node inserted at the beginning!\n");
}

// Function to insert a node at the end of the list
void insend(int data) {
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    if(!newNode) {
        printf("Memory allocation error!\n");
        return;
    }

    newNode->data = data;
    if(last == NULL) {
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }

    printf("Node inserted at the end!\n");
}

// Function to delete a node from the beginning of the list
void delbeg() {
    struct Node *temp;

    if(last == NULL) {
        printf("List is empty!\n");
        return;
    }

    if(last->next == last) {
        free(last);
        last = NULL;
    } else {
        temp = last->next;
        last->next = temp->next;
        free(temp);
    }

    printf("Node deleted from the beginning!\n");
}

// Function to delete a node from the end of the list
void delend() {
    struct Node *temp, *prev;

    if(last == NULL) {
        printf("List is empty!\n");
        return;
    }

    if(last->next == last) {
        free(last);
        last = NULL;
    } else {
        temp = last->next;
        while(temp->next != last->next) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = last->next;
        free(last);
        last = prev;
    }

    printf("Node deleted from the end!\n");
}

// Function to delete a node after a given node
void delaft(int adata) {
    struct Node *temp, *nodeToDelete;

    if(last == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = last->next;
    do {
        if(temp->data == adata) {
            nodeToDelete = temp->next;
            if(nodeToDelete == last) {
                last = temp;
            }
            temp->next = nodeToDelete->next;
            free(nodeToDelete);
            printf("Node deleted after %d!\n", adata);
            return;
        }
        temp = temp->next;
    } while(temp != last->next);

    printf("Node with data %d not found!\n", adata);
}

// Function to delete the entire list
void dellist() {
    struct Node *temp;

    if(last == NULL) {
        printf("List is already empty!\n");
        return;
    }

    while(last != NULL) {
        if(last->next == last) {
            free(last);
            last = NULL;
        } else {
            temp = last->next;
            last->next = temp->next;
            free(temp);
        }
    }

    printf("Entire list deleted!\n");
}