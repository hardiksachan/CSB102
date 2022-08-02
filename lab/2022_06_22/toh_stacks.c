#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#define STACK_SIZE 10

struct stack
{
    int *arr;
    int top;
    char label;
};

// create stack
struct stack *create_stack(char label)
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->arr = (int *)malloc(sizeof(int) * STACK_SIZE);
    s->top = -1;
    s->label = label;
    return s;
}

// stack push
void push(struct stack *s, int data)
{
    if (s->top == STACK_SIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    s->top++;
    s->arr[s->top] = data;
}

// stack pop
int pop(struct stack *s)
{
    if (s->top == -1)
    {
        printf("Stack Underflow\n");
        return INT_MIN;
    }
    int data = s->arr[s->top];
    s->top--;
    return data;
}

// stack peek
int peek(struct stack *s)
{
    if (s->top == -1)
    {
        printf("Stack Underflow\n");
        return INT_MIN;
    }
    return s->arr[s->top];
}

// stack is Empty
int isEmpty(struct stack *s)
{
    return s->top == -1;
}

// stack size
int size(struct stack *stack)
{
    return stack->top + 1;
}
// stack print
void print_stack(struct stack *s)
{
    printf("%c: ", s->label);
    if (isEmpty(s))
    {
        printf("Stack is Empty\n");
        return;
    }
    int i;
    for (i = s->top; i >= 0; i--)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

// print board
void printBoard(struct stack *from, struct stack *to, struct stack *aux)
{
    print_stack(from);
    print_stack(aux);
    print_stack(to);
    printf("\n");
}

void move(struct stack *a, struct stack *b)
{
    if (size(a) == 0)
    {
        push(a, pop(b));
        return;
    }
    else if (size(b) == 0)
    {
        push(b, pop(a));
        return;
    }

    if (peek(a) > peek(b))
    {
        push(a, pop(b));
    }
    else
    {
        push(b, pop(a));
    }
}

// tower of hanoi using stacks
void toh(struct stack *from, struct stack *to, struct stack *aux)
{
    printBoard(from, to, aux);

    int n = size(from);

    if (n % 2 == 0)
    {
        struct stack *temp = to;
        to = aux;
        aux = temp;
    }

    for (int i = 1; i <= pow(2, n) - 1; i++)
    {
        // if (size(from) == 0 && size(aux) == 0 && size(to) == n)
        // {
        //     break;
        // }

        if (i % 3 == 1)
        {
            move(to, from);
        }
        else if (i % 3 == 2)
        {
            move(aux, from);
        }
        else
        {
            move(to, aux);
        }
        printBoard(from, to, aux);
    }
}

int main()
{
    struct stack *from = create_stack('S');
    push(from, 5);
    push(from, 4);
    push(from, 3);
    push(from, 2);
    push(from, 1);

    toh(from, create_stack('D'), create_stack('A'));
}