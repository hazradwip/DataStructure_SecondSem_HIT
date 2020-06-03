#include<stdlib.h>
#include<stdio.h>
struct tree
{
    int data;
    struct tree* left;
    struct tree* right;
};
typedef struct tree Tree;
Tree *root=NULL;
Tree *insert(Tree*,int);
Tree *create(int);
int search(Tree *,int);
void inorder(Tree* root);
void postorder(Tree* root);
void preorder(Tree* root);
int countnodes(Tree*);
int leafnodes(Tree*);
int height(Tree*);
Tree *create(int data)
{
    Tree *node;
    node=(Tree*)malloc(sizeof(Tree));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
    
}
Tree *insert(Tree *root,int data)
{
    if(root==NULL)
        return create(data);
    if(data<root->data)
        root->left=insert(root->left,data);
    else if(data>root->data)
        root->right=insert(root->right,data);
    return root;
}
void inorder(Tree* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d->",root->data);
    inorder(root->right);
}
void postorder(Tree* root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d->",root->data);
}
void preorder(Tree* root)
{
    if(root==NULL)
        return;
    preorder(root->right);
    preorder(root->left);
    printf("%d->",root->data);
}

static int c = 0;

int countnodes(Tree *root)
{
    
    if(root != NULL)
    {
        countnodes(root->left);
        c++;
        countnodes(root->right);
    }
    return c;
}


int count = 0;

int leafnodes(Tree *root)
{
    if(root != NULL)
    {
        leafnodes(root->left);
        if((root->left == NULL) && (root->right == NULL))
        {
            count++;
        }
        leafnodes(root->right);
    }
    return count;
}

int height(Tree *root)  
{ 
   if (root==NULL)  
       return 0; 
   else 
   { 
        int lheight = height(root->left); 
        int rheight = height(root->right); 
        if (lheight > rheight)  
            return(lheight+1); 
        else 
            return(rheight+1); 
   } 
}  

int search(Tree* root, int key) 
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