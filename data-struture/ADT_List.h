//ADT_List.h

#ifndef __ADT_LIST_H
#define __ADT_LIST_H

#include "node.h"

typedef struct List
{
    int iterator;
} List;

List *creatList();
void destroyList(List* list);
void clearList(List* list);
void addNode(List *list, int index, int val);
void deleteNode(List *list, int index);
Node *getNode(List *list, int index);
int getIndex(List *list, int val);
void traverseList(List *list, void (*visit)(Node *));

#endif