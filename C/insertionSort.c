#include <stdio.h>

void insertionSort(int arr[], int n) {
   int i, key, j;
   for (i = 1; i < n; i++) {
       key = arr[i];
       j = i - 1;

       /* Move elements of arr[0..i-1], that are greater than key,
          to one position ahead of their current position */
       while (j >= 0 && arr[j] > key) {
           arr[j + 1] = arr[j];
           j = j - 1;
       }
       arr[j + 1] = key;
   }
}

// Function to print an array
void printArray(int arr[], int n) {
   int i;
   for (i = 0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}

// Driver program to test above functions
int main() {
   int arr[] = {12, 31, 199, -1, -21, 11, 13, 5, 6};
   int n = sizeof(arr) / sizeof(arr[0]);
   printArray(arr, n);

   insertionSort(arr, n);
   printArray(arr, n);

   return 0;
}

