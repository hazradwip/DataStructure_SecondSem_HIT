#include "queue.h"

Node *insert(Node *head, int x)
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

Node *del(Node *head)
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