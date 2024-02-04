#include<stdio.h>

int binarySearch(int array[], int low, int high, int item){
    if( low <= high){
        int mid = (low+high)/2;

        printf("mid: %d\n", mid);

        if(array[mid] == item){
            return mid;
        }else if(array[mid] < item){
            binarySearch(array, mid+1, high, item);
        }else{
            binarySearch(array, low,  mid-1, item);
        }
    }
}

int main(){
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    int size = sizeof(array)/sizeof(array[0]);
    int ans = binarySearch(array, 0, size, 5)+1;
    printf("%d ", ans);

}