#include <stdio.h>
#include <string.h>

void copiar_texto(FILE *texto) {

	FILE *flaflu = fopen("hino_FlaFlu.txt", "a+");
	char linha[100], original[100], resto[50];
	
	while (fscanf(texto, "%[^\n]\n", linha) != -1) {
		
		strcpy(original, linha);
		char *palavra = strtok(linha, " ");
		int tamanhoP = 0, tamanhoL = 0, tamanhoR = 0; 
		
		while (palavra != NULL) {
			
			tamanhoP = strlen(palavra) + 1;
			
			if ((strcmp(palavra, "Fluminense") == 0) || (strcmp(palavra, "Tricolor") == 0)) {
			
				tamanhoR = tamanhoL + tamanhoP - 1;
				strcpy(resto, original+tamanhoR);
								
				if (strcmp(palavra, "Fluminense") == 0) 
					strcpy(original+tamanhoL, "*FLAMENGO*");
				
				if (strcmp(palavra, "Tricolor") == 0)
					strcpy(original+tamanhoL, "FLAMENGO");
			
				strcpy(original+tamanhoR, resto);
			
			}
			
			palavra = strtok(palavra+tamanhoP, " ");
			tamanhoL += tamanhoP;
			
		}
		
		fprintf(flaflu, "%s\n", original);
		
	}
	
	fclose(flaflu);
}

/*
1 - linha = "Casa Fluminense peixe "
	original = "Casa Fluminense peixe "
	linha = "Casa\0Fluminense peixe "
	palavra = "[Casa\0]Fluminense peixe "
	
	tamanhoP = 4 + 1 = 5
	
	palavra = "Casa\0[Fluminense\0]peixe "
	tamanhoL = 5
	
2 - original = "Casa Fluminense peixe "
	linha = "Casa\0Fluminense\0peixe "
	palavra = "Casa\0[Fluminense\0]peixe "
	
	tamanhoP = 10 + 1 = 11
	
		tamanhoR = 5 + 11 - 1 = 15
		resto = " peixe\0"
		original = "Casa *FLAMENGO*\0peixe "
		original = "Casa *FLAMENGO* peixe\0"
		
	palavra = "Casa\0Fluminense\0[peixe\0]"
	tamanhoL = 16
	
3 - original = "Casa *FLAMENGO* peixe\0"
	linha = "Casa\0Fluminense\0peixe\0"
	palavra = "Casa\0Fluminense\0[peixe\0]"
	
	tamanhoP = 5 + 1 = 6
	
	palavra = NULL
	tamanhoL = 22	
*/

int main(){

	/* 
	   "r" = modo de leitura; se o arquivo não existir ou der erro retorna NULL (ponteiro no começo do arquivo)
	   "r+" = modo atualização (grava e lê); se o arquivo não existir ou der erro retorna NULL 
	*/
	FILE *fluminense = fopen("hino_fluminense.txt", "r");
	
	if (fluminense != NULL) 
		copiar_texto(fluminense);
		
	else
		printf("ERRO AO ABRIR O ARQUIVO FLUMINENSE\n");
		
	fclose(fluminense);

	return 0;
} 
