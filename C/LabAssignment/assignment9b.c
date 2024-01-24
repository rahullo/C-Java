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


int main(){

    printf("Rahul");
}