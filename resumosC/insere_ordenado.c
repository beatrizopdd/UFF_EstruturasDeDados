#include <stdio.h>
#include <stdlib.h>

/* criação do tipo estruturado */
typedef struct listaEncadeada {
    int info;
    struct listaEncadeada *prox;
} TLista;

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







int main() {
    int vetor[5] = {5, 98, 4, 24, 1};

    TLista *listaO;
    int numero;

    listaO = (TLista*)malloc(sizeof(TLista));
    listaO->prox = NULL;

    for (int i = 0; i < 5; i++) {
        /*printf("\nDigite um número: ");
        scanf(" %d", &numero);*/

        numero = vetor[i];
        listaO = insere_ordenado(listaO, numero);
    }

    return 0;
}