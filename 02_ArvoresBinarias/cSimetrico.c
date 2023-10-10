#include "TAB.h"

/* CAMINHAMENTO: ORDEM SIMÉTRICA  */
void cSimetrico(TAB *arvore) {
    if (arvore != NULL) {
        /* trabalha com a esquerda */
        cSimetrico(arvore->esq);

        /* trabalha com a raiz */
        printf("%c ", arvore->info);

        /* trabalha com a direita */
        cSimetrico(arvore->dir);
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

    /* D - B - E - A - F - C - G  */
    cSimetrico(raiz);
    return 0;
}
