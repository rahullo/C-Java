#include<stdio.h>
#include<stdlib.h>

struct Node{
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

struct Node* inOrderTraversal(struct Node* root){
    if(root != NULL){
        inOrderTraversal(root->left);
        printf("%d, ", root->data);
        inOrderTraversal(root->right);
    }
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
    if(root->data == data){
        return root;
    }

    if(data < root->data){
        return searchNode(root->left, data);
    }else if (data > root->data){
        return searchNode(root->right, data);
    }
}

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

    inOrderTraversal(root);

}