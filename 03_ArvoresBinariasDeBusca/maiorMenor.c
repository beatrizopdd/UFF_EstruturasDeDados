#include "arvoreBinariaBusca.c"

/* EX.1 */
TABB *maior(TABB *a) {
    TABB *aux = a;
    while (aux->dir != NULL)
        aux = aux->dir;
    return aux;
}

/* EX.2 */
TABB *menor(TABB *a) {
    TABB *aux = a;
    while (aux->esq != NULL)
        aux = aux->esq;
    return aux;
}

int main() {
    int base[] = {16,2,6,14,5,13, 1, 65};
    TABB *arvore = criaFolha(10);

    for (int i = 0; i < 8; i++)
        arvore = inserir(arvore, base[i]);

    printf("Arvore binaria de busca\n");
    imprimir(arvore, 1);

    TABB *maiorElem = maior(arvore);
    printf("\n1 - TABB* maior(TAB *a)\n-> %d\n", maiorElem->info);

    TABB *menorElem = menor(arvore);
    printf("\n2 - TABB *menor(TABB *a)\n-> %d\n", menorElem->info);

    return 0;
}