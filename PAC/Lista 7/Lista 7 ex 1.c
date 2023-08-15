#include<stdio.h>
int produto (int num[], int qtd)
{
	int cont, rprod;
	for (cont = 1; cont < qtd; cont++)
	{
		rprod = num[cont] * cont;
	}
	return rprod;
}
