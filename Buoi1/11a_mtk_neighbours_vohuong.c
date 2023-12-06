#include <stdio.h>
typedef struct {
    int n,m;
    int A[100][100];
}Graph;
void init_graph(Graph *G, int n){
    G->n=n;
    G->m=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            G->A[i][j]=0;
}
void add_edge(Graph *G, int u, int v){
    if(u==v) 
        G->A[u][u]++;
    else {
        G->A[u][v]++;
        G->A[v][u]++;
    }
    G->m++;
}
void neighbours(Graph *G, int u){
    printf("neighbours(%d) = ", u);

    int i,j;
    for(i=1; i<=G->n; i++){
        for(j=1; j<=G->A[u][i]; j++){
            printf("%d ", i);
        }
    }
    printf("\n"); 
}
int main(){
    Graph G;
    freopen("dt.txt","r",stdin);
    int n,m,i, u, v,e;
    scanf("%d%d",&n,&m);
    init_graph(&G, n);

    for(e=0; e<m; e++){ //e nhỏ hơn m mới ra
        scanf("%d%d",&u,&v);
        add_edge(&G, u, v);
    }
    for(i=1; i<=G.n; i++)
        neighbours(&G,i);
}