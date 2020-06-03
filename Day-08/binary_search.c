#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *, int, int, int);
int *sort(int *, int);

int main(void)
{
    int *arr;
    int n, x, i, flag;

    printf("Enter the size of array\t");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    srand(time(0));
    for (i = 0; i < n; i++)
        *(arr + i) = rand() % 100;

    printf("The entered list is:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", *(arr + i));

    printf("\nEnter element to search\t");
    scanf("%d", &x);

    int *s;
    s = sort(arr, n);

    printf("\nThe Sorted list is:\n");
    for (int i = 0; i < n; i++)
        printf("%d\t", *(s + i));

    flag = binarySearch(arr, 0, n - 1, x);

    if (flag == -1)
        printf("\nItem not Found!!!");
    else
        printf("\nItem found at location in the sorted list\t%d\n", flag + 1);

    return 0;
}

int binarySearch(int *arr, int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
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

Enter the size of array 10
The entered list is:
68      58      64      44      15      26      20      2       5       85
Enter element to search 44

The Sorted list is:
2       5       15      20      26      44      58      64      68      85
Item found at location in the sorted list       6
*/