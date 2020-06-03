#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node Node;

Node *insertFront(Node *, int);
Node *insertRear(Node *, int);

Node *delFront(Node *);
Node *delRear(Node *);

void display(Node *);