// Linked List: Inserting a Node at beginning
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head; // global variable, can be accessed everywhere

void Insert(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if (head == NULL)
    {
        temp->next = head;
        head = temp; // insertion at the begin
    }
    else
    {
        struct Node* temp1 = head;
        while (temp1->next != NULL) // used to find the last node in the linked list
        {
            temp1 = temp1->next;
        }
        
        temp1->next = temp; // Insertion at the end
    }
    
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

void Reverse(struct Node* p)
{
    if(p->next == NULL){
        head = p;
        return;
    }
    Reverse(p->next);
    struct Node* q = p->next;
    q->next = p;
    p->next = NULL;
};

int main()
{

    head = NULL; // empty list
    
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(4);
    Print();
    Reverse(head);
    Print();
    return 0;
}