#include <stdio.h>

void tower_of_hanoi(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        printf("Disc %d:\t%c -> %c\n", n, from, to);
    }
    else
    {
        tower_of_hanoi(n - 1, from, aux, to);
        printf("Disc %d:\t%c -> %c\n", n, from, to);
        tower_of_hanoi(n - 1, aux, to, from);
    }
}

int main() {
    tower_of_hanoi(2, 'S', 'D', 'A');
}