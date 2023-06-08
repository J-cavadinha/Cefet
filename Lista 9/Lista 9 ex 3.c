#include<stdio.h>
#define TOT 2
struct aluno
{
	char nome[31];
	float media;
};
typedef struct aluno Taluno;

void exibe (Taluno aluno_a[], float mdt)
{
	int i;
	for(i =0; i < TOT; i++)
	{
		printf("\nNome: %s\t Media: %.2f\t Situacao:", aluno_a[i].nome, aluno_a[i].media);
		if (aluno_a[i].media > mdt)	
		 	printf("Acima da media.");
		else
		if (aluno_a[i].media == mdt)
		printf("Na media.");
		else
		printf("Abaixo da media.");	
	}	
}
int main()
{
	int i, cont;
	float mdt = 0, nota1, nota2;
	Taluno aluno_a[TOT];
	for(i=0; i < TOT; i++)
	{
		printf("Digite seu nome e suas duas notas: ");
		scanf(" %s%f%f", &aluno_a[i].nome, &nota1, &nota2);
		aluno_a[i].media = (nota1 + nota2)/2;
	}
	for(cont=0; cont < TOT; cont++)
	{
		mdt = mdt + aluno_a[i].media;
		if (cont == TOT -1)
			mdt = mdt / cont;
	}
	exibe(aluno_a, mdt);
	return 0;
}
