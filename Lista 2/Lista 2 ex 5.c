//Programa deve ler matrícula, nota prova1, nota prova2, trabalho1, trabalho2
//Programa eve exibir matrícula, média provas, média trabalhos e média final
//calcula_media: receber os dois valores, calcular e retornar a média
#include<stdio.h>
float mediaProvas (float prova1, float prova2)
{
	float mediap;
	mediap = (prova1 + prova2)/2;
	return mediap;
}
float mediaTrab (float trab1, float trab2)
{
	float mediat;
	mediat = (trab1 + trab2)/2;
	return mediat;
}
float mediaGeral (float mediap, float mediat)
{
	float calcula_geral;
	calcula_geral = (mediap + mediat)/2;
	return calcula_geral;
}
int main()
{
	int matricula;
	float p1, p2, t1, t2, mediap, mediat, mediag;
	printf("Digite sua matricula: ");
	scanf("%d", &matricula);
	printf("Digite a nota da primeira prova: ");
	scanf("%f", &p1);
	printf("Digite a nota da segunda prova: ");
	scanf("%f", &p2);
	printf("Digite a nota dos trabalhos: ");
	scanf("%f", &t1);
	printf("Digite a nota do segundo trabalho: ");
	scanf("%f", &t2);
	mediap = mediaProvas(p1, p2);
	mediat = mediaTrab(t1, t2);
	mediag = mediaGeral(mediap, mediat);
	printf("\nmatricula: %d", matricula);
	printf("\nmedia das provas: %.1f", mediap);
	printf("\nmedia dos trabalhos; %.1f", mediat);
	printf("\nmedia geral: %.1f", mediag);
	return 0;
}
