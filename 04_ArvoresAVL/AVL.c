#include "AVL.h"

TAVL *rotacaoD(TAVL *desbalanceado) {
    TAVL *substituto = desbalanceado->esq;
    desbalanceado->esq = substituto->dir;
    substituto->dir = desbalanceado;
    return substituto;
}

TAVL *rotacaoE(TAVL *desbalanceado) {
    TAVL *substituto = desbalanceado->dir;
    desbalanceado->dir = substituto->esq;
    substituto->esq = desbalanceado;
    return substituto;
}

TAVL *busca(TAVL *raiz, int chave) {
    TAVL *anterior = raiz;
    TAVL *aux = raiz;

    while (aux != NULL && aux->chave != chave) {
        anterior = aux;
        if (chave < aux->chave)
            aux = aux->esq;
        else if (chave > aux->chave)
            aux = aux->dir;
    }
    return anterior;
}

int altura(TAVL *raiz) {
    if (raiz != NULL) {
        int esquerda = altura(raiz->esq);
        int direita = altura(raiz->dir);
        if (esquerda > direita)
            return (esquerda + 1);
        else
            return (direita + 1);
    } else
        return -1;
}

TAVL *insere(TAVL *raiz, int chave) {

    TAVL *anterior = busca(raiz, chave);

    if (anterior == NULL)
        return criaNoh(chave);

    else if (chave < anterior->chave && anterior->esq == NULL)
        anterior->esq = criaNoh(chave);

    else if (chave > anterior->chave && anterior->dir == NULL)
        anterior->dir = criaNoh(chave);

    return raiz;
}

int main() {
    TAVL *raizA = NULL;
    int numerosA[] = {42,15,88,27,20,63,57,71};

    for (int i = 0; i < 8; i++) {
        raizA = insere(raizA, numerosA[i]);
    }

    imprimeArvore(raizA, 0);
    printf("ALTURA: %d\n\n", altura(raizA));

    return 0;
}


