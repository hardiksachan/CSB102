#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 100

char arr[CAPACITY];
int size = 0;

// Function to push an element to the stack
void push(char x)
{
    if (size == CAPACITY)
    {
        printf("Stack Overflow\n");
        return;
    }
    arr[size++] = x;
}

// Function to pop an element from the stack
char pop()
{
    if (size == 0)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return arr[--size];
}

// Function to check if the stack is empty
int isEmpty()
{
    return size == 0;
}

// Function to check if the stack is full
int isFull()
{
    return size == CAPACITY;
}

// Function to peek an element in stack
char peek()
{
    if (size == 0)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return arr[size - 1];
}

// precedence
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else
        return 0;
}

// infix to postfix
void print_postfix_of(char *infix, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (infix[i] == '(')
            push(infix[i]);
        else if (infix[i] == ')')
        {
            while (!isEmpty() && peek() != '(')
                printf("%c", pop());
            if (!isEmpty())
                pop();
        }
        else if (precedence(infix[i]) == 0)
            printf("%c", infix[i]);
        else
        {
            while (!isEmpty() && precedence(infix[i]) <= precedence(peek()))
                printf("%c", pop());
            push(infix[i]);
        }
    }
    while (!isEmpty())
        printf("%c", pop());
    
    printf("\n");
}

int main()
{
    char infix[] = "(A+B)*(C+D)";
    print_postfix_of(infix, 11);
}