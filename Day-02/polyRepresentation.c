#include "polynomial.h"

int main()
{
    int n,i,j;

    printf("Enter the no.of terms in  polynomial : ");
    scanf("%d",&n);

    poly *p;
    p=create(n);
    
    display(p,n);

    return 0;
}

/*
================ OUTPUT ================

SET - 1
--------
Enter the no.of terms in  polynomial : 5
Enter the Exponent : 6
Enter the Co-efficient : 5
Enter the Exponent : 7
Enter the Co-efficient : 2
Enter the Exponent : 1
Enter the Co-efficient : -5
Enter the Exponent : 0
Enter the Co-efficient : 5
Enter the Exponent : 4
Enter the Co-efficient : 6
 +2x^7 +5x^6 +6x^4 -5x +5
*/