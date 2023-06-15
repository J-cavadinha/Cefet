#include<stdio.h>
#define TOT 2
#define MAX 31

struct aluno{
	char nome[MAX];
	float media; 
};
typedef struct aluno Taluno;

void exibe(aluno v[], float mdturma)
{
	int i;
	for(i = 0; i < TOT; i++){
		
		printf("\n%-30s\t%.1f\t", v[i].nome, v[i].media);
		if(v[i].media > mdturma)
		printf("Acima da media da turma.");

		else if(v[i].media == mdturma)
			printf("Na media da turma.");
		
		else
			printf("Abaixo da media da turma.");
	}
	
}

int main(){
	Taluno aluno[MAX];
	float mdturma=0, nota1, nota2, soma=0;
	int i;
	
	for(i = 0; i < TOT; i++)
	{
		printf("Digite o nome do aluno e a suas 2 notas: ");
		scanf(" %30[^\n]%f%f", aluno[i].nome, &nota1, &nota2);
		aluno[i].media = (nota1 + nota2)/2;
		soma += aluno[i].media;
	}
	mdturma = soma / TOT;
	exibe(aluno, mdturma);
	
	return 0;
}
