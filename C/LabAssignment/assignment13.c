#include<stdio.h>

void insertionSort(int array[], int size){
    int i;
    for(i = 1; i < size; i++){
        int key = array[i];
        int j = i-1;
         
        while(key < array[j] && j >= 0){
            array[j+1] = array[j];
            --j;
        }

        array[j+1] = key;
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
    int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int size = sizeof(array)/sizeof(array[0]);

    printingArray(array, size);
    insertionSort(array, size);
    printingArray(array, size);

    return 0;
}