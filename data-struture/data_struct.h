
/**
 * 关于realloc()函数
 * 先判断当前的指针是否有足够的连续空间，
 * 如果有，扩大mem_address指向的地址，并且将mem_address返回，
 * 如果空间不够，先按照newsize指定的大小分配空间，将原有数据从头到尾拷贝到新分配的内存区域，
 * 而后释放原来mem_address所指内存区域（注意：原来指针是自动释放，不需要使用free），
 * 同时返回新分配的内存区域的首地址。即重新分配存储器块的地址。
*/

/**
 * ADT List(抽象线性表)
 * basic options
 *  1.construct an empty list
 *  2.destroy a list
 *  3.clear a list to empty
 *  4.get list length
 *  5.get element by index
 *  6.locate(L,compare())locate an element
 *  7.get prior element of an element
 *  8.get next element of an element
 *  9.insert an element
 *  10.delete am element
 *  11.ListTraverse(L,visit())----------traver a list
 */

#ifndef _DS_H
#define _DS_H

#include "stack.h"

#include "vector.h"

//dynamic array
typedef struct Vector
{
    int size;
    int capacity;
    int *arr;
};
Vector* creatVector(int capacity);

//Queue
typedef struct
{
    int head;
    int tail;
    int *array;
    int capicity;

} Deque;

//Stack
typedef struct
{
    int* top;
    int* base;
    int length;
    int capacity;
} Stack;

Stack* creatStack(int capacity);

//Linked Node
typedef struct Node
{
    int val;
    Node *next;
} Node;



//adjList
typedef struct
{
    Node *head;
} AdjList;

//ALGraph
typedef struct
{
    int V;
    AdjList *listArray;
} ALGraph;


#endif
