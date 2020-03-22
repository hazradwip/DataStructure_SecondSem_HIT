#include "linked_list.h"

/*
* Create Lined List
*/

Node *create(Node *head, int x)
{
    Node *p, *temp;

    temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;

    if (head == NULL)
        head = temp;
    else
    {
        p = head;
        while (p->next != NULL)
            p = p->next;
        p->next = temp;
    }

    return head;
}

/*
* Add a Node to Linked List
*/

Node *insert_beg(Node *head, int x)
{
    Node *temp;

    temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->next = head;

    head = temp;

    return head;
}

Node *insert_end(Node *head, int x)
{
    Node *p, *temp;

    temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;

    p = head;
    while (p->next != NULL)
        p = p->next;
    p->next = temp;

    return head;
}

Node *insert_any(Node* head,int pos,int x)
{
    if(pos==1)
        head=insert_beg(head,x);
    else if(pos==(count(head)+2))
        head=insert_end(head,x);
    else
    {
        Node *q,*t;
        q=(Node*)malloc(sizeof(Node));
        q->data=x;
        q->next=NULL;
        int c=1;
        t=head;
        while(t->next!=NULL)
        {
            if(c==pos-1)
            {
                q->next=t->next;
                t->next=q;
            }
            c++;
            t=t->next;
        }
    }
    return head;
}

/*
* Delete a Node from Linked List
*/

Node *del_beg(Node* head)
{
    Node* p;
    p=head;
    if(head==NULL)
        printf("\nNo Node to delete\n");
    else
        head=head->next;
        free(p);
    return head;
}
Node *del_end(Node* head)
{
    Node *p,*t;
    p=head;
    if(head==NULL)
        printf("\n No need to delete\n");
    else if(p->next==NULL)
    {
        head=NULL;
        printf("\nNULL\n");
        free(p);
    }
    else
    {
        while(p->next!=NULL)
        {
            t=p;
            p=p->next;
        }
    }
    t->next=NULL;
    free(p);
    return head;
}
Node* del_any(Node* head,int pos)
{
    if(head==NULL)
        printf("No Node to delete\n");
    else if(head->next==NULL)
        head=del_beg(head);
    else if(pos==count(head))
        head=del_end(head);
    else
    {
        Node *p,*t;
        int c=1;
        p=head;
        while(p->next!=NULL&&c<pos)
        {
            t=p;
            p=p->next;
            c++;
        }
        t->next=p->next;
        free(p);
        return head;
    }
}
int count(Node* head)
{
    Node *p;
    int c=0;
    p=head;
    while(p->next!=NULL)
    {
        ++c;
        p=p->next;
    }
    return c;
}

void display(Node *head)
{
    Node *p;
    p=head;
    while(p!=NULL)
    {
        printf("|%d|->",p->data);
        p=p->next;
    }
}