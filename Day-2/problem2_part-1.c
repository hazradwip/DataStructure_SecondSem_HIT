#include<stdio.h>
#include<stdlib.h>
struct poly
{
    int coeff;
    int exp;
};
typedef struct poly poly;
poly *sort(poly*,int);
int main()
{
    int n,i,j;
    printf("Enter the no.of terms in  polynomial\n");
    scanf("%d",&n);
    poly *p;
    p=(poly*)malloc(n*sizeof(poly));
    for(i=0;i<n;i++)
    {
        printf("Enter the degree\t");
        scanf("%d",&(p+i)->exp);
        printf("Enter the coefficient\t");
        scanf("%d",&(p+i)->coeff);
    }
    poly *s;
    s=sort(p,n);
    for(i=0,j=i+1;i<n;i++,j++)
    {
        if(((s+i)->coeff)<0)
            printf("%dX^%d",((p+i)->coeff),((p+i)->exp));
        else if(((s+i)->exp)==1)
            printf("+%dX",((s+i)->coeff));
        else if(((s+i)->exp)==0)
            printf("+%d",((s+i)->coeff));
        else
            printf("+%dX^%d",((s+i)->coeff),((s+i)->exp));
    }
}
poly *sort(poly *p,int n)
{
    poly temp;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if((p+i)->exp<(p+j)->exp)
            {
                temp=*(p+i);
                *(p+i)=*(p+j);
                *(p+j)=temp;
            }
        }
    }
    /*for(i=0;i<n;i++)
        printf("+%dX^%d",((p+i)->coeff),((p+i)->exp));*/
    return p;
}