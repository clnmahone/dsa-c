//node.c

#ifndef __NODE_H
#define __NODE_H

#include "node.h"
#include<stdlib.h>
Node* creatNode(int val,Node* pointer_1,Node* pointer_2)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val=val;
    newNode->pointer_1=pointer_1;
    newNode->pointer_2=pointer_2;
}

#endif