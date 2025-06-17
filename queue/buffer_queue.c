#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct
{
    int bufferId;
    int bufferCapacity;
    int NoBufferItems;
} bufferSchedule;

typedef struct
{
    bufferSchedule arr[MAX];
    int front;
    int rear;
} bufferQueue;

void init(bufferQueue *bq)
{
    bq->front = -1;
    bq->rear = -1;
}

int isFull(bufferQueue *bq)
{
    return bq->rear == MAX - 1;
}

int isEmpty(bufferQueue *bq)
{
    return bq->front == -1 && bq->rear == -1;
}

void enque(bufferQueue *bq, bufferSchedule bs)
{
    if (isFull(bq))
    {
        printf("\nQueue is empty");
    }
    else if (isEmpty(bq))
    {
        bq->front = bq->rear = 0;
    }
    else
    {
        bq->rear++;
    }
    bq->arr[bq->rear] = bs;
}

void denque(bufferQueue *bq)
{
    if (isEmpty(bq))
    {
        printf("\nQueue is empty");
    }
    else if (bq->front == bq->rear)
    {
        bq->front = bq->rear = -1;
    }
    else
    {
        bq->front++;
    }
}

bufferSchedule peek(bufferQueue *bq)
{
    return bq->arr[bq->front + 1];
}

void display(bufferQueue *bq)
{
    for (int i = bq->front + 1; i < bq->rear; i++)
    {
        printf("bufferId : %d", bq->arr[i].bufferId);
        printf("bufferCapacity : %d", bq->arr[i].bufferCapacity);
        printf("NoBufferItems : %d", bq->arr[i].NoBufferItems);
    }
}

int main()
{
    bufferQueue bq;

    init(&bq);

    return 0;
}