#include "stack.h"

int main()
{
    int ch, n, data;
    char c;
    Node *head = NULL;
    //printf("%d",head->data);
    do
    {
        printf("\n\n------MENU------\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("Enter Choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the element to push : ");
            scanf("%d", &data);
            head = push(head, data);
            break;

        case 2:
            head = pop(head);
            break;

        case 3:
            printf("\nThe Peek item is : %d", peek(head));
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
1. PUSH
2. POP
3. PEEK
Enter Choice : 1

Enter the element to push : 10

Do you want to continue? (y/n) : y

------MENU------
1. PUSH
2. POP
3. PEEK
Enter Choice : 1

Enter the element to push : 20

Do you want to continue? (y/n) : y

------MENU------
1. PUSH
2. POP
3. PEEK
Enter Choice : 1

Enter the element to push : 30

Do you want to continue? (y/n) : y

------MENU------
1. PUSH
2. POP
3. PEEK
Enter Choice : 3
30
The Peek item is : 30
Do you want to continue? (y/n) : y

------MENU------
1. PUSH
2. POP
3. PEEK
Enter Choice : 2

30 is Deleted.

Do you want to continue? (y/n) : y

------MENU------
1. PUSH
2. POP
3. PEEK
Enter Choice : 3
20
The Peek item is : 20
Do you want to continue? (y/n) : n
*/