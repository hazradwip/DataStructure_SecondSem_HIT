#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void create(int);
void lin_search(int*,int,int);
void sen_lin_search(int*,int,int);
void bi_search(int*,int,int);
int *sort(int*,int);
int main()
{
    int i,ch,n,x;
    int *m;
    FILE *f;
    printf("Enter the size of array\t");
    scanf("%d",&n);
    printf("Creation of list done\n-----------------------------\n");
    create(n);
    f=fopen("Numbers.txt","r");
    m=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        fscanf(f,"%d",(m+i));
    }
    printf("The entered list is:\n");
    for(i=0;i<n;i++)
        printf("%d\t",*(m+i));
    printf("\nEnter element to search\t");
    scanf("%d",&x);
    printf("\nEnter choice");
    printf("\nEnter 1 to linear search\nEnter 2 to sentinel linear search\nEnter 3 for binary search\n");
    printf("Enter choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        lin_search(m,n,x);
        break;
        case 2:
        sen_lin_search(m,n,x);
        break;
        case 3:
        bi_search(m,n,x);
        break;
        default:
        printf("\nInvalid choice");
        break;
    }
    fclose(f);
}
void create(int n)
{
    int i=0;
    FILE *f;
    f=fopen("Numbers.txt","w");
    srand(time(0));
    for(i=0;i<n;i++)
    {
        fprintf(f,"%d\t",rand()%10);
    }
    fclose(f);
}
void lin_search(int *m,int n,int x)
{
    int i,j=0;
    int ar[n];
    for(i=0;i<n;i++)
    {
        if(*(m+i)==x)
        {
            ar[j]=i+1;
            j++;
        }
    }
    if(j==0)
        printf("Item not found\n");
    else
    {
        printf("Item found at locations\n");
        for(i=0;i<j;i++)
            printf("%d\t",ar[i]);
    }
}
void sen_lin_search(int *m,int n,int x)
{
    int last=m[n-1];
    m[n-1]=x;
    int i=0,j=0,ar[n];
    while(*(m+i)!=x)
        i++;
    m[n-1]=last;
    if(i<n-1||(x==m[n-1]))
        printf("Item found at locations\t%d\n",i+1);
    else
        printf("Item not found\n");
}
void bi_search(int *m,int n,int x)
{
    int f=0,l=n-1,i;
    int *s;
    s=sort(m,n);
    printf("The sorted list\n");
    for(i=0;i<n;i++)
        printf("%d\t",s[i]);
    int mid=((f+l)/2);
    while(f<=l)
    {
        if(s[mid]<x)
            f=mid+1;
        else if(s[mid]==x)
        {
            printf("\nItem found at location in the sorted list\t%d\n",mid+1);
            break;
        }
        else
            l=mid-1;
        mid=(f+l)/2;
    }
    if(f>l)
        printf("\nItem not found\n");
}
int *sort(int *m,int n)
{
    int i,j,t;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(m[i]>m[j])
            {
                t=m[i];
                m[i]=m[j];
                m[j]=t;
            }
        }
    }
    return m;
}