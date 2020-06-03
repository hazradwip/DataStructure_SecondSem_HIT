#include "circular_queue.h"

int isFull(queue *qp)
{
	if ((qp->front == qp->rear + 1) || (qp->front == 0 && qp->rear == SIZE - 1))
		return 1;
	return 0;
}

int isEmpty(queue *qp)
{
	if (qp->front == -1)
		return 1;
	return 0;
}

void insert(queue *qp, int item)
{
	if (isFull(qp))
		printf("\nQueue is Full");
	else
	{
		if (qp->front == -1)
			qp->front = 0;
		qp->rear = (qp->rear + 1) % SIZE;
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
		int item = qp->arr[qp->front];
		if (qp->front == qp->rear)
		{
			qp->front = -1;
			qp->rear = -1;
		}
		else
			qp->front = (qp->front + 1) % SIZE;

		return item;
	}
}

void display(queue *qp)
{
	for (int i = qp->front; i != qp->rear+1; i = (i + 1) % SIZE)
		printf("(%d) -", qp->arr[i]);
}
