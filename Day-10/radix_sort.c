#include <stdio.h>
#include<stdlib.h>

void radixSort(int *, int);

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

	radixSort(arr, n);

	printf("\nThe numbers in sorting order is:");
	for (i = 0; i < n; i++)
		printf("  %d", *(arr + i));

	return 0;
}

void radixSort(int *arr, int n)
{
	int bucket[10][10], bcount[10];
	int i, j, k, r, count = 0, div = 1;
	int max, pass;

	for (i = 1, max = arr[0]; i < n; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}

	while (max != 0)
	{
		count++;
		max = max / 10;
	}

	for (pass = 1; pass <= count; pass++)
	{
		for (k = 0; k < 10; bcount[k++] = 0)
			;
		for (i = 0; i < n; i++)
		{
			r = (arr[i] / div) % 10;
			bucket[r][bcount[r]] = arr[i];
			bcount[r]++;
		}

		for (i = 0, k = 0; k < 10; k++)
			for (j = 0; j < bcount[k]; j++)
			{
				arr[i] = bucket[k][j];
				i++;
			}

		div = (div * 10);
	}
}


/*
================ OUTPUT ================
******* All the inputs are taking by Random Function *******

Enter how many numbers you want to sort: 11

Taking Numbers fron Random Function
The numbers before sorting :  73  28  41  32  48  54  50  37  51  70  3
The numbers in sorting order is:  3  28  32  37  41  48  50  51  54  70  73
*/