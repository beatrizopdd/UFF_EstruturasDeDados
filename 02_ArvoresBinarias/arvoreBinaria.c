#include <stdlib.h>
#include <stdio.h>

typedef struct ab {
    int info;
    struct ab *esq, *dir;
} TAB;

TAB *criaFolha(int info) {
    TAB *nova = (TAB*) malloc(sizeof(TAB));
    nova->info = info;
    nova->esq = NULL;
    nova->dir = NULL;
    return nova;
}

void imprime(TAB *arvore, int tab) {
    if (arvore != NULL) {
        imprime(arvore->dir, tab + 3);

        for (int i = 0; i < tab; i++)
            printf(" ");
        printf("%d\n", arvore->info);

        imprime(arvore->esq, tab + 3);
    }
}

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

/* raiz - esquerda - direita */
void camPreOrdem(TAB *arvore) {
    if (arvore != NULL) {
        printf("%d ", arvore->info);
        camPreOrdem(arvore->esq);
        camPreOrdem(arvore->dir);
    }
}

/* esquerda - raiz - direita */
void camSimetrico(TAB *arvore) {
    if (arvore != NULL) {
        camSimetrico(arvore->esq);
        printf("%d ", arvore->info);
        camSimetrico(arvore->dir);
    }
}

/* esquerda - direita - raiz */
void camPosOrdem(TAB *arvore) {
    if (arvore != NULL) {
        camPosOrdem(arvore->esq);
        camPosOrdem(arvore->dir);
        printf("%d ", arvore->info);
    }
}

/* por nível - esquerda - direita */
void camLargura(TAB *arvore);

int main() {
    TAB *arvore = criaFolha(1);
    arvore->esq = criaFolha(21);
    arvore->esq->esq = criaFolha(31);
    arvore->esq->dir = criaFolha(32);
    arvore->dir = criaFolha(22);
    arvore->dir->esq = criaFolha(33);
    arvore->dir->dir = criaFolha(34);

    TAB *arvoreC = copia(arvore);
    TAB *arvoreE = espelho(arvore);

    printf("Original\n");
    imprime(arvore, 1);

    printf("\nCopia\n");
    imprime(arvoreC, 1);

    printf("\nEspelho\n");
    imprime(arvoreE, 1);

    printf("\nOriginal == Copia? %d", igual(arvore, arvoreC));
    printf("\nOriginal == Espelho? %d\n", igual(arvore, arvoreE));

    printf("\nPRE-ORDEM\n");
    camPreOrdem(arvore);
    printf("\n");

    printf("\nPOS-ORDEM\n");
    camPosOrdem(arvore);
    printf("\n");

    printf("\nSIMETRICO\n");
    camSimetrico(arvore);
    printf("\n");

    return 0;
}