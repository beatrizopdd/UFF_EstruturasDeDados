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

    strcpy(nome, "07_OrdenacaoArquivos/snParticoes/p");
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

void particiona(FILE *arq, int M) {

    FILE *particao = NULL;
    int partQTD = 0;
    int FDA = 0; // fim do arquivo

    Jogador *reservatorio[M];
    int iR = 0;

    // Ler M registros do arquivo para a memória
    Jogador *memoria[M];
    for (int i = 0; i < M; i++) {
        memoria[i] = leJogador(arq);
        reservatorio[i] = NULL;
    }

    while (FDA == 0) {
        // abrir nova partição de saída
        if (particao == NULL)
            particao = fopen(nomeiaParticao(++partQTD), "w");

        // voltar ao passo 2
        // Selecionar, no array em memória, o registro com menor chave
        Jogador *menorJ = NULL;
        int menorI = -1;
        for (int i = 0; i < M; i++) {
            if (memoria[i] != NULL && (menorJ == NULL || memoria[i]->numero < menorJ->numero)) {
                menorJ = memoria[i];
                menorI = i;
            }
        }

        // Gravar o registro na partição de saída
        if (menorJ != NULL) {
            escreveJogador(particao, menorJ);

            // Substituir, no array em memória, o registro r pelo próximo registro do arquivo de entrada
            Jogador *substituicao = NULL;
            // Caso a chave deste último seja menor do que a chave recém gravada, gravá-lo no reservatório e substituir, no array em memória, o registro r pelo próximo registro do arquivo de entrada
            while (iR < M) {
                substituicao = leJogador(arq);
                if (substituicao != NULL && substituicao->numero < menorJ->numero) {
                    reservatorio[iR++] = substituicao;
                    substituicao = NULL;
                } else
                    break;
            }
            memoria[menorI] = substituicao;

        // Caso ainda exista espaço livre no reservatório, voltar ao passo 2

        // Caso contrário:
        // Não existe menor elemento na memória mas ainda tenha coisa no reservatório
        } else if (menorJ == NULL && iR > 0) {

            // fechar a partição de saída
            fclose(particao);
            particao = NULL;

            // copiar os registros do reservatório para o array em memória e esvaziar o reservatório
            for (int i = 0; i < M; i++) {
                memoria[i] = reservatorio[i];
                reservatorio[i] = NULL;
            }
            iR = 0;

        // Não existe menor elemento na memória e não tem coisa no reservatório
        } else{
            fclose(particao);
            FDA = 1;
        }
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