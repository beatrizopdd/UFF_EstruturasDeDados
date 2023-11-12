#include "arvoreBinaria.c"

int antecessor(TAB *a, int k) {
    if (a != NULL) {
        int menorE = antecessor(a->esq, k);
        int menorD = antecessor(a->dir, k);

        if (a->info < k && a->info > menorE && a->info > menorD)
            return a->info;

        if (menorE < k && menorE > menorD)
            return menorE;

        if (menorD < k && menorD > menorE)
            return menorD;

    } else
        return -1;
}

int main() {
    TAB *arvore = criaFolha(5);
    arvore->esq = criaFolha(15);
    arvore->esq->esq = criaFolha(65);
    arvore->esq->dir = criaFolha(3);
    arvore->dir = criaFolha(2);
    arvore->dir->esq = criaFolha(13);
    arvore->dir->dir = criaFolha(45);

    printf("Arvore\n");
    imprime(arvore, 1);

    printf("\no antecessor de 1 eh %d\n", antecessor(arvore, 1));
    printf("\no antecessor de 64 eh %d\n", antecessor(arvore, 64));
    printf("\no antecessor de 3 eh %d\n", antecessor(arvore, 3));
    return 0;
}
