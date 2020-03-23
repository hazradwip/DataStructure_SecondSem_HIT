#include "stack.h"
#include <string.h>
#include <ctype.h>

void postEval(char[], stack *);

int main()
{
    char postfix[SIZE];
    stack S = {-1,};
    printf("\nEnter the postfix postfixression (separate the Oparands using spaces) : ");
    gets(postfix);
    postEval(postfix, &S);
}

void postEval(char postfix[], stack *sp)
{
    int item_1, item_2, val;
    int i = 0, j = 0;
    int data = 0;

    for(i=0; postfix[i]; i++)
    {
        if (postfix[i] == ' ')
            continue;

        else if (isdigit(postfix[i])) 
		{
            data = 0;
            
            while (isdigit(postfix[i]))
            {
                data = data * 10 + (int)(postfix[i] - '0');
                i++;
            }
            i--;

            push(sp,data); 
		} 

        else
        {
            item_1 = pop(sp);
            item_2 = pop(sp);
            switch (postfix[i])
            {
            case '*':
                val = item_2 * item_1;
                break;
            case '/':
                val = item_2 / item_1;
                break;
            case '+':
                val = item_2 + item_1;
                break;
            case '-':
                val = item_2 - item_1;
                break;
            case '%':
                val = item_2 % item_1;
                break;
            default:
                printf("\nWrong Operator found!!");
                exit(0);
            }
            push(sp, val);
        }
    }
    
    printf("\nResult of postfix is : %d", pop(sp));
}
