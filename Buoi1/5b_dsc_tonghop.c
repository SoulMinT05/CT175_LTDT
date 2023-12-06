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
int degree(Graph *G, int u){
    int e, deg_u=0;
    for(e=0; e<G->m; e++){
        if(G->edges[e].u == u) {
            deg_u++;
        }
        if(G->edges[e].v == u){
            deg_u++;   
        }
    }
    return deg_u;
}
int main(){
    freopen("dt.txt","r",stdin);
    Graph G;
    int n,m,u,v,e, i;
    scanf("%d%d",&n,&m);
    init_graph(&G,n);

    for(e=0; e<m; e++){
        scanf("%d%d",&u,&v);
        add_edge(&G, u, v);
    }
    for(i=1; i<=n; i++)
        printf("deg(%d) = %d\n", i, degree(&G, i));
}