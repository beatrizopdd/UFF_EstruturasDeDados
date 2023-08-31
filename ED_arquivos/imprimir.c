#include <stdio.h>
#include <string.h>

void imprimir(FILE *texto) {

	char linha[200];
	
	/* %s pega a linha até o primeiro espaço em branco    */
	/* %[^\n] pega a linha até a primeira quebra de linha */
	
	while (fscanf(texto, "%[^\n]\n", linha) != -1)
		printf("%s\n", linha);
		
}

int main() {

	/* 
	   "r" = modo de leitura; se o arquivo não existir ou der erro retorna NULL (ponteiro no começo do arquivo)
	   "r+" = modo atualização (grava e lê); se o arquivo não existir ou der erro retorna NULL 
	*/
	FILE *botafogo = fopen("hino_botafogo.txt", "r");
	
	if (botafogo != NULL) 
		imprimir(botafogo);
		
	else
		printf("ERRO AO ABRIR O ARQUIVO BOTAFOGO\n");
		
	fclose(botafogo);

	return 0;
}
