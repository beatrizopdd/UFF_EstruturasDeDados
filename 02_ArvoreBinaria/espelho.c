#include "arvoreBinaria.c"

/* EXE2 */
TAB *espelho(TAB *a) {
    TAB *nova;
    if (a != NULL) {
        nova = (TAB*) malloc(sizeof(TAB));
        nova->info = a->info;
        nova->esq = espelho(a->dir);
        nova->dir = espelho(a->esq);
    } else
        nova = NULL;
    return nova;
}

int main() {
    TAB *arvore = criaArvore(0);

    printf("Original\n");
    imprime(arvore, 1);

    TAB *arvoreE = espelho(arvore);
    printf("\n2. TAB *espelho(TAB *a)\n");
    imprime(arvoreE, 1);

    return 0;
}