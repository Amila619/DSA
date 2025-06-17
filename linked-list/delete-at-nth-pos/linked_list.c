// Linked List: Deleting a Node at nth position
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head;

void Insert(int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = head;

    head = temp;
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

void Delete(int n) 
{
    int i;

    struct Node* temp = head;

    if (n == 1)
    {
        head = temp->next; // head now points to to second Node
        free(temp);
        return;
    }

    for (i = 0; i < n-2; i++)
    {
        temp = temp->next; // temp points to (n-1)th Node
    }

    struct Node* temp1 = temp->next; // (n)th Node 
    temp->next = temp1->next; // (n+1)th Node
    free(temp1); // delete (n)th Node
}

int main()
{
    head = NULL;

    Insert(2); // List : 2
    Insert(3); // List : 3, 2
    Insert(4); // List : 4, 3, 2
    Insert(5); // List : 5, 4, 3, 2
    Print();

    int n;
    printf("Enter a position\n");
    scanf("%d", &n);
    Delete(n);
    Print();

    return 0;
}