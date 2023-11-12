#include "grafo.c"

/* EXE3 */
int testek(TGrafo *g, int k) {
    TGrafo *auxG = g;
    while (auxG != NULL) {
        int qtd = 0;
        TVizinho *auxV = auxG->primeiro_vizinho;
        while (auxV != NULL) {
            qtd++;
            auxV = auxV->prox;
        }
        if (qtd != k)
            return 0;
        auxG = auxG->prox;
    }
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

    printf("\n\n3.  int testek(TGrafo *g, int k)");
    printf("\nGrafo A, grau 0 = %d", testek(grafoA, 0));
    printf("\nGrafo A, grau 1 = %d", testek(grafoA, 1));
    printf("\nGrafo A, grau 2 = %d", testek(grafoA, 2));
    printf("\n\nGrafo B, grau 0 = %d", testek(grafoB, 0));
    printf("\nGrafo B, grau 1 = %d", testek(grafoB, 1));
    printf("\nGrafo B, grau 2 = %d", testek(grafoB, 2));
    return 0;
}