#include "doubly_linked_list.h"

int main()
{
    int ch, choice, n, i, data, pos;
    char c = 'y';
    Node *head = NULL;

    do
    {
        printf("\n\n-------MENU-------\n");
        printf("1. Create List\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("Choose an Option : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the no.of Nodes to create\n");
            scanf("%d", &n);

            for (i = 0; i < n; i++)
            {
                printf("\nEnter the value of the  Node : \n");
                scanf("%d", &data);
                head = create(head, data);
            }

            break;
        case 2:
            printf("\n1. Insert at Beginning\n");
            printf("2. Insert at End\n");
            printf("3. Insert at any Position\n");
            printf("Enter choice : ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("\nEnter value : ");
                scanf("%d", &data);
                head = insert_beg(head, data);
                break;
            case 2:
                printf("\nEnter value : ");
                scanf("%d", &data);
                head = insert_end(head, data);
                break;
            case 3:
                printf("\nEnter position to insert : ");
                scanf("%d", &pos);
                if (pos > count(head) + 1)
                    printf("\nInsertion not possible, Enter a shorter range...");
                else
                    printf("\nEnter value : ");
                scanf("%d", &data);
                head = insert_anyPos(head, pos, data);
                break;
            default:
                printf("\nInvalid choice\n");
                break;
            }
            break;
        case 3:
            printf("\n1. Delete Beginning\n");
            printf("2. Delete from End\n");
            printf("3. Delete from any Position\n");
            printf("\nEnter choice : ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                head = del_beg(head);
                break;
            case 2:
                head = del_end(head);
                break;
            case 3:
                printf("\nEnter the position to delete : ");
                scanf("%d", &pos);
                if (pos > count(head))
                    printf("\nDeletion not possible, Enter a shorter range...");
                else
                    head = del_anyPos(head, pos);
                break;
            default:
                printf("\nInvalid choice\n");
                break;
            }
            break;
        case 4:
            display(head);
            break;
        default:
            printf("\nInvalid choice\n");
        }
        printf("\nDo you want to continue ? (y/n) : ");
        c = getche();
    } while (c == 'y' || c == 'Y');
}


/*
================ OUTPUT ================
-------MENU-------
1. Create List
2. Insert
3. Delete
4. Display
Choose an Option : 1

Enter the no.of Nodes to create
2

Enter the value of the  Node :
20

Enter the value of the  Node :
30

Do you want to continue ? (y/n) : y

-------MENU-------
1. Create List
2. Insert
3. Delete
4. Display
Choose an Option : 4
 <->(20) <->(30)
Do you want to continue ? (y/n) : y

-------MENU-------
1. Create List
2. Insert
3. Delete
4. Display
Choose an Option : 2

1. Insert at Beginning
2. Insert at End
3. Insert at any Position
Enter choice : 1

Enter value : 10

Do you want to continue ? (y/n) : y

-------MENU-------
1. Create List
2. Insert
3. Delete
4. Display
Choose an Option : 1

Enter the no.of Nodes to create
1

Enter the value of the  Node :
20

Do you want to continue ? (y/n) : y

-------MENU-------
1. Create List
2. Insert
3. Delete
4. Display
Choose an Option : 4
 <->(10) <->(20) <->(30) <->(20)
Do you want to continue ? (y/n) : y

-------MENU-------
1. Create List
2. Insert
3. Delete
4. Display
Choose an Option : 2

1. Insert at Beginning
2. Insert at End
3. Insert at any Position
Enter choice : 3

Enter position to insert : 2

Enter value : 50

Do you want to continue ? (y/n) : y

-------MENU-------
1. Create List
2. Insert
3. Delete
4. Display
Choose an Option : 4
 <->(10) <->(50) <->(20) <->(30) <->(20)
Do you want to continue ? (y/n) : y

-------MENU-------
1. Create List
2. Insert
3. Delete
4. Display
Choose an Option : 3

1. Delete Beginning
2. Delete from End
3. Delete from any Position

Enter choice : 1

10 is Deleted.

Do you want to continue ? (y/n) : y

-------MENU-------
1. Create List
2. Insert
3. Delete
4. Display
Choose an Option : 3

1. Delete Beginning
2. Delete from End
3. Delete from any Position

Enter choice : 2

20 is Deleted.

Do you want to continue ? (y/n) : y

-------MENU-------
1. Create List
2. Insert
3. Delete
4. Display
Choose an Option : 3

1. Delete Beginning
2. Delete from End
3. Delete from any Position

Enter choice : 3

Enter the position to delete : 2

20 is Deleted.

Do you want to continue ? (y/n) : y

-------MENU-------
1. Create List
2. Insert
3. Delete
4. Display
Choose an Option : 4
 <->(50) <->(30)
Do you want to continue ? (y/n) : n
*/