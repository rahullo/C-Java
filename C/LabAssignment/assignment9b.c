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

// Function to delete First Node
struct Node* deleteFirstNode(struct Node *head){
    struct Node* current = head;
    if(current != NULL){
        head = current->next;
        // free(current);
    }
    return head;
}

// Function to delete Last Node
struct Node* deleteLastNode(struct Node *head){
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

//Function to delete Node with given data
struct Node* deleteNode(struct Node *head, int data){
	struct Node* current = head;
	struct Node* prev = NULL;
	
	while(current != NULL && current->data != data){
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
    head = insertAtFirst(head, 400);
    head = insertAtFirst(head, 500);

    // Display the linked list
    printf("Linked List after insertions at the beginning:\n");
    displayList(head);

    head = deleteFirstNode(head);
    displayList(head);
    
    head = deleteLastNode(head);
    displayList(head);

    head = deleteNode(head, 300);
    displayList(head);


    return 0;
}
