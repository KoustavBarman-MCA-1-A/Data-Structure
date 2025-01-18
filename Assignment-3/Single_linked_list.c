#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function prototypes
void createList();
void displayList();
void insbeg(int data);
void insend(int data);
void insbef(int bdata, int data);
void insaft(int adata, int data);
void delbeg();
void delend();
void delaft(int adata);
void dellist();

int main() {
    int choice, data, bdata, adata;

    while(1) {
        printf("\nMenu:\n");
        printf("1. Create a single linked list\n");
        printf("2. Display the elements of the list\n");
        printf("3. Insert a node at the beginning\n");
        printf("4. Insert a node at the end\n");
        printf("5. Insert a node before a given node\n");
        printf("6. Insert a node after a given node\n");
        printf("7. Delete a node from the beginning\n");
        printf("8. Delete a node from the end\n");
        printf("9. Delete a node after a given node\n");
        printf("10. Delete the entire list\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createList();
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
                printf("Enter the data of the node before which to insert: ");
                scanf("%d", &bdata);
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insbef(bdata, data);
                break;
            case 6:
                printf("Enter the data of the node after which to insert: ");
                scanf("%d", &adata);
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insaft(adata, data);
                break;
            case 7:
                delbeg();
                break;
            case 8:
                delend();
                break;
            case 9:
                printf("Enter the data of the node after which to delete: ");
                scanf("%d", &adata);
                delaft(adata);
                break;
            case 10:
                dellist();
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to create a single linked list
void createList() {
    int n, data, i;
    struct Node *newNode, *temp;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if(!newNode) {
            printf("Memory allocation error!\n");
            return;
        }
        printf("Enter the data for node %d: ", i+1);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    printf("Linked list created successfully!\n");
}

// Function to display the elements of the list
void displayList() {
    struct Node *temp;

    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = head;
    printf("The elements in the linked list are:\n");
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the beginning of the list
void insbeg(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if(!newNode) {
        printf("Memory allocation error!\n");
        return;
    }

    newNode->data = data;
    newNode->next = head;
    head = newNode;

    printf("Node inserted at the beginning!\n");
}

// Function to insert a node at the end of the list
void insend(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp;

    if(!newNode) {
        printf("Memory allocation error!\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("Node inserted at the end!\n");
}

// Function to insert a node before a given node
void insbef(int bdata, int data) {
    struct Node *newNode, *temp, *prev;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    if(!newNode) {
        printf("Memory allocation error!\n");
        return;
    }

    newNode->data = data;

    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    // If the node to be inserted before is the head node
    if(head->data == bdata) {
        newNode->next = head;
        head = newNode;
    } else {
        temp = head;
        prev = NULL;

        while(temp != NULL && temp->data != bdata) {
            prev = temp;
            temp = temp->next;
        }

        if(temp == NULL) {
            printf("Node with data %d not found!\n", bdata);
            free(newNode);
        } else {
            newNode->next = temp;
            prev->next = newNode;
        }
    }

    printf("Node inserted before %d!\n", bdata);
}

// Function to insert a node after a given node
void insaft(int adata, int data) {
    struct Node *newNode, *temp;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    if(!newNode) {
        printf("Memory allocation error!\n");
        return;
    }

    newNode->data = data;

    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = head;

    while(temp != NULL && temp->data != adata) {
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Node with data %d not found!\n", adata);
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }

    printf("Node inserted after %d!\n", adata);
}

// Function to delete a node from the beginning of the list
void delbeg() {
    struct Node *temp;

    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);

    printf("Node deleted from the beginning!\n");
}

// Function to delete a node from the end of the list
void delend() {
    struct Node *temp, *prev;

    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = head;

    if(head->next == NULL) {
        head = NULL;
    } else {
        while(temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
    }

    free(temp);
    printf("Node deleted from the end!\n");
}

// Function to delete a node after a given node
void delaft(int adata) {
    struct Node *temp, *nodeToDelete;

    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = head;

    while(temp != NULL && temp->data != adata) {
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL) {
        printf("Node with data %d not found or no node to delete after it!\n", adata);
    } else {
        nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        free(nodeToDelete);
        printf("Node deleted after %d!\n", adata);
    }
}

// Function to delete the entire list
void dellist() {
    struct Node *temp;

    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    printf("Entire list deleted!\n");
}