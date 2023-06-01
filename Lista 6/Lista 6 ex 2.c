#include<stdio.h>
void contabProd (char tipop, int *nacional, int *importado)
{
	int cont;
	*nacional = *importado = cont = 0;
	
	do{
		
	cont = cont + 1;
	
	if (tipop == 'N'){
		printf("Produto nacional.");
		*nacional = *nacional + 1;
	}
	
	if (tipop == 'I'){
		printf("Produto importado.");
		*importado = *importado + 1;
	}
	}
	while (cont < 40);
}
int main()
{
	char tipop;
	int codigo, qtestoque;
	float preco, calculavalor;
	
	printf("Digite o código do produto: ");
	scanf("%d", &codigo);
	printf("Digite o tipo de produto (I - importado e N - nacional): ");
	scanf(" %c", &tipop);
	printf("Digite a quantidade em estoque: ");
	scanf("%d", &qtestoque);
	printf("Digite o preço unitario: ");
	scanf("%f", &preco);
	calculavalor = qtestoque * preco;
	
	printf("Codigo: %d", codigo);
	contabProd(tipop);
	printf("%d",contabilizador);
	printf("Valor em estoque: ", calculavalor);
	return 0;
	}
