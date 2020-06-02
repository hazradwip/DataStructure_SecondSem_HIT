#include "dequeue.h"

int isFull(queue *qp)
{
    if ((qp->front == 0 && qp->rear == SIZE - 1) || qp->front == qp->rear + 1)
        return 1;
    return 0;
}

int isEmpty(queue *qp)
{
    if (qp->front == -1)
        return 1;
    return 0;
}

void insertFront(queue *qp, int item)
{
    if (isFull(qp))
    {
        printf("\nQueue is Full");
        return;
    }
    if (qp->front == -1)
    {
        qp->front = 0;
        qp->rear = 0;
    }
    else if (qp->front == 0)
        qp->front = SIZE - 1;
    else
        qp->front = qp->front - 1;

    qp->arr[qp->front] = item;
}

void insertRear(queue *qp, int item)
{
    if (isFull(qp))
    {
        printf("\nQueue is Full");
        return;
    }
    if (qp->front == -1)
    {
        qp->front = 0;
        qp->rear = 0;
    }
    else if (qp->rear == SIZE - 1)
        qp->rear = 0;
    else
        qp->rear = qp->rear + 1;

    qp->arr[qp->rear] = item;
}

int delFront(queue *qp)
{
    if (isEmpty(qp))
    {
        printf("\nQueue is Empty");
        return -9999;
    }

    int val;
    val = qp->arr[qp->front];
    if (qp->front == qp->rear)
    {
        qp->front = -1;
        qp->rear = -1;
    }
    else
    {
        if (qp->front == SIZE - 1)
            qp->front = 0;
        else
            qp->front = qp->front + 1;
    }

    return val;
}

int delRear(queue *qp)
{
    if (isEmpty(qp))
    {
        printf("\nQueue is Empty");
        return -9999;
    }

    int val;
    val = qp->arr[qp->rear];
    if (qp->front == qp->rear)
    {
        qp->front = -1;
        qp->rear = -1;
    }
    else if (qp->rear == 0)
        qp->rear = SIZE - 1;
    else
        qp->rear = qp->rear - 1;

    return val;
}

void display(queue *qp)
{
    for (int i = qp->front; i != qp->rear + 1; i = (i + 1) % SIZE)
        printf("(%d) -", qp->arr[i]);
}
