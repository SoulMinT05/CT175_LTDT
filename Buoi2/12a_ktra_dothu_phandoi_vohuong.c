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
    G->A[v][u] = 1;
    G->m++;

}
int adjacent(Graph *G, int u, int v) {
    return G->A[u][v] > 0;
}

#define NO_COLOR 0
#define BLUE 1
#define RED 2

int color[MAX_N];
int conflict;

void colorize(Graph *G, int u, int c) {
    color[u] = c;

    for(int v=1; v<=G->n; v++)  {
        if(adjacent(G, u, v)) {
            if(color[v] == NO_COLOR)
                colorize(G, v, 3-c);
            else if(color[v] == color[u])
                conflict = 1;
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

    for(int i=1; i<=G.n; i++) {
        if(color[i] == NO_COLOR) {
            colorize(&G, i, BLUE);
        }
    }
    if(conflict) {
        printf("NO");
    }else printf("YES");
}