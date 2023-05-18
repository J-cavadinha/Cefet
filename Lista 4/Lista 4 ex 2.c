// Lista 4, ex 2
#include<stdio.h>
int difAuto (int qtdeauto) //qtdeauto -> qtde automóveis diferentes produzidos.
{
	int contador, acimademil, codmod, qtdeestoq;
	contador = 0;
	acimademil = 0;
	while (contador < qtdeauto)
	{
		contador = contador + 1;
		printf("\nDigite o codigo do modelo: ");
		scanf("%d", &codmod);
		printf("\nDigite a quantidade em estoque: ");
		scanf("%d", &qtdeestoq);
			if(qtdeestoq > 1000)
				acimademil = acimademil + 1;
	}
	return acimademil;
}

void main ()
{
	int qtdeauto;
	printf("Digite a quantidade de automoveis diferentes produzidos: ");
	scanf("%d", &qtdeauto);
	printf("%d automoveis tem quantidade em estoque acima de mil.", difAuto(qtdeauto));
}
