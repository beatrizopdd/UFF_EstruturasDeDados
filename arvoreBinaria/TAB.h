#include <stdio.h>
#include <stdlib.h>

typedef struct arvoreBinaria {
    char info;
    struct arvoreBinaria *esq, *dir;
} TAB;

TAB *criaNoh(char letra) {
    TAB *novoNoh;
    novoNoh = (TAB*)malloc(sizeof(TAB));
    novoNoh->info = letra;
    novoNoh->esq = NULL;
    novoNoh->dir = NULL;
    return novoNoh;
}

// impressão por profundidade
void imprimeArvore(TAB *raiz, int espacamento) {

    if (raiz != NULL) {
        for (int i = 0; i < espacamento; i++)
            printf("-");
        printf("%c\n", raiz->info);
        imprimeArvore(raiz->esq, espacamento+2);
        imprimeArvore(raiz->dir, espacamento+2);
    }
}