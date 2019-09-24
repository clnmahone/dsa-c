#include <stdio.h>
#include <stdlib.h>

//data model
typedef struct Node
{
    int data;
    struct Node *next;
}Node;

//options

//creatNode
Node *creatNode()
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->next = NULL;
    return node;
}

//push
void push(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    //always push after the head
    newNode->next = head->next;
    head->next = newNode;
}

//insert at index
void insert(struct Node *head, int index, int data)
{
    int i = 0;
    struct Node *p = head;
    while (p && i < index)
    {
        p = p->next;
        i++;
    }
    //build the newNode
    struct Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    //insert
    newNode->next = p->next;
    p->next = newNode;
}

//del
void del(struct Node *head, int index)
{
    int i = 0;
    struct Node *p = head;
    while (p && i < index)
    {
        p = p->next;
        i++;
    }
    if (!(p->next) || i > index)
        return;
    struct Node *q = p->next;
    p->next = q->next;
    //free(p->next);
}

void show(struct Node *head)
{
    struct Node *p = head->next;
    while (!p == NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = creatNode();
    push(head, 1);
    push(head, 2);
    push(head, 3);
    insert(head, 2, 999);
    show(head);
    del(head,2);
    show(head);

    return 0;
}