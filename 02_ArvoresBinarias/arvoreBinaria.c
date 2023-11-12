#include <stdlib.h>
#include <stdio.h>

typedef struct ab {
    int info;
    struct ab *esq, *dir;
} TAB;

TAB *criaFolha(int info) {
    TAB *nova = (TAB*) malloc(sizeof(TAB));
    nova->info = info;
    nova->esq = NULL;
    nova->dir = NULL;
    return nova;
}

void imprime(TAB *arvore, int tab) {
    if (arvore != NULL) {
        imprime(arvore->dir, tab + 3);

        for (int i = 0; i < tab; i++)
            printf(" ");
        printf("%d\n", arvore->info);

        imprime(arvore->esq, tab + 3);
    }
}

TAB *criaArvore(int i) {
    TAB *arvore = criaFolha(10 + i);
    arvore->esq = criaFolha(11 + i);
    arvore->esq->esq = criaFolha(12 + i);
    arvore->esq->esq->esq = criaFolha(13 + i);
    arvore->esq->esq->dir = criaFolha( + i);
    arvore->esq->dir = criaFolha(15 + i);
    arvore->esq->dir->esq = criaFolha(16 + i);
    arvore->esq->dir->dir = criaFolha(17 + i);

    arvore->dir = criaFolha(18 + i);
    arvore->dir->esq = criaFolha(19 + i);
    arvore->dir->esq->esq = criaFolha(20 + i);
    arvore->dir->esq->dir = criaFolha(21 + i);
    arvore->dir->dir = criaFolha(22 + i);
    arvore->dir->dir->esq = criaFolha(23 + i);
    arvore->dir->dir->dir = criaFolha(24 + i);

    return arvore;
}