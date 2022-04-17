#include<stdio.h>
#include<stdlib.h>
typedef struct graph{
    int V,E;
    int **adj;
}Graph;
typedef struct list{
    int V;
    struct list *next;
}List;

List *list(int nodes, int n)
{
    if(n == nodes)
    {
        return NULL;
    }
    else
    {
        int x;
        printf("Enter the vertex: ");
        scanf("%d", &x);
        n++;
        List *L = malloc(sizeof(List));
        L->V = x;
        L->next = list(nodes, n);
        return L;
    }
}

Graph * AdjListGraph()
{
    int u, nodes;
    int n = 0;
    Graph *G = (Graph *)malloc(sizeof(Graph));
    printf("Enter the number of vertices and Edges of the Graph: ");
    scanf("%d %d", &G->V, &G->E);
    G->adj = malloc(sizeof(List *) * G->V);

    for(u = 0; u < G->V; u++)
    {
        printf("Enter the number of nodes attached to %d: ", u);
        scanf("%d", &nodes);
        G->adj[u] = list(nodes, n);
    }

}

void Display(Graph *G)
{
    int i, j;
    printf("There are edges between: \n");
    for(i = 0; i<G->V; i++)
        for(j = 0; j<G->V; j++)
        {
            if(G->adj[i][j])
                printf(" %d %d\n", i, j);
            else
                break;
        }
}

int main()
{
    Graph *G = AdjListGraph();
    Display(G);

    return 0;
}