/*Programa n�o finalizado, dificuldade na fun��o exibe e main (achar o menor sal�rio por depto
e exibir*/
#include<stdio.h>
#define TOT 500 /*500 funcion�rios*/
void inicializa(float sal[]) //Fun��o coloca 0 em todas as pos. do vetor
{
	int i;
	for(i = 0; i <= TOT; i++)
	{
		sal[i] = 0;
	}
}
void exibe(float sal[])
{
	int i, menorsal[10];
	
	for(i = 0; i < 10; i++) //inicializa o vetor de menores sal�rios.
	{
		menorsal[i] = 999999.9;
	}
	for(i = 0; i < TOT; i++)
	{
		if(sal[i] > ++sal[i])
		menorsal = sal[i];
	}
	printf("Menor salario e: %.2f", menorsal);
}

int main()
{
	float sal[9999999]; //N�mero alto p abranger todos os sal�rios.
	inicializa(sal);
	int dep[10];
	int i;
	for(i = 0; i < TOT; i++)
	{
		printf("Digite o codigo do departamento: ");
		scanf("%d", &dep[i]);
		printf("Digite o salario: ");
		scanf("%f", &sal[i]);	
	}
	return 0;
}
