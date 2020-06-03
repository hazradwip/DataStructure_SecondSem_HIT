#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "BST_func.c"
int main()
{
    int n,d,i,x,l,k,ch;
    printf("Enter th no. of nodes in a tree\n");
    scanf("%d",&n);
    printf("Enter the  values to insert in a tree\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&d);
        root=insert(root,d);
    }
    while(1)
    {
        printf("\nEnter 1 for Traversal\nEnter 2 for count Nodes\nEnter 3 to count leaf nodes\nEnter 4 to find the height\nEnter 5 to search any key");
        printf("\nEnter choice\t");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nThe inorder traversal :\t");
                inorder(root);
                printf("\nThe postorder traversal :\t");
                postorder(root);
                printf("\nThe preorder traversal :\t");
                preorder(root);
                break;
            case 2:
                printf("\nThe no.of nodes is: \t%d",countnodes(root));
                break;
            case 3:
                printf("\nThe no. of leaf nodes is\t%d",leafnodes(root));
                break;
            case 4:
                printf("\nHeight of the tree:\t%d",height(root));
                break;
            case 5:
                printf("\nEnter the value to be searched");
                scanf("%d",&k);
                if(search(root,k))
                    printf("\nKey found");
                else
                    printf("\nKey not found");
                break;
            default:
                printf("\nInvalid choice");
                break;
        }
    }
}
