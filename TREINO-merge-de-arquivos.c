#include <stdio.h>

void imprime_arquivo(char *nomeArq){
    FILE *arq; //declara ponteiro para arquivo
    //abre arquivo para leitura
    arq = fopen(nomeArq, "r");
    if (arq != NULL){// checa se não deu erro na abertura do arquivo
        char s[10];
        fscanf(arq, "%s", s);
        while (!feof(arq)) {//testa se chegou ao final do arquivo
            printf("%s\n", s);
            fscanf(arq, "%s", s);
        }
        fclose(arq); //fecha arquivo
    }
    else printf("Erro ao abrir arquivo\n");
}

void merge(char *nomeArq1, char *nomeArq2, char *nomeArqMerge) {
    FILE *arq1 = fopen(nomeArq1, "r");
    FILE *arq2 = fopen(nomeArq2, "r");
    FILE *arqMerge = fopen(nomeArqMerge, "w");

    int num1, num2;
    fscanf(arq1, "%d", &num1);
    fscanf(arq2, "%d", &num2);

    while (!feof(arq1) && !feof(arq2)) {
        if (num1 < num2) {
            fprintf(arqMerge, "%d\n", num1);
            fscanf(arq1, "%d", &num1);

        } else if (num2 < num1) {
            fprintf(arqMerge, "%d\n", num2);
            fscanf(arq2, "%d", &num2);

        } else {
            fprintf(arqMerge, "%d\n", num1);
            fscanf(arq1, "%d", &num1);
            fscanf(arq2, "%d", &num2);
        }
    }

    if (!feof(arq1) && feof(arq2))
        while (!feof(arq1)) {
            fprintf(arqMerge, "%d\n", num1);
            fscanf(arq1, "%d", &num1);
        }
    else if (feof(arq1) && !feof(arq2))
        while (!feof(arq2)) {
            fprintf(arqMerge, "%d\n", num2);
            fscanf(arq2, "%d", &num2);
        }

    fclose(arq1);
    fclose(arq2);
    fclose(arqMerge);
}

int main(int argc, char **argv) {
    merge("arquivosTXT/numeros1.txt", "arquivosTXT/numeros2.txt", "arquivosTXT/merge.txt");
    imprime_arquivo("merge.txt");
}
