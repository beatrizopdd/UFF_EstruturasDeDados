#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// estranhamente só roda no debug

typedef struct jogador {
    int numero;
    char nome[200];
} Jogador;

char *nomeiaParticao(int valor) {
    char *nome = (char*)malloc(sizeof(char[10]));
    char numero[10];

    strcpy(nome, "07_OrdenacaoArquivos/ciParticoes/p");
    sprintf(numero, "%d", valor);
    strcat(nome, numero);
    strcat(nome, ".txt");

    return nome;
}

Jogador *leJogador(FILE *arq) {
    char linha[300];
    if (fgets(linha, 300, arq) == NULL)
        return NULL;

    Jogador *novo = (Jogador*)malloc(sizeof(Jogador));
    char *palavra = strtok(linha, " ");
    novo->numero = atoi(palavra);
    palavra = strtok(NULL, " "); //descarta o " - "
    palavra = strtok(NULL, "\n");
    strcpy(novo->nome, palavra);

    return novo;
}

void escreveJogador(FILE *arq, Jogador *jogador) {
    fprintf(arq, "%d ", jogador->numero);
    fprintf(arq, "- ");
    fprintf(arq, "%s ", jogador->nome);
    fprintf(arq, "\n");
}

void insertionSort(int M, Jogador **memoria) {
    for (int i = 1; i < M; i++) {
        Jogador *aux = memoria[i];
        int j = i-1;
        while (j >= 0 && memoria[j]->numero > aux->numero) {
            memoria[j+1] = memoria[j];
            --j;
        }
        memoria[j+1] = aux;
    }
}

void particiona(FILE *arq, int M) {

    int lidos = M;
    int partQTD = 0;

    while (lidos == M) {

        // leitura de M registros para a memória
        Jogador *memoria[M];
        for (lidos = 0; lidos < M; lidos++) {
            memoria[lidos] = leJogador(arq);
            if (memoria[lidos] == NULL)
                break;
        }

        // ordenação desses registros
        insertionSort(lidos, memoria);

        // gravação desses registros ordenados em uma partição
        FILE *particao = fopen(nomeiaParticao(++partQTD), "w+");
        for (int j = 0; j < lidos; j++)
            escreveJogador(particao, memoria[j]);
        fclose(particao);
    }
}

int main() {
    char *nomeArquivo = "07_OrdenacaoArquivos/arquivosTXT/elenco_flamengo.txt";
    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo != NULL) {
        particiona(arquivo, 5);
    } else
        printf("ERRO ao abrir o arquivo!\n");

    fclose(arquivo);

    return 0;
}