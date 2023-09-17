#include "TAB.h"

typedef struct fila {
    TAB *noh;
    struct fila *prox;
} TFila;

void addFila(TFila *fila, TAB *filho) {
    if (filho != NULL) {
        TFila *novo, *aux = fila;
        novo = (TFila *) malloc(sizeof(TFila));
        novo->noh = filho;
        novo->prox = NULL;

        while (aux->prox != NULL)
            aux = aux->prox;

        aux->prox = novo;
    }
}

TFila* delFila(TFila *fila) {
    TFila *novoInicio = fila->prox, *lixo = fila;
    free(lixo);
    return novoInicio;
}

/* CAMINHAMENTO: LARGURA  */
void cLargura(TAB *arvore) {
    TFila *fila;
    fila = (TFila*)malloc(sizeof(TFila));
    fila->noh = arvore;
    fila->prox = NULL;

    while (fila != NULL) {
        printf("%c ", fila->noh->info);

        /* adicionando a próxima linha final */
        addFila(fila, fila->noh->esq);
        addFila(fila, fila->noh->dir);

        /* removendo o primeiro elemento */
        fila = delFila(fila);
    }

}

int main() {
    TAB *raiz = criaNoh('A');
    raiz->esq = criaNoh('B');
    raiz->esq->esq = criaNoh('D');
    raiz->esq->dir = criaNoh('E');
    raiz->dir = criaNoh('C');
    raiz->dir->esq = criaNoh('F');
    raiz->dir->dir = criaNoh('G');

    /* A - B - C - D - E - F - G  */
    cLargura(raiz);
    return 0;
}