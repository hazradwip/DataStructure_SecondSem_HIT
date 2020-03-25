#include<stdio.h>
#include<math.h>
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

void add(poly*,poly*,int);

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
    poly *p;
    p=sort(s,n);
    for(i=0,j=i+1;i<n;i++,j++)
    {
        if((s+i)->coeff==-1)
            {
                if(((s+i)->exp)==1)
                    printf("-X");
                else if(((s+i)->exp)==0)
                    printf("-%d",abs(((s+i)->coeff)));
                else
                    printf("-X^%d",((s+i)->exp));
            }
        else if((s+i)->coeff==1)
        {
            if(((s+i)->exp)==1)
                printf("+X");
            else if(((s+i)->exp)==0)
                printf("+%d",((s+i)->coeff));
            else
                printf("+X^%d",((s+i)->exp));
        }
        else if(((s+i)->coeff)<0)
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
void add(poly *p1,poly *p2,int n)
{
    int i,k=0;
    poly *sum;
    sum=(poly*)malloc((n*2)*sizeof(poly));
    for(i=0;i<n;i++)
    {
        if((p1+i)->exp==((p2+i)->exp))
        {
            (sum+k)->coeff=(p1+i)->coeff+(p2+i)->coeff;
            (sum+k)->exp=(p1+i)->exp;
            k++;
        }
        else
        {
            (sum+k)->coeff=(p1+i)->coeff;
            (sum+k)->exp=(p1+i)->exp;
            k++;
            (sum+k)->coeff=(p2+i)->coeff;
            (sum+k)->exp=(p2+i)->exp;
            k++;
        }
    }
    printf("\nThe added polynomial is\n");
    display(sum,k);
}
