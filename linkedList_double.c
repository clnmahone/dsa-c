#include <stdio.h>
#include <stdlib.h>
/**
 * 双向链表
 * 
 * 
 * 
*/

typedef struct Node
{
    int data;
    Node *prior;
    Node *next;
} Node;

Node *creat()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    head->prior = NULL;
    head->data = NULL;
    return head;
}

void push(Node *head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    Node *q = head->next;
    if (q != NULL)
        q->prior = newNode;
    newNode->next = q;

    newNode->prior = head;
    head->next = newNode;
}

Node *getElem(Node *head, int index)
{
    Node *p = head;
    for (int i = 0; i < index && p; i++)
        p = p->next;
    return p;
}

void insert(Node *head, int index, int data)
{

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    //空链表
    if (head->next == NULL)
    {
        newNode->next = head->next;
        newNode->prior = head;
        head->next = newNode;
    }
    else
    {   
        Node* p = head;
        if (!(p = getElem(head, index)))
        {
            printf("invald insert position");
            return;
        }

        Node *q = p->next;
        newNode->next = q;
        q->prior = newNode;

        p->next = newNode;
        newNode->prior = p;
    }
}

void del(Node *head, int index)
{
    Node* p = head;
    
    if (!(p = getElem(head, index)))
    {
        printf("invald insert position");
        return;
    }

    Node* q = p->next;
    p->next=q->next;
    q->next->prior=q;

}

void show(Node *head)
{
    Node *p = head->next;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}



int main()
{

    Node *head = creat();
    push(head, 1);
    push(head, 2);
    push(head, 3);
    //insert(head, 1, 99);
    del(head,1);
    show(head);
    return 0;
}