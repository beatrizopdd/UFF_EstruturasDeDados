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







int main() {
    int vetor[5] = {5, 98, 4, 24, 1};

    TLista *listaF;
    int numero;

    listaF = (TLista*)malloc(sizeof(TLista));
    listaF->prox = NULL;

    for (int i = 0; i < 5; i++) {
        /*printf("\nDigite um número: ");
        scanf(" %d", &numero);*/

        numero = vetor[i];
        listaF = insere_fim(listaF, numero);
    }

    return 0;
}