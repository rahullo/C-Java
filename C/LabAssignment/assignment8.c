#include<stdio.h>


int binarySearch(int array[], int num, int size){

    int left = 0, right = size-1;

    while (left <= right){
        int mid = left + (right - left) / 2;

        if(array[mid] == num){
            return mid;
        }else if(array[mid] < num){
            left = mid+1;
        }else{
            right = mid-1;
        }

    }

    return -1;
}


int main(){
    int array[] = { 1, 4, 8, 9, 10, 12, 14, 16, 19, 21, 23};
    int arraySize = sizeof(array)/sizeof(array[0]);

    int num;

    printf("Enter the item to search: ");
    scanf("%d", &num);

    int ans = binarySearch(array, num, arraySize);

    if(ans == -1){
        printf("\n%d is not found!!!");
    }else{
        printf("\n%d is found at position %d.", num, ans);
    }
    return 0;
}