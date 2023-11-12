#include "grafo.c"

/* EXE4 */
int iguais(TGrafo *g1, TGrafo *g2) {
    TGrafo *auxG1 = g1;
    TGrafo *auxG2 = g2;

    while (auxG1 != NULL && auxG2 != NULL) {
        if (auxG1->id != auxG2->id)
            return 0;

        TVizinho *auxV1 = auxG1->primeiro_vizinho;
        TVizinho *auxV2 = auxG2->primeiro_vizinho;
        while (auxV1 != NULL && auxV2 != NULL) {
            if (auxV1->id_vizinho != auxV2->id_vizinho)
                return 0;
            auxV1 = auxV1->prox;
            auxV2 = auxV2->prox;
        }

        if ((auxV1 == NULL && auxV2 != NULL) || (auxV1 != NULL && auxV2 == NULL))
            return 0;

        auxG1 = auxG1->prox;
        auxG2 = auxG2->prox;
    }

    if ((auxG1 == NULL && auxG2 != NULL) || (auxG1 != NULL && auxG2 == NULL))
        return 0;

    return 1;
}

int main() {
    TGrafo *grafoA = NULL, *grafoB = NULL;
    int vertices[] = {1, 2, 3,4};
    int arestasA[5][2] = {{1,2}, {1,3}, {2,3}, {2,4}, {3,4}};
    int arestasB[4][2] = {{1,2}, {2,4}, {3,1}, {4,3}};

    for (int i = 0; i < 4; ++i) {
        grafoA = insereGrafo(grafoA, vertices[i]);
        grafoB = insereGrafo(grafoB, vertices[i]);
    }

    for (int i = 0; i < 5; ++i)
        grafoA = insereVizinho(grafoA, arestasA[i][0], arestasA[i][1]);

    for (int i = 0; i < 4; ++i)
        grafoB = insereVizinho(grafoB, arestasB[i][0], arestasB[i][1]);

    printf("\nGRAFO A:");
    imprime(grafoA);

    printf("\n\nGRAFO B:");
    imprime(grafoB);

    printf("\n\n4. int iguais(TGrafo *g1, TGrafo *g2)");
    printf("\nGrafo A eh igual a Grafo A = %d", iguais(grafoA, grafoA));
    printf("\nGrafo A eh igual a Grafo B = %d", iguais(grafoA, grafoB));
    printf("\nGrafo B eh igual a Grafo B = %d", iguais(grafoB, grafoB));
    return 0;
}