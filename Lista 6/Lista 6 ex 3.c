#include<stdio.h>
void umDepartamento (int qtdf, int *qtdmaiorsal, float *maiorsal)
{
	int matr, i;
	float sal;
	*maiorsal = 0;
	*qtdmaiorsal = 0;
	
	for (i = 0; i < qtdf; i++)
	{
		printf("Digite a matricula e o salario: ");
		scanf("%d%f", &matr, &sal);
		if(sal > *maiorsal)
		{
			*maiorsal = sal;
			*qtdmaiorsal = *qtdmaiorsal + 1;
		if (sal == *maiorsal)
		{
			*qtdmaiorsal = *qtdmaiorsal + 1;
		}
	}
}
	printf("O maior salario e: %.2f\t", *maiorsal);
	printf("%d pessoas tem  maior salario", *qtdmaiorsal);
}
void main ()
{
	int coddep, qtdf, qtdmaiorsal;
	float maiorsal;
	
	printf("Digite o codigo do departamento (0 - fim): ");
	scanf("%d", &coddep);
	printf("Digite a quantidade de funcionarios: ");
	scanf("%d", &qtdf);
	umDepartamento (qtdf, &qtdmaiorsal, &maiorsal);
	
	while (coddep != 0)
	
	
	}
