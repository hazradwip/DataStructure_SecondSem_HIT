#include "stack.h"

int main()
{
    int ch, n, data;
    char c;
    stack S = {-1,};
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
            push(&S, data);
            break;

        case 2:
            data = pop(&S);
            if (data == -9999)
                break;
            printf("\n%d Popped.", data);
            break;

        case 3:
            printf("\nThe Peek item is : %d", peek(&S));
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
Enter Choice : 2

Stack is Underflow
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

Enter the element to push : 50

Do you want to continue? (y/n) : y

------MENU------
1. PUSH
2. POP
3. PEEK
Enter Choice : 1

Enter the element to push : 40

Do you want to continue? (y/n) : y

------MENU------
1. PUSH
2. POP
3. PEEK
Enter Choice : 3

The Peek item is : 40
Do you want to continue? (y/n) : y

------MENU------
1. PUSH
2. POP
3. PEEK
Enter Choice : 2

40 Popped.
Do you want to continue? (y/n) : y

------MENU------
1. PUSH
2. POP
3. PEEK
Enter Choice : 3

The Peek item is : 50
Do you want to continue? (y/n) : n
*/