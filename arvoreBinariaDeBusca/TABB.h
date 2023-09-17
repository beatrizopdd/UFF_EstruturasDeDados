#include <stdio.h>
#include <stdlib.h>

typedef struct arvoreBusca {
    int info;
    int chave;
    struct arvoreBusca *esq, *dir;
} TABB;

void imprimeArvore(TABB *raiz, int espacamento) {
    if (raiz != NULL) {
        for (int i = 0; i < espacamento; i++)
            printf("-");
        printf("%d\n", raiz->info);
        imprimeArvore(raiz->esq, espacamento+2);
        imprimeArvore(raiz->dir, espacamento+2);
    }
}

TABB *criaNoh(int num, int chave) {
    TABB *novoNoh;
    novoNoh = (TABB*)malloc(sizeof(TABB));

    novoNoh->chave = chave;
    novoNoh->info = num;
    novoNoh->esq = NULL;
    novoNoh->dir = NULL;

    return novoNoh;
}

TABB *localizaNoh(TABB *raiz, int chave) {
    if (chave < raiz->chave && raiz->esq != NULL)
        localizaNoh(raiz->esq, chave);
    if (chave > raiz->chave && raiz->dir != NULL)
        localizaNoh(raiz->dir, chave);
    else
        return raiz;
}

void insereNovo(TABB *arvore, int num, int chave) {

    TABB *filha = criaNoh(num, chave);

    if (arvore != NULL) {
        TABB *mae = localizaNoh(arvore, chave);
        if (filha->chave < mae->chave)
            mae->esq = filha;
        else if (filha->chave > mae->chave)
            mae->dir = filha;

    } else
        arvore = filha;

}


