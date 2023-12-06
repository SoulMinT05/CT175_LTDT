#define MAX_N 100
#include <stdio.h>
// #include "List.c"

typedef int ElementType;

typedef struct {
	ElementType data[100];
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

typedef struct {
    int n, m;
    int A[MAX_N][MAX_N];
}Graph;

void init_graph(Graph *G, int n) {
    G->m = 0;
    G->n =n;
    for(int u=1; u<=G->n; u++) {
        for(int v=1; v<=G->n; v++) {
            G->A[u][v] = 0;
        }
    }
}

void add_edge(Graph *G, int u, int v) {
    G->A[u][v] = 1;
    // G->A[v][u] = 1;
    G->m++;

}
int adjacent(Graph *G, int u, int v) {
    return G->A[u][v] > 0;
}
int min(int a, int b) {
    return a < b ? a : b;
}
int max(int a, int b) {
    return a > b ? a : b;
}


int num[MAX_N], min_num[MAX_N];
int k;
Stack S;
int on_stack[MAX_N];
int dem = 0;
int max_cnt;
void SCC(Graph *G, int u) {
    num[u] = min_num[u] = k;
    k++;
    push(&S, u);
    on_stack[u] = 1;

    for(int v = 1; v<=G->n; v++) {
        if(adjacent(G, u, v)) {
            if(num[v] < 0) {
                SCC(G, v);
                min_num[u] = min(min_num[u], min_num[v]);
            }else if(on_stack[v]) 
                min_num[u] = min(min_num[u], num[v]);
        }
    }
    if(num[u] == min_num[u]) {
        int dem = 0;
        int w;
        do {
            w = top(&S);
            pop(&S);
            on_stack[w] = 0;
            dem++;
        }while(w != u);
        max_cnt = max(max_cnt, dem);
    }
}

int main() {
    freopen("dt.txt", "r", stdin); //Khi nộp bài nhớ bỏ dòng này.
    Graph G;
    int n, m, u, v, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
        
    for (e = 0; e < m; e++) {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    for(int i =1; i<=G.n; i++) {
        num[i] = -1;
    }

    k = 1;
    max_cnt = 0;
    make_null_stack(&S);

    for(int i=1; i<=G.n; i++) {
        if(num[i] == -1)
            SCC(&G, i);
    }
    printf("%d", max_cnt);
    return 0;

}