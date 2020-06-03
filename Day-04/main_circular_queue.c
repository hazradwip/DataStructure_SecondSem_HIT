#include "circular_queue.h"

int main()
{
    int ch, n, data;
    char c;
    queue Q = {-1,-1};
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
            insert(&Q, data);
            break;

        case 2:
            data = del(&Q);
            if (data == -9999)
                break;
            printf("\n%d Deleted.", data);
            break;

        case 3:
            display(&Q);
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
Enter Choice : 1

Enter the element to insert : 40

Do you want to continue? (y/n) : y

------MENU------
1. INSERT
2. DELETE
3. DISPLAY
Enter Choice : 1

Enter the element to insert : 50

Do you want to continue? (y/n) : y

------MENU------
1. INSERT
2. DELETE
3. DISPLAY
Enter Choice : 3
(10) -(20) -(30) -(40) -(50) -
Do you want to continue? (y/n) : y

------MENU------
1. INSERT
2. DELETE
3. DISPLAY
Enter Choice : 1

Enter the element to insert : 60

Queue is Full
Do you want to continue? (y/n) : y

------MENU------
1. INSERT
2. DELETE
3. DISPLAY
Enter Choice : 2

10 Deleted.
Do you want to continue? (y/n) : y

------MENU------
1. INSERT
2. DELETE
3. DISPLAY
Enter Choice : 2

20 Deleted.
Do you want to continue? (y/n) : y

------MENU------
1. INSERT
2. DELETE
3. DISPLAY
Enter Choice : 1

Enter the element to insert : 60

Do you want to continue? (y/n) : y

------MENU------
1. INSERT
2. DELETE
3. DISPLAY
Enter Choice : 3
(30) -(40) -(50) -(60) -
Do you want to continue? (y/n) : n
*/