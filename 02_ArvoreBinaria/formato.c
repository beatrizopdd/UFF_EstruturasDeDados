#include "arvoreBinaria.c"

/* EXE10 */
int zz(TAB *a) {
    TAB *aux = a;
    while(aux != NULL) {
        if (aux->esq != NULL && aux->dir != NULL)
            return 0;
        else if (aux->esq != NULL && aux->dir == NULL)
            aux = aux->esq;
        else if (aux->esq == NULL && aux->dir != NULL)
            aux = aux->dir;
        else if (aux->esq == NULL && aux->dir == NULL)
            aux = NULL;
    }
    return 1;
}

/* EXE11 */
int estbin(TAB *a) {
    if (a != NULL) {
        if ((a->esq == NULL && a->dir == NULL) || (a->esq != NULL && a->dir != NULL))
            return (estbin(a->esq) && estbin(a->dir));
        return 0;
    }
    return 1;
}

/* EXE12 */
int mesmos_nos(TAB *a1, TAB *a2) {
    if ((a1 == NULL && a2 != NULL) && (a1 != NULL && a2 == NULL))
        return 0;

    if (a1 != NULL && a2 != NULL) {
        if (a1->info == a2->info)
            return (mesmos_nos(a1->esq, a2->esq) && mesmos_nos(a1->dir, a2->dir));
        return 0;
    }

    return 1;
}

int main() {
    TAB *binariaCheia = criaArvore(1);

    TAB *estritamenteBinaria = criaFolha(10);
    estritamenteBinaria->esq = criaFolha(11);
    estritamenteBinaria->dir = criaFolha(12);
    estritamenteBinaria->dir->esq = criaFolha(13);
    estritamenteBinaria->dir->esq->esq = criaFolha(15);
    estritamenteBinaria->dir->esq->dir = criaFolha(16);
    estritamenteBinaria->dir->dir = criaFolha(14);

    TAB *ziguezague = criaFolha(5);
    ziguezague->dir = criaFolha(6);
    ziguezague->dir->esq = criaFolha(7);
    ziguezague->dir->esq->dir = criaFolha(8);

    printf("\nBinaria cheia\n");
    imprime(binariaCheia, 1);
    printf("\nEstritamente binaria\n");
    imprime(estritamenteBinaria, 1);
    printf("\nZigue zague\n");
    imprime(ziguezague, 1);

    printf("\n\n10. int zz(TAB *a)");
    printf("\nBinaria cheia: %d", zz(binariaCheia));
    printf("\nEstritamente binaria: %d", zz(estritamenteBinaria));
    printf("\nZigue zague: %d", zz(ziguezague));

    printf("\n\n11. int estbin(TAB *a)");
    printf("\nBinaria cheia: %d", estbin(binariaCheia));
    printf("\nEstritamente binaria: %d", estbin(estritamenteBinaria));
    printf("\nZigue zague: %d", estbin(ziguezague));

    printf("\n\n12. mesmos_nos(TAB *a1, TAB *a2)");
    printf("\nBinaria cheia e Estritamente binaria: %d", mesmos_nos(binariaCheia, estritamenteBinaria));
    printf("\nBinaria cheia e Zigue zague: %d", mesmos_nos(binariaCheia, ziguezague));
    printf("\nBinaria cheia e Binaria cheia: %d", mesmos_nos(binariaCheia, binariaCheia));

    return 0;
}