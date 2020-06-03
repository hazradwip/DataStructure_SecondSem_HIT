#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

typedef struct queue
{
    int front,rear;
    int arr[SIZE];
} queue;

int isFull(queue *);
int isEmpty(queue *);

void insert(queue *, int);
int del(queue *);

void display(queue *);