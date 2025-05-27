// Linked List: Inserting a Node at beginning
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void Insert(struct Node** pointerToHead, int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    // temp->next =  NULL;

    // if (head != NULL) 
    // {
    //     temp->next = head;
    // }
    temp->next = *pointerToHead;
    *pointerToHead = temp; // insertion at the begin
};
 
void Print(struct Node** pointerToHead)
{
    struct Node* temp = *pointerToHead;
    printf("List is: ");
    while(temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
};

int main()
{

    struct Node* head = NULL; // empty list
    printf("How many numbers?\n");
    int n, i, x;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the number \n");
        scanf("%d", &x);
        Insert(&head, x);
        Print(&head);
    }

    return 0;
}