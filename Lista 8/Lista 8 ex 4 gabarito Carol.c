#include<stdio.h>
#define TOT 100
#define DEP 11
struct depto
{
	int qtd;
	float soma;
};
typedef struct depto Tdep;
void inicializa(Tdep v[])
{
	int i;
	for(i=0; i < DEP; i++)
	{
		v[i].qtd = 0;
		v[i].soma = 0;
	}
}
void exibe(Tdep v[])
{
	int i;
	float idmd;
	for(i = 0; i<DEP; i++)
	{
		if(v[i].qtd != 0)
			idmd = (float) v[i].soma / v[i].qtd;
		else
			idmd = 0;
			printf("\nDepartamento %d: %f", i + 10, idmd);
	}
}
int main()
{
	Tdep depart[DEP];
	int cont, matr, cod, idade;
	inicializa(depart);
	for(cont = 0; cont < TOT; cont++)
	{
		printf("\nDigite matricula, departamento e idade: ");
		scanf("%d%d%d", &matr, &cod, &idade);
		depart[cod - 10].qtd++;
		depart[cod - 10].soma += idade;
	}
	exibe(depart);
	return 0;
}
