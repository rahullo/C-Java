// Write a program to find approachable nodes from a given source of a given graph using
// queue as an intermediate data structure (BFS).

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Define a structure for the graph
struct Graph {
    int numVertices;
    struct Node** adjList;
};

// Function to create a new node
struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode != NULL) {
        newNode->vertex = vertex;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    if (graph != NULL) {
        graph->numVertices = numVertices;
        graph->adjList = (struct Node**)malloc(numVertices * sizeof(struct Node*));
        if (graph->adjList != NULL) {
            for (int i = 0; i < numVertices; ++i) {
                graph->adjList[i] = NULL;
            }
        } else {
            free(graph);
            return NULL;
        }
    }
    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Function to perform Breadth-First Search on the graph
void BFS(struct Graph* graph, int startVertex) {
    // Create an array to keep track of visited vertices
    bool* visited = (bool*)malloc(graph->numVertices * sizeof(bool));
    if (visited == NULL) {
        return; // Memory allocation failed
    }
    // Initialize all vertices as not visited
    for (int i = 0; i < graph->numVertices; ++i) {
        visited[i] = false;
    }
    // Create a queue for BFS
    int* queue = (int*)malloc(graph->numVertices * sizeof(int));
    if (queue == NULL) {
        free(visited);
        return; // Memory allocation failed
    }

    int front = 0; // Front of the queue
    int rear = 0;  // Rear of the queue

    // Enqueue the start vertex and mark it as visited
    queue[rear++] = startVertex;
    visited[startVertex] = true;

    printf("Breadth-First Traversal starting from vertex %d: ", startVertex);

    while (front < rear) {
        // Dequeue a vertex from the queue and print it
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Traverse the adjacency list of the dequeued vertex
        struct Node* current = graph->adjList[currentVertex];
        while (current != NULL) {
            // If the adjacent vertex is not visited, enqueue it and mark it as visited
            if (!visited[current->vertex]) {
                queue[rear++] = current->vertex;
                visited[current->vertex] = true;
            }
            current = current->next;
        }
    }

    printf("\n");

    // Free allocated memory
    free(visited);
    free(queue);
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; ++i) {
        struct Node* current = graph->adjList[i];
        printf("Adjacency list of vertex %d: ", i);
        while (current != NULL) {
            printf("%d ", current->vertex);
            current = current->next;
        }
        printf("\n");
    }
}

// Function to free the memory allocated for the graph
void freeGraph(struct Graph* graph) {
    if (graph != NULL) {
        for (int i = 0; i < graph->numVertices; ++i) {
            struct Node* current = graph->adjList[i];
            while (current != NULL) {
                struct Node* next = current->next;
                free(current);
                current = next;
            }
        }
        free(graph->adjList);
        free(graph);
    }
}

int main() {
    struct Graph* graph = createGraph(7);

    // addEdge(graph, 0, 1);
    // addEdge(graph, 0, 2);
    // addEdge(graph, 1, 3);
    // addEdge(graph, 1, 4);
    // addEdge(graph, 2, 5);
    // addEdge(graph, 2, 6);

    // Add edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 5, 3);
    addEdge(graph, 6, 3);
    addEdge(graph, 5, 2);
    addEdge(graph, 6, 1);


    printGraph(graph);
    printf("\n");
    BFS(graph, 0);

    freeGraph(graph);

    return 0;
}
