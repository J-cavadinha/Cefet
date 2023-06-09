/*Programa não finalizado, dificuldade na função exibe e main (achar o menor salário por depto
e exibir*/
#include<stdio.h>
#define TOT 2 //500 funcionários
#define DEP 10
void inicializa(float sal[])
{
	int i;
	for(i = 0; i <= TOT; i++)
	{
		sal[i] = 0;
	}
}
void exibe(float sal[])
{
	int i;
	float menorsal;
	for(i = 1; i < DEP; i++)
	{
	if(sal[i] < sal[0] )
		menorsal = sal[i];
	else
		menorsal = sal[0];
	}
	printf("Menor salario: %.2f", menorsal);
}
int main()
{
	float sal[TOT];
	inicializa(sal);
	int dep[10];
	int i;
	for(i = 0; i < TOT; i++)
	{
		printf("Digite o codigo do departamento e o salario: ");
		scanf("%d%f", &dep[i], &sal[i]);
	}
	exibe(sal);
	return 0;
}
