#include<stdio.h>

void bubbleSort(int array[], int size){
    int i, j;

    printf("\n");
    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            // printf("i = %d,  j = %d\n", i, j);
            if(array[i] < array[j]){
                printf("arrayi[%d] = %d,  arrayj[%d] = %d\n", i, array[i], j, array[j]);
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void printArray(int array[], int size){
    int i;
    for(i = 0; i < size; i++){
        printf("%d, ", array[i]);
    }
}

int main(){
    // int array[] = {4, 3, 7, 1, 0, 9, 2, 5, 6, 8};
    int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int size = sizeof(array)/sizeof(array[0]);

    printArray(array, size);
    bubbleSort(array, size);
    printf("\n");
    printArray(array, size);


    return 0;
}