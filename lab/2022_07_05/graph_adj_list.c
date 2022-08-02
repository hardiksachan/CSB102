#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 50
#define MAX_NEIGHBOURS 10

// [neighbour_count, ...neighbours]
int graph[MAX_NODES][MAX_NEIGHBOURS + 1];
int nodes = 0;

void initialise_graph(int n)
{
    nodes = n;
    for (int i = 0; i < n; i++)
    {
        graph[i][0] = 0;
    }
}

void create_one_way_conn(int a, int b)
{
    graph[a][0]++;
    graph[a][graph[a][0]] = b;
}

void create_two_way_conn(int a, int b)
{
    create_one_way_conn(a, b);
    create_one_way_conn(b, a);
}

void print_graph()
{
    for (int i = 0; i < nodes; i++)
    {
        printf("%d: ", i);
        for (int j = 1; j <= graph[i][0]; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void bfs()
{
    int visited[nodes];
    for (int i = 0; i < nodes; i++)
    {
        visited[i] = 0;
    }
}

int main()
{
    initialise_graph(3);

    create_one_way_conn(0, 1);
    create_one_way_conn(1, 2);
    create_two_way_conn(0, 2);

    print_graph();
}