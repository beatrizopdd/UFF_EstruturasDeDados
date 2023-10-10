#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define TAM_NOME 100

typedef struct Departamento {
    int cod_dept;
    int sala;
    char nome[TAM_NOME];
} TDepartamento;

typedef struct Funcionario {
    int cod_func;
    int cod_dept;
    char nome[TAM_NOME];
} TFuncionario;

TFuncionario *le_funcionario(FILE *in)
{
    TFuncionario *func = (TFuncionario *) malloc(sizeof(TFuncionario));
    char linha[150];
    if (fgets (linha, 150, in) == NULL ) {
        free(func);
        return NULL;
    }

    char delimitador[] = ";";
    char *ptr;
    int cod;

    //quebra a linha
    ptr = strtok(linha, delimitador);
    cod = atoi(ptr);
    func->cod_func = cod;
    ptr = strtok(NULL, delimitador);
    cod = atoi(ptr);
    func->cod_dept = cod;
    ptr = strtok(NULL, delimitador);
    strcpy(func->nome, ptr);

    return func;
}

TDepartamento *le_departamento(FILE *in)
{
    TDepartamento *dept = (TDepartamento *) malloc(sizeof(TDepartamento));
    char linha[150];
    if (fgets (linha, 150, in) == NULL ) {
        free(dept);
        return NULL;
    }

    char delimitador[] = ";";
    char *ptr;
    int cod, sala;

    //quebra a linha
    ptr = strtok(linha, delimitador);
    cod = atoi(ptr);
    dept->cod_dept = cod;
    ptr = strtok(NULL, delimitador);
    sala = atoi(ptr);
    dept->sala = sala;
    ptr = strtok(NULL, delimitador);
    strcpy(dept->nome, ptr);

    return dept;
}

void imprime_arquivo(char *name) {
    FILE *arq; //declara ponteiro para arquivo
    // abre arquivo para leitura
    arq = fopen(name, "r");
    if (arq != NULL) {// checa se não deu erro na abertura do arquivo
        char linha[150];
        fgets (linha, 150, arq);
        while (!feof(arq)) {//testa se chegou ao final do arquivo
            printf("%s", linha);
            fgets (linha, 150, arq);
        }
        fclose(arq); //fecha arquivo
    } else printf("Erro ao abrir arquivo\n");
}

void leftOuterJoin(char *nome_arq_dept, char *nome_arq_funcionarios, char *nome_arq_join) {
    FILE *arqF;
    TFuncionario *funcionario;

    FILE *arqD = fopen(nome_arq_dept,  "r");
    TDepartamento *departamento  = le_departamento(arqD);

    FILE *arqJ = fopen(nome_arq_join, "w");
    int controle = 0;

    while (departamento !=  NULL) {

        arqF = fopen(nome_arq_funcionarios, "r");
        funcionario = le_funcionario(arqF);

        while (funcionario != NULL) {
            if (funcionario->cod_dept == departamento->cod_dept) {
                fprintf(arqJ, "%d;%d;%s;", departamento->cod_dept, departamento->sala, departamento->nome);
                fprintf(arqJ, "%d;%s;\n", funcionario->cod_func, funcionario->nome);
                controle = 1;
            }
            funcionario = le_funcionario(arqF);
        }

        if (controle == 0)
            fprintf(arqJ, "%d;%d;%s;0;;\n", departamento->cod_dept, departamento->sala, departamento->nome);
        else
            controle = 0;

        departamento = le_departamento(arqD);
    }

    fclose(arqD);
    fclose(arqF);
    fclose(arqJ);
}

int main() {
    leftOuterJoin("arquivosTXT/departamentos.txt", "arquivosTXT/funcionarios.txt", "arquivosTXT/join.txt");
    imprime_arquivo("join.txt");
}