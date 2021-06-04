#include <stdio.h>
#include <stdlib.h>
typedef struct {
  int **adj;
  int n;
} Grafo;

 typedef Grafo * p_grafo;

 p_grafo criar_grafo(int n);

 void destroi_grafo ( p_grafo g );

void insere_aresta( p_grafo g, int u, int v);

 void remove_aresta( p_grafo g, int u, int v);

int tem_aresta( p_grafo g, int u, int v);

 void imprime_arestas ( p_grafo g );

p_grafo criar_grafo(int n) {
     int i, j;
     p_grafo g = malloc ( sizeof ( Grafo ) );
     g->n = n;
     g->adj = malloc(n * sizeof(int *));
     for (i = 0; i < n; i++)
     g->adj[i] = malloc(n * sizeof(int));
     for (i = 0; i < n; i++)
     for (j = 0; j < n; j++)
     g->adj[i][j] = 0;
     return g;
}

void destroi_grafo ( p_grafo g) {
     int i;
     for (i = 0; i < g->n; i++)
     free(g->adj[i]);
     free(g->adj);
     free(g);
}

void insere_aresta ( p_grafo g, int u, int v) {
     g->adj[u][v] = 1;
     g->adj[v][u] = 1;
}

void remove_aresta ( p_grafo g, int u, int v) {
     g->adj[u][v] = 0;
     g->adj[v][u] = 0;
}

int tem_aresta( p_grafo g, int u, int v) {
    return g->adj[u][v];
}

p_grafo le_grafo() {
     int n, m, i, u, v;
     p_grafo g;
     scanf("%d %d", &n, &m);
     g = criar_grafo(n);
     for (i = 0; i < m; i++) {
         scanf("%d %d", &u, &v);
         insere_aresta(g, u, v);
     }
     return g;
}

void imprime_arestas ( p_grafo g) {
 int u, v;
 for (u = 0; u < g->n; u++)
    for (v = u+1; v < g->n; v++)
        if ( g->adj[u][v])
            printf("{%d,%d}\n ", u, v);
         }

int grau ( p_grafo g, int u) {
 int v, grau = 0;
 for (v = 0; v < g->n; v++)
 if ( g->adj[u][v]){
    grau++;
 }
 return grau;
}

int main(){
    return 0;
}
