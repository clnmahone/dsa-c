#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node
{
    int date;
    struct Node *next;
};

void add(struct Node *head, int data)
{
    struct Node *current;
    current=head;
    while(current->next!=NULL){
        current=current->next;
    }
    
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    current->next = newNode;
    newNode->date = data;
    newNode->next = NULL;

}

void print(struct Node *head)
{
    struct Node *current;
    current = head->next;
    while (current->next != NULL)
    {
        printf("%d->", current->date);
        current=current->next;
    }
    printf("%d", current->date);
}

int main()
{
    //head
    struct Node *head;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->date = 0;
    head->next = NULL;

    //add
    add(head, 3);
    add(head, 4);
    add(head, 5);
    add(head, 6);

    //print

    print(head);
    //system("pause");
    return 0;
}
