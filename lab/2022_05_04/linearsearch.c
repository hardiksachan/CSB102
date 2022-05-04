#include <stdio.h>

// linear search
int search(int size, int arr[], int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target) {
            return i;
        }
    }

    return -1;
    
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    printf("%d\n", search(5, arr, 5));
}