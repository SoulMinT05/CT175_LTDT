#include <stdio.h>
typedef struct {
	int u, v;
}Edge;
typedef struct {
	int n,m;
	Edge edges[100];
}Graph;
void init_graph(Graph *G, int n){
	G->n=n;
	G->m=0;
}
void add_edge(Graph *G, int u, int v){
	G->edges[G->m].u = u;
	G->edges[G->m].v = v;
	G->m++;
}

int main(){
	Graph G;
	int n;
	freopen("dt.txt", "r", stdin);
	scanf("%d", &n);
	init_graph(&G, n);
	
	int mtk[n][n];
	int i,j;
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			int temp;
			scanf("%d", &temp);
			mtk[i][j] = temp;
		}
	}
	for(i=1; i<=n; i++){
		for(j=i; j<=n; j++){ //xu ly do thi vo huong
			for(int k=1; k<=mtk[i][j]; k++){
				add_edge(&G, i, j);
			}
		}
	}
	for(int i=0; i<G.m; i++)
		printf("%d %d\n", G.edges[i].u, G.edges[i].v);

	return 0;
}