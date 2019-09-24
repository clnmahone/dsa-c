/**
 * Deep First Search application in cycle detect of undirected graph
 * using:
 *       adjacency linked list
 *       recursion function
 * 
 * think:
 * We do a BFS traversal of the given graph. 
 * For every visited vertex ‘v’, 
 * if there is an adjacent ‘u’ such that u is already visited
 * and u is not parent of v, then there is a cycle in graph.
 * If we don’t find such an adjacent for any vertex, we say that there is no cycle. 
 * 
 * @date 6/2/2019
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
} Graph;

//new adjListNode
AdjListNode *
newAdjListNode(int vertex)
{
	AdjListNode *newNode = (AdjListNode *)malloc(sizeof(AdjListNode));
	newNode->vertex = vertex;
	newNode->next = NULL;
	return newNode;
}

Graph *newGraph(int V)
{
	Graph *graph = (Graph *)malloc(sizeof(Graph));
	graph->V = V;
	graph->listArray = (AdjList *)malloc(sizeof(AdjList) * V);
	for (int i = 0; i < V; i++)
		graph->listArray[i].head = NULL;
	return graph;
}

void addEdge(Graph *graph, int src, int dest)
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

void printGraph(Graph *graph)
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

bool isCycleUtil(Graph *graph, bool *visited, int startVertex, int parent)
{
	int j=startVertex;
	visited[startVertex] = true;

	//for each adjacency node of v
	AdjListNode *current = graph->listArray[startVertex].head;

	while (current)
	{
		j = current->vertex;
		if (!visited[j])
		{
			if (isCycleUtil(graph, visited, j, startVertex))
				return true;
		}
		else if (current->vertex != parent)
			return true;
		current = current->next;
	}

	return false;
}

bool isCycle(Graph *graph)
{
	int V = graph->V;
	//visited array
	bool visited[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	for (int i = 0; i < V; i++)
	{
		if (!visited[i])
			if (isCycleUtil(graph, visited, i, -1))
				return true;
	}
	return false;
}

int main()
{
	int V = 5;
	Graph *graph = newGraph(V);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 0, 3);
	//addEdge(graph, 3, 1);
	addEdge(graph, 4, 1);

	if (isCycle(graph))
		printf("has cycle");
	else
		printf("no cycle.");
	return 0;
}