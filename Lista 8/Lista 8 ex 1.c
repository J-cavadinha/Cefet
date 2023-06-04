#include<stdio.h>
#define size 5
void inicializa (int vet[], int tam) //inicia o vetor com 0 em todas as posições.
{
	int i;	
	for (i = 0; i <= tam; i++)
	{
		vet[i] = 0;
	}
}

void exibe (int vet[], int tam)
{
	int i;
	for (i = 0; i < tam; i++)
	{
		printf("Nota %d: %d\n", i, vet[i]);
	}
}

void main ()
{
	int vet[11], i, nota;
	inicializa(vet, 10);
	
	printf("Digite as notas dos alunos: ");
	for (i = 0; i < 100; i++)
	{
		scanf("%d", &nota);
		if (nota == -1)
		{
			exibe (vet, 10);
		}
		if (nota >= 0 && nota <= 10)
		{
			vet[nota]++;
		}
		else
		{
			printf("Nota invalida.");
		}
	}
}
