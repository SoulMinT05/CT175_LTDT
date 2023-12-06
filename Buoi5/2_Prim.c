#include <stdio.h>
typedef struct {
    int n, m;
    int A[100][100];
}Graph;
void init_graph(Graph *G, int n){
    G->n=n;
    G->m=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            G->A[i][j]=0;
        }
    }
}
void add_edge(Graph *G, int u, int v, int w){
    G->A[u][v] = w;
    G->m++;
}
int pi[100], p[100], mark[100];
#define oo 999999
int Prim(Graph *G, Graph *T, int s){
    int i,u,v,x;
    for(u=1; u<=G->n; u++){
        pi[u]=oo;
        p[u]=-1;
        mark[u]=0;
    }
    pi[s]=0;

    for(i=1; i<G->n;i++){
        int min_dst= oo;
        for(x=1; x<=G->n; x++)
            if(mark[x]==0 && pi[x] < min_dst){
                min_dst=pi[x];
                u=x;
            }
        mark[u]=1;
        for(v=1; v<=G->n;v++)
            if(G->A[u][v] !=0)
                if(mark[v] == 0 && pi[v] > G->A[u][v]){
                    pi[v] = G->A[u][v];
                    p[v]=u;
                }
    }
    init_graph(T, G->n);
    int sum_w=0;
    for(u=1; u<=G->n;u++){
        if(p[u]!=-1){
            int w=G->A[p[u]][u];
            add_edge(T,p[u],u,w);
            sum_w+=w;
        }
    }
    return sum_w;
}
int main(){
    Graph G, T;
    int n,m,u,v,w,e;
    freopen("dt.txt","r",stdin);
    scanf("%d%d",&n,&m);
    init_graph(&G,n);
    for(e=0; e<m; e++){
        scanf("%d%d%d",&u,&v,&w);
        add_edge(&G,u,v,w);
    }
    int sum_w = Prim(&G,&T,1);
    printf("%d\n",sum_w);
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(T.A[i][j] !=0)
                printf("%d %d %d\n", i, j, T.A[i][j]);
        }
    }
}