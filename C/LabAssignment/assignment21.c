// Write a program using functions for binary tree traversals Pre-order, In-order and
// Post-order using both Recursive and Non-recursive approach.
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode){
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

// Function to insert Element in Tree
struct Node* insertNode(struct Node* root, int data){
    if(root == NULL){
        return createNode(data);
    }

    if(data < root->data){
        root->left = insertNode(root->left, data);
    }else if(data > root->data){
        root->right = insertNode(root->right, data);
    }
    return root;
}

// InOrder recursive
struct Node* inOrderRecursive(struct Node* root){
    if(root){
        inOrderRecursive(root->left);
        printf("%d, ", root->data);
        inOrderRecursive(root->right);
    }
}
// InOrder non-recursive
void inorderTraversal(struct Node* root) {
    struct Node* current = root;

    // Use a stack to keep track of nodes to visit
    struct Node* stack[100];  // Adjust stack size as needed
    int top = -1;

    while (current != NULL || top != -1) {
        // Push left children onto the stack
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        // Pop and print the top node
        current = stack[top--];
        printf("%d, ", current->data);

        // Move to the right subtree
        current = current->right;
    }
}

// PreOrder recursive
struct Node* preOrderRecursive(struct Node* root){
    if(root){
        printf("%d, ", root->data);
        preOrderRecursive(root->left);
        preOrderRecursive(root->right);
    }
}
// PreOrder non-recursive

// PostOrder recursive
struct Node* postOrderRecursive(struct Node* root){
    if(root){
        postOrderRecursive(root->left);
        postOrderRecursive(root->right);
        printf("%d, ", root->data);
    }
}
// PostOrder non-recursive

int main(){
    struct Node* root  = NULL;

    root = insertNode(root, 50);
    insertNode(root, 60);
    insertNode(root, 80);
    insertNode(root, 25);
    insertNode(root, 55);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 35);
    insertNode(root, 68);

    inOrderRecursive(root);
    printf("\n");
    inorderTraversal(root);
    // preOrderRecursive(root);
    // printf("\n");
    // postOrderRecursive(root);
}