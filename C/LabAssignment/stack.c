#include<stdio.h>
#define maxlimit 100

int stack[maxlimit];
int top = -1;

int push() {
	
	int element;
	
	if(top == maxlimit-1){
		printf("Stack is full!!!");
	}else{
		printf("Enter the number to insert: ");
		scanf("%d", &element);
		top+=1;
		stack[top] = element;
		printf("%d is Inserted at position %d\n", element, top);
		return 1;
	}
	
	return 0;
};

int pop(){
	if(top == -1){
		printf("Stack is Empty!");
	}else{
		int item = stack[top];
		printf("%d is Deleted from position %d\n", item, top);
		top-=1;
		return item;
	}
};

int main() {
	char operation[100];
	
	printf("push/pop/quit?: ");
	scanf("%99[^\n]", operation);
	
	while(operation != "quit"){
		printf("Intered while loop");
		if(operation == "pop"){
			pop();
		}else if(operation == "push"){
			push();
		}
	}
	
}
