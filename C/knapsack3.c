#include<stdio.h>

// Structure to represent an item with weight and value
struct Item {
    int value;
    int weight;
};

// Function to calculate the maximum value using Fractional Knapsack
double fractionalKnapsack(int capacity, struct Item items[], int n) {
    // Calculate the value-to-weight ratios for each item
    double valuePerWeight[n];
    for (int i = 0; i < n; i++) {
        valuePerWeight[i] = (double)items[i].value / items[i].weight;
    }

    // Sort the items based on value-to-weight ratios in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (valuePerWeight[j] < valuePerWeight[j + 1]) {
                // Swap items
                struct Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;

                // Swap corresponding value-to-weight ratios
                double tempRatio = valuePerWeight[j];
                valuePerWeight[j] = valuePerWeight[j + 1];
                valuePerWeight[j + 1] = tempRatio;
            }
        }
    }

    double totalValue = 0.0; // Initialize total value

    // Iterate through sorted items and fill the knapsack
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            // Take the whole item if it fits
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            // Take a fraction of the item if it doesn't fit entirely
            totalValue += valuePerWeight[i] * capacity;
            break;
        }
    }

    return totalValue;
}

// Example usage
int main() {
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int capacity = 50;
    int n = sizeof(items) / sizeof(items[0]);

    printf("Maximum value that can be obtained: %.2f\n", fractionalKnapsack(capacity, items, n));

    return 0;
}
