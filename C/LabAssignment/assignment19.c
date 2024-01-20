#include <stdio.h>

#define N 10

int board[N][N];

int isSafe(int row, int col) {
    for (int i = col-1; i >=0; i--) {
        if (board[row][i] == 1) {
            return 0;  
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return 0;  
        }
    }
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return 0;  
        }
    }
    return 1;  
}

int NQueen(int col) {
    if (col >= N) {
        return 1;
    }
    for (int i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;
            if (NQueen(col + 1) == 1) {
                return 1;
            }
            board[i][col] = 0;
        }
    }
    return 0; 
}

void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    if (NQueen(0) == 0) {
        printf("Solution does not exist\n");
    } else {
        printf("Solution:\n");
        printSolution();
    }
    return 0;
}
