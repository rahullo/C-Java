#include<stdio.h>
#include<stdlib.h>



struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


// Function to print tree data in a tree structure
void printTree(struct Node* root, int space) {
    if (root == NULL) {
        return;
    }

    // Increase distance between levels
    space += 4;

    // Print right subtree first
    printTree(root->right, space);

    // Print current node after spacing
    printf("\n");
    for (int i = 4; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);

    // Print left subtree
    printTree(root->left, space);
}

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode){
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

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

struct Node* searchNode(struct Node* root, int data){
    if(root == NULL || root->data == data){
        return root;
    }

    if(data < root->data){
        return searchNode(root->left, data);
    }else if(data > root->data){
        return searchNode(root->right, data);
    }
}


int main(){
    struct Node* root  = NULL;

    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    printTree(root, 0);
    struct Node* ans = searchNode(root, 40);
    printf("%d", ans->data);
}
