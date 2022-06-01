#include <stdio.h>
#define BASE_LEN 5
#define EMPTY -1

int arr[BASE_LEN];
int count = 0;

int hash(int key)
{
    return key % BASE_LEN;
}

int size()
{
    return count;
}

void add(int key)
{
    if (count >= BASE_LEN)
    {
        printf("overflow\n");
        return;
    }

    int i = 0;
    while (1)
    {
        int idx = (hash(key) + (i*i)) % BASE_LEN;
        printf("inserting %d at %d. count %d\n", key, idx, count);
        if (arr[idx] == EMPTY)
        {
            arr[idx] = key;
            count++;
            printf("success\n");
            return;
        }
        i++;
    }
}

void find(int key)
{
    int i = 0;
    while (1)
    {
        if (i >= BASE_LEN)
        {
            printf("not found\n");
            return;
        }

        int idx = (hash(key) + (i*i)) % BASE_LEN;
        if (arr[idx] == key)
        {
            printf("found\n");
            return;
        }
        i++;
    }
}

int show()
{
    printf("\n\n");
    for (int i = 0; i < BASE_LEN; i++)
    {
        printf("%d\n", arr[i]);
    }
    printf("\n\n");
}

int main()
{
    for (int i = 0; i < BASE_LEN; i++)
    {
        arr[i] = EMPTY;
    }

    add(21);
    add(18);
    add(43);
    add(22);
    show();
    find(43);
    find(52);
    add(38);
    add(40);
    find(38);
    find(50);
    show();
}
