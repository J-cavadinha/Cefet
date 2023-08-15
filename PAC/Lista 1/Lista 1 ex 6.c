//Função que recebe o num de dias corridos e exiba-o em num de semanas e dias
//ex: 19 dias = 2 semanas e 5 dias
#include<stdio.h>
void Duracao (int diascorridos)
{
	int semanas, dias;
	semanas = diascorridos/7;
	dias = diascorridos %7;
	printf("%d semanas e %d dias", semanas, dias);
}
