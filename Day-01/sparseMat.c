#include "matrix.h"

int countNonZero(int **, int, int);
void createSparse(int **, int, int, int);
void createSparseTranspose(int **, int);

int main()
{
    int **mat;
    int i, j;
    int row, col;

    printf("\nEnter No. of Rows : ");
    scanf("%d",&row);
    printf("\nEnter No. of Columns : ");
    scanf("%d",&col);

    mat = (int **)malloc(row * sizeof(int *));
    for (i = 0; i < row; i++)
        *(mat + i) = (int *)malloc(col * sizeof(int));

    getSparse(mat, row, col);
    display(mat, row, col);

    int N = countNonZero(mat, row, col);
    if (row * col > (N + 1) * 3)
    {
        printf("\nIt is a sparse matrix\n");
        createSparse(mat, row, col, N);
    }
    else
        printf("\nIt is not a sparse matrix\n");

    return 0;
}

int countNonZero(int **mat, int row, int col)
{
    int count = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (*(*(mat + i) + j) != 0)
                count++;

    return count;
}

void createSpareseTranspose(int **sparseMat, int row)
{
    int i, j, k, col, N;
    int **sparseTanspose;

    col = 3;
    N = *(*(sparseMat + 0) + 2);

    sparseTanspose = (int **)malloc(row * sizeof(int *));
    for (i = 0; i < row; i++)
        *(sparseTanspose + i) = (int *)malloc(col * sizeof(int));

    *(*(sparseTanspose + 0) + 0) = *(*(sparseMat + 0) + 1);
    *(*(sparseTanspose + 0) + 1) = *(*(sparseMat + 0) + 0);
    *(*(sparseTanspose + 0) + 2) = N;

    k = 1;
    for (i = 0; i < *(*(sparseMat + 0) + 1); i++)
        for (j = 1; j <= N; j++)
            //if a column number of current triple==i then insert the current triple in b2
            if (i == *(*(sparseMat + j) + 1))
            {
                *(*(sparseTanspose + k) + 0) = i;
                *(*(sparseTanspose + k) + 1) = *(*(sparseMat + j) + 0);
                *(*(sparseTanspose + k) + 2) = *(*(sparseMat + j) + 2);
                k++;
            }

    printf("\nThe Transpose of the Matrix is :\n");
    display(sparseTanspose, N + 1, 3);
}

void createSparse(int **orgMat, int row, int col, int N)
{
    int **sparseMat;
    int i, j;

    sparseMat = (int **)malloc((N + 1) * sizeof(int *));
    for (i = 0; i < N + 1; i++)
        *(sparseMat + i) = (int *)malloc(3 * sizeof(int));

    *(*(sparseMat + 0) + 0) = row;
    *(*(sparseMat + 0) + 1) = col;
    *(*(sparseMat + 0) + 2) = N;

    int k = 1;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (*(*(orgMat + i) + j) != 0)
            {
                *(*(sparseMat + k) + 0) = i;
                *(*(sparseMat + k) + 1) = j;
                *(*(sparseMat + k) + 2) = *(*(orgMat + i) + j);
                k++;
            }
        }
    }

    display(sparseMat, N + 1, 3);
    createSpareseTranspose(sparseMat, N + 1);
}


/*
================ OUTPUT ================
******* All the inputs are taking by Random Function written in matrix.c *******

SET - 1
--------
Enter No. of Rows : 5

Enter No. of Columns : 4

The Matrix is :
 1  1  0  1
 0  2  0  0
 0  0  0  0 
 0  0  0  2
 0  0  2  0

It is not a sparse matrix

--------
SET - 2
--------
Enter No. of Rows : 5 

Enter No. of Columns : 4

The Matrix is :
 0  0  4  0
 0  0  0  0
 0  0  0  0
 0  5  0  0
 0  0  0  0 

It is a sparse matrix

The Matrix is :
 5  4  2
 0  2  4
 3  1  5

The Transpose of the Matrix is :

The Matrix is :
 4  5  2
 1  3  5
 2  0  4
*/