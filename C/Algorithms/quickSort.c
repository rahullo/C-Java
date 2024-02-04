#include<stdio.h>

int partition(int array[], int low, int high){
    int pivot = high;
    int i = low -1;
    int j;
    for(j = low; j < high; j++){
        if(array[j] < array[pivot]){
            i++;
            int temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }
    int temp = array[i+1];
    array[i+1] = array[pivot];
    array[pivot] = temp;
    return i+1;
}

void quickSort(int array[], int low, int high){
    if(low < high){
        int partitionIndex = partition(array, low, high);
        quickSort(array, low, partitionIndex-1);
        quickSort(array, partitionIndex+1, high);

    }
}

void printData(int array[], int size){
    for(int i = 0; i < size; i++){
        printf("%d, ", array[i]);
    }
    printf("\n");
}


int main(){
    int array[] = {3, 5, 2, 6, 1, 8, 4, 9, 0, 7};
    int size = sizeof(array)/ sizeof(array[0]);

    printData(array, size);
    quickSort(array, 0, size);
    printData(array, size);
}