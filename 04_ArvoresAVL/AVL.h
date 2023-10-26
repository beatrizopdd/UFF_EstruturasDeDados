#include <stdio.h>
#include <stdlib.h>

typedef struct AVL {
    int chave;
    struct AVL *esq, *dir;
} TAVL;

TAVL *criaNoh(int chave) {
    TAVL *novoNoh;
    novoNoh = (TAVL*)malloc(sizeof(TAVL));
    novoNoh->chave = chave;
    novoNoh->esq = NULL;
    novoNoh->dir = NULL;
    return novoNoh;
}

// impressão por profundidade
void imprimeArvore(TAVL *raiz, int espacamento) {

    if (raiz != NULL) {
        imprimeArvore(raiz->dir, espacamento+2);

        for (int i = 0; i < espacamento; i++)
            printf(". ");
        printf("%d\n", raiz->chave);

        imprimeArvore(raiz->esq, espacamento+2);
    }
}