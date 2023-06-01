#include<stdio.h>
void ParImpar (int vetor[], int qtd, int *qtdpar, int *qtdimpar)
{
	int cont;
	
	for (cont = 0; cont < qtd; cont++)
	{
		rest = vetor[cont] % 2;
		if (rest == 0)
			*qtdpar = *qtdpar + 1;
		else
			*qtdimpar = *qtdimpar + 1;
	}
}
