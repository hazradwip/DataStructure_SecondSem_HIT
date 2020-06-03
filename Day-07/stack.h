#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node Node;

Node *push(Node *, int);

Node *pop(Node *);

int peek(Node *);
