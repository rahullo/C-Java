#include<stdio.h>



int partition(int array[], int low, int high){
	printf("High: %d, array[%d]: %d\n", high, high, array[high]);
	int pivot = high;
	int key = low -1;

	for(int i = low; i < high; i++){
		if(array[i] < array[pivot]){
			key++;
			int temp1 = array[i];
			array[i] = array[key];
			array[key] = temp1;

		}
	}
	int temp2 = array[key+1];
	array[key+1] = array[pivot];
	array[pivot] = temp2;
	return key+1;
}

int quickSort(int array[], int low, int high){
	if(low < high){
		int partitionIndex = partition(array, low, high);
		quickSort(array, 0, partitionIndex-1);
		quickSort(array, partitionIndex+1, high);
	}
}

int printArray(int array[], int size){
	for(int i = 0; i < size; i++){
		printf("%d", array[i]);

		if(i < size-1){
			printf(", ");
		}
	}
	printf("\n");
}

int main(){
	int array[] = {6, 3, 7, 3, 2, 9, 0, 2, -1};

	int size = sizeof(array)/sizeof(array[0]);

	printArray(array, size);
	quickSort(array, 0, size-1);
	printArray(array, size);
}