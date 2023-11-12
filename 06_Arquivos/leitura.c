#include <stdio.h>

void imprimeArquivo(FILE *arquivo) {
    char linha[200];
    while (fscanf(arquivo, "%[^\n]\n", linha) != -1) {
        printf("%s\n", linha);
    }
}

int main() {
    char *nomeArquivo = "06_Arquivos/arquivosTXT/elenco_flamengo.txt";
    FILE *leitor = fopen(nomeArquivo, "r");

    if (leitor != NULL) {
        imprimeArquivo(leitor);
    } else
        printf("\nErro na abertura do arquivo!\n");

    fclose(leitor);

    return 0;
}