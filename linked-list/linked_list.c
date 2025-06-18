#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

void InsertAtBegin(int item)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = item;
    temp->next = head;

    head = temp;
}

void InsertAtEnd(int item)
{
    struct Node *temp_ = (struct Node *)malloc(sizeof(struct Node));
    temp_->data = item;
    temp_->next = NULL;

    if (head == NULL)
    {
        temp_->next = head;
        head = temp_; // insertion at the begin
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = temp_;
    }
}

void insertAtNthpos(int n, int item)
{
    struct Node *temp_ = (struct Node *)malloc(sizeof(struct Node));
    temp_->data = item;
    temp_->next = NULL;

    if (n == 1)
    {
        temp_->next = head;
        head = temp_;
        return;
    }

    struct Node *temp = head;
    for (int i = 0; i < n - 2; i++)
    {
        if (temp->next == NULL)
        {
            printf("Position out of range.\n");
            return;
        }
        temp = temp->next;
    }

    temp_->next = temp->next;
    temp->next = temp_;
}

void deleteAtBegin()
{

    if (head == NULL)
    {
        printf("List is already empty.\n");
        return;
    }

    struct Node *temp = head;
    head = temp->next;
    free(temp);
}

void deleteAtEnd()
{

    if (head == NULL)
    {
        printf("List is already empty.\n");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

void deleteAtNthpos(int n)
{
    if (head == NULL)
    {
        printf("List is already empty.\n");
        return;
    }

    if (n == 1)
    {
        struct Node *temp = head;
        head = temp->next;
        free(temp);
        return;
    }

    struct Node *temp = head;
    for (int i = 0; i < n - 2; i++)
    {
        if (temp == NULL || temp->next == NULL)
        {
            printf("Position out of range.\n");
            return;
        }
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        printf("Position out of range.\n");
        return;
    }

    struct Node *toDelete = temp->next;

    temp->next = toDelete->next;
    free(toDelete);
}

void Print()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    head = NULL; // empty list
    printf("How many numbers?\n");
    int n, i, x;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the number \n");
        scanf("%d", &x);
        InsertAtEnd(x);
        Print();
    }
    insertAtNthpos(1, 3);
    Print();
    insertAtNthpos(2, 4);
    Print();
    deleteAtNthpos(200);
    Print();

    return 0;
}