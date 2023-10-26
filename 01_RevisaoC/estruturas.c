#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct canino {
    char sexo;
    int idade;
    char nome[50];
} Cachorro;

int main() {
    char sexos[5] = {'M', 'M', 'F', 'M', 'F'};
    int idades[5] = {2, 8, 1, 3,10};
    char nomes[5][20] = {"bolinha", "snoopy", "belinha", "cao", "luna"};
    Cachorro *adocao[5];

    for (int i = 0; i < 5; i++) {
        Cachorro *novo = (Cachorro*)malloc(sizeof(Cachorro));
        novo->sexo = sexos[i];
        novo->idade = idades[i];
        strcpy(novo->nome, nomes[i]);
        adocao[i] = novo;
    }

    printf("\nLista de machos:\n");
    for (int i = 0; i < 5; i++)  {
        Cachorro aux = *(adocao[i]);
        if (aux.sexo == 'M')
            printf("%s, %d anos\n", aux.nome, aux.idade);
    }

    printf("\nLista de femeas:\n");
    for (int i = 0; i < 5; i++)
        if (adocao[i]->sexo == 'F')
            printf("%s, %d anos\n", adocao[i]->nome, adocao[i]->idade);

    for (int i = 0; i < 5; i++)
        free(adocao[i]);

    return 0;
}
