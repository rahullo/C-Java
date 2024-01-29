// Implement following functions for Binary Search Trees



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

// b. Insertion of a new node
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


// a. Search a given item (Recursive & Non-Recursive)
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


// c. Maximum element of the BST
struct Node* searchMaximumNode(struct Node* root){
    if(root->right == NULL){
        return root;
    }

    return searchMaximumNode(root->right);
}

// d. Minimum element of the BST
struct Node* searchMinimumNode(struct Node* root){
    if(root->left == NULL){
        return root;
    }

    return searchMinimumNode(root->left);
}

// e. Successor of the BST
// f. Delete a given node from the BST
struct Node* deleteNode(struct Node* root, int data){
    if(root == NULL){
        return root;
    }

    if(data < root->data){
        root->left = deleteNode(root->left, data);
    }else if(data > root->data){
        root->right = deleteNode(root->right, data);
    }else {
        if(root->left == NULL){
            struct Node* temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        // struct Node* temp = searchMinimumNode(root->right);
        // root->data = temp->data;
        // root->right = deleteNode(root->right, temp->data);

        struct Node* temp = searchMaximumNode(root->left);
        root->data = temp->data;
        root->left = deleteNode(root->left, temp->data);

    }
    return root;
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
    deleteNode(root, 55);
    printf("\n");
    inOrderTraversal(root);


    // printf("\nMaximum Number in Tree: %d", searchMaximumNode(root)->data);
    // printf("\nMinimum Number in Tree: %d", searchMinimumNode(root)->data);

}