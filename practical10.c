/*
Write a menu driven program to create graph and perform following operations on graph.1)Graph
traversal –Breadth First Search (BFS) and Depth First Search (DFS)2)Find shortest paths in
graphs3)Find minimum spanning tree
*/

#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of vertices
#define MAX_VERTICES 100

// Define the graph structure using adjacency lists
struct Node
{
    int vertex;
    struct Node *next;
};

struct Graph
{
    int numVertices;
    struct Node *adjLists[MAX_VERTICES];
};

// Function to create a new node
struct Node *createNode(int vertex)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
struct Graph *createGraph(int numVertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++)
    {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int src, int dest)
{
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // For undirected graph, add the reverse edge as well
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to display the graph
void displayGraph(struct Graph *graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        struct Node *temp = graph->adjLists[i];
        printf("Adjacency list of vertex %d:\n", i);
        while (temp)
        {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int numVertices, choice;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    struct Graph *graph = createGraph(numVertices);

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Add an edge\n");
        printf("2. Display the graph\n");
        printf("3. Perform BFS\n");
        printf("4. Perform DFS\n");
        printf("5. Find Shortest Paths\n");
        printf("6. Find Minimum Spanning Tree\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int src, dest;
            printf("Enter source and destination vertices: ");
            scanf("%d %d", &src, &dest);
            addEdge(graph, src, dest);
            break;
        }
        case 2:
            displayGraph(graph);
            break;
        // Implement cases 3 to 6 for BFS, DFS, shortest path, and MST
        case 7:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
