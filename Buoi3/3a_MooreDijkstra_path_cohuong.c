#include <stdio.h>

#define MAXN 100
#define oo 999999
#define NO_EDGE -1


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
}

int mark[MAXN];
int pi[MAXN];
int p[MAXN];

void MooreDijkstra(Graph *pG, int s) {
	int u, v, it;
	for (u = 1; u <= pG->n; u++) {
		pi[u] = oo;
		mark[u] = 0;
	}

	pi[s] = 0; //chiều dài đường đi ngắn nhất từ s đến chính nó bằng 0
	p[s] = -1; //trước đỉnh s không có đỉnh nào cả

	//Lặp n-1 lần
	for (it = 1; it < pG->n; it++) {
		//1. Tìm u có mark[u] == 0 và có pi[u] nhỏ nhất
		int j, min_pi = oo;
		for (j = 1; j <= pG->n; j++)
			if (mark[j] == 0 && pi[j] < min_pi) {
				min_pi = pi[j];
				u = j;
			}
		//2. Đánh dấu u đã xét
		mark[u] = 1;

		//3. Cập nhật pi và p của các đỉnh kề của v (nếu thoả)
		for (v = 1; v <= pG->n; v++)
			if (pG->W[u][v] != NO_EDGE && mark[v] == 0)
				if (pi[u] + pG->W[u][v] < pi[v]) {
					pi[v] = pi[u] + pG->W[u][v];
					p[v] = u;
				}
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
    
    int s, u;
    scanf("%d%d", &s, &u);
    
    MooreDijkstra(&G, s);
    
    //Tìm đường đi ngắn nhất
    int path[MAXN]; //lưu các đỉnh trên đường đi
    int k = 0;      //số đỉnh của đường đi
    int current = u;

    //Lần ngược theo p để lấy đường đi
    while (current != -1) {
	    path[k] = current; k++;
	    current = p[current];
    }
    printf("%d",path[k-1]);
    //In ra màn hình theo chiều ngược lại    
    for (int u = k-2; u >= 0; u--)
	    printf(" -> %d ", path[u]);

    

    return 0;
}