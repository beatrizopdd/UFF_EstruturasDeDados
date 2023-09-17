#include "TAB.h"

/* CAMINHAMENTO: POS-ORDEM  */
void cPosOrdem(TAB *arvore) {
    if (arvore != NULL) {
        /* trabalha com a esquerda */
        cPosOrdem(arvore->esq);

        /* trabalha com a direita */
        cPosOrdem(arvore->dir);

        /* trabalha com a raiz */
        printf("%c ", arvore->info);

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

    /* D - E - B - F - G - C - A  */
    cPosOrdem(raiz);
    return 0;
}

