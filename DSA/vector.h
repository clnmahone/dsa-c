//vector.h

#ifndef __VECTOR_H
#define __VECTOR_H

//data modle
typedef struct
{
    int size;
    int capacity;
    int *data; //元素首地址
} Vector;

#define GROW_UP_FATOR 2

//options

//initinal
void vector_init(Vector *v, int capacity);
//add
void vector_add(Vector *v, int data);
//insert
void vector_insert(Vector *v, int index, int data);
//remove
void vector_remove(Vector *v, int data);
//set
void vector_set(Vector *v, int index, int data);
//find
int vector_indexOf(Vector *v, int data);
//get
int vector_get(Vector *v, int index);
//free up
void vector_freeUp(Vector *v);
//show
void vector_show(Vector *v);
//isFull
void vector_isFull(Vector *v);

#endif