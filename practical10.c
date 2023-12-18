/*
Write a menu driven program to create graph and perform following operations on graph.1)Graph
traversal –Breadth First Search (BFS) and Depth First Search (DFS)2)Find shortest paths in
graphs3)Find minimum spanning tree
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

struct Node
{
    int vertex;
    struct Node *next;
};

struct Graph
{
    int vertices;
    struct Node **adjList;
    int *visited;
};

struct Queue
{
    int items[MAX];
    int front;
    int rear;
};

struct Node *createNode(int vertex)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->adjList = (struct Node **)malloc(vertices * sizeof(struct Node *));
    graph->visited = (int *)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++)
    {
        graph->adjList[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(struct Graph *graph, int src, int dest)
{
    // Add edge from src to dest
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Add edge from dest to src for undirected graph
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void enqueue(struct Queue *q, int value)
{
    if (q->rear == MAX - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        if (q->front == -1)
        {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(struct Queue *q)
{
    int item;
    if (q->front == -1)
    {
        printf("Queue is empty\n");
        item = -1;
    }
    else
    {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear)
        {
            q->front = q->rear = -1;
        }
    }
    return item;
}

void BFS(struct Graph *graph, int startVertex)
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = q->rear = -1;

    graph->visited[startVertex] = 1;
    printf("BFS starting from vertex %d: ", startVertex);
    printf("%d ", startVertex);
    enqueue(q, startVertex);

    while (q->front != -1)
    {
        int currentVertex = dequeue(q);

        struct Node *temp = graph->adjList[currentVertex];
        while (temp != NULL)
        {
            int adjVertex = temp->vertex;
            if (graph->visited[adjVertex] == 0)
            {
                printf("%d ", adjVertex);
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }

    free(q);
}

void DFS(struct Graph *graph, int startVertex)
{
    graph->visited[startVertex] = 1;
    printf("%d ", startVertex);

    struct Node *temp = graph->adjList[startVertex];
    while (temp != NULL)
    {
        int adjVertex = temp->vertex;
        if (graph->visited[adjVertex] == 0)
        {
            DFS(graph, adjVertex);
        }
        temp = temp->next;
    }
}

void shortestPaths(struct Graph *graph, int startVertex)
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = q->rear = -1;

    int distance[MAX];
    for (int i = 0; i < graph->vertices; i++)
    {
        distance[i] = -1;
    }

    distance[startVertex] = 0;
    printf("Shortest paths from vertex %d using BFS:\n", startVertex);

    enqueue(q, startVertex);

    while (q->front != -1)
    {
        int currentVertex = dequeue(q);

        struct Node *temp = graph->adjList[currentVertex];
        while (temp != NULL)
        {
            int adjVertex = temp->vertex;
            if (distance[adjVertex] == -1)
            {
                distance[adjVertex] = distance[currentVertex] + 1;
                printf("Shortest path from %d to %d is %d\n", startVertex, adjVertex, distance[adjVertex]);
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }

    free(q);
}

void minSpanningTree(struct Graph *graph)
{
    printf("Minimum Spanning Tree using Prim's algorithm:\n");

    int parent[MAX];
    int key[MAX];
    int INT_MAX;
    bool mstSet[MAX];

    for (int i = 0; i < graph->vertices; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < graph->vertices - 1; count++)
    {
        int u = -1;
        for (int v = 0; v < graph->vertices; v++)
        {
            if (!mstSet[v] && (u == -1 || key[v] < key[u]))
            {
                u = v;
            }
        }

        mstSet[u] = true;

        struct Node *temp = graph->adjList[u];
        while (temp != NULL)
        {
            int v = temp->vertex;
            if (!mstSet[v] && temp->vertex && key[v] > temp->vertex)
            {
                parent[v] = u;
                key[v] = temp->vertex;
            }
            temp = temp->next;
        }
    }

    for (int i = 1; i < graph->vertices; i++)
    {
        printf("Edge: %d - %d\n", parent[i], i);
    }
}

void display(struct Graph *graph)
{
    printf("Graph:\n");
    for (int i = 0; i < graph->vertices; i++)
    {
        struct Node *temp = graph->adjList[i];
        printf("Vertex %d: ", i);
        while (temp != NULL)
        {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int vertices, choice, startVertex;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    struct Graph *graph = createGraph(vertices);

    do
    {
        printf("\nGraph Operations:\n");
        printf("1. Add edge\n");
        printf("2. Breadth First Search (BFS)\n");
        printf("3. Depth First Search (DFS)\n");
        printf("4. Shortest Paths\n");
        printf("5. Minimum Spanning Tree\n");
        printf("6. Display graph\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter source and destination vertices: ");
            int src, dest;
            scanf("%d %d", &src, &dest);
            addEdge(graph, src, dest);
            break;

        case 2:
            printf("Enter the starting vertex for BFS: ");
            scanf("%d", &startVertex);
            BFS(graph, startVertex);
            break;

        case 3:
            printf("Enter the starting vertex for DFS: ");
            scanf("%d", &startVertex);
            printf("DFS starting from vertex %d: ", startVertex);
            DFS(graph, startVertex);
            printf("\n");
            break;

        case 4:
            printf("Enter the starting vertex for shortest paths: ");
            scanf("%d", &startVertex);
            shortestPaths(graph, startVertex);
            break;

        case 5:
            minSpanningTree(graph);
            break;

        case 6:
            display(graph);
            break;

        case 0:
            printf("Exiting program\n");
            break;

        default:
            printf("Invalid choice, please try again\n");
        }

    } while (choice != 0);

    return 0;
}