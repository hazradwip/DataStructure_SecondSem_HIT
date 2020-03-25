#include<stdio.h>
#include<stdlib.h>
#include "poly_fun.c"

int main()
{
    int n,i,j;
    printf("Enter the no.of terms in  polynomial\n");
    scanf("%d",&n);
    poly *p;
    p=create(n);
    display(p,n);
}