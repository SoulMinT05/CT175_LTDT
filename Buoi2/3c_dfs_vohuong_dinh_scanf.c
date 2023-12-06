#define MAX_N 100
#include <stdio.h>

typedef struct {
    int n,m;
    int A[MAX_N][MAX_N];
}Graph;

void init_graph(Graph *G, int n) {
    G->n = n;
    G->m = 0;
    for(int u=1; u<=G->n; u++) {
        for(int v=1; v<=G->n; v++) {
            G->A[u][v] = 0;
        }
    }
}

void add_edge(Graph *G, int u, int v) {
    G->A[u][v] = 1;
    G->A[v][u] = 1;
    G->m++;
}

int adjacent(Graph *G, int u, int v) {
    return G->A[u][v] >0;
}

typedef int ElementType;
typedef struct {
	ElementType data[MAX_N];
	int top_idx;
} Stack;

void make_null_stack(Stack *pS) {
	pS->top_idx = -1;
}

void push(Stack *pS, ElementType u) {
	pS->top_idx++;
	pS->data[pS->top_idx] = u;
}

ElementType top(Stack *pS) {
	return pS->data[pS->top_idx];
}

void pop(Stack *pS) {
	pS->top_idx--;
}

int empty(Stack *pS) {
	return pS->top_idx == -1;
}

int mark[MAX_N];
void dfs(Graph *G, int a) {
    Stack S;
    make_null_stack(&S);

    push(&S, a);

    while(!empty(&S)) {
        int u = top(&S);
        pop(&S);
        
        if(mark[u] != 0) 
            continue;

        printf("%d\n", u);
        mark[u] = 1;


        //phai viet for nguoc lai moi duoc
        for(int v=G->n;v>=1;--v){
			if(adjacent(G, u, v)){
				push(&S, v);
			}
		}
    }
}

int main() {
    freopen("dt.txt", "r", stdin); //Khi nộp bài nhớ bỏ dòng này.
    Graph G;
    int n, m, u, v, w, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
        
    for (e = 0; e < m; e++) {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    for(int i=1; i<=G.n; i++) {
        mark[i] = 0;
    }

    int s;
    scanf("%d",&s);
    dfs(&G, s);
    return 0;
}