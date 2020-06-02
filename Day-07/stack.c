#include "stack.h"

Node *push(Node *head, int x)
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

Node *pop(Node *head)
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

int peek(Node *head)
{
    if (head != NULL)
    {
        Node *p;
        p = head;
        while (p->next != NULL)
            p = p->next;
        printf("%d",p->data);
        return p->data;
    }
    else
        return -1;
}