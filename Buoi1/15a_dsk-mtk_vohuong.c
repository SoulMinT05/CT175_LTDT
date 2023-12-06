#include <stdio.h>
typedef struct {
    int n,m;
    int A[100][100];
}Graph;
void init_graph(Graph *G, int n){
    G->n=n;
    G->m=0;
    for(int i=1; i<=n;i++){
        for(int j=1; j<=n; j++){
            G->A[i][j]=0;
        }
    }
}
void add_edge(Graph *G, int u, int v){
    if(u==v)
        G->A[u][v]++;
    else {
        G->A[u][v]++;
    }
    G->m++;
}
int main(){
    Graph G;
    int n;
    freopen("dt.txt","r",stdin);
    scanf("%d",&n);
    init_graph(&G, n);
    for(int i=1; i<=n;i++){
        int temp;
        scanf("%d",&temp);
        while(temp != 0){
            add_edge(&G, i, temp);
            scanf("%d", &temp);
        }
    }
    printf("Ma tran ke:\n");
    for(int u=1; u<=G.n; u++){
        for(int v=1; v<=G.n; v++)
            printf("%d ", G.A[u][v]);
        printf("\n");
    }
}