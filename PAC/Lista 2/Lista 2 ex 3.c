//Programa que leia 3 num int fornecidos pelo usuário utilizando as seg funções:
//calcula_soma: recebe 3 num int, calcula, exibe e retorna a soma
//calcula_media: calcula e exibe a media utilizando a função anterior
#include<stdio.h>
int calculaSoma (int num1, int num2, int num3)
{
	int calcula_soma;
	calcula_soma = num1 + num2 + num3;
	printf("A soma e: %d", calcula_soma);
	return calcula_soma;
}
void calculaMedia (int calcula_soma)
{
	float calcula_media;
	calcula_media = (float)(calcula_soma)/3.0;
	printf("\nA media e: %.2f", calcula_media);
}
int main()
{
	int numero1, numero2, numero3, csoma;
	printf("Digite o primeiro numero inteiro: ");
	scanf("%d", &numero1);
	printf("Digite o segundo numero inteiro: ");
	scanf("%d", &numero2);
	printf("Digite o terceiro numero inteiro: ");
	scanf("%d", &numero3);
	csoma = calculaSoma(numero1, numero2, numero3);
	calculaMedia (csoma);
	return 0;
}
