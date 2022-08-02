// 1) 1500 + 20*25 + 15 = 2015
// 2) 1500 + 15*25 + 20 = 1895
#include <stdio.h>

int main()
{
    int addr = 1500;
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            if (i == 15 && j == 35)
            {
                printf("*");
            }
            printf("%d\t", addr);
            addr += 4;
        }
        printf("\n");
    }
}
