#include <stdio.h>
#define MAX_N 100
#define NO_EDGE 0

typedef struct {
    int u, v, w;
}Edge;
typedef struct {
    int n, m;
    Edge edges[MAX_N];
}Graph;

void init_graph(Graph *G, int n) {
    G->n = n;
    G->m = 0;   
}
void add_edge(Graph *G, int u, int v, int w) {
    G->edges[G->m].u = u;
    G->edges[G->m].v = v;
    G->edges[G->m].w = w;
    G->m++;
}

int adjacent(Graph *G, int u, int v) {
    for(int i=0; i<G->m; i++) {
        if((G->edges[i].u == u && G->edges[i].v == v) || (G->edges[i].u == v && G->edges[i].v == u)) 
            return 1;
    }
    return 0;
}

#define oo 99999
int mark[MAX_N], pi[MAX_N], p[MAX_N];

int getWeight(Graph *G, int u, int v) {
    for(int i=0; i<G->m; i++) {
        if((G->edges[i].u == u && G->edges[i].v == v) || (G->edges[i].u == v && G->edges[i].v == u)) 
            return G->edges[i].w;
    }
    return 0;
}

void MooreDijkstra(Graph *G, int s) {
    int v, u, it;
    for(u=1; u<= G->n; u++) {
        pi[u] = oo;
        mark[u] = 0;
    }
    pi[s] = 0;
    p[s] = -1;

    for(it=1; it<G->n; it++) {
        int j, min_pi = oo;
        for(j=1; j<=G->n; j++) 
            if(mark[j] == 0 && pi[j] < min_pi) {
                min_pi = pi[j];
                u = j;
            }
        
        mark[u] = 1;

        for(v=1; v<=G->n; v++) {
            if(adjacent(G, u, v) && mark[v] == 0)
                if(pi[u] + getWeight(G, u, v) < pi[v]) {
                    pi[v] = pi[u] + getWeight(G, u, v);
                    p[v] = u;
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
        scanf("%d%d%d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }
    MooreDijkstra(&G, 1);
	
    if(pi[n] == oo) printf("-1");
    else printf("%d", pi[n]);
    
    return 0;
}