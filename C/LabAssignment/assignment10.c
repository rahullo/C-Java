//Write a program to implement Stack and Queue using linked lists.
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode != NULL){
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

struct Node* stackInsertion(struct Node* head, int data){
    struct Node* newNode = createNode(data);

    if(newNode != NULL){
        newNode->next = head;
        head = newNode;
    }
    return head;
}

struct Node* stackDeletion(struct Node* head){
    struct Node* current = head;
    if(current != NULL){
        head = current->next;
        free(current);
    }
    
    return head;
}

struct Node* queueInsertion(struct Node* head, int data){
    struct Node* newNode = createNode(data);

    if(newNode != NULL){
        newNode->next = head;
        head = newNode;
    }

    return head;
}


struct Node* queueDeletion(struct Node* head){
    struct Node* current = head;
    struct Node* prev = NULL;

    while(current->next != NULL){
        prev = current;
        current = current->next;
    }

    prev->next = NULL;
    free(current);
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
    // struct Node *head = NULL;

    // head = stackInsertion(head, 500);
    // head = stackInsertion(head, 400);
    // head = stackInsertion(head, 300);
    // head = stackInsertion(head, 200);
    // head = stackInsertion(head, 100);

    // displayList(head);

    // head = stackDeletion(head);
    // displayList(head);
    
    // head = stackDeletion(head);
    // displayList(head);


    struct Node* head2 = NULL;

    head2 = queueInsertion(head2, 50);
    head2 = queueInsertion(head2, 40);
    head2 = queueInsertion(head2, 30);
    head2 = queueInsertion(head2, 20);
    head2 = queueInsertion(head2, 10);

    displayList(head2);

    head2 = queueDeletion(head2);
    displayList(head2);


}
