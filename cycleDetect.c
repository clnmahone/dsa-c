/**
 * Deep First Search application in cycle detect of directed graph
 * using:
 *       adjacency linked list
 *       recursion function
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
		graph->listArray[i].head = newAdjListNode(i);
	return graph;
}

void addEdge(Graph *graph, int src, int dest)
{

	// Add an edge from src to dest.
	AdjListNode *newNode = newAdjListNode(dest);

	//The new node is added at the begining of src adjacency list.
	newNode->next = graph->listArray[src].head->next;
	graph->listArray[src].head->next = newNode;

	// Since graph is undirected, add an edge from dest to src also
	// newNode = newAdjListNode(src);
	// newNode->next = graph->listArray[dest].head;
	// graph->listArray[dest].head = newNode;
}

void printGraph(Graph *graph)
{
	int V = graph->V;
	for (int i = 0; i < V; i++)
	{
		AdjListNode *current = graph->listArray[i].head;
		printf("Vertext %d", current->vertex);
		current=current->next;
		while (current)
		{
			printf("->%d", current->vertex);
			current = current->next;
		}
		printf("\n");
	}
}

bool isCycleUtil(Graph *graph, bool *visited, bool *recStack, int startVertex)
{
	int j=startVertex;
	if (!visited[startVertex])
	{
		visited[startVertex] = true;
		recStack[startVertex] = true;

		//for each adjacency node of v
		AdjListNode *current = graph->listArray[startVertex].head->next;

		while (current)
		{
			j = current->vertex;
			if (!visited[j] && isCycleUtil(graph, visited, recStack, j))
				return true;
			else if (recStack[j])
				return true;
			current = current->next;
		}
	}
	recStack[j] = false;
	return false;
}

bool isCycle(Graph *graph)
{
	int V = graph->V;
	//visited array
	bool visited[V];
	bool recStack[V];

	for (int i = 0; i < V; i++)
		visited[i] = false;
	for (int i = 0; i < V; i++)
		recStack[i] = false;

	for (int i = 0; i < V; i++)
	{
		if (isCycleUtil(graph, visited, recStack, i))
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
	addEdge(graph, 3, 1);
	addEdge(graph, 4, 1);

	//printGraph(graph);
	if (isCycle(graph))
		printf("has cycle");
	else
		printf("no cycle.");
	return 0;
}