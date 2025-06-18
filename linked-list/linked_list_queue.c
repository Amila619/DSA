#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

int isEmpty()
{
    return front == NULL && rear == NULL;
}

void Enqueue(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if (isEmpty())
    {
        front = rear = temp;
        return;
    }
    
    rear->next = temp;
    rear = temp;
}

void Dequeue()
{
    struct Node* temp = front;

    if (front == NULL)
    {
        return;
    }

    if (front == rear)
    {
        front = rear = NULL;
    }else
    {
        front = front->next;
    }

    free(temp);
}

int Front()
{
    return front->data;
}

void Print()
{

    if (isEmpty())
    {
        return;
    }
    

    struct Node* temp = front;
    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);

    Print();

    Dequeue();

    Print();


    return 0;
}