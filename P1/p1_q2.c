//P1 - 2)
#include<stdio.h>
float calcula_variacao(int a, int b)
{
	float variacao;
	variacao = 100 * ((float)(b - a) / a);
	return variacao;
}
int main()
{
	int i, codigo, a, b, norte, nordeste, sudeste, sul, centroeste, brasil;
	float variacao;
	norte = nordeste = sudeste = sul = centroeste = 0;
	
	for(i=0; i<5; i++)
	{
		printf("Digite o codigo, a populacao em 2010 e a populacao em 2022: ");
		scanf("%d%d%d", &codigo, &a, &b);
		
		if(codigo > 10 && codigo < 20)
		{
			norte = norte + b;
			brasil = brasil + b;
		}
		else if(codigo > 20 && codigo < 30)
		{
			nordeste = nordeste + b;
			brasil = brasil + b;
		}
		else if(codigo > 30 && codigo < 40)
		{
			sudeste = sudeste + b;
			brasil = brasil + b;
		}
		else if(codigo > 40 && codigo < 50)
		{
			sul = sul + b;
			brasil = brasil + b;
		}
		else if(codigo > 50 && codigo < 60)
		{
			centroeste = centroeste + b;
			brasil = brasil + b;
		}
		else
			printf("Erro.");
/////
	variacao = calcula_variacao(a, b);
	
		if(variacao > 0)
			printf("Codigo: %d\t Variacao: %.2f\t Aumentou.\n", codigo, variacao);
		else if(variacao < 0)
			printf("Codigo: %d\t Variacao: %.2f\t Diminuiu.\n", codigo, variacao);
		else
			printf("Codigo: &d\t Variacao: %.2f\t Constante.\n", codigo, variacao);
	}
	printf("\nNorte: %d \nNordeste: %d \nSudeste: %d\n", norte, nordeste, sudeste);
	printf("Sul: %d \nCentro-oeste: %d \nBrasil: %d", sul, centroeste, brasil);
	return 0;
}
