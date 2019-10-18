#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define INCREMENT 10;
Stack *creatStack(int capacity)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->capacity = capacity;
    s->items = (int*)malloc(sizeof(int)*capacity);
    s->top = -1;
    return s;
}

// void isFull(Stack *s)
// {
//     if (IS_FULL(s))
//     {
//         s->capacity += INCREMENT;
//         s->items = (int *)realloc(s->items, s->capacity * sizeof(int));
//     }
// }

/**
 * push
 * 
*/
void push(Stack *s, int val)
{

    if (IS_FULL(s))
        printf("push:stack overflow.\n");
    else
        s->items[++s->top] = val;
}

/**
 * pop
 * 
*/
int pop(Stack *s)
{
    if (IS_EMPTY(s))
    {
        printf("pop:stack is empty.\n");
        return -1;
    }
    else
        return s->items[s->top--];
}

/**
 * peek
 * 
*/
int peek(Stack *s)
{

    if (IS_EMPTY(s))
    {
        printf("peek:stack is empty.\n");
        return -1;
    }
    else
        return s->items[s->top];
}

/**
 * traverse
 * 
*/
void stackTraverseTop(Stack *stack, void (*opt)(int))
{
    for (int i = SIZE(stack) - 1; i >= 0; i--)
        opt(stack->items[i]);
}

void stackTraverseBottom(Stack *stack, void (*opt)(int))
{
    for (int i = 0; i < SIZE(stack); i++)
        opt(stack->items[i]);
}

int main(){
    int capacity=9;
    Stack* s = creatStack(capacity);
    for(int i = 0;i<capacity;i++)
        push(s,i);
    stackTraverseTop(s,show);
    //printf("hh");
    //getchar();
    return 0;
}