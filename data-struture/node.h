//node.h
#ifndef __NODE_H__
#define __NODE_H__

//节点模型
typedef Node{
    int val;
    Node* pointer_1,pointer_2;
}Node;
//节点操作

Node* creatNode(int val,Node* pointer_1,Node* pointer_2);


#endif