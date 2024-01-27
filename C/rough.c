#include<stdio.h>

int maxi(int num1, int num2){
    if(num1 > num2){
        return num1;
    }else{
        return num2;
    }
}

void printArray(int array[], int size){
	int i;
	for(i = 0; i < size; i++){
		printf("%d, ", array[i]);
	}
	printf("\n");
}

void insertionSort(int array[], int size){
	int i;
	for(i = 1; i < size; i++){
		int key = array[i];
		int j = i-1;
		while(array[j] > key && j >= 0){
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = key;
	}
}

int partition(int array[], int low, int high){
	int pivot = high;
	int i = low -1;
	
	for(int j = low; j < high; j++){
		if(array[j] < array[pivot]){
			i++;
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	int temp = array[i+1];
	array[i+1] = array[pivot];
	array[pivot] = temp;
	return i+1;
}

void quickSort(int array[], int low, int high){
	if(low < high){
		int partitionIndex = partition(array, low, high);
		quickSort(array, low, partitionIndex-1);
		quickSort(array, partitionIndex +1, high);
	}
}

int knapsack(int wt[], int val[], int W, int N){
	int dp[N +1][W + 1];

	for(int i = 0; i <= N; i++){
		for(int j = 0; j <= W; j++){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
			}else if( wt[i-1] > j ){
				dp[i][j] = dp[i-1][j];
			}else{
				dp[i][j] = maxi(val[i-1] + dp[i-1][j - wt[i-1]] , dp[i-1][j]);
			}
		}
	}
	return dp[N][W];
}

int main(){
	// int array[] = {8, 4, 0, 2, 7, 1, 6, 3, 5, 5, 58 ,65, 4, 22, 68 ,35, 98, 75, 95, 65, 42, 36, 76, 91, 52, 63, 298, 7};
	int array[] = {8, 4, 0, 2, 7, 1, 6, 3, 5};
	int size = sizeof(array)/sizeof(array[0]);

	printArray(array, size);

	quickSort(array, 0, size);
	// insertionSort(array, size);

	printArray(array, size);

	// int wt[] = {3, 4, 5};
    // int val[] = {30, 50, 60};
    // int W = 8;
    // int N = sizeof(wt) / sizeof(wt[0]);

    // int maxValue = knapsack(wt, val, W, N);
    // printf("Maximum value attainable: %d\n", maxValue);

}