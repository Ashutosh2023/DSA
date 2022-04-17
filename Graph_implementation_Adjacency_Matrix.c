#include<stdio.h>
#include<stdlib.h>
struct Graph {
    int v;
    int e;
    int **adj;
};

struct Graph* adjMatrixGraph()
{
    int i,j,u;
    struct Graph *G = (struct Graph*)malloc(sizeof(struct Graph));
    if(G == NULL){
        printf("memory Error");
        return 0;
    }
    printf("Enter the number of vertices and Edges: ")  ;
    scanf("%d %d",&G->v, &G->e);
    G->adj = malloc(G->v*sizeof(int));
    for(i = 0; i < G->v; i++)
    {
        G->adj[i] = malloc(G->v*sizeof(int));
    }
    for(i = 0; i < G->v; i++)
        for(j = 1; j <= G->v; j++)
            G->adj[i][j] = 0;            //Assingning all the memory block with 0.
    for (u = 0; u < G->e; u++)
    {
        printf("\nEnter pair of nodes connected an Edge that \n");
        printf("\tStarts at: ");
        scanf("%d", &i);
        printf("\tEnds at: ");
        scanf("%d", &j);
        G->adj[i][j] = 1;
        G->adj[j][i] = 1; // undirected graph, unordered pair;
    }
    return G;
}
void Display(struct Graph *G)
{
    int i, j;
    printf("There are edges between: \n");
    for(i = 0; i<G->v; i++)
        for(j = 0; j<G->v; j++)
        {
            if(G->adj[i][j])
                printf(" %d %d\n", i, j);
        }
}
int main()
{
    struct Graph *G = adjMatrixGraph();
    Display(G);

    return 0; 
}
