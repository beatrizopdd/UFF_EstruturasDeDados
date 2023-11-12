#include <stdlib.h>
#include <stdio.h>

typedef struct arvore {
    int info;
    int cor;
    struct arvore *esq, *dir;
} TAB;

TAB *criaFolha(int info) {
    TAB *nova = (TAB*) malloc(sizeof(TAB));
    nova->info = info;
    nova->cor = -1;
    nova->esq = NULL;
    nova->dir = NULL;
    return nova;
}

void imprime(TAB *arvore, int tab) {
    if (arvore != NULL) {
        imprime(arvore->dir, tab + 3);

        for (int i = 0; i < tab; i++)
            printf("-");
        printf("%d [%d]\n", arvore->info, arvore->cor);

        imprime(arvore->esq, tab + 3);
    }
}

/* EXE7 */
void colore(TAB *a) {
    if (a != NULL) {
        if (a->cor == -1) {
            a->cor = 0;
            if (a->esq != NULL)
                a->esq->cor = 1;
            if (a->dir != NULL)
                a->dir->cor = 1;
        }
        colore(a->esq);
        colore(a->dir);
    }
}

int main() {
    TAB *arvore = criaFolha(2);
    arvore->esq = criaFolha(4);
    arvore->esq->esq = criaFolha(8);
    arvore->esq->esq->esq = criaFolha(16);
    arvore->esq->esq->dir = criaFolha(18);
    arvore->esq->dir = criaFolha(10);
    arvore->esq->dir->esq = criaFolha(20);
    arvore->esq->dir->dir = criaFolha(22);
    arvore->dir = criaFolha(6);
    arvore->dir->esq = criaFolha(12);
    arvore->dir->esq->esq = criaFolha(24);
    arvore->dir->esq->dir = criaFolha(26);
    arvore->dir->dir = criaFolha(14);
    arvore->dir->dir->esq = criaFolha(28);
    arvore->dir->dir->dir = criaFolha(30);

    printf("Original\n");
    imprime(arvore, 1);

    colore(arvore);
    printf("\n7. void colore (TAB* arv)\n");
    imprime(arvore, 1);

    return 0;
}