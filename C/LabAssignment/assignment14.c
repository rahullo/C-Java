#include<stdio.h>

int partition(int array[], int low, int high){
    int pivot = high;
    int i = low-1;
    int j;
    for(j = low; j < high; j++){
        if(array[j]<array[pivot]){
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
        int partitionPoint = partition(array,  low,  high);
        quickSort(array, low, partitionPoint-1);
        quickSort(array, partitionPoint+1, high);
    }

}

void printingArray(int array[], int size){
    int i;
    for(i = 0; i < size; i++){
        printf("%d, ", array[i]);
    }
    printf("\n");
}

int main(){
    int array[] = {8, 9, 7, 5, 6, 3, 4, 2, 1, 0};

	int size = sizeof(array)/sizeof(array[0]);

    printingArray(array, size);
    quickSort(array, 0, size);
    printingArray(array, size);
    
}