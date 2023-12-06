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
typedef struct {
    int data[200];
    int size;
}List;
void make_null_List(List *L) {
    L->size=0;
}
void push_back(List *L, int x) {
    L->data[L->size] = x;
    L->size++;
}
int member(List L, int x){
    for(int i=0; i<L.size; i++) {
        if(L.data[i] == x)
            return 1;
    }
    return 0;
}
void sort(List *L) {
    int i,j;
    for(i=0; i<L->size-1;i++) {
        for(j=i; j<L->size; j++) {
            if(L->data[i] > L->data[j]) {
                int temp = L->data[i];
                L->data[i] = L->data[j];
                L->data[j] = temp;
            }
        }
    }
}
void print_list(List L) {
    for(int i=0; i<L.size;i++)
        printf("%d ", L.data[i]);
    printf("\n");
}
List neighbours(Graph G, int x){
    List L;
    make_null_List(&L);

    int i;
    for(i=0; i<G.m;i++) {
        if(G.edges[i].u == x && !member(L, G.edges[i].v)){
            push_back(&L, G.edges[i].v);
        }
    }
    sort(&L);
    return L;
}
int main(){
    Graph G;
    int n,m,u,v;
    freopen("dt.txt", "r", stdin);
    scanf("%d%d",&n,&m);
    init_graph(&G, n);

    for(int i=0; i<m; i++){
        scanf("%d%d",&u,&v);
        add_edge(&G, u, v);
    }
    for(int i=1; i<=n;i++){
        printf("neighbours(%d) = ", i);
        List L = neighbours(G, i);
        print_list(L);
    }
}