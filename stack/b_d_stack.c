#include <stdio.h>
#include <stdlib.h>
#define MAX 5

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
    if((isFull(s)))
    {
        // printf("\nStack is full");
        return;
    }
    s->top++;
    s->arr[s->top] = item;
}

void pop(Stack *s, int *item)
{
    if (isEmpty(s))
    {
        // printf("\nStack is empty");
        return;
    }

    *item = s->arr[s->top];
    s->top--;    
}

void display(Stack *s)
{
    if(isEmpty(s))
    {
        // printf("\nStack is empty");
        return;
    }else{
        for(int i = s->top ; i >= 0  ; i--)
        {
            printf("%d", s->arr[i]);
        }
    }
}

int convertBinary(Stack *s, int num)
{
    int rem;

    while(num > 0)
    {
        rem = num % 2;
        num = num / 2;
        push(s, rem);
    }

    printf("\n");
}

int main()
{
    Stack s;
    int n = 12;

    init(&s);
    convertBinary(&s, n);
    display(&s);

    return 0;
}