#include <stdio.h>
typedef struct {
    int data[200];
    int size;
}List;
void make_null(List *L) {
    L->size=0;
}
void push_back(List *L, int x){
    L->data[L->size] = x;
    L->size++;
}
int element_at(List L, int i){
    return L.data[i-1];
}
void print_list(List L){
    for(int i=1; i<=L.size; i++) 
        printf("%d ", element_at(L, i));
    printf("0\n");
}
typedef struct {
    int n,m;
    List adj[200];
}Graph;
void init_graph(Graph *G, int n){
    int i;
    G->m=0;
    G->n=n;
    for(i=1; i<=n; i++)
        make_null(&G->adj[i]);
}
void add_edge(Graph *G, int u, int v){
    push_back(&G->adj[u], v);
    G->m++;
}
int main() {
    Graph G;
    int n;
    scanf("%d",&n);
    init_graph(&G, n);
    freopen("dt.txt","r", stdin);
    int mtk[n][n];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int temp;
            scanf("%d",&temp);
            mtk[i][j] = temp;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(mtk[i][j] > 0) {
                for(int k=1; k<=mtk[i][j]; k++){
                    add_edge(&G, i, j);
                }
            }
        }
    }
    
    for(int i=1; i<=G.n; i++)
        print_list(G.adj[i]);
}