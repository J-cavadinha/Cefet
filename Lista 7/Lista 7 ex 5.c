#include<stdio.h>

struct depto
{
int qtd;
float soma;
};
typedef struct depto Tdepto;

void seila (struct depto dados[])
{
	int cont;
	float salmedio;
	for (cont = 1; cont < 30; cont++)
	{
		salmedio = depto.soma / depto.qtd;
		printf("Codigo do departamento: %d\t\t Salario medio: %.2f", cont, salmedio);
	}
}
