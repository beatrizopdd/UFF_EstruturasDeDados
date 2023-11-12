#include <stdio.h>
#include <stdlib.h>

typedef struct ab {
    int info;
    struct ab *esq, *dir;
} TABB;

TABB *criaFolha(int info) {
    TABB *nova = (TABB*) malloc(sizeof(TABB));
    nova->info = info;
    nova->esq = NULL;
    nova->dir = NULL;
    return nova;
}

void imprimir(TABB *arvore, int tab) {
    if (arvore != NULL) {
        imprimir(arvore->dir, tab + 3);

        for (int i = 0; i < tab; i++)
            printf("--");
        printf("%d\n", arvore->info);

        imprimir(arvore->esq, tab + 3);
    }
}

TABB *inserir(TABB *a, int numero) {
    if (a == NULL)
        a = criaFolha(numero);
    else {
        TABB *ante, *aux = a;
        while (aux != NULL) {
            ante = aux;
            if (numero < aux->info)
                aux = aux->esq;
            else
                aux = aux->dir;
        }
        if (numero < ante->info)
            ante->esq = criaFolha(numero);
        else
            ante->dir = criaFolha(numero);
    }
    return a;
}

