#include<stdio.h>
float procuraNumero (float num[], float procurase, int qtd)
{
	for (cont = 0; cont < qtd; cont++)
	{
		if (num[cont] == procurase)
			return cont;
	}
	return -1;
}
