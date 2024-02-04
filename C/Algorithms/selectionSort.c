#include<stdio.h>

void selectionSort(int array[], int size){
    for(int i = 0; i < size; i++){
        int min = i;
        for(int j = i+1; j < size; j++){
            if(array[j] < array[min]){
                min = j;
            }
        }
        if(i != min){
            int temp = array[i];
            array[i] = array[min];
            array[min] = temp;
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
    int array[] = {3, 5, 2, 6, 1, 8, 4, 9, 0, 7};
    int size = sizeof(array)/ sizeof(array[0]);

    printData(array, size);
    selectionSort(array, size);
    printData(array, size);

}