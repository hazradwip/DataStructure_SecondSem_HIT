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