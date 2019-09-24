#include <stdio.h>
#include<stdlib.h>
#include "stack.h"
//data mode
typedef struct
{
    int* top;
    int* base;
    int length;
    int capacity;
} Stack;

#define INIT_SIZE 100
#define INCREMENT 10

//options
//creat
Stack* creat(){
    Stack* s=(Stack*)malloc(sizeof(Stack));
    s->base=(int*)malloc(sizeof(int)*INIT_SIZE);
    s->top=s->base;
    s->capacity=INIT_SIZE;
    s->length=0;
    return s;
}

bool isEmpty(Stack* s){
    return s->top==s->base;
}

void isFull(Stack* s){
    if (s->length==s->capacity)
    {
        s->capacity+=INCREMENT;
        s->base=(int*)realloc(s->base,s->capacity*sizeof(int));
    }
    
}

void push(Stack* s, int data){
    //is full?
    isFull(s);
    *(++s->top)=data;
    s->length++;
}



int pop(Stack* s){
    //is empty?
    if(isEmpty(s)){
        printf("no more element");
        exit(1);
    }
    s->length--;
    return *(s->top--);
}

int getTop(Stack* s){

    isEmpty(s);
    return *(s->top);
}
void show(int data){
    printf("%d ",data);
}

void traverse(Stack* s, void (*opt)(int)){
    while(s->top!=s->base){
        (*opt)(*s->top--);
    }
}

int main(){

    Stack* s = creat();
    push(s,1);
    push(s,2);
    push(s,3);
    traverse(s,show);
    
    return 0;
}