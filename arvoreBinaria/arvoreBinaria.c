#include "TAB.h"

int main() {
    TAB *arvore = criaNoh('A');

    arvore->esq = criaNoh('B');
    arvore->esq->esq = criaNoh('D');
    arvore->esq->dir = criaNoh('E');

    arvore->dir = criaNoh('C');
    arvore->dir->esq = criaNoh('F');
    arvore->dir->dir = criaNoh('G');

    imprimeArvore(arvore, 1);
    return 0;
}