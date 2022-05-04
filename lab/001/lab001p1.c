#include <stdio.h>

// ANS: 0

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    // contructing v
    int sum =0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // printf("%d\t", i - j);
            sum += i - j;
        }
        // printf("\n");
    }

    printf("Sum: %d\n", sum);
    
}