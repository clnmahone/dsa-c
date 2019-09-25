/**
 * AVL tree----balance binary search tree
 * 
*/
#include <stdio.h>
#include <stdlib.h>
//node
typedef struct Node
{
    int data;
    //balance factor
    int bf;
    Node *lchild, *rchild;
} Node;

Node* newNode(int key)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data=key;
    node->lchild=NULL;
    node->rchild=NULL;
    node->bf=0;
    return node;
}

/**
 * right rotate
 *    z
 *   /
 *  y
 *   \
 *    T1
*/

void R_rotate(Node *z)
{
    Node *y = z->lchild;
    Node *T1 = y->rchild;

    y->rchild = z;
    z->lchild = T1;
}

/**
 * left rotate
 *  z
 *   \
 *    y
 *   /
 *  T1
*/

void L_rotate(Node *z)
{
    Node *y = z->rchild;
    Node *T1 = y->lchild;

    y->lchild = z;
    z->rchild = T1;
}

//insert
void insertAVL(Node *T, int key)
//T-----tree
//e-----new node
{
    //if blank tree
    if (!T)
        T= newNode(key);
    //find the same element
    else if (key==T->data)
        return -1;
    //go left
    else if (key < T->data)
        insertAVL(T->lchild, key);
    //go right
    else
        insertAVL(T->rchild,key);
}

//search
int search(Node *T, int key)
{
    if (!T)
        return -1;
    else
    {
        if (key == T->data)
            return 0;
        else if (key < T->data)
            return search(T->lchild, key);
        else
            return search(T->rchild, key);
    }
}

//del
void del(Node *T)
{
    
}

int main()
{

    return 0;
}