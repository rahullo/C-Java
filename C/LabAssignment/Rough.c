#include<stdio.h>

int array[10];
int front = -1, rear = -1;

int enque(int num){
	if(rear == 9){
		printf("Queue is full!!!");
		return 0;
	}
	rear++;
	array[rear] = num;
	return 1;
}

int shifting(int rear){
	int i;
	for(i = 0; i < rear; i++){
		array[i] = array[i+1];
	}
}

int deque(){
	if(front == rear){
		printf("Queue is Empty!!!");
		return 0;
	}
	shifting(rear);
	rear--;
	return 1;
}

void displayQueueElement(){
	int i = 0;
	while(i <= rear){
		printf("%d, ", array[i]);
		i++;
	}
	
	printf("\n");
}


int main(){
	enque(1);
	enque(12);
	enque(23);
	enque(34);
	enque(45);
	enque(56);
	enque(67);
	enque(78);
	displayQueueElement();
	deque();
	printf("Rear: %d & Front: %d\n", rear, front);
	deque();
	printf("Rear: %d & Front: %d\n", rear, front);
	deque();
	printf("Rear: %d & Front: %d\n", rear, front);
	displayQueueElement();
	deque();
	printf("Rear: %d & Front: %d\n", rear, front);
	deque();
	printf("Rear: %d & Front: %d\n", rear, front);
	deque();
	displayQueueElement();
}
