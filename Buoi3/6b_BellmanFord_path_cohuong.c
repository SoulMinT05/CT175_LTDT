#include <stdio.h>
typedef struct {
    int u, v, weight;
}Edge;
typedef struct {
    int n,m;
    Edge edges[100];
}Graph;
void init_graph(Graph *G, int n){
    G->n=n;
    G->m=0;
}
void add_edge(Graph *G, int u, int v, int w){
    G->edges[G->m].u = u;
    G->edges[G->m].v = v;
    G->edges[G->m].weight = w;
    G->m++;
}

#define oo 999999
int pi[99999], p[99999];
void BellmanFord(Graph *G, int s){
    int u,v,w,it,k;
    for(u=1; u<=G->n;u++)
        pi[u] = oo;
    pi[s]=0;
    p[s]=-1;

    for(it=1; it<G->n;it++){
        for(k=0; k<G->m; k++){
            u = G->edges[k].u;
            v = G->edges[k].v;
            w = G->edges[k].weight;
            if(pi[u] == oo)
                continue;
            
            if(pi[u] + w < pi[v]) {
                pi[v] = pi[u] + w;
                p[v] = u;
            }
        }
    }
}
void print_path(Graph *G, int parent, int start, int end){
    if(parent == start){
        printf("%d -> ", start);
        return;
    }
    print_path(G, parent, p[start], end);
    printf("%d",start);
    if(start!=end){
        printf(" -> ");
    }
}
int main(){
    freopen("dt.txt","r",stdin);
    Graph G;
    int n,m;
    scanf("%d%d",&n,&m);
    init_graph(&G,n);

    for(int i=0; i<m; i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add_edge(&G,u,v,w);
    }
    int start, end;
    scanf("%d%d",&start, &end);
    BellmanFord(&G, start);
    print_path(&G, start, end, end);

}


