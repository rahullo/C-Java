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
	for(i = 1; i < size; i++){
		int key = array[i];
		int j = i-1;
		while(array[j] > key && j >= 0){
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = key;
	}
}

int partition(int array[], int low, int high){
	int pivot = high;
	int i = low -1;
	int j;
	for(j = low; j < high; j++){
		if(array[j] < array[pivot]){
			i++;
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	int temp2 = array[i+1];
	array[i+1] = array[pivot];
	array[pivot] = temp2;
	return i+1;
}

void quickSort(int array[], int low, int high){
	if(low < high){
		int partitionIndex = partition(array, low, high);
		quickSort(array, low, partitionIndex-1);
		quickSort(array, partitionIndex +1, high);
	}
}

int main(){
	// int array[] = {8, 4, 0, 2, 7, 1, 6, 3, 5, 5, 58 ,65, 4, 22, 68 ,35, 98, 75, 95, 65, 42, 36, 76, 91, 52, 63, 298, 7};
	int array[] = {8, 4, 0, 2, 7, 1, 6, 3, 5};
	int size = sizeof(array)/sizeof(array[0]);

	printArray(array, size);

	quickSort(array, 0, size);
	// insertionSort(array, size);

	printArray(array, size);

}