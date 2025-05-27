#include <stdio.h>
#include <stdlib.h>
#define MAX 3

typedef struct
{
   int arr[MAX];
   int top;
}Stack;

void init(Stack *s)
{
    s->top = -1;
}

int isFull(Stack *s)
{
    return s->top == (MAX - 1);
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

void push(Stack *s, int item)
{
    if(isFull(s))
    {
        printf("\nStack is full");
        return;
    }

    s->top = s->top + 1;
    s->arr[s->top] = item;
}

void pop(Stack *s, int *item)
{
    if(isEmpty(s))
    {
        printf("\nStack is empty");
        return;
    }else{
        *item = s->arr[s->top];
        s->top = s->top - 1;
    }
}

void display(Stack *s)
{
    if(isEmpty(s))
    {
        printf("\nStack is empty");
        return;
    }else{
        for(int i = s->top ; i >= 0 ; i--)
        {
            printf(" %d", s->arr[i]);
        }
    }
}

int main()
{

    Stack s;
    int item;

    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    pop(&s, &item);
    printf("\nPoped Item : %d", item);
    
    pop(&s, &item);
    printf("\nPoped Item : %d", item);
    
    pop(&s, &item);
    printf("\nPoped Item : %d", item);

    return 0;
}