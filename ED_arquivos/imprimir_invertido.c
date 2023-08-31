#include <stdio.h>
#include <string.h>

void imprimir_invertido(FILE *texto) {

	char linha[200];
	
	/* 1 - se não for a última linha, manda o resto do texto pra dentro da função
	   2 - se for última linha, essa linha sai da função e continua a chamada da anterior 
	   3 - a anterior se imprime, sai da função e continua a anterior, até chegar na primeira linha que chamou a função
	*/
	if ((fscanf(texto, "%[^\n]\n", linha) != -1)) {
		imprimir_invertido(texto);
		printf("%s\n", linha);
	}
	
	/*
	imprimir_inverso(RATO/ROEU/A/ROUPA/)
	|	imprimir_inverso(ROEU/A/ROUPA/)
	|	|	imprimir_inverso(A/ROUPA/)
	|	|	|	imprimir_inverso(ROUPA/)
	|	|	|	|	imprimir_inverso(null)
	|	|	|	ROUPA
	|	|	A
	|	ROEU
	RATO
	*/
}

int main() {

	/* 
	   "r" = modo de leitura; se o arquivo não existir ou der erro retorna NULL (ponteiro no começo do arquivo)
	   "r+" = modo atualização (grava e lê); se o arquivo não existir ou der erro retorna NULL 
	*/
	FILE *vasco = fopen("hino_vasco.txt", "r");
	
	if (vasco != NULL) 
		imprimir_invertido(vasco);
			
	else
		printf("ERRO AO ABRIR O ARQUIVO VASCO\n");	

	fclose(vasco);
	
	return 0;			
}
