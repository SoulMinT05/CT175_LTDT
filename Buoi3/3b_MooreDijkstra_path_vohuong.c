#include <stdio.h>
typedef struct {
    int u,v,weight;
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
int adjecent(Graph *G, int u, int v){
    int i;
    for(i=0; i<G->m; i++){
        if((G->edges[i].u == u && G->edges[i].v == v) || (G->edges[i].u == v && G->edges[i].v == u))
            return 1;
    }
    return 0;
}
#define oo 99999
int pi[99999], p[99999], mark[99999];

int getWeight(Graph *G, int u, int v){
    int i;
    for(i=0; i<G->m; i++){
        if((G->edges[i].u == u && G->edges[i].v == v) || (G->edges[i].u == v && G->edges[i].v == u)) 
            return G->edges[i].weight;
    }
    return 0;
}
void MooreDijktra(Graph *G, int s){
    int u,v,it;
    for(u=1; u<=G->n;u++){
        pi[u]=oo;
        mark[u]=0;
    }

    pi[s]=0;
    p[s]=-1;

    for(it=1; it<G->n;it++){
        int j, min_pi=oo;
        for(j=1; j<=G->n;j++)
            if(mark[j] == 0 && pi[j] < min_pi) {
                min_pi=pi[j];
                u=j;
            }
        
        mark[u]=1;
        for(v=1; v<=G->n;v++){
            if(adjecent(G,u,v) && mark[v]==0){
                if(pi[u] + getWeight(G,u,v) < pi[v]){
                    pi[v] = pi[u] + getWeight(G,u,v);
                    p[v]=u;
                }
            }
        }
    }
}
void print_path(Graph *G, int parent, int start, int end){
    if(parent == start) {
        printf("%d -> ", start);
        return;
    }
    print_path(G, parent, p[start], end);
    printf("%d", start);
    if(start != end){
        printf(" -> ");
    }
}
int main(){
    freopen("dt.txt","r",stdin);
    Graph G;
    int n,m;
    scanf("%d%d",&n,&m);
    init_graph(&G,n);

    for(int i=0; i<m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add_edge(&G,u,v,w);
    }
    int start,end;
    scanf("%d%d",&start,&end);
    MooreDijktra(&G, start);
    print_path(&G, start, end, end);
}