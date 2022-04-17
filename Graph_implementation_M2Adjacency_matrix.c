#include<stdio.h>
#include<stdlib.h>

typedef struct Graph {
    int V;
    int E;
    int **adj;
}Graph;

Graph * adjMatrixGraph()
{
    int i, j, u;
    Graph *graph = malloc(sizeof(Graph));
    printf("Enter the number of Vertices and Edges in the graph: ");
    scanf("%d %d", &graph->V, &graph->E);
    
    graph->adj=malloc(sizeof(int)*(graph->V * graph->V));
    if(!graph->adj){
        printf("Out of memory\n");
        return 0;
    }

    for(u = 0; u < graph->E; u++)
    {
        printf("Enter the pair of Edges that connnect the nodes that: \n");
        printf("\tStarts at: ");
        scanf("%d", &i);
        printf("\tEnds at: ");
        scanf("%d", &j);
        graph->adj[i][j] = 1;
        graph->adj[j][i] = 1;
    }
    return graph;
}
void Display(struct Graph *G)
{
    int i, j;
    printf("There are edges between: \n");
    for(i = 0; i<G->V; i++)
        for(j = 0; j<G->V; j++)
        {
            if(G->adj[i][j] != 0)
                printf(" %d %d\n", i, j);
        }
}
int main()
{
    struct Graph *G = adjMatrixGraph();
    Display(G);

    return 0;
}