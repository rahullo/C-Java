#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

struct node {
    char *key;
    char *value;
    struct node *next;
};

struct node *hash_table[TABLE_SIZE];

int hash_function(char *key) {
    int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash += key[i];
    }
    return hash % TABLE_SIZE;
}

void insert(char *key, char *value) {
    int index = hash_function(key);
    printf("%d\n", index);
    struct node *head = hash_table[index];

    struct node *new_node = malloc(sizeof(struct node));
    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = head;

    hash_table[index] = new_node;
}

char *search(char *key) {
    int index = hash_function(key);
    struct node *head = hash_table[index];

    while (head != NULL) {
        if (strcmp(head->key, key) == 0) {
            return head->value;
        }
        head = head->next;
    }

    return NULL;
}

int main() {
    insert("Apple", "red");
    insert("Banana", "yellow");
    insert("Grape", "purple");
    insert("Mango", "yellow");

    char *value = search("Mango");
    if (value != NULL) {
        printf("Mango is %s\n", value);
    } else {
        printf("Key not found\n");
    }

    return 0;
}
