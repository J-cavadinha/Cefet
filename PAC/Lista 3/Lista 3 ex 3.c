//Função calcula área corporal usando a fórmula de Mosteller (altura e peso)
//Função q recebe duas áreas e exibe se "manteve", "aumentou" ou "diminuiu" a área corporal
//Programa usando as funções que leia peso e altura no início do ano e o valor no final do ano e 
//exibe se "manteve", "aumentou" ou "diminuiu" a área corporal
#include<stdio.h>
#include<math.h>
float areaCorporal (float h, float kg)
{
	float calculoarea;
	calculoarea = (sqrt(kg*h))/60;
	return calculoarea;
}
float compArea (float areainicio, float areafinal)
{
	if (areainicio == areafinal)
		printf("Manteve a area corporal");
	else
		if (areainicio > areafinal)
		printf("Diminuiu a area corporal");
	else
		printf("Aumentou a area corporal");
}
void main()
{
	int pesoi, alturai, pesof, alturaf;
	float areainicio, areafinal, comparacao;
	printf("Digite seu peso em kg e sua altura em cm respectivamente ao inicio do ano:");
	scanf("%d%d", &pesoi, &alturai);
	printf("\nDigite seu peso em kg e sua altura em cm respectivamente ao final do ano:");
	scanf("%d%d", &pesof, &alturaf);
	areainicio = areaCorporal (pesoi, alturai);
	areafinal = areaCorporal (pesof, alturaf);
	comparacao = compArea (areainicio, areafinal);
}
