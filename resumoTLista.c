#include <stdio.h>
#include <stdlib.h>

/* criação do tipo estruturado */
typedef struct listaEncadeada {
    int info;
    struct listaEncadeada *prox;
} TLista;

TLista *insere_fim(TLista *lista, int numero) {
    TLista *atual = lista, *novo;

    novo = (TLista*)malloc(sizeof(TLista));
    novo->info = numero;
    novo->prox = NULL;

    while (atual->prox != NULL)
        atual = atual->prox;

    atual->prox = novo;
    return lista;
}

TLista *insere_ordenado(TLista *lista, int numero) {
    TLista *atual = lista, *novo;

    novo = (TLista*)malloc(sizeof(TLista));
    novo->info = numero;

    while ((atual->prox != NULL) && (atual->prox->info < numero))
        atual = atual->prox;

    novo->prox = atual->prox;
    atual->prox = novo;
    return lista;
}


void insere_recursivo(TLista *lista, int numero) {

    if (lista->prox == NULL) {
        TLista *novo = (TLista*)malloc(sizeof(TLista));
        novo->info = numero;
        novo->prox = NULL;
        lista->prox = novo;
    } else
        insere_recursivo(lista->prox, numero);

}

int main() {
    int vetor[5] = {5, 98, 4, 24, 1};

    TLista *listaS, *listaO, *listaR;
    int numero;

    listaS = (TLista*)malloc(sizeof(TLista));
    listaS->prox = NULL;

    for (int i = 0; i < 5; i++) {
        /*printf("\nDigite um número: ");
        scanf(" %d", &numero);*/

        numero = vetor[i];
        listaS = insere_fim(listaS, numero);
    }

    listaO = (TLista*)malloc(sizeof(TLista));
    listaO->prox = NULL;

    for (int i = 0; i < 5; i++) {
        /*printf("\nDigite um número: ");
        scanf(" %d", &numero);*/

        numero = vetor[i];
        listaO = insere_ordenado(listaO, numero);
    }

    listaR = (TLista*)malloc(sizeof(TLista));
    listaR->prox = NULL;

    for (int i = 0; i < 5; i++) {
        /*printf("\nDigite um número: ");
        scanf(" %d", &numero);*/

        numero = vetor[i];
        insere_recursivo(listaR, numero);
    }

    return 0;
}