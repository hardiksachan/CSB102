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

struct Node *reverse(struct Node *head)
{
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

void *combine(struct Node *head, struct Node *tail)
{
    struct Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = tail;
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

    struct Node *six = malloc(sizeof(struct Node));
    struct Node *seven = malloc(sizeof(struct Node));
    struct Node *eight = malloc(sizeof(struct Node));
    struct Node *nine = malloc(sizeof(struct Node));

    six->data = 6;
    seven->data = 7;
    eight->data = 8;
    nine->data = 9;

    six->next = seven;
    seven->next = eight;
    eight->next = nine;
    nine->next = NULL;

    struct Node *head2 = six;

    printll(head);
    printll(head2);
    combine(head, head2);
    printll(head);
    head = reverse(head);
    printll(head);
}