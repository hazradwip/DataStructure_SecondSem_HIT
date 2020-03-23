#include<stdio.h>
#include<stdlib.h>
#define size 5
struct stack
{
    int top;
    int a[size];
};
typedef struct stack stck;
stck s={-1,};
void push(stck*,int);
int pop(stck*);
int isfull(stck*);
int isemp(stck*);

int main()
{
    int ch,n,x,flag;
    do
    {
        printf("\nSelect option\n");
        printf("1 to PUSH\n");
        printf("2 to pop\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter the element to push\n");
                scanf("%d",&n);
                push(&s,n);
                break;
            case 2:
                flag=pop(&s);
                printf("\nThe item popped%d\t",flag);
                break;
            default:
                printf("\nInvalid option");
                break;
        }
    } while (1);
}
int isemp(stck *s)
{
    if(s->top==-1)
        return 1;
    else
        return 0;
}
int isfull(stck *s)
{
    if(s->top==(size-1))
        return 1;
    else
        return 0;
}
void push(stck *s,int e)
{
    if(isfull(s))
        printf("Overflow");
    else
    {
        s->top=s->top+1;
        s->a[s->top]=e;
    }
}
int pop(stck *s)
{
    if(isemp(s))
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        return(s->a[(s->top)--]);
    }
}
