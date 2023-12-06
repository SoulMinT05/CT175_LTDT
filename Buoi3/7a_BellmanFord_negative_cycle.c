#include <stdio.h>
#include <limits.h>

#define MAX_N 100

typedef struct Edge {
	int u, v;
	int weight;
} Edge;

typedef struct Graph {
	int n, m;
	Edge edges[MAX_N];
} Graph;

void init_graph(Graph *pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edges(Graph *pG, int u, int v, int w) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->edges[pG->m].weight = w;

	pG->m++;
}

#define oo INT_MAX

int pi[MAX_N];
int p[MAX_N];


int negative_cycle;
void BellmanFord(Graph *G, int s) {
	int u, v, w, it, k;
	for(u=1; u<=G->n; u++)
		pi[u] = oo;
	pi[s] = 0;
	p[s] = -1;
	
	for(it = 1; it<G->n; it++) {
		for(k=0; k<G->m; k++) {
			u = G->edges[k].u;
			v = G->edges[k].v;
			w = G->edges[k].weight;
			if(pi[u] + w < pi[v]) {
				pi[v] = pi[u] + w;
				p[v] = u;
			}
		}
	}
	
	negative_cycle = 0;
	for(k=0; k<G->m; k++) {
		u = G->edges[k].u;
		v = G->edges[k].v;
		w = G->edges[k].weight;
		if(pi[u] + w < pi[v] && pi[u] != oo) { //thêm pi[u] khác oo nữa
			negative_cycle = 1;
			break;
		}
	}
}

int main(void) {
	freopen("dt.txt", "r", stdin);

	Graph G;

	int n, m;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);

	for (int i = 0; i < m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add_edges(&G, u, v, w);
	}
	
	int start;
	scanf("%d", &start);

	BellmanFord(&G, start);
	
	if(negative_cycle){
		printf("YES");
	}else{
		printf("NO");
	}

	return 0;
}
