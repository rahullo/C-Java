#include<stdio.h>


int linearSearch(int array[], int num, int size){
    int i;
    for(i = 0; i < size; i++){
        if(array[i] == num){
            return i;
        }
    }
    return -1;
}


int main(){
    int array[] = {4, 6, 2, 9, 2, 10, 91, 43};
    int arraySize = sizeof(array)/sizeof(array[0]);
    int num;
    printf("Enter the number you want to search: ");
    scanf("%d", &num);

    int ans = linearSearch(array, num, arraySize);

    if(ans != -1){
        printf("\n%d is found at position %d", num, ans);
    }else{
        printf("\n%d is not found", num);
    }
    
    return 0;
}