#include "TAB.h"

/* CAMINHAMENTO: PRÉ-ORDEM (PROFUNDIDADE) */
void cPreOrdem(TAB *arvore) {
    if (arvore != NULL) {
        /* trabalha com a raiz */
        printf("%c ", arvore->info);

        /* trabalha com a esquerda */
        cPreOrdem(arvore->esq);

        /* trabalha com a direita */
        cPreOrdem(arvore->dir);
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

    /* A - B - D - E - C - F - G */
    cPreOrdem(raiz);
    return 0;
}