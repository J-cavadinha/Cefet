//P1 - 1)
#include<stdio.h>
float perimetro(float Xmin, float Ymin, float Xmax, float Ymax)
{
	float largura, altura, peri_retangulo;
	largura = Xmax - Xmin;
	altura = Ymax - Ymin;
	peri_retangulo = (largura + altura) * 2;
	return peri_retangulo;
}
float area(float Xmin, float Ymin, float Xmax, float Ymax)
{
	float largura, altura, area_retangulo;
	largura = Xmax - Xmin;
	altura = Ymax - Ymin;
	area_retangulo = largura * altura;
	return area_retangulo;
}
int main()
{
	int qtpontos, i, quadrante1, quadrante2, quadrante3, quadrante4;
	quadrante1 = quadrante2 = quadrante3 = quadrante4 = 0;
	float x, y, Xmin, Ymin, Xmax, Ymax, calcula_peri, calcula_area;
	printf("Digite a quantidade de pontos que deseja processar: ");
	scanf("%d", &qtpontos);
	for(i=0; i<qtpontos/2; i++)
	{
		printf("%d) Digite x e y: ", i);
		scanf("%f%f", &x, &y);
		if(x>0 && y>0)
			quadrante1 = quadrante1 + 1;
		else if(x<0 && y>0)
			quadrante2 = quadrante2 + 1;
		else if(x<0 && y<0)
			quadrante3 = quadrante3 + 1;
		else
			quadrante4 = quadrante4 + 1;
			
		if(i==0)
		{
			Xmax = Xmin = 0;
			Ymax = Ymin = 0;
		}
		else
		{
			if(x > Xmax)
				Xmax = x;
			if(x < Xmin)
				Xmin = x;
			if(y > Ymax)
				Ymax = y;
			if(y < Ymin)
				Ymin = y;
		}
	}
	calcula_peri = perimetro(Xmin, Ymin, Xmax, Ymax);
	calcula_area = area(Xmin, Ymin, Xmax, Ymax);
	printf("Perimetro: %.2f\t Area: %.2f\n", calcula_peri, calcula_area);
	printf("1o quadrante: %d pontos\t", quadrante1);
	printf("2o quadrante: %d pontos\t", quadrante2);
	printf("3o quadrante: %d pontos\t", quadrante3);
	printf("4o quadrante: %d pontos\t", quadrante4);
}
