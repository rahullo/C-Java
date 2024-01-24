#include <stdio.h>
#include <stdlib.h>

// Define a Node structure
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to insert a node at the beginning of the linked list
struct Node* insertAtBeginning(struct Node *head, int data) {
    struct Node *newNode = createNode(data);
    if (newNode != NULL) {
        newNode->next = head;
        head = newNode;
    }
    return head;
}

// Function to insert a node at the end of the linked list
struct Node* insertAtEnd(struct Node *head, int data) {
    struct Node *newNode = createNode(data);
    if (newNode != NULL) {
        if (head == NULL) {
            // If the list is empty, the new node becomes the head
            head = newNode;
        } else {
            // Traverse to the end and append the new node
            struct Node *current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    return head;
}

// Function to delete a node with the given data from the linked list
struct Node* deleteNode(struct Node *head, int data) {
    struct Node *current = head;
    struct Node *prev = NULL;

    // Search for the node to delete
    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    // If the node is found, delete it
    if (current != NULL) {
        if (prev == NULL) {
            // If the node is at the beginning
            head = current->next;
        } else {
            // If the node is in the middle or end
            prev->next = current->next;
        }
        free(current);
    }

    return head;
}

// Function to display the linked list
void displayList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free the memory allocated for the linked list
void freeList(struct Node *head) {
    struct Node *current = head;
    struct Node *nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

int main() {
    struct Node *head = NULL;

    // Insert nodes at the beginning
    head = insertAtBeginning(head, 100);
    head = insertAtBeginning(head, 200);
    head = insertAtBeginning(head, 300);

    // Display the linked list
    printf("Linked List after insertions at the beginning:\n");
    displayList(head);

    // Insert nodes at the end
    head = insertAtEnd(head, 400);
    head = insertAtEnd(head, 500);

    // Display the linked list
    printf("Linked List after insertions at the end:\n");
    displayList(head);

    // Delete a node
    head = deleteNode(head, 200);

    // Display the linked list after deletion
    printf("Linked List after deleting node with data 20:\n");
    displayList(head);

    // Free the memory allocated for the linked list
    freeList(head);

    return 0;
}