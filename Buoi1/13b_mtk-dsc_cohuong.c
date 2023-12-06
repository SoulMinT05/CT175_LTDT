#include <stdio.h>
typedef struct {
    int u,v;
}Edge;
typedef struct {
    int n,m;
    Edge edges[100];
}Graph;
void init_graph(Graph *G, int n){
    G->n=n;
    G->m=0;
}
void add_edge(Graph *G, int u, int v){
    G->edges[G->m].u = u;
    G->edges[G->m].v = v;
    G->m++;
}
int main() {
    Graph G;
    freopen("dt.txt", "r", stdin);
    int n;
    scanf("%d",&n);
    init_graph(&G, n);

    int mtk[n][n];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int temp;
            scanf("%d", &temp);
            mtk[i][j] = temp;
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++){ // xu ly do thi co huong
            for(int k=1; k<=mtk[i][j]; k++){
                add_edge(&G, i, j);
            }
        }
    }
    for(int i=0; i<G.m; i++) 
        printf("%d %d\n", G.edges[i].u, G.edges[i].v);
}