#include "stack.h"

int isFull(stack *sp)
{
    if (sp->top == SIZE - 1)
        return 1;
    return 0;
}

int isEmpty(stack *sp)
{
    if (sp->top == -1)
        return 1;
    return 0;
}

void push(stack *sp, int item)
{
    if (isFull(sp))
        printf("\nStack is Overflow");
    else
    {
        sp->top++;
        sp->arr[sp->top] = item;
    }
}

int pop(stack *sp)
{
    if (isEmpty(sp))
    {
        printf("\nStack is Underflow");
        return -9999;
    }
    else
        return sp->arr[sp->top--];
}

int peek(stack *sp)
{
    return sp->arr[sp->top];
}