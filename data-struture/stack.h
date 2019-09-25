#ifndef __STACK_H
#define __STACK_H

#define SIZE(stack) (stack->top + 1)
#define IS_EMPTY(stack) (stack->top == -1)
#define IS_FULL(stack) (stack->top == stack->capacity)

//data mode
typedef struct
{
    int top;
    int *items;
    int capacity;
} Stack;

//opthions
Stack *creatStack(int capacity);
int pop(Stack *s);
void push(Stack *s, int val);
int peek(Stack *s);
void show(int data);
void stackTraverseTop(Stack *stack, void (*opt)(int));
void stackTraverseBottom(Stack *stack, void (*opt)(int));

#endif