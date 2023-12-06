#define MAX_N 100
#include <stdio.h>
typedef struct {
    int n, m;
    int A[MAX_N][MAX_N];
}Graph;

void init_Graph(Graph *G, int n) {
    G->m=0;
    G->n=n;
    for(int u=1; u<=G->n; u++) {
        for(int v=1; v<=G->n; v++){
            G->A[u][v] = 0;
        }
    }
}

void add_edge(Graph *G, int u, int v) {
    G->A[u][v]++;
    G->m++;
}
int adjacent(Graph *G, int u, int v) {
    return G->A[u][v] >0;
}

typedef int ElementType;
typedef struct {
    ElementType data[MAX_N];
    int front, rear;
}Queue;

void make_null_Queue(Queue *pQ) {
	pQ->front = 0;
	pQ->rear = -1;
}
int emptyQ(Queue *pQ) {
	return pQ->front > pQ->rear;
}
void enQueue(Queue *pQ, ElementType u) {
	pQ->rear++;
	pQ->data[pQ->rear] = u;
}
ElementType front(Queue *pQ) {
	return pQ->data[pQ->front];
}
void deQueue(Queue *pQ) {
	pQ->front++;
}

int mark[MAX_N];
void bfs(Graph *G, int s) {
    Queue Q;
    make_null_Queue(&Q);

    enQueue(&Q, s);

    while(!emptyQ(&Q)) {
        int u= front(&Q);
        deQueue(&Q);

        if(mark[u] != 0)
            continue;

        printf("%d\n", u);
        mark[u] = 1;

        for(int v=1; v<=G->n; v++) {
            if(adjacent(G, u, v)) {
                enQueue(&Q, v);
            }
        }
    }
}

int main() {
    freopen("dt.txt", "r", stdin); //Khi nộp bài nhớ bỏ dòng này.
    Graph G;
    int n, m, u, v, e;
    scanf("%d%d", &n, &m);
    init_Graph(&G, n);
        
    for (e = 0; e < m; e++) {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    
    for(int i=1; i<=G.n; i++) {
        mark[i] = 0;
    }

    //them dong nay de duyet tat ca
    for(int i=1; i<=G.n; i++) {
        if(mark[i] == 0) {
            bfs(&G, i);
        }
    }
    return 0;
}