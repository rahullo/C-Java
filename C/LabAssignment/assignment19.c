#include <stdio.h>
#include <stdbool.h>

#define N 4  // Change N to the desired board size

// Function to check if a queen can be placed at board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    // Check this row on the left side
    int i;
    int j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on the left side
    
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on the left side
    for (i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// Recursive function to solve N-Queens problem using backtracking
bool solveNQueensUtil(int board[N][N], int col) {
    // Base case: All queens are placed
    if (col >= N)
        return true;

    // Try placing a queen in each row of the current column
    int i;
    for (i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;  // Place queen

            // Recur to place the rest of the queens
            if (solveNQueensUtil(board, col + 1))
                return true;

            // If placing queen in the current position doesn't lead to a solution,
            // then remove the queen from the current position (backtrack)
            board[i][col] = 0;
        }
    }

    // If the queen can't be placed in any row of the current column
    return false;
}

// Function to solve the N-Queens problem
void solveNQueens() {
    int board[N][N] = {0};

    if (solveNQueensUtil(board, 0)) {
        // Print the solution
        int i;
        for (i = 0; i < N; i++) {
        	int j;
            for (j = 0; j < N; j++)
                printf("%2d ", board[i][j]);
            printf("\n");
        }
    } else {
        printf("Solution does not exist.\n");
    }
}

int main() {
    solveNQueens();

    return 0;
}

