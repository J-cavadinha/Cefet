// Lista 5 ex 1
// Programa para processar os downloads dos usuários do site
// Programa deve ler o preço que o site cobra por Mbytes
// Para cada usuário, o programa deverá ler a qtde de downloads desejada e para cada download o tam
// em Mbytes, calcular e exibir o valor a ser pago pelo usuário
// No final o programa deverá exibir o valor médio pago pelo usuário e o maior valor pago

// Função para processar os downloads de um usuário, recebe a qtde de downloads e o preço cobrado 
// por Mbyte, a função deve ler o tam de cada download, calcular, exibir e retornar o valor a ser pg
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

