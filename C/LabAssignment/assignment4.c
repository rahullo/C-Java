#include<stdio.h>
#include <string.h>

#define max 100

int leftIndex = -1;
int rightIndex = max;

//push function for left stack
int leftStackPush(int* array){
	int num;
	printf("\nEnter the number to Insert in left stack: ");
	scanf("%d", &num);
	
	
	if(num){
		leftIndex++;
		array[leftIndex] = num;
		printf("\nInserted in left stack");
	}
		
	return 0;
};

//pop function for left function
int popLeftStack(int* array){
	int temp = array[leftIndex];
	leftIndex--;
	return temp;
}

//push function for right stack
int rightStackPush(int* array){
	int num;
	printf("\nEnter the number to Insert in right stack: ");
	scanf("%d", &num);
	
	if(num){
		rightIndex--;
		array[rightIndex] = num;
		printf("\nInserted in right stack");
	}
	
	return 0;
};

//pop function for right function
int popRightStack(int* array){
	int temp = array[rightIndex];
	rightIndex++;
	return temp;
}


// function to display left stack element
void displayLeftStackItems(int* array){
	int i;
	for(i=leftIndex; i>-1;i--){
		printf("\n%d", array[i]);
	}
}

// function to display left stack element
void displayRightStackItems(int* array){
	int i;
	for(i=rightIndex; i<max;i++){
		printf("\n%d", array[i]);
	}
}

int main(){
	int array[max]; // declaring an array
	
	char operation[100]; // taking a char variable
	
	displayLeftStackItems(array);
	leftStackPush(array);
	leftStackPush(array);
	leftStackPush(array);
	leftStackPush(array);
	leftStackPush(array);
	displayLeftStackItems(array);
	
	displayRightStackItems(array);
	rightStackPush(array);
	rightStackPush(array);
	rightStackPush(array);
	rightStackPush(array);
	rightStackPush(array);
	displayRightStackItems(array);
	
	printf("\n %d", popLeftStack(array));
	printf("\n %d", popLeftStack(array));
	printf("\n %d", popLeftStack(array));
	printf("\n %d", popLeftStack(array));
	
	printf("\n %d", popRightStack(array));
	printf("\n %d", popRightStack(array));
	printf("\n %d", popRightStack(array));
	printf("\n %d", popRightStack(array));
	return 0;
}
