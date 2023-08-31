#include <stdio.h>
#include <string.h>

char jogadores[][100] = {"25 - Matheus Cunha", "01 - Santos", "17 - Rossi", "03  Rodrigo Caio", "04 - Léo Pereira", "23 - David Luiz", "15 - Fabrício Bruno", "30 - Pablo", "34 - Matheuzinho", "02 - Varela", "43 - Wesley", "16 - Filipe Luís", "06 - Ayrton Lucas", "08 - Thiago Maia", "05 - Erick", "20 - Gerson", "21 - Allan", "07 - Everton Ribeiro", "14 - De Arrascaeta", "29 - Victor Hugo", "42 - Matheus França", "10 - Gabi", "27 - Bruno Henrique", "09 - Pedro", "11 - Everton", "22 - Luiz Araújo"};

void preencher(FILE *texto) {

	for (int i = 0; i < 26; i++) {
	
		if ((i == 0) || (i == 3) || (i == 8) || (i == 11) || (i == 13) || (i == 17) || (i == 21))
		
			switch (i){
			
				case 0:
					fprintf(texto, "*** GOLEIROS ***\n");
					break;
					
				case 3:
					fprintf(texto, "*** ZAGUEIROS ***\n");
					break;
					
				case 8:
					fprintf(texto, "***  LATERAIS DIREITOS ***\n");
					break;
					
				case 11:
					fprintf(texto, "*** LATERAIS ESQUERDOS ***\n");
					break;
					
				case 13:
					fprintf(texto, "*** VOLANTES ***\n");
					break;
					
				case 17:
					fprintf(texto, "***  MEIAS ***\n");
					break;
					
				case 21:
					fprintf(texto, "***  ATACANTES ***\n");
					break;
			}
		
		fprintf(texto, "%s\n", jogadores[i]);
	}	
}

int main () {

	/*
	   "w" = modo de gravação; se o arquivo existir apaga tudo que tem nele
	   "w+" = modo atualização (grava e lê); se o arquivo existir apaga tudo que tem nele
	*/
	FILE *elenco = fopen("elenco_flamengo.txt", "w");
	
	if (elenco != NULL) 
		preencher(elenco);
		
	else
		printf("ERRO AO ABRIR O ARQUIVO ELENCO DO FLAMENGO\n");

	fclose(elenco);
	
	return 0;
}

