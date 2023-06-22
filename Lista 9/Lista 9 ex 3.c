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
		printf("Digite seu nome: ");
		scanf(" %30[^\n]", &aluno_a[i].nome);
		printf("Digite suas duas notas: ");
		scanf("%f%f", &nota1, &nota2);
		aluno_a[i].media = (nota1 + nota2)/2;
		mdt = mdt + aluno_a[i].media;
	}
	mdt = mdt/TOT;
	exibe(aluno_a, mdt);
	return 0;
}
