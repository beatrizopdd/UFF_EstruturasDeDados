#include <limits.h>
#include <stdio.h>

#include "arquivosTXT/treino2411/cliente.c"
#include "arquivosTXT/treino2411/compartimento_hash.c"

#define M 7

void imprime_arquivos(char *nome_arquivo_hash, char *nome_arquivo_dados) {
    //Imprime arquivo de hash
    printf("TABELA HASH:\n");
    imprime_arquivo_hash(nome_arquivo_hash);

    //Imprime arquivo de dados
    printf("\nDADOS:\n");
    imprime_arquivo_dados(nome_arquivo_dados);
}

/* Executa busca em Arquivos por Encadeamento Exterior (Hash)
 * Assumir que ponteiro para proximo noh eh igual a -1 quando nao houver proximo noh
 * Ponteiros são lógicos (é preciso multiplicar pelo tamanho do registro para calcular o valor do deslocamento
 * Use a função tamanho_compartimento() e tamanho_cliente() dependendo do arquivo que está sendo manipulado
 *
 * Parametros:
 * cod_cli: chave do cliente que esta sendo buscado
 * nome_arquivo_hash: nome do arquivo que contem a tabela hash
 * nome_arquivo_dados: nome do arquivo onde os dados estao armazenados
 * m: tamanho da tabela hash (a função de hash é h(x) = x mod m
 *
 * Retorna o endereco (lógico) onde o cliente foi encontrado, ou -1 se nao for encontrado
 */
int busca(int cod_cli, char *nome_arquivo_hash, char *nome_arquivo_dados, int m) {

    FILE *hash = fopen(nome_arquivo_hash, "r");
    FILE *clientes = fopen(nome_arquivo_dados, "r");

    TCompartimento *inicio;
    TCliente *cliente;

    int Hx = (cod_cli % m) * tamanho_compartimento();
    fseek(hash, Hx, SEEK_SET);
    inicio = le_compartimento(hash);

    int endereco = inicio->prox;

    while (endereco != -1) {
        fseek(clientes, endereco * tamanho_cliente(), SEEK_SET);
        cliente = le_cliente(clientes);
        imprime_cliente(cliente);
        if (cliente->cod == cod_cli && cliente->ocupado == 1)
            break;
        endereco = cliente->prox;
    }

    fclose(hash);
    fclose(clientes);

    return endereco;
}

int main() {
    /* Essa função gera a saída que é usada no teste do run.codes. Ela NÃO DEVE SER MODIFICADA */
    int cod;
    int pont;

    //Imprime arquivos de entrada
    //imprime_arquivos("00_GithubClassroom/arquivosTXT/treino2411/tabHash.dat", "00_GithubClassroom/arquivosTXT/treino2411/clientes.dat");

    //le chave a ser buscada
    scanf("%d", &cod);
    printf("REGISTROS ACESSADOS:\n");
    pont = busca(cod, "00_GithubClassroom/arquivosTXT/treino2411/tabHash.dat", "00_GithubClassroom/arquivosTXT/treino2411/clientes.dat", M);

    //Imprime resultado da função
    printf("RESULTADO: %d", pont);
}