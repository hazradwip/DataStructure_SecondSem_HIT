#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};

typedef struct tree tree;

int count_node, leaf;

tree *create(int);
tree *insert(tree *, int);

int search(tree *, int);

void preOrder(tree *root);
void inOrder(tree *root);
void postOrder(tree *root);

int countNode(tree *);
int countLeaf(tree *);
int calHeight(tree *);

tree *minValueNode(tree *);
tree *del(tree *, int);