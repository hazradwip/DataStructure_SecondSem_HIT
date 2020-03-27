#include "linked_list.h"

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
        //printf("5. Search an Element\n");
        //printf("6. Insert after an Element\n");
        //printf("7. Insert after an Element\n");
        printf("8. Reverse the List\n");
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
        case 8:
            head = revList(head);
            display(head);
            break;
        default:
            printf("\nInvalid choice\n");
        }
        printf("\nDo you want to continue ? (y/n) : ");
        c = getche();
    } while (c == 'y' || c == 'Y');
}
