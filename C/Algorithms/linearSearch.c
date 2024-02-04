#include<stdio.h>

int linearSearch(int array[], int size, int item){
    for(int i = 0; i < size; i++){
        if(array[i] == item){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr)/sizeof(arr[0]);

    int ans = linearSearch(arr, size, 8) + 1;

    if(ans != -1){
        printf("Item Found at position %d: ", ans);
    }

}