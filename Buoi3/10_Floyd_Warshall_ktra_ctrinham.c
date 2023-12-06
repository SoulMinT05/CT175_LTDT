// #include <stdio.h>
// #include <limits.h>
// typedef struct {
//     int u, v, weight;
// }Edge;

// typedef struct {
//     int n,m;
//     Edge edges[100];
// }Graph;
// void init_graph(Graph *G, int n){
//     G->n=n;
//     G->m=0;
// }
// void add_edge(Graph *G, int u, int v, int w){
//     G->edges[G->m].u = u;
//     G->edges[G->m].v = v;
//     G->edges[G->m].weight = w;
//     G->m++;
// }
// int adjacent(Graph *G, int u, int v){
//     for(int i=0; i<G->m; i++){
//         if(G->edges[i].u == u && G->edges[i].v == v) 
//             return 1;
//     }
//     return 0;
// }
// #define oo 999999
// int getWeight(Graph *G, int u, int v){
//     for(int i=0; i<G->m; i++){
//         if(G->edges[i].u == u && G->edges[i].v == v) 
//             return G->edges[i].weight;
//     }
//     return oo;
// }
// int pi[100][100], next[100][100];
// int negative_cycle;
// void FloydWarshall(Graph *G){
//     int u, v, k;
//     for(u=1;u<=G->n;u++){ //khoi tao 2 mang
// 		for(v=1;v<=G->n;v++){
// 			pi[u][v] = oo;
// 			next[u][v] = -1;
// 		}
// 	}
	
// 	for(u=1;u<=G->n;u++){
// 		pi[u][u] = 0;
// 	}
	
// 	for(u=1;u<=G->n;u++){ //khoi tao 2 mang
// 		for(int v=1;v<=G->n;v++){
// 			if(adjacent(G, u, v)){
// 				pi[u][v] = getWeight(G, u, v);
// 				next[u][v] = v;
// 			}
// 		}
// 	}
//     for( k=1;k<=G->n;k++){
// 		for( u=1;u<=G->n;u++){
// 			for( v=1;v<=G->n;v++){
// 				if(pi[u][k] + pi[k][v] < pi[u][v] && pi[u][k]!=oo && pi[k][v]!=oo){
// 					pi[u][v] = pi[u][k] + pi[k][v];
// 					next[u][v] = next[u][k];
// 				}
// 			}
// 		}
// 	}
//     negative_cycle = 0;
//     for(u=1; u<=G->n; u++){
//         if(pi[u][u] < 0) {
//             negative_cycle = 1;
//             break;
//         }
//     }
// }
// int main() {
//     freopen("dt.txt", "r", stdin);
//     Graph G;
//     int n,m,u,v,w,i;
//     scanf("%d%d", &n, &m);
//     init_graph(&G, n);

//     for(i=0; i<m; i++){
//         scanf("%d%d%d",&u,&v,&w);
//         add_edge(&G,u,v,w);
//     }
//     FloydWarshall(&G);
//     if(negative_cycle)
//         printf("YES");
//     else printf("NO");
// }


//MTK

//MTK
#include <stdio.h>

#define MAXM 500
#define MAXN 100
#define oo 999999
#define NO_EDGE 0

typedef struct {
    int n, m;
    int W[MAXN][MAXN];
} Graph;

void init_graph(Graph *pG, int n) {
    pG->n = n;
    pG->m = 0;
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
            pG->W[u][v] = NO_EDGE;
}

void add_edge(Graph *pG, int u, int v, int w) {
    pG->W[u][v] = w;
    pG->m++;
}


#define oo 999999
int pi[MAXN][MAXN];
int next[MAXN][MAXN];
int negative_cycle;
void FloydWarshall(Graph *pG) {
    int u, v, k;
    for (u = 1; u <= pG->n; u++)
        for (v = 1; v <= pG->n; v++) {
            pi[u][v] = oo;
            next[u][v] = -1;
        }

    for (u = 1; u <= pG->n; u++) {
        pi[u][u] = 0;
        // next[u][u] = u;
    }

    for (u = 1; u <= pG->n; u++)
        for (v = 1; v <= pG->n; v++)
            if (pG->W[u][v] != NO_EDGE) {
                pi[u][v] = pG->W[u][v]; //đi trực tiếp từ u -> v
                next[u][v] = v;
            }
    
    for (k = 1; k <= pG->n; k++)
        for (u = 1; u <= pG->n; u++) {
            for (v = 1; v <= pG->n; v++) {
                if (pi[u][k] + pi[k][v] < pi[u][v] && pi[u][k] != oo && pi[k][v]!=oo) {
                    pi[u][v] = pi[u][k] + pi[k][v];
                    next[u][v] = next[u][k];
                }
            }
        }
    
    //Kiểm tra chu trình âm (nếu cần thiết)
    negative_cycle =0;
    for(u=1; u<=pG->n; u++)
        if(pi[u][u] < 0){
            negative_cycle = 1;
            break;
        }

}


int main() {
    freopen("dt.txt","r",stdin);
    Graph G;
    int n, m;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    
    for (int e = 0; e < m; e++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }

    FloydWarshall(&G);
    if(negative_cycle)
        printf("YES");
    else printf("NO");
    
    return 0;
}