#define MAX_N 100
#include <stdio.h>
#include "list.c"
#include "queue.c"
typedef struct {
    int n,m;
    int A[MAX_N][MAX_N];
}Graph;
void init_graph(Graph *G, int n){
    G->n=n;
    G->m=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            G->A[i][j] = 0;
        }
    }
}
void add_edge(Graph *G, int u, int v){
    G->A[u][v]++;
    G->m++;
}
void topo_sort(Graph *G, List *L){
    int d[100];
    for(int u=1; u<=G->n; u++){
        d[u]=0;
        for(int x=1; x<=G->n; x++)
            if(G->A[x][u] != 0)
                d[u]++;
    }
    Queue Q;
    make_null_queue(&Q);
    for(int u=1; u<=G->n; u++)
        if(d[u] == 0)
            enQueue(&Q, u);
    make_null(L);
    while(!empty(&Q)){
        int u = front(&Q);
        deQueue(&Q);
        push_back(L, u);
        for(int v=1; v<=G->n; v++)
            if(G->A[u][v] !=0){
                d[v]--;
                if(d[v] ==0)
                    enQueue(&Q, v);
            }
    }
}

int d[100];
#define oo 999999
int min(int a, int b){
    return a<b?a:b;
}
int max(int a, int b){
    return a>b?a:b;
}
int main(){
    Graph G;
    int n,u,x,v,j;
    freopen("dt.txt","r",stdin);
    scanf("%d",&n);
    init_graph(&G, n+2);
    int alpha = n+1, beta=n+2;
    d[alpha]=0;
    //1
    for(u=1; u<=n; u++){
        scanf("%d",&d[u]);
        do{
            scanf("%d",&x);
            if(x>0)
                add_edge(&G,x,u);
        }while(x>0);
    }
    //2
    for(u=1; u<=n; u++){
        int deg_neg=0;
        for(x=1; x<=n; x++)
            if(G.A[x][u]>0)
                deg_neg++;
        if(deg_neg==0)
            add_edge(&G,alpha,u);
    }
    //3
    for(u=1; u<=n; u++){
        int deg_pos=0;
        for(v=1; v<=n; v++)
            if(G.A[u][v]>0)
                deg_pos++;
        if(deg_pos==0)
            add_edge(&G,u,beta);
    }
    //4
    List L;
    topo_sort(&G, &L);
    //5
    int t[100];
    t[alpha]=0;
    for(j=2; j<=L.size; j++){
        int u = element_at(&L, j);
        t[u] = -oo;
        for(x=1; x<=G.n; x++)
            if(G.A[x][u] >0)
                t[u] = max(t[u], t[x] + d[x]);
    }
    //6
    int T[100];
    T[beta] = t[beta];
    for(j=L.size-1; j>=1; j--){
        int u = element_at(&L, j);
        T[u] = +oo;
        for(v=1; v<=G.n; v++)
            if(G.A[u][v]>0)
                T[u] = min(T[u], T[v] - d[u]);
    }
    //7
    for(u=1; u<=n; u++){
        printf("%d %d\n", t[u], T[u]);
    }
}