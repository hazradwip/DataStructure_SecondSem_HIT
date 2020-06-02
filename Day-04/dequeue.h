#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct queue
{
    int front, rear;
    int arr[SIZE];
} queue;

int isFull(queue *);
int isEmpty(queue *);

void insertFront(queue *, int);
void insertRear(queue *, int);

int delFront(queue *);
int delRear(queue *);

void display(queue *);