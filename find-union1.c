/**
 * minum spanning tree
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Edge
{
    int src, des;
    //set default weight as 0
    int weight = 0;
} Edge;

typedef struct Graph
{
    int V, E;
    Edge *edge;
} Graph;

Graph *newGraph(int V, int E)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->E = E;
    graph->V = V;
    graph->edge = (Edge *)malloc(sizeof(Edge) * graph->E);
    return graph;
}

int find(int *parent, int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void Union(int *parent, int x, int y)
{
    int xx = find(parent, x);
    int yy = find(parent, y);
    if (xx != yy)
        parent[xx] = yy;
}

int isCycle(Graph *graph)
{
    int *parent = (int *)malloc(sizeof(int) * graph->V);
    /**
     * memset
     * from string.h
     * set all array elemnts to a same value 
     * 
    */
    memset(parent, -1, graph->V * sizeof(int));

    for (int i = 0; i < graph->E; i++)
    {
        int x = find(parent, graph->edge[i].src);
        int y = find(parent, graph->edge[i].des);
        if (x == y)
            return 1;
        Union(parent, x, y);
    }
    return 0;
}

int main()
{
    int V = 3;
    int E = 2;
    Graph *graph = newGraph(V, E);

    //0-1
    graph->edge[0].src = 0;
    graph->edge[0].des = 1;

    //1-2
    graph->edge[1].src = 1;
    graph->edge[1].des = 2;

    if (isCycle(graph))
        printf("cycle");
    else
        printf("no cycle");

    return 0;
}