//Lista 4 - ex 2
#include<stdio.h>
int processaAuto (int qtd)
{
	int cont, acima, cod, qtdest;
	cont = acima = 0;
	while(cont < qtd)
	{
		printf("Digite o codigo e qtde em estoque: ");
		scanf("%d%d", &cod, &qtdest);
		if(qtdest > 1000)
			acima = acima + 1;
		cont = cont + 1;
	}
	return acima;
}
int main()
{
	int qtddifer, qtdacima;
	printf("Digite a qtde de automoveis diferentes: ");
	scanf("%d", &qtddifer);
	qtdacima = processaAuto (qtddifer);
	printf("\nQuantidade acima de 100: %d", qtdacima);
	return 0;
}
