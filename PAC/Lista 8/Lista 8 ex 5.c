//Lista 8 ex 5
#include<stdio.h>
#define TOT 3
struct produto
{
	int cod;
	float pu;
	int qtestq;
};
typedef struct produto Tprod;

void leitura(Tprod produto[])
{
	int i;
	for(i = 0; i< TOT; i++)
	{
		printf("Digite o codigo, preco e qtd do produto: ");
		scanf("%d%f%d", &produto[i].cod, &produto[i].pu, &produto[i].qtestq);
	}
}
int busca(Tprod produto[], int cadecod)
{
	int i;
	for(i = 0; i < TOT; i++)
	{
		if(produto[i].cod == cadecod)
			return i;
	}
	return -1;
}
int main()
{
	int cont, codprod;
	Tprod produto[TOT];
	leitura(produto);
	
	for(cont = 1; cont < 999; cont++)
	{
	printf("Digite o codigo do produto que deseja procurar: ");
	scanf("%d", &codprod);
	
	if(codprod != 0)
		{
		int i = busca(produto, codprod);
		if(i != -1)
		printf("Preco unitario: %.2f\nQuantidade em estoque: %d\n", produto[i].pu, produto[i].qtestq);
		else
		printf("Produto não encontrado!");
		}	
	else
	break;
	}
	return 0;
}

