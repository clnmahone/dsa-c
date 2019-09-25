/**
 * @date 5/9/2019
 * 
 * a impletation of deque using array
 * deque 循环队列，环形，内存固定
*/

#include <stdio.h>
#include <stdlib.h>
//data modle
typedef struct Deque
{
    int head;
    int tail;
    int *array;
    int capicity;

} Deque;

#define CAPICITY 5

//opt

//creat
Deque *creatDeque(int capicity)
{
    Deque *deque = (Deque *)malloc(sizeof(Deque));
    deque->head = 0;
    deque->tail = 0;
    deque->array = (int *)malloc(sizeof(int) * capicity);
    deque->capicity=capicity;
    return deque;
}
//length
int length(Deque *deque)
{
    //magic!
    int capicity= deque->capicity;
    return (deque->tail - deque->head + capicity) % capicity;
}

//is full
bool full(Deque *dq)
{
    return (dq->tail + 1) % dq->capicity == dq->head;
}

//is empty
bool empty(Deque *dq)
{
    return dq->head == dq->tail;
}

//enqueue
void EnQueue(Deque *dq, int data)
{
    if (full(dq))
    {
        printf("it is full\n");
        exit(1);
    }
    else
    {
        dq->array[dq->tail] = data;
        dq->tail = (dq->tail + 1) % dq->capicity;
    }
}
//dequeue
int Dequeue(Deque *dq)
{
    if (empty(dq))
    {
        printf("it is empty\n");
        exit(1);
    }
    else
    {
        int data = dq->array[dq->head];
        dq->head = (dq->head + 1) % dq->capicity;
        return data;
    }
}

void show(Deque *dq)
{
    int len = length(dq);
    int p = 0;
    for (int i = 0; i < len; i++)
    {
        p = (dq->head + i) % dq->capicity;
        printf("%d ", dq->array[p]);
    }
    printf("\n");
}

// int main()
// {
//     Deque *dq = creatDeque(5);
//     EnQueue(dq, 1);
//     EnQueue(dq, 2);
//     EnQueue(dq, 3);

//     Dequeue(dq);
//     Dequeue(dq);
//     Dequeue(dq);

//     EnQueue(dq, 1);
//     EnQueue(dq, 2);
//     EnQueue(dq, 3);

//     show(dq);
//     return 0;
// }