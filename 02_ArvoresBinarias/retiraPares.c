#include "arvoreBinaria.c"

/* EXE6 */
TAB *retira_pares(TAB* arv) {

    if (arv != NULL) {
        arv->esq = retira_pares(arv->esq);
        arv->dir = retira_pares(arv->dir);

        if (arv->info % 2 == 0)
            arv->info = 0;
        return arv;
    }

    return NULL;
}

int main() {
    TAB *arvore = criaArvore(0);

    printf("Original\n");
    imprime(arvore, 1);

    TAB *arvoreI = retira_pares(arvore);
    printf("\n6. TAB *retira_pares(TAB* arv)\n");
    imprime(arvoreI, 1);
    return 0;
}