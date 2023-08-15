//Programa que leia 3 num int fornecidos pelo usuário usando as funções:
//calcula_soma -> recebe 3 num int, calcula e retorne a soma
//calcula_media -> recebe 3 num int, calcula e exiba a media
#include<stdio.h>
int calculaSoma (int n1, int n2, int n3)
{
	int calcula_soma;
	calcula_soma = n1 + n2 + n3;
	return calcula_soma;
}
void calculaMedia (int num1, int num2, int num3)
{
	float calcula_media;
	calcula_media = (num1 + num2 + num3) /3;
	printf("\nA media e: %.2f", calcula_media);
}
int main()
{
	int numero1, numero2, numero3, calcsoma;
	printf("Digite 1 numero inteiro: ");
	scanf("%d", &numero1);
	printf("Digite o segundo numero inteiro: ");
	scanf("%d", &numero2);
	printf("Digite o terceiro inteiros: ");
	scanf("%d", &numero3);
	calcsoma = calculaSoma (numero1, numero2, numero3);
	printf("\nA soma e: %d", calcsoma);
	calculaMedia (numero1, numero2, numero3);
	return 0;
}
