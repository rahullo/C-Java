#include<stdio.h>

void printArray(int array[], int size){
	int i;
	for(i = 0; i < size; i++){
		printf("%d, ", array[i]);
	}
	printf("\n");
}

void insertionSort(int array[], int size){
	int i;
	for(i = 0; i < size; i++){
		int key = array[i];
		int j = i-1;

		while(key < array[j] && j >= 0){
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = key;
	}
}

int main(){
	int array[] = {8, 4, 0, 2, 7, 1, 6, 3, 5};

	printArray(array, 9);
	insertionSort(array, 9);
	printArray(array, 9);

}