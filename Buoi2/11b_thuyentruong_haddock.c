#define MAX_N 100
#include <stdio.h>

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
    G->m++;
    // G->A[v][u] = 1;

}
int adjacent(Graph *G, int u, int v) {
    return G->A[u][v] > 0;
}

#define WHITE 0
#define GRAY 1
#define BLACK 2
int color[MAX_N];
int is_drunk;

void dfs(Graph *G, int u) {
    color[u] = GRAY;

    for(int v=1; v<=G->n; v++) 
        if(adjacent(G, u, v)) {
            if(color[v] == WHITE) {
                dfs(G, v);
            }else if(color[v] == GRAY) {
                is_drunk = 1;
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

    for(int i=1; i<=G.n; i++) {
        if(color[i] == WHITE) {
            dfs(&G, i);
        }
    }
    if(is_drunk) {
        printf("NO");
    }else printf("YES");
}