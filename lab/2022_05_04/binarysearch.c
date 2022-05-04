#include <stdio.h>

// binary search on ascending sorted array
int search(int size, int arr[], int target)
{
    int start = 0;
    int end = size-1;

    while (start <= end)
    {
        int mid = start + (end-start)/2;

        if (arr[mid] < target) {
            start = mid + 1;
        } else if (arr[mid] > target) {
            end = mid -1;
        } else {
            return mid;
        }
    }
    

    return -1;
    
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    printf("%d\n", search(5, arr, 95));
}