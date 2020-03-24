#include<stdio.h>
#include<stdlib.h>
struct poly
{
    int coeff;
    int exp;
};
typedef struct poly poly;
poly *create(int);
poly *sort(poly*,int);
void display(poly*,int);
int main()
{
    int n,i,j;
    printf("Enter the no.of terms in  polynomial\n");
    scanf("%d",&n);
    poly *p,*s;
    p=create(n);
    s=sort(p,n);
    display(p,n);
}
poly *create(int n)
{
    poly *p;
    p=(poly*)malloc(n*sizeof(poly));
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter the degree\t");
        scanf("%d",&(p+i)->exp);
        printf("Enter the coefficient\t");
        scanf("%d",&(p+i)->coeff);
    }
    return p;
}
void display(poly* s,int n)
{
    int i,j;
    for(i=0,j=i+1;i<n;i++,j++)
    {
        if(((s+i)->coeff)<=0)
        {
            if(((s+i)->exp)==1)
                printf("-%dX",abs(((s+i)->coeff)));
            else if(((s+i)->exp)==0)
                printf("-%d",abs(((s+i)->coeff)));
            else
                printf("-%dX^%d",abs(((s+i)->coeff)),((s+i)->exp));
        }
        else
        {
            if(((s+i)->exp)==1)
                printf("+%dX",((s+i)->coeff));
            else if(((s+i)->exp)==0)
                printf("+%d",((s+i)->coeff));
            else
                printf("+%dX^%d",((s+i)->coeff),((s+i)->exp));
        }
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
    return p;
}