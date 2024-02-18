#include <stdio.h>

struct Item {
    int value;
    int weight;
};

int compare(const void *a, const void *b) {
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;
    double ratio1 = (double)item1->value / item1->weight;
    double ratio2 = (double)item2->value / item2->weight;
    if (ratio1 > ratio2) {
        return -1;
    } else if (ratio1 < ratio2) {
        return 1;
    } else {
        return 0;
    }
}

// Function to solve the knapsack problem using a greedy algorithm
void knapsack(struct Item items[], int n, int capacity) {
    // Sort items by value-to-weight ratio in descending order
    qsort(items, n, sizeof(struct Item), compare);

    // Initialize the total value and weight in the knapsack
    int total_value = 0;
    int total_weight = 0;

    // Add items to the knapsack until the capacity is reached
    for (int i = 0; i < n; i++) {
        if (total_weight + items[i].weight <= capacity) {
            total_value += items[i].value;
            total_weight += items[i].weight;
            printf("Added item %d with value %d and weight %d\n", i + 1, items[i].value, items[i].weight);
        } else {
            break;
        }
    }

    printf("Total value in knapsack: %d\n", total_value);
}

int main() {
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    for (int i = 0; i < n; i++) {
        printf("Enter the value and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    knapsack(items, n, capacity);

    return 0;
}
