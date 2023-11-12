#include "arvoreBinariaBusca.c"

/* extra pro 3 */
TABB *remover(TABB *a) {

    // nó com 0 filhos
    if (a->esq == NULL && a->dir == NULL)
        return NULL;

    // nó com 1 filho
    if (a->esq != NULL && a->dir == NULL)
        return a->esq;

    if (a->esq == NULL && a->dir != NULL)
        return a->dir;

    // nó com 2 filhos
    TABB *anterior = a;
    TABB *substituto = a->esq;

    // se o primeiro a esquerda já for o maior
    if (substituto->dir == NULL) {
        substituto->dir = a->dir;
        return substituto;
    }

    // encontrar o maior
    while (substituto->dir != NULL) {
        anterior = substituto;
        substituto = substituto->dir;
    }

    anterior->dir = substituto->esq;
    substituto->dir = a->dir;
    return substituto;

}

/* EX.3 */
TABB *retira_impares(TABB *a) {
    if (a != NULL) {
        a->esq = retira_impares(a->esq);
        a->dir = retira_impares(a->dir);

        if (a->info % 2 != 0)
            a = remover(a);
    }
    return a;
}

int main() {
    int base[] = {16,2,6,14,5,13, 1, 65};
    TABB *arvore = criaFolha(10);

    for (int i = 0; i < 8; i++)
        arvore = inserir(arvore, base[i]);

    printf("Arvore binaria de busca\n");
    imprimir(arvore, 1);

    printf("\n3 -  TABB* retira_impares(TABB* a)\n");
    TABB *arvorePar = retira_impares(arvore);
    imprimir(arvorePar, 1);

    return 0;
}