#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

typedef struct Node Node;

//Node *head=NULL;

Node *create(Node *, int);
Node *insert_beg(Node *, int);
Node *insert_end(Node *, int);
Node *insert_anyPos(Node *, int, int);

Node *del_beg(Node *);
Node *del_end(Node *);
Node *del_anyPos(Node *, int);

int count(Node *);

void display(Node *);