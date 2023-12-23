#include<stdio.h>


int binarySearch(int array[], int start, int end, int item){

    while(start < end ){

        // int mid = end + (start - end) / 2;
        int mid = (start + end) / 2;


        printf("%d\n", mid);

        if(item == array[mid]){
            return mid;
        }

        if(item < array[mid]){
            end = mid-1;
        }else if(item > array[mid]){
            start = mid+1;
        }
    }
    return -1;
};


int main() {
    int array[] = { 1, 2, 3, 4, 5, 6};
    int index = binarySearch(array, 0, 5, 6);
    if(index == -1){
        printf("No items found!!");
    }else{
        printf("Item Found at index %d ", index);

    }
    return 0;
}