#include <stdio.h>
#include <stdlib.h>

typedef struct viz{
    int id_vizinho;
    struct viz *prox;
}TVizinho;

typedef struct grafo{
    int id;
    int cor;
    struct grafo *prox;
    TVizinho *primeiro_vizinho;
}TGrafo;

TVizinho *criaVizinho(int id) {
    TVizinho *novo = (TVizinho*) malloc(sizeof(TVizinho));
    novo->id_vizinho = id;
    novo->prox = NULL;
    return novo;
}

TGrafo *criaGrafo(int id, int cor) {
    TGrafo *novo = (TGrafo*) malloc(sizeof(TGrafo));
    novo->id = id;
    novo->cor = cor;
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

TGrafo *insereGrafo(TGrafo *g, int id, int c) {
    TGrafo *aux = g;
    while (aux != NULL && aux->prox != NULL)
        aux = aux->prox;

    if (aux == NULL)
        g = criaGrafo(id, c);
    else
        aux->prox = criaGrafo(id, c);

    return g;
}

void imprimeCor(TGrafo *grafo) {
    TGrafo *auxG = grafo;
    while (auxG != NULL) {
        printf("\n%d(%d) <", auxG->id, auxG->cor);
        TVizinho *auxV = auxG->primeiro_vizinho;
        while (auxV != NULL) {
            printf("- %d ", auxV->id_vizinho);
            auxV = auxV->prox;
        }
        auxG = auxG->prox;
    }
}

TGrafo *busca(TGrafo *g, int id) {
    TGrafo *aux = g;
    while (aux != NULL && aux->id != id)
        aux = aux->prox;
    return aux;
}

/* EXE5 */
int nao_tem_mesma_cor(TGrafo *g) {
    TGrafo *auxG = g;
    while (auxG != NULL) {
        int cor = auxG->cor;
        TVizinho *auxV = auxG->primeiro_vizinho;
        while (auxV != NULL) {
            TGrafo *rBusca = busca(g, auxV->id_vizinho);
            if (rBusca->cor == cor)
                return 0;
            auxV = auxV->prox;
        }
        auxG = auxG->prox;
    }
    return 1;
}

int main() {
    TGrafo *grafoA = NULL, *grafoB = NULL;
    int vertices[] = {1, 2, 3,4};
    int arestasA[5][2] = {{1,2}, {1,4}, {2,3}, {2,1}, {3,4}};
    int arestasB[4][2] = {{1,3}, {2,4}, {3,1}, {4,2}};

    for (int i = 0; i < 4; ++i) {
        grafoA = insereGrafo(grafoA, vertices[i], i%2);
        grafoB = insereGrafo(grafoB, vertices[i], i%2);
    }

    for (int i = 0; i < 5; ++i)
        grafoA = insereVizinho(grafoA, arestasA[i][0], arestasA[i][1]);

    for (int i = 0; i < 4; ++i)
        grafoB = insereVizinho(grafoB, arestasB[i][0], arestasB[i][1]);

    printf("\nGRAFO A:");
    imprimeCor(grafoA);

    printf("\n\nGRAFO B:");
    imprimeCor(grafoB);

    printf("\n\n5. int nao_tem_mesma_cor(TGrafo *g)");
    printf("\nGrafo A = %d", nao_tem_mesma_cor(grafoA));
    printf("\nGrafo B = %d", nao_tem_mesma_cor(grafoB));

    return 0;
}
