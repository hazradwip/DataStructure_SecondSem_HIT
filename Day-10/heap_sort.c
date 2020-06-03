#include <stdio.h>
#include <stdlib.h>

void heapSort(int *, int);

int main()
{
    int i, n;
    int *arr;

    /* Input Block */
    printf("Enter how many numbers you want to sort: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    srand(time(0));
    printf("\nTaking Numbers fron Random Function");
    for (i = 0; i < n; i++)
        *(arr + i) = rand() % 100;

    printf("\nThe numbers before sorting :");
    for (i = 0; i < n; i++)
        printf("  %d", *(arr + i));

    /* End of Input Block */

    heapSort(arr, n);

    printf("\nThe numbers in sorting order is:");
    for (i = 0; i < n; i++)
        printf("  %d", *(arr + i));

    return 0;
}

void heapSort(int *arr, int n)
{
    int i, ivalue, s, f, l;

    printf("\n\nConstruction & Sorting of the Heap:\n");
    for (i = n - 1; i > 0; i--)
    {
        ivalue = arr[i];
        arr[i] = arr[0];
        f = 0;
        if (i == 1)
            s = -1;
        else
            s = 1;
        if (i > 2 && arr[2] > arr[1])
            s = 2;
        while (s >= 0 && ivalue < arr[s])
        {
            arr[f] = arr[s];
            f = s;
            s = 2 * f + 1;
            if (s + 1 < i - 1 && arr[s] < arr[s + 1])
                s = s + 1;
            if (s > i - 1)
                s = -1;
        }
        arr[f] = ivalue;
        for (l = 0; l < n; l++)
            printf("%d   ", arr[l]);
        printf("\n\n");
    }
}

/*
================ OUTPUT ================
******* All the inputs are taking by Random Function *******

Enter how many numbers you want to sort: 9

Taking Numbers fron Random Function
The numbers before sorting :  36  4  24  49  55  34  88  7  60

Construction & Sorting of the Heap:
60   4   24   49   55   34   88   7   36

24   4   34   49   55   7   88   60   36

88   4   34   49   55   7   24   60   36   

34   4   7   49   55   88   24   60   36

55   4   7   49   34   88   24   60   36

49   4   7   55   34   88   24   60   36   

7   4   49   55   34   88   24   60   36

4   7   49   55   34   88   24   60   36


The numbers in sorting order is:  4  7  49  55  34  88  24  60  36
*/
