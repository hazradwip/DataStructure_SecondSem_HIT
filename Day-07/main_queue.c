#include "queue.h"

int main()
{
    int ch, n, data;
    char c;
    Node *head = NULL;

    do
    {
        printf("\n\n------MENU------\n");
        printf("1. INSERT\n");
        printf("2. DELETE\n");
        printf("3. DISPLAY\n");
        printf("Enter Choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the element to insert : ");
            scanf("%d", &data);
            head = insert(head, data);
            break;

        case 2:
            head = del(head);
            break;

        case 3:
            display(head);
            break;

        default:
            printf("\nInvalid option");
            break;

        }

        printf("\nDo you want to continue? (y/n) : ");
        c = getche();

    } while (c == 'y' || c == 'Y');

    return 0;
}

/*
================ OUTPUT ================
------MENU------
1. INSERT
2. DELETE
3. DISPLAY
Enter Choice : 1

Enter the element to insert : 10

Do you want to continue? (y/n) : y

------MENU------
1. INSERT
2. DELETE
3. DISPLAY
Enter Choice : 1

Enter the element to insert : 20

Do you want to continue? (y/n) : y

------MENU------
1. INSERT
2. DELETE
3. DISPLAY
Enter Choice : 1

Enter the element to insert : 30

Do you want to continue? (y/n) : y

------MENU------
1. INSERT
2. DELETE
3. DISPLAY
Enter Choice : 3
 ->(10) ->(20) ->(30)
Do you want to continue? (y/n) : y

------MENU------
1. INSERT
2. DELETE
3. DISPLAY
Enter Choice : 2

10 is Deleted.

Do you want to continue? (y/n) : y

------MENU------
1. INSERT
2. DELETE
3. DISPLAY
Enter Choice : 2

20 is Deleted.

Do you want to continue? (y/n) : y

------MENU------
1. INSERT
2. DELETE
3. DISPLAY
Enter Choice : 3
 ->(30)
Do you want to continue? (y/n) : y

------MENU------
1. INSERT
2. DELETE
3. DISPLAY
Enter Choice : 2

30 is Deleted.

Do you want to continue? (y/n) : y

------MENU------
1. INSERT
2. DELETE
3. DISPLAY
Enter Choice : 3

Do you want to continue? (y/n) : n
*/