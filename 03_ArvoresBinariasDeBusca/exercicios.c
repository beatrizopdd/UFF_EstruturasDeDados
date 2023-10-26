#include <stdio.h>
#include <stdlib.h>

typedef struct ab {
    int info;
    struct ab *esq, *dir;
} TABB;

void imprime(TABB *arvore, int tab) {
    if (arvore != NULL) {
        imprime(arvore->dir, tab + 3);

        for (int i = 0; i < tab; i++)
            printf(" ");
        printf("%d\n", arvore->info);

        imprime(arvore->esq, tab + 3);
    }
}

TABB *criaFolha(int info) {
    TABB *nova = (TABB*) malloc(sizeof(TABB));
    nova->info = info;
    nova->esq = NULL;
    nova->dir = NULL;
    return nova;
}

/* E1 */
TABB *maior(TABB *a) {
    TABB *aux = a;

    while (aux->dir != NULL)
        aux = aux->dir;

    return aux;
}

/* E2 */
TABB *menor(TABB *a) {
    TABB *aux = a;

    while (aux->esq != NULL)
        aux = aux->esq;

    return aux;
}

/* E3 */
TABB *retira_impares(TABB *a) {
    if ()
}

int main() {
    TABB *arvore = criaFolha(10);
    arvore->esq = criaFolha(5);
    arvore->esq->esq = criaFolha(2);
    arvore->esq->dir = criaFolha(6);
    arvore->dir = criaFolha(14);
    arvore->dir->esq = criaFolha(13);
    arvore->dir->dir = criaFolha(16);

    printf("Arvore original\n");
    imprime(arvore, 1);

    TABB *maiorElem = maior(arvore);
    printf("O maior elemento é %d\n", maiorElem->info);

    TABB *menorElem = menor(arvore);
    printf("O menor elemento é %d\n", menorElem->info);

    return 0;
}
