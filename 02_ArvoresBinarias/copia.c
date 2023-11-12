#include "arvoreBinaria.c"

/* EXE1 */
TAB *copia(TAB *a) {
    TAB *novaFolha;
    if (a != NULL) {
        novaFolha = (TAB*) malloc(sizeof(TAB));
        novaFolha->info = a->info;
        novaFolha->esq = copia(a->esq);
        novaFolha->dir = copia(a->dir);
    } else
        novaFolha = NULL;
    return novaFolha;
}

int main() {
    TAB *arvore = criaArvore(0);

    printf("Original\n");
    imprime(arvore, 1);

    TAB *arvoreC = copia(arvore);
    printf("\n1. TAB *copia(TAB *a)\n");
    imprime(arvoreC, 1);

    return 0;
}