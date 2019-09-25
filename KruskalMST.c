/**
 * minum spanning tree
 * find-union method to find cycle in graph
 * kuckral's MST(greedy algorithm)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Edge
typedef struct
{
    int src, des;
    //set default weight as 0
    int weight = 0;
} Edge;

//Graph
typedef struct
{
    int V, E;
    Edge *edge;
} Graph;

//subset
typedef struct Subset
{
    int rank;
    int parent;
};

//new Graph
Graph *newGraph(int V, int E)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->E = E;
    graph->V = V;
    graph->edge = (Edge *)malloc(sizeof(Edge) * graph->E);
    return graph;
}

//find
int find(Subset *subsets, int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

//union
int Union(Subset *subsets, int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int isCycle(Graph *graph)
{
    Subset *subsets = (Subset *)malloc(graph->V * sizeof(Subset));

    for (int i = 0; i < graph->V; i++)
    {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    for (int i = 0; i < graph->E; i++)
    {
        int x = find(subsets, graph->edge[i].src);
        int y = find(subsets, graph->edge[i].des);
        if (x == y)
            return 1;
        Union(subsets, x, y);
    }
    return 0;
}

int myComp(const void *a, const void *b)
{
    Edge *aa = (Edge *)a;
    Edge *bb = (Edge *)b;
    return aa->weight > bb->weight;
}

Edge *KruskalMST(Graph *graph)
{
    int V = graph->V;
    int E = graph->E;
    //Edge* result= (Edge*)malloc(sizeof(Edge)*(V-1);
    Edge result[V - 1];
    //sort the edge by their weight
    qsort(graph->edge, E, sizeof(Edge), myComp);

    //subsets initional
    Subset subsets[V];
    for (int i = 0; i < graph->V; i++)
    {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    //choose V-1 min edges and they in a circle
    int e = 0;
    int i = 0;
    while (e < V - 1)
    {
        Edge next_min = graph->edge[i++];

        int x = find(subsets, next_min.src);
        int y = find(subsets, next_min.des);
        if (x != y)
        {
            result[e++] = next_min;
            Union(subsets, x, y);
        }
    }
    return result;
}
int main()
{
    /* Let us create following weighted graph 
             10 
        0--------1 
        |  \     | 
       6|   5\   |15 
        |      \ | 
        2--------3 
            4       */
    int V = 4; // Number of vertices in graph
    int E = 5; // Number of edges in graph
    Graph *graph = newGraph(V, E);

    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].des = 1;
    graph->edge[0].weight = 10;

    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].des = 2;
    graph->edge[1].weight = 6;

    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].des = 3;
    graph->edge[2].weight = 5;

    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].des = 3;
    graph->edge[3].weight = 15;

    // add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].des = 3;
    graph->edge[4].weight = 4;

    KruskalMST(graph);

    return 0;
}