// Lista 5 ex 1
// Programa para processar os downloads dos usu�rios do site
// Programa deve ler o pre�o que o site cobra por Mbytes
// Para cada usu�rio, o programa dever� ler a qtde de downloads desejada e para cada download o tam
// em Mbytes, calcular e exibir o valor a ser pago pelo usu�rio
// No final o programa dever� exibir o valor m�dio pago pelo usu�rio e o maior valor pago

// Fun��o para processar os downloads de um usu�rio, recebe a qtde de downloads e o pre�o cobrado 
// por Mbyte, a fun��o deve ler o tam de cada download, calcular, exibir e retornar o valor a ser pg
#include<stdio.h>
float processDown (int qtdedown, float precombyte)
{
	float download;
	download = qtdedown * precombyte;
	printf("O valor a ser pago e: %.2f", download);
	return download;
}
int main()
{
	printf("Quantidade de downloads:");
	scanf("%d", &qtdedown);
	printf("Digite o tamanho dos downloads em Mbyte: ");
	scanf("%f", &tammbyte);
	printf("Preco cobrado por Mbyte:");
	scanf("%f", &precombyte);
}

