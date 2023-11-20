#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// estranhamente só roda no debug

typedef struct jogador {
    int numero;
    char nome[200];
} Jogador;

typedef struct lista {
    int congelado;
    Jogador *info;
    struct lista *prox;
} LE;

LE *insere(LE *lista, Jogador *novo) {
    LE *novoNoh = (LE*) malloc(sizeof(LE));
    novoNoh->congelado = 0;
    novoNoh->info = novo;
    novoNoh->prox = NULL;

    if (lista != NULL) {
        LE *aux =  lista;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novoNoh;
    } else
        lista = novoNoh;

    return lista;
}

char *nomeiaParticao(int valor) {
    char *nome = (char*)malloc(sizeof(char[10]));
    char numero[10];

    strcpy(nome, "07_OrdenacaoArquivos/scsParticoes/p");
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

    // Ler M registros do arquivo para a memória
    LE *memoria = NULL;
    for (int i = 0; i < M; i++)
        memoria = insere(memoria, leJogador(arq));

    while (FDA < M) {
        // abrir nova partição de saída
        if (particao == NULL)
            particao = fopen(nomeiaParticao(++partQTD), "w");
        // voltar ao passo 2

        // Selecionar, no array em memória, o registro r com menor chave
        LE *aux = memoria;
        LE *menor = NULL;
        for (int j = 0; j < M; j++) {
            if ((aux->info != NULL && aux->congelado == 0) && (menor == NULL || aux->info->numero < menor->info->numero))
                menor = aux;
            aux = aux->prox;
        }

        // Gravar o registro na partição de saída
        if (menor != NULL) {
            escreveJogador(particao, menor->info);

            // Substituir, no array em memória, o registro r pelo próximo registro do arquivo de entrada
            Jogador *substituicao = leJogador(arq);

            // caso tenham acabado as opções
            if (substituicao == NULL)
                FDA++;

            // Caso a chave deste último seja menor do que a chave recém gravada, considerá-lo congelado e ignorá-lo no restante do processamento
            else if (substituicao->numero < menor->info->numero)
                menor->congelado = 1;

            menor->info = substituicao;
        // Caso existam em memória registros não congelados, voltar ao passo 2

        // Caso contrário:
        } else {
            // fechar a partição de saída
            fclose(particao);
            // descongelar os registros congelados
            aux = memoria;
            while (aux != NULL) {
                aux->congelado = 0;
                aux = aux->prox;
            }
            particao = NULL;
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