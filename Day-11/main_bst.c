#include <math.h>
#include "binary_search_tree.h"

int main()
{
    int ch, n, i, data;
    char c = 'y';
    tree *root = NULL;

    printf("Enter the No. of Nodes in BST : ");
    scanf("%d", &n);

    printf("Enter Values : \n");
    for (i = 0; i < n; i++)
    {
        printf("%dth Node : ", i + 1);
        scanf("%d", &data);
        root = insert(root, data);
    }

    do
    {
        printf("\n\n-------MENU-------\n");
        printf("1. Tree Traversal\n");
        printf("2. Count Nodes\n");
        printf("3. Count Leaf Nodes\n");
        printf("4. Find the Height of BST\n");
        printf("5. Search an Element\n");
        printf("6. Delete an Element\n");
        printf("Choose an Option : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nPre-Order : ");
            preOrder(root);

            printf("\nIn-Order : ");
            inOrder(root);

            printf("\nPost-Order : ");
            postOrder(root);
            break;

        case 2:
            count_node = 0;
            printf("\nNo of Nodes : %d", countNode(root));
            break;

        case 3:
            leaf = 0;
            printf("\nNo of Leaf Nodes : %d", countLeaf(root));
            break;

        case 4:
            printf("\nHeight of the BST : %d", calHeight(root));
            break;

        case 5:
            printf("\nEnter the Value to be searched : ");
            scanf("%d", &data);

            if (search(root, data))
                printf("\nItem Found...!!!");
            else
                printf("\nItem Not Found..!!!");
            break;

        case 6:
            printf("\nEnter the Value to be Delete : ");
            scanf("%d", &data);

            if (search(root, data))
            {
                del(root, data);
                printf("\n%d Deleted...");
                
                printf("\nPre-Order : ");
            preOrder(root);

            printf("\nIn-Order : ");
            inOrder(root);

            printf("\nPost-Order : ");
            postOrder(root);
            }
            else
                printf("\nItem Not Found..!!!");
            break;

        default:
            printf("\nInvalid choice\n");
        }
        printf("\nDo you want to continue ? (y/n) : ");
        c = getche();
    } while (c == 'y' || c == 'Y');

    return 0;
}


/*
================ OUTPUT ================

Enter the No. of Nodes in BST : 7
Enter Values : 
1th Node : 50
2th Node : 30
3th Node : 70
4th Node : 10
5th Node : 40
6th Node : 60
7th Node : 20


-------MENU-------
1. Tree Traversal
2. Count Nodes
3. Count Leaf Nodes
4. Find the Height of BST
5. Search an Element
6. Delete an Element
Choose an Option : 1

Pre-Order : -> 50-> 30-> 10-> 20-> 40-> 70-> 60
In-Order : -> 10-> 20-> 30-> 40-> 50-> 60-> 70
Post-Order : -> 20-> 10-> 40-> 30-> 60-> 70-> 50
Do you want to continue ? (y/n) : y

-------MENU-------
1. Tree Traversal
2. Count Nodes
3. Count Leaf Nodes
4. Find the Height of BST
5. Search an Element
6. Delete an Element
Choose an Option : 2

No of Nodes : 7
Do you want to continue ? (y/n) : y

-------MENU-------
1. Tree Traversal
2. Count Nodes
3. Count Leaf Nodes
4. Find the Height of BST
5. Search an Element
6. Delete an Element
Choose an Option : 3

No of Leaf Nodes : 3
Do you want to continue ? (y/n) : y

-------MENU-------
1. Tree Traversal
2. Count Nodes
3. Count Leaf Nodes
4. Find the Height of BST
5. Search an Element
6. Delete an Element
Choose an Option : 4

Height of the BST : 4
Do you want to continue ? (y/n) : y

-------MENU-------
1. Tree Traversal
2. Count Nodes
3. Count Leaf Nodes
4. Find the Height of BST
5. Search an Element
6. Delete an Element
Choose an Option : 5

Enter the Value to be searched : 30

Item Found...!!!
Do you want to continue ? (y/n) : y

-------MENU-------
1. Tree Traversal
2. Count Nodes
3. Count Leaf Nodes
4. Find the Height of BST
5. Search an Element
6. Delete an Element
Choose an Option : 5

Enter the Value to be searched : 35

Item Not Found..!!!
Do you want to continue ? (y/n) : y

-------MENU-------
1. Tree Traversal
2. Count Nodes
3. Count Leaf Nodes
4. Find the Height of BST
5. Search an Element
6. Delete an Element
Choose an Option : 6

Enter the Value to be Delete : 30

30 Deleted...
Pre-Order : -> 50-> 40-> 10-> 20-> 70-> 60
In-Order : -> 10-> 20-> 40-> 50-> 60-> 70
Post-Order : -> 20-> 10-> 40-> 60-> 70-> 50
Do you want to continue ? (y/n) : y

-------MENU-------
1. Tree Traversal
2. Count Nodes
3. Count Leaf Nodes
4. Find the Height of BST
5. Search an Element
6. Delete an Element
Choose an Option : 2

No of Nodes : 6
Do you want to continue ? (y/n) : n
*/