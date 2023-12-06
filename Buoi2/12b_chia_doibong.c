#define MAX_N 100
#include <stdio.h>
// #include "List.c"


typedef struct List{
	int data[MAX_N];
	int size;
}List;

//tao rong
void make_null_list(List *L){
	L->size=0;
}

//chen cuoi
void push_back(List *L, int x){
	L->data[L->size] = x;
	L->size++;
}

//lay 1 ptu trong ds tai vtri i
int element_at(List L, int i){
	return L.data[i-1];
}

void print_list(List N){
	for(int i=1;i<=N.size;++i){
		printf("%d ", element_at(N, i));
	}
	printf("\n");
}


 // copy S2 vao S1
void copy_list(List* S1, List* S2){
	make_null_list(S1);
	int i;
	for (i=1; i<=S2->size; i++){
		push_back(S1,element_at(*S2,i));
	}
}


void sort(List *pL){
	if(pL->size == 0){
		return;
	}
	for(int i= element_at(*pL, 1); i<pL->size-1;++i){
		for(int j = i+1; j<pL->size;++j){
			if(element_at(*pL,i)>element_at(*pL,j)){
				int temp = element_at(*pL, i);
				pL->data[i] = pL->data[j];
				pL->data[j] = temp;
			}
		}
	}
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
List team_red, team_blue;
void colorize(Graph *G, int u, int c) {
    color[u] = c;

    if(c== BLUE) {
        push_back(&team_blue, u);
    }else if(c == RED) {
        push_back(&team_red, u);
    }

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

    make_null_list(&team_blue);
    make_null_list(&team_red);

    for(int i=1; i<=G.n; i++) {
        if(color[i] == NO_COLOR) {
            colorize(&G, i, BLUE);
        }
    }
    if(conflict) {
        printf("IMPOSSIBLE");
    }else{
        sort(&team_blue);
        sort(&team_red);
        print_list(team_blue);
        print_list(team_red);
    }
}