#include "matrix.h"
/*
* Function to Generate a Sparse Matrix
*/
void getSparse(int **mat, int row, int col)
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

/*
* Function to Generate a Left Lower or Right Lower Matrix
*/
void getLower(int **mat, int dim)
{
    int i, j;

    srand(time(0));

    int c = rand() % 2;

    switch (c)
    {
    case 0:
        for (i = 0; i < dim; i++)
            for (j = 0; j < dim; j++)
            {
                if (i >= j)
                    *(*(mat + i) + j) = rand() % 10;
                else
                    *(*(mat + i) + j) = 0;
            }
        break;

    case 1:
        for (i = 0; i < dim; i++)
            for (j = 0; j < dim; j++)
            {
                if (i + j >= dim-1)
                    *(*(mat + i) + j) = rand() % 10;
                else
                    *(*(mat + i) + j) = 0;
            }
        break;
    }
}

/*
* Function to Generate a Left Upper or Right Upper Matrix
*/
void getUpper(int **mat, int dim)
{
    int i, j;

    srand(time(0));

    int c = rand() % 2;

    switch (c)
    {
    case 0:
        for (i = 0; i < dim; i++)
            for (j = 0; j < dim; j++)
            {
                if (i <= j)
                    *(*(mat + i) + j) = rand() % 10;
                else
                    *(*(mat + i) + j) = 0;
            }
        break;

    case 1:
        for (i = 0; i < dim; i++)
            for (j = 0; j < dim; j++)
            {
                if (i + j <= dim-1)
                    *(*(mat + i) + j) = rand() % 10;
                else
                    *(*(mat + i) + j) = 0;
            }
        break;
    }
}

/*
* Function to Generate a Left Diagonal or Right Diagonal Matrix
*/
void getDigonal(int **mat, int dim)
{
    int i, j;

    srand(time(0));

    int c = rand() % 2;

    switch (c)
    {
    case 0:
        for (i = 0; i < dim; i++)
            for (j = 0; j < dim; j++)
            {
                if (i == j)
                    *(*(mat + i) + j) = rand() % 10;
                else
                    *(*(mat + i) + j) = 0;
            }
        break;

    case 1:
        for (i = 0; i < dim; i++)
            for (j = 0; j < dim; j++)
            {
                if (i + j == dim-1)
                    *(*(mat + i) + j) = rand() % 10;
                else
                    *(*(mat + i) + j) = 0;
            }
        break;
    }
}

/*
* Function to Generate a Identity Matrix
*/
void getIdentity(int **mat, int dim)
{
    int i, j;

    srand(time(0));

        for (i = 0; i < dim; i++)
            for (j = 0; j < dim; j++)
            {
                if (i == j)
                    *(*(mat + i) + j) = 1;
                else
                    *(*(mat + i) + j) = 0;
            }
}

/*
* Function to Generate a Left Tri-Diagonal or Right Tri-Diagonal Matrix
*/
void getTriDigonal(int **mat, int dim)
{
    int i, j;

    srand(time(0));

    int c = rand() % 2;

    switch (c)
    {
    case 0:
        for (i = 0; i < dim; i++)
            for (j = 0; j < dim; j++)
            {
                if ((i == j) || (i == j + 1) || (i == j - 1))
                    *(*(mat + i) + j) = rand() % 10;
                else
                    *(*(mat + i) + j) = 0;
            }
        break;

    case 1:
        for (i = 0; i < dim; i++)
            for (j = 0; j < dim; j++)
            {
                if ((i + j == dim - 1) || (i + j == dim) || (i == j - 2))
                    *(*(mat + i) + j) = rand() % 10;
                else
                    *(*(mat + i) + j) = 0;
            }
        break;
    }
}
