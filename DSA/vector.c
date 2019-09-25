//vector.c
#include <stdlib.h>
#include "vector.h"
//initinal
void vector_init(Vector *v, int capacity)
{
    v->capacity = capacity;
    v->size = 0;
    v->data = (int *)malloc(sizeof(int) * v->capacity);
}
//add
void vector_add(Vector *v, int data)
{
    //is full
    vector_isFull(v);

    v->data[v->size++] = data;
}
//insert
void vector_insert(Vector *v, int index, int data)
{
    if (index < 0 || index >= v->size)
        exit(1);

    vector_isFull(v);

    for (int i = v->size - 1; i >= index; i--)
    {
        v->data[i + 1] = v->data[i];
    }
    v->data[index] = data;

    //alternative way
    // int *p, *q;
    // q = &(v->data[index]);
    // for (p = &(v->data[v->size - 1]); p >= q; p--)
    // {
    //     *(p+1)=*p;
    // }
    // *q=data;

    v->size++;
}
//remove
void vector_remove(Vector *v, int index)
{
    if (index < 0 || index >= v->size)
        exit(1);
    // for (int i = index; i < v->size - 1; i++)
    // {
    //     v->data[i] = v->data[i + 1];
    // }
    int *p, *q;
    p = &(v->data[index]);
    q = &(v->data[v->size - 1]);
    for (++p; p <= q; ++p)
        *(p - 1) = *p;

    v->size--;
}
//set
void vector_set(Vector *v, int index, int data)
{
    if (index < 0 || index >= v->size)
        exit(1);

    v->data[index] = data;
}
//find
int vector_indexOf(Vector *v, int key)
{
    for (int i = 0; i < v->size; i++)
    {
        if (v->data[i] == key)
            return i;
    }
    return -1;
}
//get
int vector_get(Vector *v, int index)
{
    if (index < 0 || index >= v->size)
        exit(1);
    return v->data[index];
}
//free up
void vector_freeUp(Vector *v)
{
    free(v->data);
}

//show
void vector_show(Vector *v)
{
    for (int i = 0; i < v->size; i++)
    {
        printf("%d ", v->data[i]);
    }
    printf("\n");
}

//isFull
void vector_isFull(Vector *v)
{
    if (v->size >= v->capacity)
    {
        v->capacity *= GROW_UP_FATOR;
        v->data = (int *)realloc(v->data, sizeof(int) * v->capacity);
    }
}
