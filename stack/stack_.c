#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct Stack
{
    int arr[MAX];
    int top;
}st;

void push()
{
    int item;
    if(st.top == (MAX - 1))
    {
        printf("\n\n\t the stack is full/overflow....");
    }else
    {
        printf("\n\n\t Enter the element to be pushed into the stack : ");
        scanf("%d", &item);
        st.top = st.top + 1;
        st.arr[st.top] = item;
    }

}

void pop()
{
    int item;
    if(st.top == -1)
    {
        printf("\n\n\t the stack is empty/underflow....");
    }else
    {
        item = st.arr[st.top];
        st.top = st.top - 1;
        printf("\n\n\t the popped element is : %d", item);
    }
}

void display()
{
    if(st.top == -1)
    {   printf("\n\n\t the stack is empty/underflow....");
    }else
    {
        printf("\n\n\t The contents of the stack are ");
        for(int i = st.top ; i >= 0 ; i--)
        {
            printf(" %d", st.arr[i]);
        }
    }
}

int main()
{
    int choice;
    st.top = -1;

    do
    {
        printf("\n\n\t 1. push an element into stack :");
        printf("\n\n\t 2. pop an element from stack :");
        printf("\n\n\t 3. display the elements of stack :");
        printf("\n\n\t 4. exit from the program :");
        printf("\n\n\t Enter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\n\n\t wrong entry try again");
                break;
        }
    }while(choice != 4);


    return 0;
}