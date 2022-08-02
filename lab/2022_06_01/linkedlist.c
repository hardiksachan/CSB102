#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void printll(struct Node *head)
{
    while (head->next != NULL)
    {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("%d\n", head->data);
}

void insert(struct Node **head, int data, int pos)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    struct Node *temp = *head;
    if (pos == 0)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        int i = 0;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
}

int main()
{

    struct Node *one = malloc(sizeof(struct Node));
    struct Node *two = malloc(sizeof(struct Node));
    struct Node *three = malloc(sizeof(struct Node));
    struct Node *four = malloc(sizeof(struct Node));

    one->data = 1;
    two->data = 2;
    three->data = 3;
    four->data = 4;

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = NULL;

    struct Node *head = one;


    insert(&head, 20, 2);


    printll(head);
}