#define MAX_N 100
#include <stdio.h>

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
    G->A[u][v]++;
    G->A[v][u]++;
    G->m++;
}
int adjacent(Graph *G, int u, int v) {
    return G->A[u][v] >0;
}

int mark[MAX_N];

void dfs(Graph *G, int u) {
	if(mark[u]){
		return;
	}
    // printf("%d\n", u);

    mark[u] = 1;

    for(int v=1; v<=G->n; v++) {
        if(adjacent(G, u, v)) {
            dfs(G, v);
        }
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

    for(int i=1; i<= G.n; i++) {
        mark[i] = 0;
    }

    int dem=0;
    for(int i=1; i<=G.n; i++) {
        if(mark[i] == 0) {
            dfs(&G, i);
            dem++;
        }
    }
    printf("%d",dem);

    return 0;
}