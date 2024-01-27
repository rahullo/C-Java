// Write a function for the evaluation of a given postfix expression.

#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

// Function to push an element onto the stack
void push(int elem) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = elem;
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(char *expr) {
    int i, op1, op2, result;

    for (i = 0; expr[i] != '\0'; i++) {
        printf("%c, ", expr[i]);

        if (isdigit(expr[i])) {
            push(expr[i] - '0'); // Convert character to integer
        } else {
            op2 = pop();
            op1 = pop();
            switch (expr[i]) {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    if (op2 == 0) {
                        printf("Error: Division by zero\n");
                        exit(1);
                    }
                    result = op1 / op2;
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }
            push(result);
        }
    }

    return pop(); // Final result will be at the top of the stack
}

int main() {
    // char expr[] = "542+*3-";  // Example postfix expression
    char expr[] = "23*5+5*";  // Example postfix expression
    int i;

    int result = evaluatePostfix(expr);
    printf("Result: %d\n", result);  // Output: 17
    return 0;
}

