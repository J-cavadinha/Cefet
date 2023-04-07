//Programa que leia 3 números int fornecidos pelo usuário usando as seguintes funções:
// a)calcula_soma -> 3 num int, calcula, exibe e retorna a soma
// b)calcula_media -> 3 num int, calcula e exibe a media
#include<stdio.h>
int calculaSoma (int num1, int num2, int num3)
{
	int calcula_soma;
	calcula_soma = (num1 + num2 + num3);
	printf("\n Resultado da soma: %d", calcula_soma);
	return calcula_soma;
}
void calculaMedia (int n1, int n2, int n3)
{
	float calcula_media;
	calcula_media = (float)(n1 + n2 + n3)/3.0;
	printf("\n Resultado da media: %.2f", calcula_media);
}
int main()
{
	int numero1, numero2, numero3, csoma;
	printf("Digite o primeiro numero: ");
	scanf("%d", &numero1);
	printf("Digite o segundo numero: ");
	scanf ("%d", &numero2);
	printf("Digite o terceiro numero: ");
	scanf("%d", &numero3);
	csoma = calculaSoma (numero1, numero2, numero3);
	calculaMedia (numero1, numero2, numero3);
	return 0;
}
