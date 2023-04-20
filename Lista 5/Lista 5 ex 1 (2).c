// Lista 5 ex 2
#include<stdio.h>
int menu (char 1, char 2, char 3, char 4, char 5){
	printf("1) Quadrado\n 2) Retangulo\n 3) Triangulo\n 4) Trapezio\n 5) Fim.\n");
	scanf("%c", &opcao);
	
	if (opcao == 1){
		printf("Digite o lado do quadrado:");
		scanf("%f", &lado);
		areaquadrado (lado);
		printf("Area do quadrado: %.2f", areaquadrado);
	}
	if (opcao == 2){
		printf("Digite a base e a altura:");
		scanf("%f%f", &base, &altura);
		arearetangulo (base, altura);
		printf("Area do retangulo: %.2f", arearetangulo);
	}
	if (opcao == 3){
		printf("Digite a base e a altura:");
		scanf("%f%f", &base, &altura);
		areatriangulo (base, altura);
		printf("Area do triangulo: %.2f", areatriangulo);
	}
	if (opcao == 4){
		printf("Digite a base maior, base menor e a altura:");
		scanf("%f%f%f", &basemaior, &basemenor, &altura);
		areatrapezio (basemaior, basemenor, altura);
		printf("Area do trapezio: %.2f", areatrapezio);
	}
	if (opcao == 5)
		printf("Fim.");
	}
}
float quadrado (float lado)
{
	float areaquadrado;
	areaquadrado = lado * lado;
	return areaquadrado;
}
float retangulo (float base, float altura)
{
	float arearetangulo;
	arearetangulo = base * altura;
	return arearetangulo;
}
float triangulo (float base, float altura)
{
	float areatriangulo;
	areatriangulo = (base * altura)/2;
	return areatriangulo;
}
float trapezio (float basemenor, float basemaior, float altura)
{
	float areatrapezio;
	areatrapezio = ((basemenor + basemaior)*altura)/2;
	return areatrapezio;
}


