/**
 * @date 5/6/2019
 * A linked list, doubly, add and remove form the 
 * head and tail. Imitated from java LinkedList Class.
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    Node *prev;
    Node *next;
} Node;

//one alternative
//typedef struct Node Node;


typedef struct
{
    Node *first;
    Node *last;
    unsigned size;
} LinkedList;

Node *creatNode(Node *prev, int data, Node *next)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = data;
    n->prev = prev;
    n->next = next;
    return n;
}
//construct a empty list
LinkedList *nLinkedList()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->size = 0;
    list->first = NULL;
    list->last = NULL;
    return list;
}

void addFirst(LinkedList *list, int data)
{
    Node* first= list->first;
    Node *newNode = creatNode(NULL, data, list->first);
    list->first = newNode;

    if (first == NULL)
        list->last = newNode;
    else
        first->prev = newNode;
    list->size++;
}
void addLast(LinkedList *list, int data)
{
    Node *last = list->last;
    Node *newNode = creatNode(last, data, NULL);
    list->last = newNode;

    if (last == NULL)
        list->first = newNode;
    else
        last->next = newNode;

    list->size++;
}
Node *removeFirst(LinkedList *list)
{
    Node *first = list->first;

    if (!first)
    {
        printf("no element");
        exit(1);
    }

    Node *next = first->next;
    list->first=next;
    if (next == NULL)
        list->last = NULL;
    else
        next->prev = NULL;

    list->size--;
    //free(first);
    return first;
}

Node* removeLast(LinkedList *list) {
    Node* last = list->last;
    if(last==NULL){
        printf("no element");
        exit(1);
    }
    Node* prev= last->prev;
    list->last=prev;
    if(prev==NULL)
        list->first=NULL;
    else
        prev->next=NULL;
    //free(last);
    list->size--;
    return last;
}

void show(int data){
    printf("%d ",data);
}

void traverse(LinkedList* list,void (*opt)(int)){
    Node* p = list->first;
    while (p)
    {
        (*opt)(p->data);
        p=p->next;
    }
    
}

int main()
{

    LinkedList *list = nLinkedList();
    addFirst(list, 1);
    addFirst(list, 2);
    addLast(list, 3);
    removeFirst(list);
    removeLast(list);
    traverse(list,show);
    return 0;
}
