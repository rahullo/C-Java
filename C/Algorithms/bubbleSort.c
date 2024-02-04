#include<stdio.h>

void bubbleSort(int array[], int size){

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(array[j] > array[i]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void printData(int array[], int size){
    for(int i = 0; i < size; i++){
        printf("%d, ", array[i]);
    }
    printf("\n");
}


int main(){
    int array[] = {1, 4, 9, 10, 6, 7, 3, 5, 8, 2 };

    int size = sizeof(array)/sizeof(array[0]);

    printData(array, size);

    bubbleSort(array, size);

    printData(array, size);

}