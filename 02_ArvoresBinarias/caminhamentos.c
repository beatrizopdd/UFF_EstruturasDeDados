#include "arvoreBinaria.c"

typedef struct lista {
    TAB *noh;
    struct lista *prox;
} FILA;

/* por nível - esquerda - direita */
FILA *criaFila(TAB *arvore) {
    FILA *fila = (FILA*) malloc(sizeof(FILA));
    fila->noh = arvore;
    fila->prox = NULL;

    FILA *atual = fila, *ultimo;
    while (atual != NULL) {
        ultimo = atual;
        while (ultimo->prox != NULL)
            ultimo = ultimo->prox;

        if (atual->noh->esq != NULL) {
            FILA *novoE = (FILA*) malloc(sizeof(FILA));
            novoE->noh = atual->noh->esq;
            novoE->prox = NULL;
            ultimo->prox = novoE;
            ultimo = ultimo->prox;
        }

        if (atual->noh->dir != NULL) {
            FILA *novoD = (FILA*) malloc(sizeof(FILA));
            novoD->noh = atual->noh->dir;
            novoD->prox = NULL;
            ultimo->prox = novoD;
        }

        atual = atual->prox;
    }

    return fila;
}

void camLargura(TAB *arvore) {
    FILA *fila = criaFila(arvore);

    while (fila != NULL) {
        printf("%d ", fila->noh->info);
        fila = fila->prox;
    }
}

/* raiz - esquerda - direita */
void camPreOrdem(TAB *arvore) {
    if (arvore != NULL) {
        printf("%d ", arvore->info);
        camPreOrdem(arvore->esq);
        camPreOrdem(arvore->dir);
    }
}

/* esquerda - raiz - direita */
void camSimetrico(TAB *arvore) {
    if (arvore != NULL) {
        camSimetrico(arvore->esq);
        printf("%d ", arvore->info);
        camSimetrico(arvore->dir);
    }
}

/* esquerda - direita - raiz */
void camPosOrdem(TAB *arvore) {
    if (arvore != NULL) {
        camPosOrdem(arvore->esq);
        camPosOrdem(arvore->dir);
        printf("%d ", arvore->info);
    }
}

int main() {

    TAB *arvore = criaFolha(1);
    arvore->esq = criaFolha(2);
    arvore->esq->esq = criaFolha(4);
    arvore->esq->dir = criaFolha(5);
    arvore->dir = criaFolha(3);
    arvore->dir->esq = criaFolha(6);
    arvore->dir->dir = criaFolha(7);

    printf("\nPRE-ORDEM\n");
    camPreOrdem(arvore);
    printf("\n");

    printf("\nPOS-ORDEM\n");
    camPosOrdem(arvore);
    printf("\n");

    printf("\nSIMETRICO\n");
    camSimetrico(arvore);
    printf("\n");

    printf("\nLARGURA\n");
    camLargura(arvore);
    printf("\n");

    return 0;
}