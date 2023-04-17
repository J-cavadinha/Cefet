//Lista 4 - exercício 1
#include<stdio.h>
void tabuada (int n)
{
	int cont, valor;
	cont = 1;
	while(cont <= 10);
	{
		valor = n * cont;
		printf("\n%d x %d = %d", n, cont, valor);
		cont = cont + 1;
	}
	printf("\n");
}
int main()
{
	int tab;
	tab = 1;
	while (tab <= 10)
	{
		tabuada(tab);
		tab = tab +1;
	}
	return 0;
}
