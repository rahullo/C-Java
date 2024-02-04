#include<stdio.h>

void insertionSort(int array[], int size){
    for(int i = 1; i < size; i++){
        int key = array[i];
        int j = i-1;
        while(array[j] > key && j >= 0){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
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
    insertionSort(array, size);
    printData(array, size);
}