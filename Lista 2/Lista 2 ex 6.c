//Programa que capture as coordenadas dos 3 vértices de um triângulo, calcule e exiba o perímetro.
//Usando uma função que receba as coordenadas de dois pontos e retorne a distância entre eles.
#include<stdio.h>
#include<math.h>
float distancia(int px1, int py1, int px2, int py2)
{
	float d;
	d = (float)sqrt(pow(px1-px2,2) + pow(py1-py2,2));
	return d;
}
void main()
{
	int x1, y1, x2, y2, x3, y3, reta1_2, reta1_3, reta2_3, perimetro;
	printf("Digite as coordenadas do primeiro ponto:");
	scanf("%d", &x1);
	scanf("%d", &y1);
	printf("Digite as coordenadas do segundo ponto: ");
	scanf("%d", &x2);
	scanf("%d", &y2);
	printf("Digite as coordenadas do terceiro ponto: ");
	scanf("%d", &x3);
	scanf("%d", &y3);
	reta1_2 = distancia(x1, y1, x2, y2);
	reta1_3 = distancia(x1, y1, x3, y3);
	reta2_3 = distancia(x2, y2, x3, y3);
	perimetro = reta1_2 + reta1_3 + reta2_3;
	printf("O perimetro e: %d", perimetro);
}

