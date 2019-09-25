#include <stdio.h>
#include <stdlib.h>

struct ListNode* newNode(int val){
    
    struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
    new->val=val;
    new->next= NULL;
    return new;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    
    struct ListNode* head = newNode(0);
    struct ListNode* current=head;
    
    int v1,v2,c=0,sum;

    while(l1 || l2){
        
        v1=l1==NULL?0:l1->val;
        v2=l2==NULL?0:l2->val;
        
        sum=v1+v2+c;
        c=sum/10;
        
        current->next=newNode(sum%10);
       
        current=current->next;
        if(c) current->next=newNode(c);
        
        if(l1) l1=l1->next;
        if(l2) l2=l2->next;
    }
    return head->next;
}

int main()
{

    struct ListNode *p1 = newNode(1);

    struct ListNode *p2 = newNode(9);
    p2->next = newNode(9);

    struct ListNode *res = addTwoNumbers(p1, p2);

    while (res)
    {
        printf("%d", res->val);
        res = res->next;
    }

    return 0;
}