#include <stdio.h>
#include <stdlib.h>

struct noh {
    int info;
    struct noh *prox;
};
typedef struct noh TNoh;

TNoh *criaNoh(int numero) {
    TNoh *novo = (TNoh*)malloc(sizeof(TNoh));
    novo->info = numero;
    novo->prox = NULL;
    return novo;
}

void imprime(TNoh *lista) {
    TNoh *aux = lista;
    while (aux != NULL) {
        printf("%d ", aux->info);
        aux = aux->prox;
    }
}

TNoh *insereFim(TNoh *lista, int numero) {
    if (lista != NULL) {
        TNoh *aux = lista;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = criaNoh(numero);

    } else
        lista = criaNoh(numero);
    return lista;
}

TNoh *insereInicio(TNoh *lista, int numero) {
    TNoh *novo = criaNoh(numero);
    novo->prox = lista;
    return novo;
}

TNoh *insereOrdenado(TNoh *lista, int numero) {
    TNoh *novo = criaNoh(numero);

    if (lista != NULL) {
        TNoh *ant = NULL, *prox = lista;
        while (prox != NULL && prox->info < numero) {
            ant = prox;
            prox = prox->prox;
        }
        novo->prox = prox;
        if (ant == NULL)
            lista = novo;
        else
            ant->prox = novo;

    } else
        lista = novo;

    return lista;
}
int main() {
    int base[5] = {2, 8, 1, 3,10};

    printf("Ordem de original: \n");
    for (int i = 0; i < 5; i++)
        printf("%d ", base[i]);

    TNoh *fila = NULL;
    for (int i = 0; i < 5; i++)
        fila = insereFim(fila, base[i]);

    printf("\n\nFila: \n");
    imprime(fila);

    TNoh *pilha = NULL;
    for (int i = 0; i < 5; i++)
        pilha = insereInicio(pilha, base[i]);

    printf("\n\nPilha: \n");
    imprime(pilha);

    TNoh *ordenada = NULL;
    for (int i = 0; i < 5; i++)
        ordenada = insereOrdenado(ordenada, base[i]);

    printf("\n\nOrdenada: \n");
    imprime(ordenada);

    return 0;
}