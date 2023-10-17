/*
Implementation of Graph and Searching using DFS 
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure for representing a node in the adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Structure for representing a graph
typedef struct Graph {
    int numVertices;
    Node* adjList[MAX_VERTICES];
    int visited[MAX_VERTICES];
} Graph;

// Function to create a new node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with 'n' vertices
Graph* createGraph(int n) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = n;
    for (int i = 0; i < n; i++) {
        graph->adjList[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Function to add an edge between two vertices
void addEdge(Graph* graph, char src, char dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

// Depth-First Search (DFS) function
void DFS(Graph* graph, int vertex) {
    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    Node* temp = graph->adjList[vertex];
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (graph->visited[adjVertex] == 0) {
            DFS(graph, adjVertex);
        }
        temp = temp->next;
    }
}

int main() {
    int numVertices = 4;
    Graph* graph = createGraph(numVertices);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    printf("DFS starting from vertex 0:\n");
    DFS(graph, 0);
    return 0;
}

/*
OUPUT:
DFS starting from vertex 0:
0 2 3 1
*/