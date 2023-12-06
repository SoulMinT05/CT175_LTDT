#define MAX_N 100
#include <stdio.h>
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
typedef struct {
    int n, m;
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
    G->m++;
}
int adjacent(Graph *G, int u, int v) {
    return G->A[u][v] >0;
}

#define WHITE 0
#define GRAY 1
#define BLACK 2

int color[MAX_N];
int has_circle, start, end;
int parent[MAX_N];

void dfs(Graph *G, int u, int p) {
    color[u] = GRAY;
    parent[u] = p;

    for(int v=1; v<=G->n; v++) {
        if(adjacent(G, u, v)) {
            if(color[v] == WHITE) {
                dfs(G, v, u);
            }else if(color[v] == GRAY) {
                has_circle = 1;
                start = u;
                end = v; 
            }
        }
    }    
    color[u] = BLACK;
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
    
    // for(int i=1; i<=G.n; i++) {
    //     color[i] = WHITE;
    // }

    // has_circle = 0;

    for(int i =1; i<=G.n; i++) {
        if(color[i] == WHITE) 
            dfs(&G, i, -1);
    }


    if(has_circle) {
        int arr[n], index = 0;

        arr[index++] = end;
        arr[index++] = start;

        int temp = parent[start];
        while(temp != parent[end]) {
            arr[index++] = temp;
            temp = parent[temp];
        }
        for(int i=index-1; i>=0; i--) {
            printf("%d ", arr[i]);
        }
    }else {
        printf("-1");
    }
    return 0;
}