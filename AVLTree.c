/**
 * balance binary search tree
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

enum TreeType
{
    LL,
    LR,
    RR,
    RL
};

//shape recognise

TreeType shape_rec(Node *root)
{
    if (root->lchild && !root->rchild)
    {
        Node *L = root->lchild;
        if (L->lchild)
            return LL;
        else if (L->rchild)
            return LR;
    }

    if (root->rchild && !root->lchild)
    {
        Node *R = root->rchild;
        if (R->rchild)
            return RR;
        else if (R->lchild)
            return RL;
    }
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

/**
 * LL Type
 *   root
 *    /
 * pivot
 *  / \
 * L   *
*/
Node *LL_rotate(*Node root)
{
    //pivot
    Node *pivot = root->lchild;
    root->lchild = pivot->rchild;
    pivot->rchild = root;
    return pivot;
}
/**
 * RR Type
 * root
 *   \
 *   pivot
 *   / \
 *  *   R
*/
Node *RR_rotate(Node *root)
{
    Node *pivot = root->rchild;
    root->rchild = pivot->lchild;
    pivot->lchild = root;
    return pivot;
}

/**
 * LR type
 *   root
 *    /
 *   L
 *  / \
 * *   R
*/
Node *LR_rotate(*Node root)
{
    // Node *L = root->lchild;
    // Node *R = L->rchild;
    // //rotate
    // root->lchild = R;
    // R->lchild = L;

    // L->rchild = NUll;
    // LL_rotate(root);

    root->lchild = RR_rotate(root->lchild);
    LL_rotate(root);
}

/**
 * RL type
 *   root
 *     \
 *      R
 *     / \
 *    L   *
*/
Node *RL_rotate(Node *root)
{
    // Node *R = root->rchild;
    // Node *L = R->lchild;
    // //rotate
    // root->rchild = L;
    // L->rchild = R;
    // R->lchild = Null;
    // RR_rotate(root);

    root->rchild = LL_rotate(root->rchild);
    RR_rotate(root);
}

//insert
void insertAVL(Node *T, int key)
//T-----tree
//e-----new node
{
    //if blank tree
    if (!T)
    {
        T = (Node *)malloc(sizeof(Node));
        T->lchild = T->rchild = NULL;
        T->bf = 0;
        T->data = key;
    }
    //find the same element
    else if (search(T) == 0)
        return -1;
    //start insert
    //go left
    else if (key < T->data)
        insertAVL(T->lchild, key);
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

//un-balance tree locate
Node *locate(Node *root)
{
}
//balance
void balance(Node *root)
{
    TreeType tt = shape_rec(root);
    switch (tt)
    {
    case LL:
        LL_rotate(root);
        break;

    default:
        break;
    }
}

int main()
{

    return 0;
}