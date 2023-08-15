//Programa que leia 3 números inteiros e exiba o maior
//Função que leia 3 num int e retorne o maior
#include<stdio.h>
int maiornum (int num1, int num2, int num3)
{
	if (num1 > num2 && num1 > num3)
		return num1;
		
	if (num2 > num1 && num2 > num3)
		return num2;
	else
		return num3;
}
int main()
{
	int num1, num2, num3, maiornumero;
	printf("Digite 3 numeros inteiros distintos:");
	scanf("%d%d%d", &num1, &num2, &num3);
	maiornumero = maiornum (num1, num2, num3);
	printf("O maior numero e: %d", maiornumero);
}
