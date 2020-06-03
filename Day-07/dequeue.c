#include "dequeue.h"

int count(Node *head)
{
    Node *p;
    int c = 0;

    p = head;
    while (p != NULL)
    {
        ++c;
        p = p->next;
    }

    return c;
}

Node *insertFront(Node *head, int x)
{
    Node *temp;

    temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->next = head;

    head = temp;

    return head;
}

Node *insertRear(Node *head, int x)
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

Node *delFront(Node *head)
{
    Node *p;

    p = head;
    if (p == NULL)
        printf("\nLinked List is empty. No Node to delete.\n");
    else
        head = head->next;
    printf("\n%d is Deleted.\n", p->data);
    free(p);

    return head;
}

Node *delRear(Node *head)
{
    Node *p, *q;
    p = head;
    if (head == NULL)
        printf("\n No need to delete\n");

    else if (p->next == NULL)
    {
        printf("\n%d is Deleted and there is no other Node to Delete.\n", p->data);
        free(p);
        head = NULL;
    }

    else
    {
        q = p->next;
        while (q->next != NULL)
        {
            q = q->next;
            p = p->next;
        }
        p->next = NULL;
        printf("\n%d is Deleted.\n", q->data);
        free(q);
    }

    return head;
}

void display(Node *head)
{
    Node *p;
    p = head;
    while (p != NULL)
    {
        printf(" ->(%d)", p->data);
        p = p->next;
    }
}
