#include <stdio.h>

void merge(FILE *arqA, FILE *arqB, FILE *arqC) {

    char linha[500];
    if (fscanf(arqA, "%[^\n]\n", linha) != -1) {
        fprintf(arqC, "%s\n", linha);
        merge(arqB, arqA, arqC);

    } else if (fscanf(arqB, "%[^\n]\n", linha) != -1)
        while (fscanf(arqB, "%[^\n]\n", linha) != -1)
            fprintf(arqC, "%s\n", linha);

}

int main() {
    char *nomeLeitorA = "06_Arquivos/arquivosTXT/hino_vasco.txt";
    char *nomeLeitorB = "06_Arquivos/arquivosTXT/hino_botafogo.txt";
    char *nomeGravador = "06_Arquivos/arquivosTXT/hino_vasfogo.txt";

    FILE *leitorA = fopen(nomeLeitorA, "r");
    FILE *leitorB = fopen(nomeLeitorB, "r");
    FILE *gravador = fopen(nomeGravador, "w");

    if (leitorA != NULL) {
        if (leitorB != NULL) {
            merge(leitorA, leitorB, gravador);
        } else
            printf("\nErro ao abrir o arquivo B!");
    } else
        printf("\nErro ao abrir o arquivo A!");

    fclose(leitorA);
    fclose(leitorB);
    fclose(gravador);

    return 0;
}