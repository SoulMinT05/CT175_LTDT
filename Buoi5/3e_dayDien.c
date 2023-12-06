#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int u,v,weight,cost;
}Edge;
typedef struct {
    int n,m;
    Edge edges[100];
}Graph;
void init_graph(Graph *G, int n){
    G->m=0;
    G->n=n;
}
void add_edge(Graph *G, int u, int v, int w, int c){
    G->edges[G->m].u = u;
    G->edges[G->m].v = v;
    G->edges[G->m].weight = w;
    G->edges[G->m].cost = c;
    G->m++;
}
int cmpfunc(const void *a, const void *b){
    return ((*(Edge*)a).weight * (*(Edge*)a).cost) - ((*(Edge*)b).weight * (*(Edge*)b).cost);
}
int parent[100];
int findRoot(int u){
    while(parent[u] != u){
        u=parent[u];
    }
    return u;
}
int Kruskal(Graph *G, Graph *T){
    qsort(G->edges, G->m, sizeof(Edge), cmpfunc);
    init_graph(T, G->n);
    for(int u=1; u<=G->n;u++)
        parent[u]=u;
    int sum_w=0;

    for(int e=0; e<G->m;e++){
        int u = G->edges[e].u;
        int v = G->edges[e].v;
        int w = G->edges[e].weight;
		int c = G->edges[e].cost;
        int root_u = findRoot(u);
        int root_v = findRoot(v);
        if(root_u != root_v){
            add_edge(T, u, v, w, c);
            parent[root_v] = root_u;
            sum_w += w*c;
        }
    }
    return sum_w;
}
int main(){
    Graph G,T;
    freopen("dt.txt","r",stdin);
    int n,m,u,v,w,e,c;
    scanf("%d%d",&n,&m);
    init_graph(&G,n);
    for(e=0; e<m; e++){
        scanf("%d%d%d%d",&u,&v,&w,&c);
        if(u>v){
            int temp = u;
            u = v;
            v=temp;
        }
        add_edge(&G,u,v,w,c);
    }
    int sum_w = Kruskal(&G, &T);
    printf("%d\n", sum_w);
    
}