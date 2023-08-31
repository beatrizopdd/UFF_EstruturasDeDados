#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Jogador {
	int camisa;
	char nome[30];
	struct Jogador *ante, *prox; 
};
typedef struct Jogador jogador;

jogador* criar_jogador(int camisa, char nome[30]) {

	jogador *novoJ = (jogador*)malloc(sizeof(jogador*));
	
	novoJ->camisa = camisa;
	strcpy(novoJ->nome, nome);
	
	return novoJ;
}

void preencher_lista(jogador *cabeca, int camisa, char nome[30]) {

	jogador *novoJ = criar_jogador(camisa, nome);
	jogador *aux = cabeca;
	
	while ((aux->prox != NULL) && (aux->camisa < camisa))
		aux = aux->prox;
	
	/* lista vazia OU maior que o atual*/
	if ((aux->ante == NULL) && (aux->prox == NULL) || (aux->camisa < camisa)) {
	
		novoJ->ante = aux;
		novoJ->prox = aux->prox;
		aux->prox = novoJ;
			
	/* menor que o atual*/
	} else if (aux->camisa > camisa) {
		novoJ->ante = aux->ante;
		novoJ->prox = aux;
		aux->ante = novoJ;
	}

}

void copiar_ordenado() {

	FILE *original = fopen("elenco_flamengo.txt", "r");
	FILE *ordenado = fopen("elenco_ordenado.txt", "a+");
	
	jogador *Flamengo;
	Flamengo->ante = NULL;
	Flamengo->prox = NULL;
	
	int camisa, indc = 0;
	char nome[30], cabecalho[30];
	
	while (indc < 33) {
	
		if ((indc != 0) || (indc != 4) || (indc != 10) || (indc != 14) || (indc != 17) || (indc != 22) || (indc != 17)) {
			
			fscanf(original, "%d - %[^\n]\n", &camisa, nome);			
			preencher_lista(Flamengo, camisa, nome);
			
		} else
			fscanf(original, "%s\n", cabecalho);

		indc++;
	}
	
	while (Flamengo != NULL) {
		fprintf(ordenado, "%d - %s\n", Flamengo->camisa, Flamengo->nome);
		Flamengo = Flamengo->prox;
	}
	
	fclose(original);
	fclose(ordenado);

}

int main() {

	copiar_ordenado();

	return 0;
}
