#include<stdio.h>

int array[10];
int top = -1;


void displayStackElement(){
    if(top == -1){
        printf("Stack is Empty!!!");
    }else{
        for(int i = 0; i <= top; i++){
            printf("%d, ", array[i]);
        }
    }
    printf("\n");
}

void push(int data){
    if(top == 10){
        printf("Stack is full!!\n");
    }else{
        array[++top] = data;
    }
}

int pop(){
    if(top == -1){
        printf("Stack is Empty\n");
    }else{
        int data = array[top--];
        return data;
    }
}

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    displayStackElement();

    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    displayStackElement();

}