// Linked List: Inserting a Node at beginning
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head; // global variable, can be accessed everywhere

void Insert(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp; // insertion at the begin
};
 
void Print()
{
    struct Node* temp = head;
    printf("List is: ");
    while(temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
};

void Reverse()
{
    struct Node *current, *prev, *next;
    current = head;
    prev = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main()
{

    head = NULL; // empty list

    Insert(2); // List : 2
    Insert(3); // List : 3, 2
    Insert(4); // List : 4, 3, 2
    Insert(5); // List : 5, 4, 3, 2
    Print();

    Reverse();

    Print();

    return 0;
}