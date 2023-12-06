#include <stdio.h>
typedef struct {
    int A[100][100];
    int n,m;
}Graph;
void init_graph(Graph *G, int n){
    G->n=n;
    G->m=0;
}
void add_edge(Graph *G, int u, int v){
    if(u==v) 
        G->A[u][v]++;
    else {
        G->A[u][v]++;
        G->A[v][u]++;
    }
    G->m++;
}
int main() {
    freopen("dt.txt","r",stdin);
    Graph G;
    int n,m,u,v;
    scanf("%d%d",&n,&m);
    init_graph(&G, n);

    for(int i=0; i<m; i++){
        scanf("%d%d",&u,&v);
        add_edge(&G,u,v);
    }
    printf("Ma tran ke:\n");
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
            printf("%d ",G.A[i][j]);
        printf("\n");
    }
}