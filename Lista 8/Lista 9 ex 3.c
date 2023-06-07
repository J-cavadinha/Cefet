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
		printf("Nome: %s\t Media: %.2f\t Situacao:", aluno_a[i].nome, aluno_a[i].media);
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
	int i;
	float mdt = 0, nota1, nota2;
	for(i=0; i < TOT; i++)
	{
		printf("Digite seu nome e suas duas notas: ");
		scanf(" %c%f%f", &aluno_a[i].nome, &nota1, &nota2);
		aluno_a.media = (nota1 + nota2)/2;
		mdt = mdt + aluno_a.media[i];
	}
	exibe(aluno_a.nome, aluno_a.media, mdt);
	return 0;
}
