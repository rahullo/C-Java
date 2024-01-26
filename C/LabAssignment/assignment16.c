#include<stdio.h>

int maxi(int num1, int num2){
    if(num1 > num2){
        return num1;
    }else{
        return num2;
    }
}

int knapsack(int wt[], int val[], int W, int N) {
    int dp[N + 1][W + 1];

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (wt[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = maxi(val[i - 1] + dp[i - 1][j - wt[i - 1]],   dp[i - 1][j]);
            }
        }
    }

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            printf("%d, ", dp[i][j]);
        }
        printf("\n");
    }

    return dp[N][W];
}

int main() {
    int wt[] = {3, 4, 5};
    int val[] = {30, 50, 60};
    int W = 8;
    int N = sizeof(wt) / sizeof(wt[0]);

    int maxValue = knapsack(wt, val, W, N);
    printf("Maximum value attainable: %d\n", maxValue);

    // Optional: Implement backtracking to retrieve chosen items
}
