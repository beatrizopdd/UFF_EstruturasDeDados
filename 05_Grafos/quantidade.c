#include "grafo.c"

/* EXE1 */
int na(TGrafo *g) {
    int qtd = 0;
    TGrafo *auxG = g;
    while (auxG != NULL) {
        TVizinho *auxV = auxG->primeiro_vizinho;
        while (auxV != NULL) {
            qtd++;
            auxV = auxV->prox;
        }
        auxG = auxG->prox;
    }
    return qtd;
}

/* EXE2 */
int nv(TGrafo *g) {
    int qtd = 0;
    TGrafo *aux = g;
    while (aux != NULL) {
        qtd++;
        aux = aux->prox;
    }
    return qtd;
}

int main() {
    int vertices[] = {1, 2, 3,4};
    int arestas[5][2] = {{1,2}, {1,3}, {2,3}, {2,4}, {3,4}};
    TGrafo *grafo = NULL;

    for (int i = 0; i < 4; ++i)
        grafo = insereGrafo(grafo, vertices[i]);
    printf("\nVertices:");
    imprime(grafo);

    for (int i = 0; i < 5; ++i)
        grafo = insereVizinho(grafo, arestas[i][0], arestas[i][1]);
    printf("\n\nVertices e arestas:");
    imprime(grafo);

    printf("\n\n1. int na(TGrafo *g)\n");
    int numArestas = na(grafo);
    printf("-> %d arestas", numArestas);

    printf("\n\n2. int nv(TGrafo *g)\n");
    int numVertices = nv(grafo);
    printf("-> %d vertices", numVertices);

    return 0;
}