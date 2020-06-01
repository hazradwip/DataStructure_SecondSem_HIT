#include "matrix.h"

int menu();
void getType(int **, int);

int isLeftLower(int **, int);
int isRightLower(int **, int);

int isLeftUpper(int **, int);
int isRightUpper(int **, int);

int isLeftDiagonal(int **, int);
int isRightDiagonal(int **, int);

int isIdentity(int **, int);

int isLeftTriDiagonal(int **, int);
int isRightTriDiagonal(int **, int);

int main()
{
    int **mat;
    int dim, i, j;
    int option_check, option_input;

    /*
    printf("\n----- What do you want to Check ? -----\n");
    option_check = menu();
    */

    printf("\nEnter the Dimention for the Matrix: ");
    scanf("%d", &dim);

    mat = (int **)malloc(dim * sizeof(int *));
    for (i = 0; i < dim; i++)
        *(mat + i) = (int *)malloc(dim * sizeof(int));

    printf("\n----- What type of Matrix you want to Input -----\n");
    option_input = menu();

    switch (option_input)
    {
    case 1:
        getLower(mat, dim);
        break;

    case 2:
        getUpper(mat, dim);
        break;

    case 3:
        getDigonal(mat, dim);
        break;

    case 4:
        getIdentity(mat, dim);
        break;

    case 5:
        getTriDigonal(mat, dim);
        break;

    default:
        printf("\nWrong Choise!!");
        exit;
        break;
    }

    //printf("\nThe Matrix is : \n");
    display(mat, dim, dim);
    printf("\n");

    getType(mat, dim);
}

int menu()
{
    int op;

    printf("1. Lower Triangular\n");
    printf("2. Upper Triangular\n");
    printf("3. Diagonal\n");
    printf("4. Identity\n");
    printf("5. Tri-Diagonal\n");
    printf("Enter you choise : ");
    scanf("%d", &op);

    return op;
}

void getType(int **mat, int dim)
{
    if (isLeftLower(mat, dim) || isRightLower(mat, dim))
        printf("The Matrix is Lower Triangular Matrix\n");
    if (isLeftUpper(mat, dim) || isRightUpper(mat, dim))
        printf("The Matrix is Upper Triangular Matrix\n");
    if (isLeftDiagonal(mat, dim) || isRightDiagonal(mat, dim))
        printf("The Matrix is Diagonal Triangular Matrix\n");
    if (isIdentity(mat, dim))
        printf("The Matrix is Identity Matrix\n");
    if (isLeftTriDiagonal(mat, dim) || isRightTriDiagonal(mat, dim))
        printf("The Matrix is Tri-Diagonal Triangular Matrix\n");
}

int isLeftLower(int **mat, int dim)
{
    int i, j, flag = 1;

    for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++)
            if (i < j)
                if (*(*(mat + i) + j) != 0)
                {
                    flag = 0;
                    break;
                }

    return flag;
}

int isRightLower(int **mat, int dim)
{
    int i, j, flag = 1;

    for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++)
            if (i + j < dim - 1)
                if (*(*(mat + i) + j) != 0)
                {
                    flag = 0;
                    break;
                }

    return flag;
}

int isLeftUpper(int **mat, int dim)
{
    int i, j, flag = 1;

    for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++)
            if (i > j)
                if (*(*(mat + i) + j) != 0)
                {
                    flag = 0;
                    break;
                }

    return flag;
}

int isRightUpper(int **mat, int dim)
{
    int i, j, flag = 1;

    for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++)
            if (i + j > dim - 1)
                if (*(*(mat + i) + j) != 0)
                {
                    flag = 0;
                    break;
                }

    return flag;
}

int isLeftDiagonal(int **mat, int dim)
{
    int i, j, flag = 1;

    for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++)
            if (i != j)
                if (*(*(mat + i) + j) != 0)
                {
                    flag = 0;
                    break;
                }

    return flag;
}

int isRightDiagonal(int **mat, int dim)
{
    int i, j, flag = 1;

    for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++)
            if (i + j != dim - 1)
                if (*(*(mat + i) + j) != 0)
                {
                    flag = 0;
                    break;
                }

    return flag;
}

int isIdentity(int **mat, int dim)
{
    int i, j, flag = 1;

    for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++)
        {
            if (i == j && *(*(mat + i) + j) != 1)
            {
                flag = 0;
                break;
            }
            if (i != j && *(*(mat + i) + j) != 0)
            {
                flag = 0;
                break;
            }
        }

    return flag;
}

int isLeftTriDiagonal(int **mat, int dim)
{
    int i, j, flag = 1;

    for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++)
            if ((i != j) && (i != j + 1) && (i != j - 1))
                if (*(*(mat + i) + j) != 0)
                {
                    flag = 0;
                    break;
                }

    return flag;
}

int isRightTriDiagonal(int **mat, int dim)
{
    int i, j, flag = 1;

    for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++)
            if ((i + j != dim - 1) && (i + j != dim) && (i != j - 2))
                if (*(*(mat + i) + j) != 0)
                {
                    flag = 0;
                    break;
                }

    return flag;
}


/*
================ OUTPUT ================
******* All the inputs are taking by Random Function written in matrix.c *******

SET - 1
--------
Enter the Dimention for the Matrix: 5

----- What type of Matrix you want to Input -----
1. Lower Triangular
2. Upper Triangular
3. Diagonal
4. Identity
5. Tri-Diagonal
Enter you choise : 1

The Matrix is :
 0  0  0  0  9
 0  0  0  0  0
 0  0  9  5  4
 0  2  8  5  0
 1  7  2  3  5

The Matrix is Lower Triangular Matrix

--------
SET - 2
--------
Enter the Dimention for the Matrix: 4

----- What type of Matrix you want to Input -----
1. Lower Triangular
2. Upper Triangular
3. Diagonal
4. Identity
5. Tri-Diagonal
Enter you choise : 5

The Matrix is :
 0  0  8  2
 0  0  6  3
 0  9  6  0
 0  4  0  0

The Matrix is Tri-Diagonal Triangular Matrix
*/