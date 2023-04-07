//Programa q leia 3 num int fornecidos pelo usuário
//le_calcula_soma: le 3 num, calcula e retorna soma
//calcula_media: recebe a função anterior como param., calcula e exibe a media
#include<stdio.h>
int calculaSoma (int n1, int n2, int n3)
{
	int le_calcula_soma;
	le_calcula_soma = n1 + n2 + n3;
	return le_calcula_soma;
}
void calculaMedia (le_calcula_soma)
{
	float calcula_media;
	calcula_media = (float)(le_calcula_soma) /3;
	printf("\nA media e: %.2f", calcula_media);
}
void main()
{
	int numero1, numero2, numero3, calcsoma, calcmedia;
	printf("Digite o primeiro numero inteiro: ");
	scanf("%d", &numero1);
	printf("Digite o segundo numero inteiro: ");
	scanf("%d", &numero2);
	printf("Digite o terceiro numero inteiro: ");
	scanf("%d", &numero3);
	calcsoma = calculaSoma (numero1, numero2, numero3);
	printf("A soma e: %d", calcsoma);
	calculaMedia (calcsoma);
}
