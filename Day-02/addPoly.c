#include "polynomial.h"

void add(poly *, poly *, int, int);

int main()
{
    int size_p1, size_p2;
    poly *p1, *p2, *sum;

    printf("Enter the polynomials : ");
    printf("\nEnter the no.of terms of 1st polynomial : ");
    scanf("%d", &size_p1);

    printf("Enter the 1st polynomial\n");
    p1 = create(size_p1);
    display(p1, size_p1);

    printf("\nEnter the no.of terms of 2nd polynomial : ");
    scanf("%d", &size_p2);

    printf("\nEnter the 2nd polynomial\n");
    p2 = create(size_p2);
    display(p2, size_p2);

    //int max_num = max(size_p1, size_p2);
    add(p1, p2, size_p1, size_p2);
}

void add(poly *p1, poly *p2, int n1, int n2)
{
    int i = 0, ptr1 = 0, ptr2 = 0;
    poly *sum;

    sum = (poly *)malloc((n1 + n2) * sizeof(poly));
    while (ptr1 < n1 && ptr2 < n2)
    {
        if ((p1 + ptr1)->exp == (p2 + ptr2)->exp)
        {
            (sum + i)->coeff = (p1 + ptr1)->coeff + (p2 + ptr2)->coeff;
            (sum + i)->exp = (p1 + ptr1)->exp;
            ptr1++;
            ptr2++;
            i++;
        }
        else
        {
            if ((p1 + ptr1)->exp > (p2 + ptr2)->exp)
            {
                (sum + i)->coeff = (p1 + ptr1)->coeff;
                (sum + i)->exp = (p1 + ptr1)->exp;
                ptr1++;
                i++;
            }
            else
            {
                (sum + i)->coeff = (p2 + ptr2)->coeff;
                (sum + i)->exp = (p2 + ptr2)->exp;
                ptr2++;
                i++;
            }
        }
    }

    while (i < n1)
    {

        (sum + i)->coeff = (p1 + ptr1)->coeff;
        (sum + i)->exp = (p1 + ptr1)->exp;
        ptr1++;
        i++;
    }

    while (i < n2)
    {
        (sum + i)->coeff = (p2 + ptr2)->coeff;
        (sum + i)->exp = (p2 + ptr2)->exp;
        ptr2++;
        i++;
    }

    printf("\nThe added polynomial is\n");
    display(sum, i);
}

/*
================ OUTPUT ================

SET - 1
--------
Enter the polynomials : 
Enter the no.of terms of 1st polynomial : 2
Enter the 1st polynomial
Enter the Exponent : 4
Enter the Co-efficient : 5
Enter the Exponent : 2
Enter the Co-efficient : 4
 +5x^4 +4x^2
Enter the no.of terms of 2nd polynomial : 3

Enter the 2nd polynomial
Enter the Exponent : 4
Enter the Co-efficient : 5
Enter the Exponent : 1
Enter the Co-efficient : 5
Enter the Exponent : 2
Enter the Co-efficient : 6
 +5x^4 +6x^2 +5x
The added polynomial is
 +10x^4 +10x^2 +5x
*/