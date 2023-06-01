#include<stdio.h>
float menornum (float num[], int qtd)
{
	int cont, qtdmenor;
	float ultimo;
	ultimo = num[qtd -1];
	
	qtdmenor = 0;
	for (cont = 0; cont < qtd; cont++)
	{
		if (num[cont] < ultimo)
			qtdmenor++;
	}
	return qtdmenor;
}
