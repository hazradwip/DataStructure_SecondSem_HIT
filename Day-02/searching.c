#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void create(int);

void linearSearch(int *, int, int);
void sentinelSearch(int *, int, int);
void binarySearch(int *, int, int);

int *sort(int *, int);

int main()
{
    int i, ch, n, key;
    int *arr;
    FILE *fp;

    printf("Enter the size of array\t");
    scanf("%d", &n);
    printf("Creation of list done\n-----------------------------\n");

    create(n);
    fp = fopen("Numbers.txt", "r");

    arr = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        fscanf(fp, "%d", (arr + i));
    }

    printf("The entered list is:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", *(arr + i));

    printf("\nEnter element to search\t");
    scanf("%d", &key);

    printf("\n----- MENU -----");
    printf("\n1. Linear Search");
    printf("\n2. Sentinel Linear Search");
    printf("\n3. Binary Search\n");
    printf("Enter choice : \n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        linearSearch(arr, n, key);
        break;
    case 2:
        sentinelSearch(arr, n, key);
        break;
    case 3:
        binarySearch(arr, n, key);
        break;
    default:
        printf("\nInvalid choice");
        break;
    }
    fclose(fp);
}

void create(int n)
{
    int i = 0;
    FILE *fp;
    fp = fopen("Numbers.txt", "w");

    srand(time(0));
    for (i = 0; i < n; i++)
    {
        fprintf(fp, "%d\t", rand() % 10);
    }
    fclose(fp);
}

void linearSearch(int *arr, int n, int x)
{
    int i, j = 0;
    int found_loc[n];

    for (i = 0; i < n; i++)
    {
        if (*(arr + i) == x)
        {
            found_loc[j] = i + 1;
            j++;
        }
    }

    if (j == 0)
        printf("Item not found\n");

    else
    {
        printf("Item found at locations\t");
        for (i = 0; i < j; i++)
            printf("%d\t", found_loc[i]);
    }
}

void sentinelSearch(int *arr, int n, int x)
{
    int last = arr[n - 1];
    arr[n - 1] = x;
    int i = 0, j = 0, ar[n];
    while (*(arr + i) != x)
        i++;
    arr[n - 1] = last;
    if (i < n - 1 || (x == arr[n - 1]))
        printf("Item found at locations\t%d\n", i + 1);

    else
        printf("Item not found\n");
}

void binarySearch(int *arr, int n, int x)
{
    int first = 0, last = n - 1, i;
    int *s;

    s = sort(arr, n);

    printf("The sorted list\n");
    for (i = 0; i < n; i++)
        printf("%d\t", s[i]);

    int mid = ((first + last) / 2);
    while (first <= last)
    {
        if (s[mid] < x)
            first = mid + 1;
        else if (s[mid] == x)
        {
            printf("\nItem found at location in the sorted list\t%d\n", mid + 1);
            break;
        }
        else
            last = mid - 1;
        mid = (first + last) / 2;
    }

    if (first > last)
        printf("\nItem not found\n");
}

int *sort(int *arr, int n)
{
    int i, j, temp;

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    return arr;
}


/*
================ OUTPUT ================
******* All the inputs are taking by Random Function *******

SET - 1
--------
Enter the size of array 10
Creation of list done        
-----------------------------
The entered list is:
3       3       2       0       4       9       4       0       1       0
Enter element to search 4

----- MENU -----
1. Linear Search
2. Sentinel Linear Search
3. Binary Search
Enter choice :
1
Item found at locations 5       7

--------
SET - 2
--------
Enter the size of array 8
Creation of list done
-----------------------------
The entered list is:
5       5       8       2       8       8       4       9       
Enter element to search 9

----- MENU -----
1. Linear Search
2. Sentinel Linear Search
3. Binary Search
Enter choice :
2
Item found at locations 8

--------
SET - 3
--------
Enter the size of array 9
Creation of list done
-----------------------------
The entered list is:
5       4       8       7       3       0       9       9       3
Enter element to search 8

----- MENU -----
1. Linear Search
2. Sentinel Linear Search
3. Binary Search
Enter choice :
3
The sorted list
0       3       3       4       5       7       8       9       9
Item found at location in the sorted list       7
*/
