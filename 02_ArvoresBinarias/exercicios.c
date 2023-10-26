#include <stdlib.h>
#include <stdio.h>

typedef struct ab {
    int info;
    struct ab *esq, *dir;
} TAB;

void imprime(TAB *arvore, int tab) {
    if (arvore != NULL) {
        imprime(arvore->esq, tab + 3);

        for (int i = 0; i < tab; i++)
            printf(" ");
        printf("%d\n", arvore->info);

        imprime(arvore->dir, tab + 3);
    }
}

TAB *criaFolha(int info) {
    TAB *nova = (TAB*) malloc(sizeof(TAB));
    nova->info = info;
    nova->esq = NULL;
    nova->dir = NULL;
    return nova;
}

/* E1 */
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

/* E2 */
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

/* E5 */
int igual(TAB *a1, TAB *a2) {
    if (a1 != NULL && a2 != NULL) {

        if (a1->info == a2->info) {
            if (igual(a1->esq, a2->esq) == 1 && igual(a1->dir, a2->dir) == 1)
                return 1;
            else
                return 0;
        } else
            return 0;

    } else if (a1 == NULL && a2 == NULL)
        return 1;
    else
        return 0;
}

int main() {
    TAB *arvore = criaFolha(1);
    arvore->esq = criaFolha(7);
    arvore->esq->esq = criaFolha(4);
    arvore->esq->dir = criaFolha(6);
    arvore->dir = criaFolha(3);
    arvore->dir->esq = criaFolha(5);
    arvore->dir->dir = criaFolha(2);

    printf("Arvore original\n");
    imprime(arvore, 1);

    TAB *arvoreC = copia(arvore);
    printf("\nArvore copia\n");
    imprime(arvoreC, 1);

    TAB *arvoreE = espelho(arvore);
    printf("\nArvore espelho\n");
    imprime(arvoreE, 1);

    printf("\nOriginal é igual a copia? %d \n", igual(arvore, arvoreC));
    printf("Original é igual a espelho? %d \n", igual(arvore, arvoreE));

    return 0;
}