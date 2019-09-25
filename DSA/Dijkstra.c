#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V_NUM 6
#define INFINITY 99
/**
 * 2-dimension array as a parameter
 * (*a)[], because *<[]
 * 
*/
void printMatrix(int (*a)[V_NUM])
{
    for (int i = 0; i < V_NUM; i++)
    {
        for (int j = 0; j < V_NUM; j++)
        {
            printf("%2d ", a[i][j]);
        }
        printf("\n");
    }
}

printArray(int *a)
{
    for (int i = 0; i < V_NUM; i++)
    {
        printf("%d", a[i]);
    }
}

void initMatrix(int (*a)[V_NUM], int val)
{
    for (int i = 0; i < V_NUM; i++)
    {
        for (int j = 0; j < V_NUM; j++)
        {
            a[i][j] = val;
        }
    }
}

void Dijkstra(int (*adjMatrix)[V_NUM], bool (*P)[V_NUM], int *D)
{

    bool final[V_NUM];

    for (int v = 0; v < V_NUM; v++)
    {
        final[v] = false;
        D[v] = adjMatrix[0][v];
        for (int w = 0; w < V_NUM; w++)
            P[v][w] = false;
        if (D[v] < INFINITY)
        {
            P[v][0] = true;
            P[v][v] = true;
        }
    }

    D[0] = 0;
    final[0] = true;

    for (int v = 1; v < V_NUM; v++)
    {
        int min = INFINITY;
        for (int w = 0; w < V_NUM; w++)
            if (!final[w])
                if (D[w] < min)
                {
                    v = w;
                    min = D[w];
                }

        final[v] = true;

        for (int w = 0; w < V_NUM; w++)
        {
            if (!final[w] && min + adjMatrix[v][w] < D[w])
            {
                D[w] = min + adjMatrix[v][w];
                P[w][v] = true;
                P[w][w] = true;
            }
        }
    }
}

int main()
{

    int adjMatrix[V_NUM][V_NUM];
    initMatrix(adjMatrix, INFINITY);

    adjMatrix[0][2] = 10;
    adjMatrix[0][4] = 30;
    adjMatrix[0][5] = 100;
    adjMatrix[1][2] = 5;
    adjMatrix[2][3] = 50;
    adjMatrix[3][5] = 10;
    adjMatrix[4][3] = 20;
    adjMatrix[4][5] = 60;
    printMatrix(adjMatrix);

    bool pathMatrix[V_NUM][V_NUM];
    int shortPath[V_NUM];

    Dijkstra(adjMatrix, pathMatrix, shortPath);

    for (int i = 0; i < V_NUM; i++)
    {
        printf("%2d ", shortPath[i]);
    }
    printf("\n");

    for (int i = 0; i < V_NUM; i++)
    {
        for (int j = 0; j < V_NUM; j++)
        {
            printf("%2d ", pathMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
