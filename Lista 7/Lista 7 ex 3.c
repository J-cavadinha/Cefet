#include<stdio.h>
void media (float num[], int qtd, float media)
{
	int cont, qtdacima;
	
	for(cont = 0; cont < qtd; cont++)
	{
		if (num[cont] > media)
			qtdacima = qtdacima + 1;
		}	
}
