#include <stdio.h>
#include <stdlib.h>
#define n 5

int queue[n];
int ch;
int front = -1;
int rear = -1;
int item;

int isFull()
{
    return rear == n - 1;
}

int isEmpty()
{
    return front == -1 && rear == -1;
}

void enqueue()
{
    if (isFull())
    {
        printf("\nQueue is full");
        return;
    }
    else if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = rear + 1;
    }
    printf("\nEnter item : ");
    scanf("%d", &item);
    queue[rear] = item;
}

void dequeue()
{
    if (isEmpty())
    {
        printf("\nQueue is empty");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        item = queue[front];
        front = front + 1;
        printf("Removed : %d", item);
    }
}

void display()
{
    if (isEmpty())
    {
        printf("\nQueue is empty");
        return;
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf(" %d", queue[i]);
        }
    }
}


void peek()
{
    if (isEmpty())
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\nFront element: %d", queue[front]);
    }
}


int main()
{

    printf("Queue using Array");
    printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");

    while (ch != 4)
    {
        printf("\nEnter the Choice:");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nWrong Choice");
            break;
        }
    }
    return 0;
}