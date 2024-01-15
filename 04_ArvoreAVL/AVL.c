#include <stdio.h>
#include <stdlib.h>

typedef struct AVL {
    int info;
    struct AVL *esq, *dir;
} TAVL;

void imprimir(TAVL *arvore, int tab) {
    if (arvore != NULL) {
        imprimir(arvore->dir, tab + 3);

        for (int i = 0; i < tab; i++)
            printf("--");
        printf("%d\n", arvore->info);

        imprimir(arvore->esq, tab + 3);
    }
}

TAVL *criaNoh(int numero) {
    TAVL *novoNoh;
    novoNoh = (TAVL*)malloc(sizeof(TAVL));
    novoNoh->info = numero;
    novoNoh->esq = NULL;
    novoNoh->dir = NULL;
    return novoNoh;
}

TAVL *inserir(TAVL *a, int numero) {
    if (a == NULL)
        a = criaNoh(numero);
    else {
        TAVL *ante, *aux = a;
        while (aux != NULL) {
            ante = aux;
            if (numero < aux->info)
                aux = aux->esq;
            else
                aux = aux->dir;
        }
        if (numero < ante->info)
            ante->esq = criaNoh(numero);
        else
            ante->dir = criaNoh(numero);
    }
    return a;
}