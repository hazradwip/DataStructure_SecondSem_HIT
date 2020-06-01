/* Infix to Postfix */

#include "stack.h"
#include <string.h>

/* symbol types */
/* symbol types */
#define Operator (-10)
#define Operand (-20)
#define LeftParen (-30)
#define RightParen (-40)
static char *symbols = "()^+-%*/";


char infix[SIZE + 1], postfix[SIZE + 1];

void IntoPost(stack *);
int get_type(char);
int get_prec(char);

int main()
{
    stack S = {-1,};

    printf("\n Infix (up to '%d' chars): ",SIZE);
    gets(infix);

    IntoPost(&S);

    printf("\n Infix: %s", infix);
    printf("\n Postfix: %s", postfix);

    return 0;
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
                while (sp->top > -1 && precedence <= get_prec(peek(sp)))
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
    case '^':
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
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 3;
    case '%':
        return 3;
    case '^':
        return 4;
    case '(':
        return 0;
    default:
        return 999;
    }
}

/*
================ OUTPUT ================
******* Stack size is define 10 at stack.h *******

 Infix (up to '10' chars): A+B*(C-D) 

 Infix: A+B*(C-D)
 Postfix: ABCD-*+
*/