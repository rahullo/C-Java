#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int sortingArray(int array[]){
    // int sizeOfArray = sizeof(array) / sizeof(array[0]);

    for(int i = 0; i < 6; i++){
        for(int j = 1; j < 6; j++){
            int num1 = array[j-1];
            int num2 = array[j];
            if (num1 > num2){
                int temp = num1;
                num1 = num2; 
                num2 = temp;
            }
        }
    }

    for(int i = 0; i < 6; i++){
        printf("%d\n", array[i]);
    }
    return 0;
};

int findingMissing(int array[], int sizeOfArray, int repetingNum){
    int sumOfAllItemInRange = ((sizeOfArray-1)*(sizeOfArray))/2;

    int sumOfAllItemInArray = 0;
    for(int i = 0; i < sizeOfArray; i++){
        sumOfAllItemInArray += array[i];
    }


    return abs(sumOfAllItemInRange - sumOfAllItemInArray + repetingNum);
};


int findingRepetitive(int array[], int size){
    bool seen[size];
    for (int i = 0; i < size; i++) {
        seen[i] = false;
    }

    for (int i = 0; i < size; i++) {
        if (seen[array[i]]) {
            return array[i];
        }
        seen[array[i]] = true;
    }
    printf("No repetitive number found.\n");
    return -1;
};

  
int main(){
    int array[] = {0, 1, 2, 2, 4, 5};
    int sizeofArray = sizeof(array) / sizeof(array[0]);


    // printf("Enter the size of your Array: ");
    // int sizeofArray;
    // scanf("%d", &sizeofArray);

    // int array[sizeofArray];
    // printf("Enter elements of your array: ");

    // for(int i = 0; i < sizeofArray; i++){
    //     scanf(" %d", &array[i]);
    // }

    int repetitive = findingRepetitive(array, sizeofArray);
    int missing = findingMissing(array, sizeofArray, repetitive);

    if(repetitive != -1){
        printf("The repetitive number is: %d\n", repetitive);
    }
    printf("The Missing number is: %d\n", missing);

}