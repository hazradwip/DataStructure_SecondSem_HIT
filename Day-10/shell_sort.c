#include <stdio.h>
#include <stdlib.h>

void shellSort(int *, int);

int main()
{
    int *arr;
    int n, i;

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

    shellSort(arr, n);

    printf("\nThe numbers in sorting order is:");
    for (i = 0; i < n; i++)
        printf("  %d", *(arr + i));

    return 0;
}

void shellSort(int *arr, int n)
{
    int gap, i, j;

    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i += 1)
        {
            int temp = arr[i];

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

/*
================ OUTPUT ================
******* All the inputs are taking by Random Function *******

Enter how many numbers you want to sort: 12

Taking Numbers fron Random Function
The numbers before sorting :  93  38  74  66  68  83  19  51  42  83  7  76
The numbers in sorting order is:  7  19  38  42  51  66  68  74  76  83  83  93
*/