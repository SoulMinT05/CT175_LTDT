#include <stdio.h>
typedef struct {
    int n,m;
    int A[100][100];
}Graph;
void init_graph(Graph *G, int n){
    G->m=0;
    G->n=n;
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
typedef struct {
    int data[100];
    int size;
}List;
void make_null(List *L){
    L->size=0;
}
void push_back(List *L, int x){
    L->data[L->size] = x;
    L->size++;
}
int element_at(List *L, int i){
    return L->data[i-1];
}
int count_list(List *L){
    return L->size;
}
typedef struct {
    int data[100];
    int front, rear;
}Queue;
void make_null_queue(Queue *Q){
    Q->front=0;
    Q->rear=-1;
}
void enQueue(Queue *Q, int u){
    Q->rear++;
    Q->data[Q->rear]=u;
}
int front(Queue *Q){
    return Q->data[Q->front];
}
void deQueue(Queue *Q){
    Q->front++;
}
int empty(Queue *Q){
    return Q->front > Q->rear;
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
    make_null(&L);
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
int main(){
    Graph G;
    freopen("dt.txt","r",stdin);
    int n,m,u,v;
    scanf("%d%d",&n,&m);
    init_graph(&G, n);

    for(int i=0; i<m; i++){
        scanf("%d%d",&u,&v);
        add_edge(&G, u, v);
    }
    List L;
    make_null(&L);
    topo_sort(&G, &L);
    for(int i=0; i<n; i++){
        printf("%d\n",L.data[i]);
    }
}