//#include <stdio.h>
#include <string.h>
#include "stack.h"

int checkPrece(char);

char infix[SIZE], postfix[SIZE], str_stack[SIZE];
stack S = {
    -1,
};

void main()
{
    int i, len, j;
    printf("Enter the infix expression : ");
    gets(infix);

    push(&S, '(');
    strcat(infix, ")");

    len = strlen(infix);
    printf("\n  NO.   | SYMBOL|         STACK         |    EXPRESSION ");
    printf("\n--------|-------|-----------------------|-----------------");
    for (i = 0, j = 0; i < len; i++)
    {
        if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || 
            infix[i] == '%' || infix[i] == '^' || infix[i] == '(' || infix[i] == ')')
        {
            if (infix[i] == ')')
            {
                while (peek(&S) != '(')
                {
                    postfix[j] = pop(&S);
                    str_stack[strlen(str_stack) - 1] = '\0';
                    j++;
                }
                pop(&S);
                str_stack[strlen(str_stack) - 1] = '\0';
            }
            else
            {
                while (checkPrece(peek(&S)) >= checkPrece(infix[i]))
                {
                    postfix[j] = pop(&S);
                    str_stack[strlen(str_stack) - 1] = '\0';
                    j++;
                }
                if (infix[i] != ')' || infix[i] == '#')
                    push(&S, infix[i]);
            }
        }
        else
        {
            postfix[j] = infix[i];
            j++;
        }

        postfix[j] = '\0';

        {
            int index = 0;
            while (index <= S.top)
            {
                str_stack[index] = (char)S.arr[index];
                index++;
            }
        }
        printf("\n%3d\t| %c\t|     %2s\t\t| %s", i + 1, infix[i], str_stack, postfix);
    }
    printf("\n----------------------------------------------------------\n");
}

int checkPrece(char p)
{
    if (p == '^')
        return (4);
    else if (p == '%' || p == '/')
        return (3);
    else if (p == '*')
        return (2);
    else if (p == '+' || p == '-')
        return (1);    
    else
        return (-1);
}
