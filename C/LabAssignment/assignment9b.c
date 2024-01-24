#include<stdio.h>
#include<stdlib.h>


struct Node {
    int data;
    struct Node *next;
};


struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode != NULL){
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}


struct Node* insertAtFirst(struct Node *head, int data){
    struct Node* newNode = createNode(data);

    if(newNode != NULL){
        newNode->next = head;
        head = newNode;
    }
    return head;
}

struct Node* deleteAtFirst(struct Node *head){
    struct Node* current = head;
    if(current != NULL){
        head = current->next;
        // free(current);
    }
    return head;
}


// Function to display the linked list
void displayList(struct Node *head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}


int main(){
    struct Node *head = NULL;

    // Insert nodes at the beginning
    head = insertAtFirst(head, 100);
    head = insertAtFirst(head, 200);
    head = insertAtFirst(head, 300);

    // Display the linked list
    printf("Linked List after insertions at the beginning:\n");
    displayList(head);

    head = deleteAtFirst(head);
    displayList(head);


    return 0;
}