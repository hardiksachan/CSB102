#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node * connections[10];
    int total_conn;
};

struct Node * create_node(char data)
{
    struct Node * node = malloc(sizeof(struct Node));
    node->data = data;
    node->total_conn = 0;
}

void create_directed_conn(struct Node * from, struct Node * to) {
    from->connections[from->total_conn] = to;
    from->total_conn++;
}


void print_adjacents(struct Node * node){
    printf("%c: ", node->data);
    for (int i = 0; i < node->total_conn; i++)
    {
        printf("%c ", node->connections[i]->data);
    }
    printf("\n"); 
}



int main() {
    
    struct Node * a = create_node('a');
    struct Node * b = create_node('b');
    struct Node * c = create_node('c');

    create_directed_conn(a, b);
    create_directed_conn(b, c);
    create_directed_conn(c, a);
    create_directed_conn(a, c);

    print_adjacents(a);
    print_adjacents(b);
    print_adjacents(c);

}
