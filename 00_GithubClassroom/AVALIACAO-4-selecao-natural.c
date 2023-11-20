#include "arquivosTXT/cliente.c"

#include <limits.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

typedef struct vetor {
    TCliente *cli;
} TVet;

void imprime_arquivo(char *nome) {
    FILE *arq; //declara ponteiro para arquivo
    // abre arquivo para leitura
    arq = fopen(nome, "r");
    if (arq != NULL) {// checa se não deu erro na abertura do arquivo
        char linha[150];
        fgets(linha, 150, arq);
        while (!feof(arq)) {//testa se chegou ao final do arquivo
            printf("%s", linha);
            fgets(linha, 150, arq);
        }
        fclose(arq); //fecha arquivo
    } else printf("Erro ao abrir arquivo\n");
}

char *gera_nome_particao(int num_part) {
    char *nome_particao = (char *) malloc(sizeof(char[10]));
    char num_particao[10];

    strcpy(nome_particao, "00_GithubClassroom/arquivosTXT/av4Particoes/p");
    sprintf(num_particao, "%d", num_part);
    strcat(nome_particao, num_particao);
    strcat(nome_particao, ".txt");

    return nome_particao;
}

// NÃO SUBMETIDA
int selecao_natural(char *nome_arquivo_entrada, int tam_memoria) {

    FILE *arq = fopen(nome_arquivo_entrada, "r");

    FILE *particao = NULL;
    int partQTD = 0;
    int FDA = 0; // fim do arquivo

    TCliente *reservatorio[tam_memoria];
    int iR = 0;

    // Ler M registros do arquivo para a memória
    TCliente *memoria[tam_memoria];
    for (int i = 0; i < tam_memoria; i++) {
        memoria[i] = le_cliente(arq);
        reservatorio[i] = NULL;
    }

    while (FDA == 0) {
        // abrir nova partição de saída
        if (particao == NULL)
            particao = fopen(gera_nome_particao(++partQTD), "w");

        // voltar ao passo 2
        // Selecionar, no array em memória, o registro com menor chave
        TCliente *menorC = NULL;
        int menorI = -1;
        for (int i = 0; i < tam_memoria; i++) {
            if (memoria[i] != NULL && (menorC == NULL || memoria[i]->cod_cliente < menorC->cod_cliente)) {
                menorC = memoria[i];
                menorI = i;
            }
        }

        // Gravar o registro na partição de saída
        if (menorC != NULL) {
            salva_cliente(menorC, particao);

            // Substituir, no array em memória, o registro r pelo próximo registro do arquivo de entrada
            TCliente *substituicao = NULL;
            // Caso a chave deste último seja menor do que a chave recém gravada, gravá-lo no reservatório e substituir, no array em memória, o registro r pelo próximo registro do arquivo de entrada
            while (iR < tam_memoria) {
                substituicao = le_cliente(arq);
                if (substituicao != NULL && substituicao->cod_cliente < menorC->cod_cliente) {
                    reservatorio[iR++] = substituicao;
                    substituicao = NULL;
                } else
                    break;
            }

            memoria[menorI] = substituicao;

        // Caso ainda exista espaço livre no reservatório, voltar ao passo 2

        // Caso contrário:
        // Não existe menor elemento na memória mas ainda tenha coisa no reservatório
        } else if (menorC == NULL && iR > 0) {

            // fechar a partição de saída
            fclose(particao);
            particao = NULL;

            // copiar os registros do reservatório para o array em memória e esvaziar o reservatório
            for (int i = 0; i < tam_memoria; i++) {
                memoria[i] = reservatorio[i];
                reservatorio[i] = NULL;
            }
            iR = 0;

            // Não existe menor elemento na memória e não tem coisa no reservatório
        } else {
            fclose(particao);
            FDA = 1;
        }

    }

    return partQTD;
}

int main() {
    int tam_memoria;
    scanf("%d", &tam_memoria);
    int num_part = selecao_natural("00_GithubClassroom/arquivosTXT/entrada.txt", tam_memoria);
    for (int i = 1; i < num_part+1; i++) {
        printf("*** %s\n", gera_nome_particao(i));
        imprime_arquivo(gera_nome_particao(i));
    }
}