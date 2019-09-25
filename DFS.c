/**
 * Deep First Search
 * using:
 *       adjacency list
 *       recursion function
 *       undirected graph
 * @date 6/1/2019
*/

#include <stdio.h>
#include <stdlib.h>

//邻接表
//adjListNode
typedef struct adjListNode
{
    int vertex;
    adjListNode *next;
} AdjListNode;

//adjList
typedef struct
{
    adjListNode *head;
} AdjList;

//graph
typedef struct
{
    int V;
    AdjList *listArray;
} ALGraph;

//new adjListNode
AdjListNode *
newAdjListNode(int vertex)
{
    AdjListNode *newNode = (AdjListNode *)malloc(sizeof(AdjListNode));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

ALGraph *newGraph(int V)
{
    ALGraph *graph = (ALGraph *)malloc(sizeof(ALGraph));
    graph->V = V;
    graph->listArray = (AdjList *)malloc(sizeof(AdjList) * V);
    for (int i = 0; i < V; i++)
        graph->listArray[i].head = NULL;
    return graph;
}

void addEdge(ALGraph *graph, int src, int dest)
{

    // Add an edge from src to dest.
    AdjListNode *newNode = newAdjListNode(dest);

    //The new node is added at the begining of src adjacency list.
    newNode->next = graph->listArray[src].head;
    graph->listArray[src].head = newNode;

    // Since graph is undirected, add an edge from dest to src also
    newNode = newAdjListNode(src);
    newNode->next = graph->listArray[dest].head;
    graph->listArray[dest].head = newNode;
}

void printGraph(ALGraph *graph)
{
    int V = graph->V;
    for (int i = 0; i < V; i++)
    {
        AdjListNode *current = graph->listArray[i].head;
        printf("vertext %d: ", i);
        while (current)
        {
            printf("->%d", current->vertex);
            current = current->next;
        }
        printf("\n");
    }
}

void DFS(ALGraph *graph, int startVertex, bool* visited)
{

    visited[startVertex] = true;
    printf("%d ", startVertex);

    //find adjNode of s
    AdjListNode *current = graph->listArray[startVertex].head;
    int j;
    while (current)
    {
        j = current->vertex;
        if (!visited[j])
        {
            visited[j] = true;
            DFS(graph, j, visited);
        }
        current = current->next;
    }
}

void DFSUtil(ALGraph* graph, int startVertex)
{
    int V = graph->V;
    //visited array
    bool visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    DFS(graph,startVertex,visited);
}

int main()
{
    int V = 5;
    ALGraph *graph = newGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 3, 1);
    addEdge(graph, 4, 1);
    printGraph(graph);
    //DFSUtil(graph, 0);

    return 0;
}