#include <stdio.h>

#define N 4  // Number of queens

int board[N][N];

// Function to check if a placement is safe
int isSafe(int row, int col) {
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return 0;  // Not safe
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return 0;  // Not safe
        }
    }
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return 0;  // Not safe
        }
    }
    return 1;  // Safe
}

// Recursive function to solve N-Queen problem
int solveNQUtil(int col) {
    if (col >= N) {
        return 1;  // Solution found
    }
    for (int i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;  // Place queen
            if (solveNQUtil(col + 1) == 1) {
                return 1;  // Solution found
            }
            board[i][col] = 0;  // Backtrack
        }
    }
    return 0;  // No solution found in this branch
}

// Function to print the solution
void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    if (solveNQUtil(0) == 0) {
        printf("Solution does not exist\n");
    } else {
        printf("Solution:\n");
        printSolution();
    }
    return 0;
}
