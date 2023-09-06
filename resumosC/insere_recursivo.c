#include <stdio.h>
#include <stdlib.h>

/* criação do tipo estruturado */
typedef struct listaEncadeada {
    int info;
    struct listaEncadeada *prox;
} TLista;

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

    TLista *listaR;
    int numero;

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