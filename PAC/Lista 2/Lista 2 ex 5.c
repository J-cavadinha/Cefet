//Programa deve ler matrícula, nota prova1, nota prova2, trabalho1, trabalho2
//Programa eve exibir matrícula, média provas, média trabalhos e média final
//calcula_media: receber os dois valores, calcular e retornar a média
#include<stdio.h>
float calcula_media (float valor1, float valor2)
{
	float media;
	media = (valor1 + valor2)/2;
	return media;
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
	printf("Digite a nota do primeiro trabalho: ");
	scanf("%f", &t1);
	printf("Digite a nota do segundo trabalho: ");
	scanf("%f", &t2);
	mediap = calcula_media(p1, p2);
	mediat = calcula_media(t1, t2);
	mediag = calcula_media(mediap, mediat);
	printf("\nmatricula: %d", matricula);
	printf("\nmedia das provas: %.1f", mediap);
	printf("\nmedia dos trabalhos; %.1f", mediat);
	printf("\nmedia geral: %.1f", mediag);
	return 0;
}
