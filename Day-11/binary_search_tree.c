#include "binary_search_tree.h"

tree *create(int data)
{
    tree *node;
    node = (tree *)malloc(sizeof(tree));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    count_node++;

    return node;
}

tree *insert(tree *root, int data)
{
    if (root == NULL)
        return create(data);

    if (data < root->data)
        root->left = insert(root->left, data);

    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

void preOrder(tree *root)
{
    if (root == NULL)
        return;
    printf("-> %d", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(tree *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("-> %d", root->data);
    inOrder(root->right);
}

void postOrder(tree *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("-> %d", root->data);
}

int countNode(tree *root)
{
    
    if(root != NULL)
    {
        countNode(root->left);
        count_node++;
        countNode(root->right);
    }
    return count_node;
}

int countLeaf(tree *root)
{
    if (root != NULL)
    {
        countLeaf(root->left);
        if ((root->left == NULL) && (root->right == NULL))
            leaf++;
        countLeaf(root->right);
    }
    return leaf;
}

int calHeight(tree *root)
{
    if (root == NULL)
        return 0;
    else
    {
        int lHeight = calHeight(root->left);
        int rHeight = calHeight(root->right);
        /*if (lHeight > rHeight)  
            return(lHeight+1); 
        else 
            return(rHeight+1); */

        return lHeight > rHeight ? lHeight + 1 : rHeight + 1;
    }
}

int search(tree *root, int key)
{
    while (root != NULL)
    {
        if (key > root->data)
            root = root->right;
        else if (key < root->data)
            root = root->left;
        else
            return 1;
    }
    return 0;
}

tree *minValueNode(tree *root)
{
    tree *current = root;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

tree *del(tree *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = del(root->left, key);

    else if (key > root->data)
        root->right = del(root->right, key);

    else
    {
        if (root->left == NULL)
        {
            tree *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            tree *temp = root->left;
            free(root);
            return temp;
        }
        tree *temp = minValueNode(root->right);

        root->data = temp->data;

        root->right = del(root->right, temp->data);
    }

    return root;
}