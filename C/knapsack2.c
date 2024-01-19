#include<stdio.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack Problem
int knapsack(int capacity, int weights[], int values[], int n) {
    // Create a 2D array to store solutions to subproblems
    int dp[n + 1][capacity + 1];

    // Build the dp table in a bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0; // Base case: no items or no capacity

            else if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);

            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < capacity +1; j++){
            printf("%d, ", dp[i][j]);
        }
        printf("\n");
    }

    // The final result is stored in dp[n][capacity]
    return dp[n][capacity];
}

// Example usage
int main() {
    // int values[] = {60, 100, 120};
    // int weights[] = {10, 20, 30};
    // int capacity = 50;
    int values[] = {2, 3, 1, 4};
    int weights[] = {3, 4, 5, 6};
    int capacity = 8;
    int n = sizeof(values) / sizeof(values[0]);

    printf("Maximum value that can be obtained: %d\n", knapsack(capacity, weights, values, n));

    return 0;
}
