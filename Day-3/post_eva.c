#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define SIZE 5
struct stack
{
    int top;
    int st[SIZE];
};
typedef struct stack st;
st s={-1,};
char pop(st *);
void push(st*,char);
int isempty(st*);
int isfull(st*);
void post_e(char [],st *);
int main()
{
    int ch;
    char n,x;
    char postfix[50];
    printf("\nEnter the postfix expression\t");
    scanf("%s",&postfix);
    post_e(postfix,&s);
    /*do
    {
    printf("\nEnter 1 to push\n2 to pop\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        printf("\nEnter element to push\n");
        scanf("%s",&n);
        push(&s,n);
        break;
        case 2:
        x=pop(&s);
        printf("The element poped is %c\t",x);
        break;
        default:
        break;
    }
    }while (1);*/
    
}
int isempty(st *s)
{
    if(s->top==-1)
        return 1;
    else
        return 0;
}
int isfull(st *s)
{
    if(s->top==SIZE-1)
        return 1;
    else
        return 0;
}
char pop(st *s)
{
    char x;
    if(isempty(s))
        {
           printf("Underflow");
           exit (0);
        }
    else
    {
        x=s->st[s->top];
        s->top=s->top-1;
        return x;
    }
}
void push(st *s,char x)
{
    if(isfull(s))
        printf("Overflow");
    else
       {
            s->top=s->top+1;
            s->st[s->top]=x;
       }
}
void post_e(char x[],st *s)
{
    int i=0,a,b,val;
    char item=x[i];
    while(item!='\0')
    {
        if(isdigit(item))
        push(s,item - '0');
        else if(item=='+'||item=='-'||item=='*'||item=='/')
        {
            a=pop(s);
            b=pop(s);
            switch(item)
            {
                case '*':
                val=a*b;
                break;
                case '/':
                val=a/b;
                break;
                case '+':
                val=a+b;
                break;
                case '-':
                val=a-b;
                break;
            }
            push(s,val);
        }
        i++;
        item=x[i];
    }
    printf("\nResult of exp is \t%d",val);
}
