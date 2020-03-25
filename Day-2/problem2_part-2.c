#include<stdio.h>
#include "poly_fun.c"
int main()
{
    int n;
    poly *p1,*p2,*sum;
    printf("Enter the polynomials\t");
    printf("\nEnter the no.of terms of  polynomial\t");
    scanf("%d",&n);
    printf("Enter the 1st polynomial\n");
    p1=create(n);
    printf("\nEnter the 2nd polynomial\n");
    p2=create(n);
    add(p1,p2,n);
}
