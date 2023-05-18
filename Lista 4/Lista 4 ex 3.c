//Lista 4 ex 3
#include<stdio.h>
float Posto ()
{
	int contador, codposto;
	float faturaposto, faturatotal, maiorfaturam;
	contador = 0;
	faturatotal = 0;
	maiorfaturam = 0;
	while (contador < 20)
	{
		contador = contador + 1;
		printf("Digite o codigo do posto: ");
		scanf("%d", &codposto);
		printf("Digite o faturamento do posto: ");
		scanf("%f", &faturaposto);
		faturatotal = faturatotal + faturaposto;
		
		if (faturaposto > maiorfaturam)
		maiorfaturam = faturaposto;
	}
	printf("\nO maior faturamento foi de: %.2f", maiorfaturam);
	return faturatotal;
}
void main ()
{
	printf("\nFatura total: %.2f", Posto());
}
