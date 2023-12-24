#include<stdio.h>

void selectionSort(int array[], int size){
    int i, j;

    for(i = 0; i < size; i++){
        int min = i;
        for(j = i; j < size; j++){
            if(array[j] < array[min]){
                min = j;
            }
        }
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
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
    int array[] = { 9, 8, 7, 6 ,5, 4, 3, 2, 1, 0};
    int size = sizeof(array)/sizeof(array[0]);

    printingArray(array, size);
    selectionSort(array, size);
    printingArray(array, size);
}