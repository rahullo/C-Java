#include <stdio.h>
#include <stdlib.h>

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

        // Create an array of adjacency lists
        graph->adjList = (struct Node**)malloc(numVertices * sizeof(struct Node*));
        if (graph->adjList != NULL) {
            // Initialize each adjacency list as empty
            for (int i = 0; i < numVertices; ++i) {
                graph->adjList[i] = NULL;
            }
        } else {
            // Memory allocation for adjacency lists failed
            free(graph);
            return NULL;
        }
    }
    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Since the graph is undirected, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
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
    // Create a graph with 5 vertices
    struct Graph* graph = createGraph(5);

    // Add edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the graph
    printGraph(graph);

    // Free the memory allocated for the graph
    freeGraph(graph);

    return 0;
}
