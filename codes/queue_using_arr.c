#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 100

struct queue
{
    int arr[CAPACITY];
    int head;
    int tail;
};

struct queue * create_queue()
{
    struct queue * q = (struct queue *)malloc(sizeof(struct queue));
    q->head = -1;
    q->tail = -1;
    return q;
}

int size(struct queue *q)
{
    if (q->head == -1)
        return 0;
    return q->tail - q->head + 1;
}

void enque(struct queue *q, int data)
{
    if (q->tail == CAPACITY - 1)
    {
        printf("!!!OVERFLOW!!!");
        return;
    }

    if (size(q) == 0)
    {
        q->head = 0;
        q->tail = 0;
        q->arr[q->tail] = data;
        return;
    }

    q->tail++;
    q->arr[q->tail] = data;
}

int deque(struct queue *q)
{
    if (size(q) == 0)
    {
        printf("!!!UNDERFLOW!!!");
        return -1;
    }

    int data = q->arr[q->head];

    if (size(q) == 1)
    {
        q->head = -1;
        q->tail = -1;
        return data;
    }
    q->head++;
    return data;
}

void display(struct queue *q)
{
    if (size(q) == 0)
    {
        printf("!!!EMPTY!!!");
        return;
    }

    int i = q->head;
    while (i <= q->tail)
    {
        printf("%d ", q->arr[i]);
        i++;
    }
    printf("\n");
}

int main()
{
    struct queue *q = create_queue();

    // menu driven program
    int choice;
    do
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            int data;
            printf("Enter data: ");
            scanf("%d", &data);
            enque(q, data);
            break;
        case 2:
            int val = deque(q);d
            if (val != -1)
                printf("Dequeued data: %d\n", val);
            break;
        case 3:
            display(q);
            break;
        case 4:
            break;
        default:
            printf("!!!INVALID CHOICE!!!");
            break;
        }
    } while (choice != 0);
}