#include "doubly_linked_list.h"

void display(Node *head)
{
    Node *p;
    p = head;
    while (p != NULL)
    {
        printf(" <->(%d)", p->data);
        p = p->next;
    }
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
* Create Linked List
*/

Node *create(Node *head, int x)
{
    Node *p, *temp;

    temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->prev = NULL;
    temp->next = NULL;

    if (head == NULL)
        head = temp;
    else
    {
        p = head;
        while (p->next != NULL)
            p = p->next;
        p->next = temp;
        temp->prev = p;
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
    temp->prev = NULL;
    temp->next = head;

    head = temp;

    return head;
}

Node *insert_end(Node *head, int x)
{
    Node *p, *temp;

    temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->prev = NULL;
    temp->next = NULL;

    p = head;
    while (p->next != NULL)
        p = p->next;
    p->next = temp;
    temp->prev = p;

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
        temp->prev = NULL;
        temp->next = NULL;

        int c = 1;
        while (p->next != NULL)
        {
            if (c == pos - 1)
            {
                temp->next = p->next;
                p->next = temp;
                temp->prev = p;
                temp->next->prev = temp;
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

    p = head;
    if (p == NULL)
        printf("\nLinked List is empty. No Node to delete.\n");
    else
    {
        head = head->next;
        head->prev = NULL;
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

    else if (p->next == NULL)
    {
        printf("\n%d is Deleted and there is no other Node to Delete.\n", p->data);
        free(p);
        head = NULL;
    }

    else
    {
        //q = p->next;
        while (p->next != NULL)
        {
            //q = q->next;
            p = p->next;
        }
        q = p;
        p = p->prev;
        p->next = NULL;
        printf("\n%d is Deleted.\n", q->data);
        free(q);
    }

    return head;
}

Node *del_anyPos(Node *head, int pos)
{
    if (head == NULL)
        printf("No Node to delete\n");

    else if (head->next == NULL)
        head = del_beg(head);

    else if (pos == count(head))
        head = del_end(head);

    else
    {
        Node *p, *q;
        int c = 1;
        p = head;
        while (p->next != NULL && c < pos)
        {
            q = p;
            p = p->next;
            c++;
        }

        if (c == pos)
        {
            q->next = p->next;
            p->next->prev = q;
            printf("\n%d is Deleted.\n", p->data);
            free(p);
        }

        return head;
    }
}