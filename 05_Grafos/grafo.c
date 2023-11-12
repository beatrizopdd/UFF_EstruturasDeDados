#include <stdio.h>
#include <stdlib.h>

typedef struct viz{
    int id_vizinho;
    struct viz *prox;
}TVizinho;

typedef struct grafo{
    int id;
    struct grafo *prox;
    TVizinho *primeiro_vizinho;
}TGrafo;

TVizinho *criaVizinho(int id) {
    TVizinho *novo = (TVizinho*) malloc(sizeof(TVizinho));
    novo->id_vizinho = id;
    novo->prox = NULL;
    return novo;
}

TGrafo *criaGrafo(int id) {
    TGrafo *novo = (TGrafo*) malloc(sizeof(TGrafo));
    novo->id = id;
    novo->prox = NULL;
    novo->primeiro_vizinho = NULL;
    return novo;
}

TGrafo *insereVizinho(TGrafo *g, int idG, int idV) {
    TGrafo *aux = g;
    while (aux->id != idG)
        aux = aux->prox;

    TVizinho *auxV = aux->primeiro_vizinho;
    while (auxV != NULL && auxV->prox != NULL)
        auxV = auxV->prox;

    if (auxV == NULL)
        aux->primeiro_vizinho = criaVizinho(idV);
    else
        auxV->prox = criaVizinho(idV);

    return g;
}

TGrafo *insereGrafo(TGrafo *g, int id) {
    TGrafo *aux = g;
    while (aux != NULL && aux->prox != NULL)
        aux = aux->prox;

    if (aux == NULL)
        g = criaGrafo(id);
    else
        aux->prox = criaGrafo(id);

    return g;
}

void imprime(TGrafo *grafo) {
    TGrafo *auxG = grafo;
    while (auxG != NULL) {
        printf("\n%d <", auxG->id);
        TVizinho *auxV = auxG->primeiro_vizinho;
        while (auxV != NULL) {
            printf("- %d ", auxV->id_vizinho);
            auxV = auxV->prox;
        }
        auxG = auxG->prox;
    }
}
