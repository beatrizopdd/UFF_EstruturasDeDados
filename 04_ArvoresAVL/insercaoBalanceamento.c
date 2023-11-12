#include "AVL.c"

int altura(TAVL *raiz) {
    if (raiz != NULL) {
        int esquerda = altura(raiz->esq);
        int direita = altura(raiz->dir);
        if (esquerda > direita)
            return (esquerda + 1);
        else
            return (direita + 1);
    } else
        return -1;
}

TAVL *rotacaoD(TAVL *noh) {
    TAVL *substituto = noh->esq;
    noh->esq = substituto->dir;
    substituto->dir = noh;
    return substituto;
}

TAVL *rotacaoE(TAVL *noh) {
    TAVL *substituto = noh->dir;
    noh->dir = substituto->esq;
    substituto->esq = noh;
    return substituto;
}

TAVL *balancear(TAVL *arvore) {
    if (arvore != NULL)  {
        arvore->esq = balancear(arvore->esq);
        arvore->dir = balancear(arvore->dir);

        int fator = altura(arvore->dir) - altura(arvore->esq);

        if (fator == -2) {
            int fEsq = altura(arvore->esq->dir) - altura(arvore->esq->esq);
            if (fEsq == 1)
                arvore->esq = rotacaoE(arvore->esq);
            return rotacaoD(arvore);
        }
        else if (fator == 2) {
            int fDir = altura(arvore->dir->dir) - altura(arvore->dir->esq);
            if (fDir == -1)
                arvore->dir = rotacaoD(arvore->dir);
            return rotacaoE(arvore);
        }
    }
    return arvore;
}

void imprimirBalanceamento(TAVL *arvore, int tab){
    if (arvore != NULL) {

        imprimirBalanceamento(arvore->dir, tab + 3);

        for (int i = 0; i < tab; i++)
            printf("--");

        int b = altura(arvore->dir) - altura(arvore->esq);
        printf("%d (%d) \n", arvore->info, b);

        imprimirBalanceamento(arvore->esq, tab + 3);
    }
}

int main() {
    TAVL *arvore = criaNoh(50);
    int insere[] = {1,64, 12, 18, 66, 38, 95, 58, 59, 70, 68, 39, 62, 7, 60,43, 16, 67, 34, 35};

    printf("\nINSERIR: \n");
    for (int i = 0; i < 20; i++) {
        arvore = inserir(arvore, insere[i]);
        arvore = balancear(arvore);
    }
    imprimirBalanceamento(arvore, 1);
    return 0;
}