#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

typedef struct stack
{
    int top;
    int arr[SIZE];
} stack;

int isFull(stack *);
int isEmpty(stack *);

void push(stack *, int);
int pop(stack *);

int peek(stack *);