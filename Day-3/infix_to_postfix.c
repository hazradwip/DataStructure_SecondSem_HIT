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
void in_post(char [],char [],st *);
char pop(st *);
void push(st*,char);
int isempty(st*);
int isfull(st*);
int precedence(char);
int isoperator(char);
int check_exp(char[]);
char infix[10],postfix[10];
int main()
{
    int ch;
    char n,x;
    printf("\nEnter the infix expression\t");
    scanf("%s",&infix);
    //printf("%d",check_exp(infix));
    if(check_exp(infix)==0)
    {
        printf("\nInvalid expression\n");
        exit(0);
    }
    else
    {
    in_post(infix,postfix,&s);
    printf("\nThe postfix expression is\t%s\t",postfix);
    }
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
void in_post(char infix[],char postfix[],st *s)
{
    char x,item;
    int i=0,j=0;
    push(s,'(');
    strcat(infix,")");
    item=infix[i];
    while (item!='\0')
    {
        if(item=='(')
        push(s,item);
        else if(isdigit(item)||isalpha(item))
        {
            postfix[j]=item;
            j++;
        }
        else if(isoperator(item))
        {
            x=pop(s);
            while(isoperator(item)&&precedence(x)>precedence(item))
            {
                postfix[j]=x;
                j++;
                x=pop(s);
            }
            push(s,x);
            push(s,item);
        }
    else if(item==')')
    {
        x=pop(s);
        while(x!='(')
        {
            postfix[j]=x;
            j++;
            x=pop(s);
        }
    }
    else
    {
        printf("\nINvalid");
        exit(0);
    }
    i++;
    item=infix[i];
    }
    if(s->top==0)
    {
        printf("\nInvalid");
        exit(0);
    }
}
int precedence(char x)
{
    if(x=='^')
    return 3;
    else if(x=='/'||x=='*')
    return 2;
    else if(x=='+'||x=='-')
    return 1;
    else
    return 0;
}
int isoperator(char x)
{
    if(x=='/'||x=='*'||x=='+'||x=='-'||x=='^')
    return 1;
    else
    return 0;
}
int check_exp(char in[])
{
    int i=0,chr=0,op=0;
    while(in[i]!='\0')
    {
        if(isalpha(in[i]))
        chr++;
        else if(in[i]=='+'||in[i]=='-'||in[i]=='*'||in[i]=='/')
        op++;
        i++;
    }
    if(op==chr-1)
    return 1;
    else
    return 0;
}