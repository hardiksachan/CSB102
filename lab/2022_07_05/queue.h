#define QUEUE_SIZE 50

struct Queue
{
    int arr[QUEUE_SIZE];
    int start;
    int end;
};

struct Queue *create_queue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->start = -1;
    queue->end = -1;
}

int size(struct Queue *q)
{
    if (q->start == -1)
        return 0;
    return q->end - q->start + 1;
}

void enque(struct Queue *q, int elem)
{
    if (size(q) == QUEUE_SIZE)
    {
        printf("\n!!!QUEUE OVERFLOW!!!\n");
        return;
    }

    if (size(q) == 0)
    {
        q->start = 0;
        q->end = 0;

        q->arr[q->end] = elem;
        return;
    }

    q->end++;
    q->arr[q->end] = elem;
}

int deque(struct Queue *q)
{
    if (size(q) == 0)
    {
        printf("\n!!!QUEUE UNDERFLOW!!!\n");
        return -3496;
    }

    if (size(q) == 1)
    {
        int data = q->arr[q->start];

        q->start = -1;
        q->end = -1;

        return data;
    }

    int data = q->arr[q->start];
    q->start++;
    return data;
}