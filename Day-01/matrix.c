#include "matrix.h"

void getData(int **mat, int row, int col)
{
    int i, j;

    srand(time(0));
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            *(*(mat + i) + j) = (rand() % 50) / (rand() % 100);
}

void display(int **mat, int row, int col)
{
    int i, j;

    printf("\nThe Matrix is : \n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
            printf(" %d ", *(*(mat + i) + j));
        printf("\n");
    }
}