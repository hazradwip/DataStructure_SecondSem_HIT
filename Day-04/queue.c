#include "queue.h"

int isFull(queue *qp)
{
    if (qp->rear == SIZE - 1)
        return 1;
    return 0;
}

int isEmpty(queue *qp)
{
    if (qp->rear == qp->front)
        return 1;
    return 0;
}

void insert(queue *qp, int item)
{
    if (isFull(qp))
        printf("\nQueue is Full");
    else
    {
        qp->rear++;
        qp->arr[qp->rear] = item;
    }
}

int del(queue *qp)
{
    if (isEmpty(qp))
    {
        printf("\nQueue is Empty");
        return -9999;
    }
    else
    {
        qp->front++;
        return qp->arr[qp->front];
    }
}

void display(queue *qp)
{
    for (int i = qp->front + 1; i <= qp->rear; i++)
        printf("(%d) -", qp->arr[i]);
}