#include "arvoreBinaria.c"

/* EXE5 */
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
    TAB *arvoreA = criaArvore(0);
    printf("ArvoreA\n");
    imprime(arvoreA, 1);

    TAB *arvoreB = criaArvore(2);
    printf("\nArvoreB\n");
    imprime(arvoreB, 1);

    printf("\n5. int igual (TAB* a1, TAB* a2)\n");
    printf("ArvoreA eh igual a ArvoreB?\n> %d\n", igual(arvoreA, arvoreB));
    printf("ArvoreA eh igual a ArvoreA?\n> %d\n", igual(arvoreA, arvoreA));

    return 0;
}