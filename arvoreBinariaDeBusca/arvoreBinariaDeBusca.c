#include "TABB.h"

int main() {
    TABB *arvoreA = NULL;
    TABB *arvoreB = NULL;
    TABB *arvoreC = NULL;

    int gabaritoA[4] = {500, 800, 300,400};
    int gabaritoB[9] = {25, 22, 40, 30, 45, 27, 20, 21, 48};
    int gabaritoC[9] = {40, 25, 20, 30, 45, 27, 22, 21, 48};

    for (int i = 0; i < 4; i++)
        insereNovo(arvoreA, gabaritoA[i], gabaritoA[i]);
    for (int i = 0; i < 9; i++)
        insereNovo(arvoreB, gabaritoB[i], gabaritoB[i]);
    for (int i = 0; i < 9; i++)
        insereNovo(arvoreC, gabaritoC[i], gabaritoC[i]);

    // 500 - 300 - 400 - 800
    imprimeArvore(arvoreA, 1);
    printf("\n");

    // 25 - 22 - 20 - 21 - 40 - 30 - 27 - 45 - 48
    imprimeArvore(arvoreB, 1);
    printf("\n");

    // 40 - 25 - 20 - 22 - 21 - 30 - 27 - 45 -48
    imprimeArvore(arvoreC, 1);

    return 0;
}