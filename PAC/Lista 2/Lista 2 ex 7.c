//Lista 2 ex 7
//função p calcular e retornar o volume de uma caixa de lados abc
//função p calcular e retornar o vol de um cilindro de raio r e altura h
#include<stdio.h>
#include<math.h>
float volCaixa (float a, float b, float c)
{
	float calc_volcaixa;
	calc_volcaixa = a * b * c;
	return calc_volcaixa;
}
float volCil (float r, float h)
{
	float calc_volcil;
	calc_volcil = 3.14 * h * pow(r,2);
	return calc_volcil;
}
void main()
{
	float a, b, c, h, r, volumecaixa, volumecilindro, volumefinal;
	printf("\nDigite o valor dos lados da caixa: ");
	scanf("%f", &a);
	scanf("%f", &b);
	scanf("%f", &c);
	volumecaixa = volCaixa (a, b, c);
	printf("\nDigite a altura e o raio do cilindro: ");
	scanf("%f", &h);
	scanf("%f", &r);
	volumecilindro = volCil (h, r);
	volumefinal = volumecaixa - volumecilindro;
	printf("O volume da caixa com o furo cilindrico e: %.2f", volumefinal);
}
