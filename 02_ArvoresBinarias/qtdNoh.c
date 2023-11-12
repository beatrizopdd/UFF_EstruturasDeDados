#include "arvoreBinaria.c"

/* EXE8 */
int ni(TAB *a) {
    if (a != NULL) {
        if (a->esq == NULL && a->dir == NULL)
            return 0;

        return (1 + ni(a->esq) + ni(a->dir));
    }
    return 0;
}

/* EXE9 */
int nf(TAB *a) {
    if (a != NULL) {
        if (a->esq == NULL && a->dir == NULL)
            return 1;

        return (nf(a->esq) + nf(a->dir));
    }
    return 0;
}

int main() {
    TAB *arvore = criaArvore(1);

    printf("Original\n");
    imprime(arvore, 1);

    int qtdNI = ni(arvore);
    printf("\n8. int ni(TAB *a)\n");
    printf("%d nohs internos", qtdNI);

    int qtdNF = nf(arvore);
    printf("\n9. int nf(TAB *a)\n");
    printf("%d nohs folha", qtdNF);

    return 0;
}