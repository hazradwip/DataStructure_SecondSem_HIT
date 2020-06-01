#include "circular_linked_list.h"

void display(Node *head)
{
    Node *p;
    p = head;
    while (p->next != head);
    {
        printf(" ->(%d)", p->data);
        p = p->next;
    }

    printf(" ->(%d) -> | ->(%d)", p->data,p->next->data);
}

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
    {
        head = temp;
        head->next = head;
    }
    else
    {
        p = head;
        while (p->next != head)
            p = p->next;
        p->next = temp;
        temp->next = head;
    }

    return head;
}

/*
* Add a Node to Linked List
*/

Node *insert_beg(Node *head, int x)
{
    Node *temp, *p;

    temp = (Node *)malloc(sizeof(Node));
    
    p = head;
    while (p->next != head)
        p = p->next;
    p->next = temp;

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
    while (p->next != head)
        p = p->next;
    p->next = temp;
    temp->next = head;

    return head;
}

Node *insert_anyPos(Node *head, int pos, int x)
{
    if (pos == 1)
        head = insert_beg(head, x);

    else if (pos == (count(head) + 1))
        head = insert_end(head, x);

    else
    {
        Node *p, *temp;

        p = head;
        temp = (Node *)malloc(sizeof(Node));
        temp->data = x;
        temp->next = NULL;

        int c = 1;
        while (p->next != head)
        {
            if (c == pos - 1)
            {
                temp->next = p->next;
                p->next = temp;
            }
            c++;
            p = p->next;
        }
    }

    return head;
}

/*
* Delete a Node from Linked List
*/

Node *del_beg(Node *head)
{
    Node *p;

    if (p == NULL)
        printf("\nLinked List is empty. No Node to delete.\n");
    else
    {
        while (p->next != head)
            p = p->next;
        p->next = head->next;

        p = head;

        head = head->next;
    }
    printf("\n%d is Deleted.\n", p->data);
    free(p);

    return head;
}

Node *del_end(Node *head)
{
    Node *p, *q;
    p = head;
    if (head == NULL)
        printf("\n No need to delete\n");

    else if (p->next == head)
    {
        printf("\n%d is Deleted and there is no other Node to Delete.\n", p->data);
        free(p);
        head = NULL;
    }

    else
    {
        q = p->next;
        while (q->next != head)
        {
            q = q->next;
            p = p->next;
        }
        p->next = head;
        printf("\n%d is Deleted.\n", q->data);
        free(q);
    }

    return head;
}

Node *del_anyPos(Node *head, int pos)
{
    if (head == NULL)
        printf("No Node to delete\n");

    else if (head->next == head)
        head = del_beg(head);

    else if (pos == count(head))
        head = del_end(head);

    else
    {
        Node *p, *q;
        int c = 1;
        p = head;
        while (p->next != head && c < pos)
        {
            q = p;
            p = p->next;
            c++;
        }

        if (c == pos)
        {
            q->next = p->next;
            printf("\n%d is Deleted.\n", p->data);
            free(p);
        }

        return head;
    }
}

