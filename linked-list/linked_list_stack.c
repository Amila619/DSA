#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* link;
};

struct Node* top = NULL;

int isEmpty()
{
    return top == NULL;
}


void Push(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->link = top;
    top = temp;
}

void Pop()
{

    if (isEmpty())
    {
        return;
    }
    

    struct Node* temp = top;
    top = temp->link;
    free(temp);
}

void Print()
{
    struct Node* temp = top;
    printf("List is: ");
    while(temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->link;
    }
    printf("\n");
};

int Top()
{
    return top->data;
}

int main()
{
    Push(1);
    Push(2);
    Push(3);
    Push(4);
    Push(5);
    Push(6);

    Print();
    
    Pop();
    
    Print();

    return 0;
}