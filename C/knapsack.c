#include <stdio.h>

// A utility function to get maximum of two integers
int max(int a, int b) { return (a > b)? a : b; }

// A function to solve the knapsack problem
int knapsack(int W, int wt[], int val[], int n)
{
	int K[n+1][W+1];
	// Build table K[][] in bottom up manner
	int i;
	for (i = 0; i <= n; i++)
	{
		int w;
		for (w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i-1] > w)
				K[i][w] = K[i-1][w];
			else
				K[i][w] = max(K[i-1][w], val[i-1] + K[i-1][w-wt[i-1]]);
		}
	}

	return K[n][W];
}

// Driver program to test the above function
int main()
{
	int val[] = {2, 3, 1, 4};
	int wt[] = {3, 4, 5, 6};
	int W = 8;
	int n = sizeof(val)/sizeof(val[0]);
	printf("%d", knapsack(W, wt, val, n));
	return 0;
}
