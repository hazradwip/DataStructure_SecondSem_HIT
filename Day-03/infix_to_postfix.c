/* Infix to Postfix */

#include "stack.h"
#include <string.h>

/* symbol types */
#define Operator (-10)
#define Operand (-20)
#define LeftParen (-30)
#define RightParen (-40)
static char *symbols = "()+-%*/";

/* Symbol precedence */
#define LeftParenPrec 0 /* ( */
#define AddPrec 1       /* + */
#define SubPrec 1       /* - */
#define MultPrec 2      /* * */
#define DivPrec 2       /* / */
#define RemPrec 2       /* % */
#define None 999        /* all else */

char infix[SIZE + 1], postfix[SIZE + 1];

void getdata();
void display();
void IntoPost(stack *);
int get_type(char);
int get_prec(char);

int main()
{
    stack S = {-1,};

    getdata();
    IntoPost(&S);
    display();

    return 0;
}

void getdata()
{
    printf("\n Infix (up to '%d' chars): ",SIZE);
    gets(infix);
}

void display()
{
    printf("\n Infix: %s", infix);
    printf("\n Postfix: %s", postfix);
}

void IntoPost(stack *sp)
{
    int i, p, len, type, precedence;
    char next;

    /* i for infix index, p for postfix index */
    i = p = 0;

    len = strlen(infix);
    while (i < len)
    {
        if (infix[i] != ' ' || '\0')
        {
            type = get_type(infix[i]);
            switch (type)
            {
            case LeftParen:
                push(sp,infix[i]);
                break;
            case RightParen:
                while ((next = pop(sp)) != '(')
                    postfix[p++] = next;
                break;
            case Operand:
                postfix[p++] = infix[i];
                break;
            case Operator:
                precedence = get_prec(infix[i]);
                while (sp->top > -1 && precedence <= get_prec(sp->arr[sp->top]))
                    postfix[p++] = pop(sp);
                push(sp, infix[i]);
                break;
            }
        }
        i++;
    }
    while (sp->top > -1)
        postfix[p++] = pop(sp);
    postfix[p] = '\0';
}

int get_type(char symbol)
{
    switch (symbol)
    {
    case '(':
        return (LeftParen);
    case ')':
        return (RightParen);
    case '+':
    case '-':
    case '%':
    case '*':
    case '/':
        return (Operator);
    default:
        return (Operand);
    }
}

int get_prec(char symbol)
{
    switch (symbol)
    {
    case '+':
        return (AddPrec);
    case '-':
        return (SubPrec);
    case '*':
        return (MultPrec);
    case '/':
        return (DivPrec);
    case '%':
        return (RemPrec);
    case '(':
        return (LeftParenPrec);
    default:
        return (None);
    }
}