#include "arvoreBinaria.c"

/* EXE3 */
TAB *maior(TAB *a) {
    if (a != NULL) {
        TAB *mE = maior(a->esq);
        TAB *mD = maior(a->dir);

        if ((mE == NULL && mD == NULL) || (mE->info < a->info && mD->info < a->info))
            return a;
        if ((mE != NULL && mD == NULL) || (mE->info > mD->info ))
            return mE;
        if ((mE == NULL && mD != NULL) || (mE->info < mD->info ))
            return mD;
    }
    return a;
}

/* EXE4 */
TAB *menor(TAB *a) {
    if (a != NULL) {
        TAB *mE = menor(a->esq);
        TAB *mD = menor(a->dir);

        if ((mE == NULL && mD == NULL) || (mE->info > a->info && mD->info > a->info))
            return a;
        if ((mE != NULL && mD == NULL) || (mE->info < mD->info ))
            return mE;
        if ((mE == NULL && mD != NULL) || (mE->info > mD->info ))
            return mD;
    }
    return a;
}

int main() {
    TAB *arvore = criaArvore(0);

    imprime(arvore, 1);

    TAB *maiorNoh = maior(arvore);
    printf("\n3. TAB *maior(TAB *a)\n");
    printf("O maior eh o %d\n", maiorNoh->info);

    TAB *menorNoh = menor(arvore);
    printf("\n4. TAB *menor(TAB *a)\n");
    printf("O menor eh o %d\n", menorNoh->info);

    return 0;
}