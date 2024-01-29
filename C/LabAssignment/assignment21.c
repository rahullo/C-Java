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
    preOrderRecursive(root);
    printf("\n");
    postOrderRecursive(root);
}