#include <stdio.h>
#include "list.c"
typedef struct {
    int n,m;
    int A[100][100];
}Graph;
void init_graph(Graph *G, int n){
    G->m++;
    G->n=n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            G->A[i][j]=0;
        }
    }
}
void add_edge(Graph *G, int u, int v){
    G->A[u][v]++;
    G->m++;
}
int r[100];
void rank(Graph *G){
    int d[100];
    for(int u=1; u<=G->n; u++){
        d[u]=0;
        for(int x=1; x<=G->n; x++)
            if(G->A[x][u]!=0)
                d[u]++;
    }
    List S1, S2;
    make_null(&S1);
    for(int u=1; u<=G->n; u++)
        if(d[u]==0)
            push_back(&S1, u);
    int k=1;
    while(S1.size >0){
        make_null(&S2);
        for(int i=1; i<=S1.size; i++){
            int u = element_at(&S1, i);
            r[u]=k;
            for(int v=1; v<=G->n; v++)
                if(G->A[u][v]!=0){
                    d[v]--;
                    if(d[v]==0)
                        push_back(&S2, v);
                }
        }
        copy_list(&S1, &S2);
        k++;
    }
}

int main(){
    Graph G;
    freopen("dt.txt","r",stdin);
    int n,m,u,v;
    scanf("%d%d",&n,&m);
    init_graph(&G,n);

    for(int i=0; i<m; i++){
        scanf("%d%d",&u,&v);
        add_edge(&G,v,u);
    }
    rank(&G);
    int tongKeo = 0;
	for( u = 1; u<=G.n;u++){
		tongKeo += r[u];
		printf("%d\n", r[u]);
	}
	printf("%d", tongKeo);
}