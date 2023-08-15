//Lista 6 ex 4, entendi foi nada dessa questão
#include<stdio.h>
int leValidaClassificacao ()
{
	int classif;
	printf("Digite a classificacao: ");
	scanf("%d", &classif);
	if (classif >= 1 && classif <=4)
		return classif;
	else
		printf(Erro.);
}
int classe (int classif, int *qtdmin, int *qtdmax)
{
	if (classif == 1)
	{
		*qtdmin = 100;
		*qtdmax = 120;
	}
	}
