//Programa que leia a idade de uma pessoa e exiba a sua situação eleitoral
#include<stdio.h>
void sitEleitoral (int idade)
{
	if (idade < 16)
		printf("\nNao eleitor.");
	else
		if (idade < 18)
			printf("\nEleitor nao obrigatorio.");
		else
			if (idade <= 70)
				printf("\nEleitor.");
			else
				printf("\nEleitor obrigatorio.");
}
void main()
{
	int idade, situacao;
	printf("Digite sua idade:");
	scanf("%d", &idade);
	sitEleitoral (idade);
}
