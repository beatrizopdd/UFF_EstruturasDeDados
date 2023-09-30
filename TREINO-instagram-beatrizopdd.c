#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct vizinho {
    char nome[10];
    struct vizinho *prox;
} TVizinho;

typedef struct grafo {
    char nome[10];
    int idade;
    TVizinho *prim_vizinho;
    struct grafo *prox;
} TGrafo;

TGrafo *insere_vertice(TGrafo *g, char *nome, int idade) {
    TGrafo *vertice = (TGrafo *) malloc(sizeof(TGrafo));
    strcpy(vertice->nome, nome);
    vertice->idade = idade;
    vertice->prox = g;
    vertice->prim_vizinho = NULL;
    return vertice;
}

TGrafo *busca_vertice(TGrafo *vertice, char *nome) {
    while ((vertice != NULL) && (strcmp(vertice->nome, nome) != 0)) {
        vertice = vertice->prox;
    }
    return vertice;
}

TVizinho *busca_vizinho(TVizinho *vizinho, char *nome) {
    while ((vizinho != NULL) && (strcmp(vizinho->nome, nome) != 0)) {
        vizinho = vizinho->prox;
    }
    return vizinho;
}

void insere_aresta(TGrafo *g, char *nome_origem, char *nome_destino) {
    TGrafo *vertice = busca_vertice(g, nome_origem);
    TVizinho *vizinho = (TVizinho *) malloc(sizeof(TVizinho));
    strcpy(vizinho->nome, nome_destino);
    vizinho->prox = vertice->prim_vizinho;
    vertice->prim_vizinho = vizinho;
}

void imprime(TGrafo *vertice) {
    while (vertice != NULL) {
        printf("Pessoa: %s - %d anos\n", vertice->nome, vertice->idade);
        printf("Segue: ");
        TVizinho *vizinho = vertice->prim_vizinho;
        while (vizinho != NULL) {
            printf("%s ", vizinho->nome);
            vizinho = vizinho->prox;
        }
        printf("\n\n");
        vertice = vertice->prox;
    }
}

int numero_seguidos(TGrafo *g, char *nome) {
    TGrafo *usuario = busca_vertice(g, nome);
    int qtd = 0;

    if (usuario != NULL) {
        TVizinho *seguidor = usuario->prim_vizinho;

        while (seguidor != NULL) {
            qtd++;
            seguidor = seguidor->prox;
        }
    }

    return qtd;
}

int seguidores(TGrafo *g, char *nome, int imprime) {
    TGrafo *usuario = g;
    TVizinho *seguidores;
    int qtd = 0;

    while (usuario != NULL) {
        if (strcmp(usuario->nome, nome) != 0) {
            seguidores = usuario->prim_vizinho;
            if (busca_vizinho(seguidores, nome) != NULL) {
                qtd++;
                if (imprime == 1)
                    printf("%s ", usuario->nome);
            }
        }
        usuario = usuario->prox;
    }

    if (imprime == 1)
        printf("\n");

    return qtd;
}

TGrafo *mais_popular(TGrafo *g) {
    TGrafo *popular = NULL, *aux = g;
    int maior = 0, qtd;

    while (aux != NULL) {
        qtd = seguidores(g, aux->nome, 0);
        if (qtd > maior) {
            maior = qtd;
            popular = aux;
        }
        aux = aux->prox;
    }

    return popular;
}

int segue_mais_velho(TGrafo *g, int imprime) {
    TGrafo *auxU = g, *infoV;
    TVizinho *auxV;
    int qtd = 0;

    while (auxU != NULL) {
        auxV = auxU->prim_vizinho;
        int seguidos = numero_seguidos(g, auxU->nome);
        int maisVelhos = 0;

        while (auxV != NULL) {
            infoV = busca_vertice(g, auxV->nome);
            if (infoV->idade > auxU->idade)
                maisVelhos++;
            else
                break;
            auxV = auxV->prox;
        }

        if (seguidos == maisVelhos && seguidos != 0) {
            qtd++;
            if (imprime == 1)
                printf("%s ", auxU->nome);
        }
        auxU = auxU->prox;
    }
    if (imprime == 1)
        printf("\n");

    return qtd;
}

void libera_vizinho(TVizinho *vizinho) {
    if (vizinho != NULL) {
        libera_vizinho(vizinho->prox);
        free(vizinho);
    }
}

void libera_vertice(TGrafo *vertice) {
    if (vertice != NULL) {
        libera_vizinho(vertice->prim_vizinho);
        libera_vertice(vertice->prox);
        free(vertice);
    }
}

int main() {
    /* A função main lê os dados de entrada, cria o grafo e chama as funções solicitadas no problema
    * depois imprime os resultados solicitados
    * ELA NÃO DEVE SER MODIFICADA
    * */
    int num_vertices, num_arestas;
    char nome[30];
    char origem[30], destino[30];
    char l[100];
    char delimitador[] = "-";
    char *ptr;
    int idade;
    int i;
    TGrafo *g = NULL;

    //le numero de vertices
    scanf("%d", &num_vertices);
    //le e cria os vertices
    for (i = 0; i < num_vertices; i++) {
        scanf("%s", l);
        //quebra a string de entrada
        ptr = strtok(l, delimitador);
        strcpy(nome,ptr);
        //printf("%s", nome);
        ptr = strtok(NULL, delimitador);
        idade = atoi(ptr);
        g = insere_vertice(g, nome, idade);
    }

    //Le numero de arestas e depois le os dados de cada aresta
    //Cria as arestas no grafo
    scanf("%d", &num_arestas);
    for (i = 0; i < num_arestas; i++) {
        scanf("%s", l);
        //quebra a string de entrada
        ptr = strtok(l, delimitador);
        strcpy(origem,ptr);
        //printf("%s", nome);
        ptr = strtok(NULL, delimitador);
        strcpy(destino,ptr);
        insere_aresta(g, origem, destino);
    }

    //Le nome de pessoa
    scanf("%s", nome);

    //Encontra o número de seguidos dessa pessoa
    printf("SEGUIDOS por %s: %d\n", nome, numero_seguidos(g, nome));

    //Encontra os seguidores de uma determinada pessoa
    printf("SEGUIDORES de %s:\n", nome);
    seguidores(g, nome, 1);

    TGrafo *p;

    //Encontra mais popular
    p = mais_popular(g);
    printf("MAIS POPULAR: %s\n", p->nome);

    //Encontra as pessoas que seguem apenas pessoas mais velhas
    printf("SEGUEM APENAS PESSOAS MAIS VELHAS:\n");
    segue_mais_velho(g,1);

    libera_vertice(g);
}