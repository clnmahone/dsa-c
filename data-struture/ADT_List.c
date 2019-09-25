//ADT_List.c
#include<stdio.h>
#include<stdlib.h>
#include "ADT_List.h"

List *creatList()
{
    List* list = (List*)malloc(sizeof(List));
    list->iterator=-1;
}
void destroyList(List* list)
{
    free(list);
}
void clearList(List* list)
{
    
}
void addNode(List *list, int index, int val){}
void deleteNode(List *list, int index){}
Node *getNode(List *list, int index){}
int getIndex(List *list, int val){}
void traverseList(List *list, void (*visit)(Node *)){}