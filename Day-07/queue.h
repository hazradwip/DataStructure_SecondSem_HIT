#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node Node;

Node* insert(Node *, int);
Node* del(Node *);

void display(Node *);