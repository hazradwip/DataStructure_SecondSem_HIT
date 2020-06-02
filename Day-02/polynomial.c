#include "polynomial.h"

poly *create(int n)
{
    poly *p;

    p = (poly *)malloc(n * sizeof(poly));
    int i;

    for (i = 0; i < n; i++)
    {
        printf("Enter the Exponent : ");
        scanf("%d", &(p + i)->exp);
        printf("Enter the Co-efficient : ");
        scanf("%d", &(p + i)->coeff);
    }

    return p;
}

void display(poly *s, int n)
{
    int i, j;
    poly *p;

    p = sort(s, n);
    for (i = 0; i < n; i++)
    {
        if ((s + i)->coeff == -1)
        {
            if (((s + i)->exp) == 1)
                printf(" -x");
            else if (((s + i)->exp) == 0)
                printf(" -%d", abs(((s + i)->coeff)));
            else
                printf(" -x^%d", ((s + i)->exp));
        }

        else if ((s + i)->coeff == 1)
        {
            if (((s + i)->exp) == 1)
                printf(" +x");
            else if (((s + i)->exp) == 0)
                printf(" +%d", ((s + i)->coeff));
            else
                printf(" +x^%d", ((s + i)->exp));
        }
    
        else if (((s + i)->coeff) < 0)
        {
            if (((s + i)->exp) == 1)
                printf(" -%dx", abs(((s + i)->coeff)));
            else if (((s + i)->exp) == 0)
                printf(" -%d", abs(((s + i)->coeff)));
            else
                printf(" -%dx^%d", abs(((s + i)->coeff)), ((s + i)->exp));
        }

        else if (((s + i)->coeff) == 0)
            continue;

        else
        {
            if (((s + i)->exp) == 1)
                printf(" +%dx", ((s + i)->coeff));
            else if (((s + i)->exp) == 0)
                printf(" +%d", ((s + i)->coeff));
            else
                printf(" +%dx^%d", ((s + i)->coeff), ((s + i)->exp));
        }
    }
}

poly *sort(poly *p, int n)
{
    poly temp;
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if ((p + i)->exp < (p + j)->exp)
            {
                temp = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = temp;
            }
        }
    }

    return p;
}

