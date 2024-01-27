#include<stdio.h>

int array[10];
int size = 10;
int rear = -1, front = -1;


void displayQueueElement( ){
    for(int i = 0; i < rear; i++){
        printf("%d, ", array[i]);
    }
    printf("\n");
}

void shifting(int rear){
    for(int i = 0; i < rear; i++){
        array[i] = array[i+1];
    }
    rear--;
}

void enqueue(int data){
    if(rear == size-1){
        printf("Queue is full\n");
    }
    array[++rear] = data;
}


void deque(){
    if(rear == -1){
        printf("Queue is Empty\n");
    }
    shifting(rear--);
}

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    displayQueueElement();

    deque();
    deque();

    displayQueueElement();
}