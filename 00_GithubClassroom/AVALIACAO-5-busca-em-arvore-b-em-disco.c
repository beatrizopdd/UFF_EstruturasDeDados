#include <stdio.h>
#include "arquivosTXT/av5Arquivos/metadados.c"
#include "arquivosTXT/av5Arquivos/no_interno.c"

void imprime_arquivos() {
    int i;
    //Imprime arquivo de metadados
    FILE *arq_m = fopen("arquivosTXT/av5Arquivos/metadados.dat", "rb");
    TMetadados *m = le_metadados(arq_m);
    printf("*** Arquivo de Metadados ***\n");
    imprime_metadados(m);
    fclose(arq_m);

    //Imprime arquivo de índice (nós internos da árvore)
    //A leitura não segue ordem específica -- os nós são lidos na ordem em que foram gravados no arquivo
    FILE *arq_i = fopen("arquivosTXT/av5Arquivos/indice.dat", "rb");
    printf("\n\n*** Arquivo de Indice ***\n");
    i = 0;
    TNoInterno *ni = le_no_interno(m->d, arq_i);
    while (ni != NULL) {
        printf("(((Endereco %d)))\n", i * tamanho_no_interno(m->d));
        imprime_no_interno(m->d, ni);
        ni = le_no_interno(m->d, arq_i);
        i += 1;
    }
    fclose(arq_i);

    //Imprime arquivo de dados (nós folha da árvore)
    //A leitura não segue ordem específica -- os nós são lidos na ordem em que foram gravados no arquivo
    FILE *arq_d = fopen("arquivosTXT/av5Arquivos/clientes.dat", "rb");
    printf("\n*** Arquivo de Dados ***\n");
    i = 0;
    TNoFolha *nf = le_no_folha(m->d, arq_d);
    while (nf != NULL) {
        printf("(((Endereco %d)))\n", i * tamanho_no_folha(m->d));
        imprime_no_folha(m->d, nf);
        nf = le_no_folha(m->d, arq_d);
        i += 1;
    }
    fclose(arq_d);
}

/*
 * Executa busca em Arquivos utilizando Arvore B+
 * Assumir que ponteiros para NULL têm valor -1
 *
 * chave: chave do cliente que esta sendo buscado
 * nome_arquivo_metadados: nome do arquivo binário que contem os metadados
 * nome_arquivo_indice: nome do arquivo binário de indice (que contem os nohs internos da arvore B+)
 * nome_arquivo_dados: nome do arquivo binário de dados (que contem as folhas da arvore B+)
 *
 * Retorna ponteiro para nó em que a chave está ou deveria estar
 */
int busca(int chave, char *nome_arquivo_metadados, char *nome_arquivo_indice, char *nome_arquivo_dados) {

    FILE *nohInterno = fopen(nome_arquivo_indice, "rb");
    FILE *nohFolha = fopen(nome_arquivo_dados, "rb");

    TMetadados *arvore = le_arq_metadados(nome_arquivo_metadados);
    TNoInterno *nohI = le_no_interno(arvore->d, nohInterno);
    TNoFolha *nohF;

    int loc = 0;

    while (nohI != NULL) {

        imprime_no_interno(arvore->d, nohI);

        int i = 0;
        while (chave > nohI->chaves[i] && i < nohI->m - 1)
            i++;

        if (chave < nohI->chaves[i])
            loc = nohI->p[i];
        else if (chave >= nohI->chaves[i])
            loc = nohI->p[i+1];

        if (nohI->aponta_folha == 1)
            nohI = NULL;
        else {
            fseek(nohInterno, loc, SEEK_SET);
            nohI = le_no_interno(arvore->d, nohInterno);
        }
    }

    fclose(nohInterno);

    fseek(nohFolha, loc, SEEK_SET);
    nohF = le_no_folha(arvore->d, nohFolha);
    fclose(nohFolha);

    imprime_no_folha(arvore->d, nohF);

    return loc;
}

int main () {
    //Descomente essa linha de código caso deseje imprimir o conteúdo dos arquivos de entrada para analisar
    //o comportamento da sua implementação

    //imprime_arquivos();

    /* Le chave a ser buscada */
    int chave;

    scanf("%d", &chave);

    //Chama função de busca
    int pont = busca(chave, "arquivosTXT/av5Arquivos/metadados.dat", "arquivosTXT/av5Arquivos/indice.dat", "arquivosTXT/av5Arquivos/clientes.dat");

    //Imprime resultado da função
    printf("RESULTADO DA BUSCA: %d", pont);
}