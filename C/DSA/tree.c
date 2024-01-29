#include<stdio.h>
#include<stdlib.h>



struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Preorder traversal
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Inorder traversal
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Postorder traversal
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}


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

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
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
    insertNode(root, 25);
    insertNode(root, 55);
    insertNode(root, 35);
    insertNode(root, 68);


    inorderTraversal(root);
    printf("\n");


    // printTree(root, 0);
    // struct Node* ans = searchNode(root, 40);
    // printf("%d", ans->data);
    // printf("\n");
    // printf("\n");
    // printf("\n");
    deleteNode(root, 40);
    // printTree(root, 0);
    inorderTraversal(root);

}
